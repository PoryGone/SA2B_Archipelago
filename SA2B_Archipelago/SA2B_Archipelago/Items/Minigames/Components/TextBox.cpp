#include "../../../pch.h"
#include "../../../Utilities/SpriteUtilities.h"
#include "TextBox.h"

void TextBox::OnRender(SpriteNode& node, NJS_SPRITE& sprite)
{
	if (isDirty)
	{
		UpdateLineData(node);
	}
	if (lines.size() == 0)
	{
		return;
	}
	NJS_SPRITE tSprite = { { 0.0f, 0.0f, 0.0f }, 1.0f, 1.0f, 0, textData->FontTex, textData->FontAnims };

	float rotation = node.GetRotationGlobal();
	NJS_POINT3 right = Point3RotateAround({ 1.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, rotation);
	NJS_POINT3 down = Point3RotateAround({ 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, rotation);
	NJS_POINT3 pos = node.GetPositionGlobal();
	pos.x -= node.displaySize.x * 0.5f;
	pos.y -= (node.displaySize.y * 0.5f) - (fontSize * 0.5);
	pos = Point3RotateAround(pos, node.GetPositionGlobal(), rotation);

	ConstantMaterial = node.color;

	int l = 0;
	while (l < lines.size())
	{
		NJS_POINT3 linePos = Point3Add(pos, Point3Scale(down, l * fontSize));
		linePos = Point3Add(linePos, Point3Scale(right, lines[l].offset));
		for (int i = lines[l].startIndex; i < lines[l].lastIndex; i++)
		{
			if (text[i] >= ' ' && text[i] <= '~')
			{
				TextDataAndAnim charData = textData->GetAnimAndData(text[i]);
				float charScale = charData.data->height / 42.0f;
				float sX = (fontSize / (float)charData.anim->sx) * charData.data->ratio * charScale;
				float sY = fontSize / (float)charData.anim->sy * charScale;
				float cWidth = fontSize * charData.data->ratio * charScale;
				linePos = Point3Add(linePos, Point3Scale(right, cWidth * 0.5f));
				NJS_POINT3 charPos = linePos;
				linePos = Point3Add(linePos, Point3Scale(right, cWidth * 0.5f));
				charPos = Point3Add(charPos, Point3Scale(right, charData.data->xOffset * sX));
				charPos = Point3Add(charPos, Point3Scale(down, charData.data->yOffset * sY));
				tSprite.tanim = charData.anim;
				tSprite.tanim--;
				tSprite.p = charPos;
				tSprite.ang = NJM_DEG_ANG(rotation);
				tSprite.sx = sX;
				tSprite.sy = sY;
				if (rotation != 0.0f)
				{
					DrawSprite2D(&tSprite, 1, 1.0f, NJD_SPRITE_ALPHA | NJD_SPRITE_ANGLE | NJD_SPRITE_COLOR);
				}
				else
				{
					DrawSprite2D(&tSprite, 1, 1.0f, NJD_SPRITE_ALPHA | NJD_SPRITE_COLOR);
				}
			}
		}
		l++;
	}

	ResetMaterial();
}

void TextBox::UpdateText(std::string newText)
{
	text = newText;
	isDirty = true;
}

void TextBox::UpdateFontSize(float newSize)
{
	fontSize = newSize;
	isDirty = true;
}

float TextBox::GetHeight()
{
	return this->fontSize * this->lines.size();
}

void TextBox::UpdateLineData(SpriteNode& node)
{
	float width = node.displaySize.x;
	float charWidth = 0.0f;
	float spaceWidth = fontSize * textData->GetCharacterData(' ')->ratio * (textData->GetCharacterData(' ')->height / 42.0f);
	int length = 0;
	int startIndex = 0;
	lines.clear();

	std::vector<WordData> words;
	int i = 0;

	while (i < text.length())
	{
		if (text[i] != ' ' && text[i] != '\n')
		{
			if (length == 0)
			{
				startIndex = i;
			}
			float charScale = textData->GetCharacterData(text[i])->height / 42.0f;
			charWidth += fontSize * textData->GetCharacterData(text[i])->ratio * charScale;
			length++;
		}

		if (text[i] == ' ' || text[i] == '\n' || i == text.length() - 1)
		{
			if (length > 0)
			{
				words.emplace_back(WordData(startIndex, length, charWidth));
				length = 0;
				charWidth = 0.0f;
			}
			if (text[i] == '\n')
			{
				words.emplace_back(WordData(i, 0, 0.0f));
			}
		}
		i++;
	}

	startIndex = 0;
	length = 0;
	i = 0;
	while (i < words.size())
	{
		length++;
		charWidth += words[i].width;
		if ((charWidth > width && length > 1 ) || i == words.size() - 1 || words[i].length == 0)
		{
			if (charWidth > width && length > 1)
			{
				charWidth -= words[i].width;
				charWidth -= spaceWidth;
				i--;
			}
			int lineStart = words[startIndex].startIndex;
			int lineEnd = words[i].startIndex + words[i].length;
			switch (alignment)
			{
			case TextAlignment::Left:
				lines.emplace_back(TextBoxLineData(0.0f, lineStart, lineEnd));
				break;
			case TextAlignment::Center:
				lines.emplace_back(TextBoxLineData((width - charWidth) * 0.5f, lineStart, lineEnd));
				break;
			case TextAlignment::Right:
				lines.emplace_back(TextBoxLineData(width - charWidth, lineStart, lineEnd));
				break;
			}
			startIndex = i + 1;
			charWidth = 0.0f;
			length = 0;
			i++;
		}
		else
		{
			charWidth += spaceWidth;
			i++;
		}
	}

	/*
	PrintDebug(text.c_str());
	std::string str = "Words: ";
	str.append(std::to_string(words.size()));
	PrintDebug(str.c_str());
	str = "Lines: ";
	str.append(std::to_string(lines.size()));
	PrintDebug(str.c_str());
	*/

	isDirty = false;
}

BoundingBox TextBox::CalculateTextBounds(SpriteNode& node)
{
	if (isDirty)
	{
		UpdateLineData(node);
	}
	if (lines.size() == 0)
	{
		return BoundingBox(node.GetPositionGlobal(), {});
	}

	float rotation = node.GetRotationGlobal();
	NJS_POINT3 right = Point3RotateAround({ 1.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, rotation);
	NJS_POINT3 down = Point3RotateAround({ 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, rotation);
	NJS_POINT3 pos = node.GetPositionGlobal();
	pos.x -= node.displaySize.x * 0.5f;
	pos.y -= (node.displaySize.y * 0.5f) - (fontSize * 0.5);
	pos = Point3RotateAround(pos, node.GetPositionGlobal(), rotation);

	BoundingBox box = BoundingBox(pos, {});

	int l = 0;
	while (l < lines.size())
	{
		NJS_POINT3 linePos = Point3Add(pos, Point3Scale(down, l * fontSize));
		linePos = Point3Add(linePos, Point3Scale(right, lines[l].offset));
		if (l == 0)
		{
			box = BoundingBox(linePos, {});
		}
		for (int i = lines[l].startIndex; i < lines[l].lastIndex; i++)
		{
			if (text[i] >= ' ' && text[i] <= '~')
			{
				TextDataAndAnim charData = textData->GetAnimAndData(text[i]);
				float charScale = charData.data->height / 42.0f;
				float sX = (fontSize / (float)charData.anim->sx) * charData.data->ratio * charScale;
				float sY = fontSize / (float)charData.anim->sy * charScale;
				float cWidth = fontSize * charData.data->ratio * charScale;
				if (i == lines[l].startIndex)
				{
					box.Add(linePos);
					box.Add(Point3Add(linePos, Point3Scale(down, fontSize)));
				}
				linePos = Point3Add(linePos, Point3Scale(right, cWidth));
				if (i == lines[l].lastIndex - 1)
				{
					box.Add(linePos);
					box.Add(Point3Add(linePos, Point3Scale(down, fontSize)));
				}
			}
		}
		l++;
	}
	return box;
}