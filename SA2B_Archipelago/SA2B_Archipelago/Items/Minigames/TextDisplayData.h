#pragma once

class TextDisplayData
{
public:
	void LoadIcons();
	void ReleaseIcons();
	NJS_TEXANIM* GetAnim(char character);
	NJS_TEXANIM* FontAnims;
	NJS_TEXLIST* FontTex;
	int AnimLength;
};