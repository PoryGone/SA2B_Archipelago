#pragma once
#include "../Backend/SpriteNode.h"
#include "../TextDisplayData.h"
#include <string>

class TextBox : public SpriteRenderComponent
{
public:
	void OnRender(SpriteNode& node) override;

	TextBox(std::string _text, float _fontSize, TextDisplayData* _textData) : text(_text), fontSize(_fontSize), textData(_textData) {}

private:
	std::string text;
	float fontSize;
	TextDisplayData* textData;
	char character = ' ';
};