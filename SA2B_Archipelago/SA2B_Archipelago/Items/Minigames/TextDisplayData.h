#pragma once

struct TextCharacterData
{
	TextCharacterData() : width(0.0f), height(0.0f), ratio(1.0f), xOffset(0.0f), yOffset(0.0f) {}
	TextCharacterData(float _width, float _height, float _ratio, float _xOffset, float _yOffset) : width(_width), height(_height), ratio(_ratio), xOffset(_xOffset), yOffset(_yOffset) {}

	float width;
	float height;
	float ratio;
	float xOffset;
	float yOffset;
};

struct TextDataAndAnim
{
	TextDataAndAnim(NJS_TEXANIM* _anim, TextCharacterData* _data) : anim(_anim), data(_data) {}

	NJS_TEXANIM* anim;
	TextCharacterData* data;
};

class TextDisplayData
{
public:
	void LoadIcons();
	void ReleaseIcons();
	NJS_TEXANIM* GetAnim(char character);
	TextCharacterData* GetCharacterData(char character);
	TextDataAndAnim GetAnimAndData(char character);
	NJS_TEXANIM* FontAnims;
	NJS_TEXLIST* FontTex;
	int AnimLength;
};