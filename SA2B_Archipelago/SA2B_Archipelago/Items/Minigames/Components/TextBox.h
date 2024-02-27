#pragma once
#include "../Backend/SpriteNode.h"
#include "../TextDisplayData.h"
#include <string>

enum TextAlignment
{
	Left,
	Center,
	Right,
};

class TextBox : public SpriteRenderComponent
{
	struct TextBoxLineData
	{
		TextBoxLineData(float _offset, int _startIndex, int _lastIndex) : offset(_offset), startIndex(_startIndex), lastIndex(_lastIndex) {}

		float offset;
		int startIndex;
		int lastIndex;
	};

	struct WordData
	{
		WordData(int _startIndex, int _length, float _width) : startIndex(_startIndex), length(_length), width(_width) {}

		int startIndex;
		int length;
		float width;
	};

public:
	void OnRender(SpriteNode& node) override;
	void UpdateText(std::string newText);

	float GetHeight();

	TextBox(std::string _text, float _fontSize, TextAlignment _alignment, TextDisplayData* _textData) : text(_text), fontSize(_fontSize), alignment(_alignment), textData(_textData) {}

private:
	void UpdateLineData(SpriteNode& node);

	std::string text;
	float fontSize;
	TextDisplayData* textData;
	TextAlignment alignment;

	bool isDirty = true;
	std::vector<TextBoxLineData> lines;
};