#include "../../pch.h"
#include "TextDisplayData.h"

static NJS_TEXANIM FontAnim[] = {
	//Characters
	{ 9 , 9 , 4 , 4 , 106 , 142 , 110 , 151 , 0, 0 },
	{ 12 , 35 , 6 , 17 , 238 , 0 , 244 , 35 , 0, 0 },
	{ 18 , 19 , 9 , 9 , 62 , 142 , 71 , 161 , 0, 0 },
	{ 35 , 34 , 17 , 17 , 147 , 0 , 164 , 34 , 0, 0 },
	{ 26 , 42 , 13 , 21 , 0 , 0 , 13 , 42 , 0, 0 },
	{ 31 , 35 , 15 , 17 , 164 , 0 , 180 , 35 , 0, 0 },
	{ 27 , 34 , 13 , 17 , 102 , 42 , 116 , 76 , 0, 0 },
	{ 11 , 17 , 5 , 8 , 80 , 142 , 86 , 159 , 0, 0 },
	{ 18 , 40 , 9 , 20 , 56 , 0 , 65 , 40 , 0, 0 },
	{ 18 , 40 , 9 , 20 , 47 , 0 , 56 , 40 , 0, 0 },
	{ 23 , 21 , 11 , 10 , 0 , 142 , 11 , 163 , 0, 0 },
	{ 22 , 21 , 11 , 10 , 21 , 142 , 32 , 163 , 0, 0 },
	{ 13 , 16 , 6 , 8 , 93 , 142 , 100 , 158 , 0, 0 },
	{ 19 , 11 , 9 , 5 , 71 , 142 , 80 , 153 , 0, 0 },
	{ 12 , 12 , 6 , 6 , 100 , 142 , 106 , 154 , 0, 0 },
	{ 22 , 35 , 11 , 17 , 227 , 0 , 238 , 35 , 0, 0 },
	{ 26 , 33 , 13 , 16 , 124 , 76 , 137 , 109 , 0, 0 },
	{ 19 , 33 , 9 , 16 , 220 , 76 , 229 , 109 , 0, 0 },
	{ 23 , 33 , 11 , 16 , 162 , 76 , 174 , 109 , 0, 0 },
	{ 23 , 33 , 11 , 16 , 185 , 76 , 197 , 109 , 0, 0 },
	{ 26 , 33 , 13 , 16 , 98 , 76 , 111 , 109 , 0, 0 },
	{ 25 , 34 , 12 , 17 , 154 , 42 , 167 , 76 , 0, 0 },
	{ 24 , 34 , 12 , 17 , 203 , 42 , 215 , 76 , 0, 0 },
	{ 26 , 33 , 13 , 16 , 111 , 76 , 124 , 109 , 0, 0 },
	{ 24 , 33 , 12 , 16 , 150 , 76 , 162 , 109 , 0, 0 },
	{ 25 , 34 , 12 , 17 , 142 , 42 , 154 , 76 , 0, 0 },
	{ 12 , 24 , 6 , 12 , 246 , 110 , 252 , 134 , 0, 0 },
	{ 14 , 29 , 7 , 14 , 87 , 110 , 94 , 139 , 0, 0 },
	{ 18 , 22 , 9 , 11 , 32 , 142 , 41 , 164 , 0, 0 },
	{ 21 , 20 , 10 , 10 , 41 , 142 , 51 , 162 , 0, 0 },
	{ 19 , 23 , 9 , 11 , 11 , 142 , 21 , 165 , 0, 0 },
	{ 23 , 33 , 11 , 16 , 197 , 76 , 208 , 109 , 0, 0 },
	{ 34 , 36 , 17 , 18 , 119 , 0 , 136 , 36 , 0, 0 },
	{ 28 , 32 , 14 , 16 , 0 , 110 , 14 , 142 , 0, 0 },
	{ 24 , 34 , 12 , 17 , 191 , 42 , 203 , 76 , 0, 0 },
	{ 26 , 33 , 13 , 16 , 85 , 76 , 98 , 109 , 0, 0 },
	{ 27 , 34 , 13 , 17 , 75 , 42 , 89 , 76 , 0, 0 },
	{ 25 , 35 , 12 , 17 , 192 , 0 , 205 , 35 , 0, 0 },
	{ 25 , 35 , 12 , 17 , 180 , 0 , 192 , 35 , 0, 0 },
	{ 28 , 34 , 14 , 17 , 61 , 42 , 75 , 76 , 0, 0 },
	{ 29 , 34 , 14 , 17 , 32 , 42 , 47 , 76 , 0, 0 },
	{ 24 , 32 , 12 , 16 , 27 , 110 , 39 , 142 , 0, 0 },
	{ 27 , 34 , 13 , 17 , 89 , 42 , 102 , 76 , 0, 0 },
	{ 25 , 34 , 12 , 17 , 129 , 42 , 142 , 76 , 0, 0 },
	{ 24 , 34 , 12 , 17 , 227 , 42 , 239 , 76 , 0, 0 },
	{ 34 , 34 , 17 , 17 , 0 , 42 , 17 , 76 , 0, 0 },
	{ 31 , 34 , 15 , 17 , 17 , 42 , 32 , 76 , 0, 0 },
	{ 31 , 33 , 15 , 16 , 28 , 76 , 43 , 109 , 0, 0 },
	{ 23 , 33 , 11 , 16 , 208 , 76 , 220 , 109 , 0, 0 },
	{ 35 , 39 , 17 , 19 , 65 , 0 , 82 , 39 , 0, 0 },
	{ 26 , 33 , 13 , 16 , 137 , 76 , 150 , 109 , 0, 0 },
	{ 27 , 32 , 13 , 16 , 14 , 110 , 27 , 142 , 0, 0 },
	{ 29 , 32 , 14 , 16 , 229 , 76 , 244 , 108 , 0, 0 },
	{ 28 , 33 , 14 , 16 , 58 , 76 , 72 , 109 , 0, 0 },
	{ 27 , 34 , 13 , 17 , 116 , 42 , 129 , 76 , 0, 0 },
	{ 39 , 34 , 19 , 17 , 82 , 0 , 102 , 34 , 0, 0 },
	{ 29 , 34 , 14 , 17 , 47 , 42 , 61 , 76 , 0, 0 },
	{ 27 , 33 , 13 , 16 , 72 , 76 , 85 , 109 , 0, 0 },
	{ 29 , 33 , 14 , 16 , 43 , 76 , 58 , 109 , 0, 0 },
	{ 17 , 39 , 8 , 19 , 102 , 0 , 110 , 39 , 0, 0 },
	{ 22 , 34 , 11 , 17 , 0 , 76 , 11 , 110 , 0, 0 },
	{ 17 , 39 , 8 , 19 , 110 , 0 , 119 , 39 , 0, 0 },
	{ 21 , 17 , 10 , 8 , 51 , 142 , 62 , 159 , 0, 0 },
	{ 30 , 11 , 15 , 5 , 72 , 110 , 87 , 121 , 0, 0 },
	{ 15 , 16 , 7 , 8 , 86 , 142 , 93 , 158 , 0, 0 },
	{ 23 , 26 , 11 , 13 , 155 , 110 , 166 , 136 , 0, 0 },
	{ 24 , 34 , 12 , 17 , 179 , 42 , 191 , 76 , 0, 0 },
	{ 22 , 26 , 11 , 13 , 201 , 110 , 212 , 136 , 0, 0 },
	{ 24 , 34 , 12 , 17 , 215 , 42 , 227 , 76 , 0, 0 },
	{ 24 , 26 , 12 , 13 , 143 , 110 , 155 , 136 , 0, 0 },
	{ 22 , 36 , 11 , 18 , 136 , 0 , 147 , 36 , 0, 0 },
	{ 23 , 33 , 11 , 16 , 174 , 76 , 185 , 109 , 0, 0 },
	{ 23 , 35 , 11 , 17 , 205 , 0 , 216 , 35 , 0, 0 },
	{ 13 , 32 , 6 , 16 , 39 , 110 , 46 , 142 , 0, 0 },
	{ 19 , 41 , 9 , 20 , 13 , 0 , 22 , 41 , 0, 0 },
	{ 23 , 34 , 11 , 17 , 239 , 42 , 251 , 76 , 0, 0 },
	{ 12 , 34 , 6 , 17 , 22 , 76 , 28 , 110 , 0, 0 },
	{ 30 , 28 , 15 , 14 , 57 , 110 , 72 , 138 , 0, 0 },
	{ 22 , 27 , 11 , 13 , 108 , 110 , 119 , 137 , 0, 0 },
	{ 23 , 26 , 11 , 13 , 189 , 110 , 201 , 136 , 0, 0 },
	{ 22 , 35 , 11 , 17 , 216 , 0 , 227 , 35 , 0, 0 },
	{ 22 , 34 , 11 , 17 , 11 , 76 , 22 , 110 , 0, 0 },
	{ 21 , 26 , 10 , 13 , 223 , 110 , 233 , 136 , 0, 0 },
	{ 22 , 27 , 11 , 13 , 119 , 110 , 130 , 137 , 0, 0 },
	{ 22 , 31 , 11 , 15 , 46 , 110 , 57 , 141 , 0, 0 },
	{ 22 , 26 , 11 , 13 , 212 , 110 , 223 , 136 , 0, 0 },
	{ 23 , 26 , 11 , 13 , 178 , 110 , 189 , 136 , 0, 0 },
	{ 28 , 26 , 14 , 13 , 94 , 110 , 108 , 136 , 0, 0 },
	{ 26 , 26 , 13 , 13 , 130 , 110 , 143 , 136 , 0, 0 },
	{ 25 , 34 , 12 , 17 , 167 , 42 , 179 , 76 , 0, 0 },
	{ 23 , 26 , 11 , 13 , 166 , 110 , 178 , 136 , 0, 0 },
	{ 19 , 40 , 9 , 20 , 37 , 0 , 47 , 40 , 0, 0 },
	{ 11 , 41 , 5 , 20 , 22 , 0 , 28 , 41 , 0, 0 },
	{ 19 , 40 , 9 , 20 , 28 , 0 , 37 , 40 , 0, 0 },
	{ 25 , 16 , 12 , 8 , 233 , 110 , 246 , 126 , 0, 0 },
	//Padding
	{40, 32, 20, 16, 0x0A, 0x10, 0x34, 0x30, 0, 0},
};

TextCharacterData TextVec[] = {
	TextCharacterData(9.0f, 9.0f, 1.00f, 0.0f, 16.5f),
	TextCharacterData(12.0f, 35.0f, 0.34f, 0.0f, 0.0f),	// !
	TextCharacterData(18.0f, 19.0f, 0.95f, 0.0f, -9.5),	// "
	TextCharacterData(35.0f, 34.0f, 1.03f, 0.0f, 0.0f),	// #
	TextCharacterData(26.0f, 42.0f, 0.62f, 0.0f, 0.0f),	// $
	TextCharacterData(31.0f, 35.0f, 0.89f, 0.0f, 0.0f),	// %
	TextCharacterData(27.0f, 34.0f, 0.79f, 0.0f, 0.0f),	// &
	TextCharacterData(11.0f, 17.0f, 0.65f, 0.0f, -9.5f),	// '
	TextCharacterData(18.0f, 40.0f, 0.45f, 0.0f, 0.0f),	// (
	TextCharacterData(18.0f, 40.0f, 0.45f, 0.0f, 0.0f),	// )
	TextCharacterData(23.0f, 21.0f, 1.10f, 0.0f, -7.5f),	// *
	TextCharacterData(22.0f, 21.0f, 1.05f, 0.0f, 0.0f),	// +
	TextCharacterData(13.0f, 16.0f, 0.81f, 0.0f, 13.0f),	// ,
	TextCharacterData(19.0f, 11.0f, 1.73f, 0.0f, 2.0f),	// -
	TextCharacterData(12.0f, 12.0f, 1.00f, 0.0f, 15.0f),	// .
	TextCharacterData(22.0f, 35.0f, 0.63f, 0.0f, 0.0f),	// /
	TextCharacterData(26.0f, 33.0f, 0.79f, 0.0f, 4.5f),	// 0
	TextCharacterData(19.0f, 33.0f, 0.58f, 0.0f, 4.5f),	// 1
	TextCharacterData(23.0f, 33.0f, 0.70f, 0.0f, 4.5f),	// 2
	TextCharacterData(23.0f, 33.0f, 0.70f, 0.0f, 4.5f),	// 3
	TextCharacterData(26.0f, 33.0f, 0.79f, 0.0f, 4.5f),	// 4
	TextCharacterData(25.0f, 34.0f, 0.74f, 0.0f, 4.0f),	// 5
	TextCharacterData(24.0f, 34.0f, 0.71f, 0.0f, 4.0f),	// 6
	TextCharacterData(26.0f, 33.0f, 0.79f, 0.0f, 4.5f),	// 7
	TextCharacterData(24.0f, 33.0f, 0.73f, 0.0f, 4.5f),	// 8
	TextCharacterData(25.0f, 34.0f, 0.74f, 0.0f, 4.0f),	// 9
	TextCharacterData(12.0f, 24.0f, 0.50f, 0.0f, 5.0f),	// :
	TextCharacterData(14.0f, 29.0f, 0.48f, 0.0f, 0.0f),	// ;
	TextCharacterData(18.0f, 22.0f, 0.82f, 0.0f, 0.0f),	// <
	TextCharacterData(21.0f, 20.0f, 1.05f, 0.0f, 0.0f),	// =
	TextCharacterData(19.0f, 23.0f, 0.83f, 0.0f, 0.0f),	// >
	TextCharacterData(23.0f, 33.0f, 0.70f, 0.0f, 4.5f),	// ?
	TextCharacterData(34.0f, 36.0f, 0.94f, 0.0f, 0.0f),	// @
	TextCharacterData(28.0f, 32.0f, 0.88f, 0.0f, 5.0f),	// A
	TextCharacterData(24.0f, 34.0f, 0.71f, 0.0f, 4.0f),	// B
	TextCharacterData(26.0f, 33.0f, 0.79f, 0.0f, 4.5f),	// C
	TextCharacterData(27.0f, 34.0f, 0.79f, 0.0f, 4.0f),	// D
	TextCharacterData(25.0f, 35.0f, 0.71f, 0.0f, 3.5f),	// E
	TextCharacterData(25.0f, 35.0f, 0.71f, 0.0f, 3.5f),	// F
	TextCharacterData(28.0f, 34.0f, 0.82f, 0.0f, 4.0f),	// G
	TextCharacterData(29.0f, 34.0f, 0.85f, 0.0f, 4.0f),	// H
	TextCharacterData(24.0f, 32.0f, 0.75f, 0.0f, 5.0f),	// I
	TextCharacterData(27.0f, 34.0f, 0.79f, 0.0f, 4.0f),	// J
	TextCharacterData(25.0f, 34.0f, 0.74f, 0.0f, 4.0f),	// K
	TextCharacterData(24.0f, 34.0f, 0.71f, 0.0f, 4.0f),	// L
	TextCharacterData(34.0f, 34.0f, 1.00f, 0.0f, 4.0f),	// M
	TextCharacterData(31.0f, 34.0f, 0.91f, 0.0f, 4.0f),	// N
	TextCharacterData(31.0f, 33.0f, 0.94f, 0.0f, 4.5f),	// O
	TextCharacterData(23.0f, 33.0f, 0.70f, 0.0f, 4.5f),	// P
	TextCharacterData(35.0f, 39.0f, 0.90f, 0.0f, 1.5f),	// Q
	TextCharacterData(26.0f, 33.0f, 0.79f, 0.0f, 4.5f),	// R
	TextCharacterData(27.0f, 32.0f, 0.84f, 0.0f, 5.0f),	// S
	TextCharacterData(29.0f, 32.0f, 0.91f, 0.0f, 5.0f),	// T
	TextCharacterData(28.0f, 33.0f, 0.85f, 0.0f, 4.5f),	// U
	TextCharacterData(27.0f, 34.0f, 0.79f, 0.0f, 4.0f),	// V
	TextCharacterData(39.0f, 34.0f, 1.15f, 0.0f, 4.0f),	// W
	TextCharacterData(29.0f, 34.0f, 0.85f, 0.0f, 4.0f),	// X
	TextCharacterData(27.0f, 33.0f, 0.82f, 0.0f, 4.5f),	// Y
	TextCharacterData(29.0f, 33.0f, 0.88f, 0.0f, 4.5f),	// Z
	TextCharacterData(17.0f, 39.0f, 0.44f, 0.0f, 1.5f),	// [
	TextCharacterData(22.0f, 34.0f, 0.65f, 0.0f, 4.0f),	// '\'
	TextCharacterData(17.0f, 39.0f, 0.44f, 0.0f, 1.5f),	// ]
	TextCharacterData(21.0f, 17.0f, 1.24f, 0.0f, 0.0f),	// ^
	TextCharacterData(30.0f, 11.0f, 2.73f, 0.0f, 0.0f),	// _
	TextCharacterData(15.0f, 16.0f, 0.94f, 0.0f, -13.0f),	// `
	TextCharacterData(23.0f, 26.0f, 0.88f, 0.0f, 8.0f),	// a
	TextCharacterData(24.0f, 34.0f, 0.71f, 0.0f, 4.0f),	// b
	TextCharacterData(22.0f, 26.0f, 0.85f, 0.0f, 8.0f),	// c
	TextCharacterData(24.0f, 34.0f, 0.71f, 0.0f, 4.0f),	// d
	TextCharacterData(24.0f, 26.0f, 0.92f, 0.0f, 8.0f),	// e
	TextCharacterData(22.0f, 36.0f, 0.61f, 0.0f, 3.0f),	// f
	TextCharacterData(23.0f, 33.0f, 0.70f, 0.0f, 13.0f),	// g
	TextCharacterData(23.0f, 35.0f, 0.66f, 0.0f, 3.5f),	// h
	TextCharacterData(13.0f, 32.0f, 0.41f, 0.0f, 5.0f),	// i
	TextCharacterData(19.0f, 41.0f, 0.46f, 0.0f, 12.5f),	// j
	TextCharacterData(23.0f, 34.0f, 0.68f, 0.0f, 4.0f),	// k
	TextCharacterData(12.0f, 34.0f, 0.35f, 0.0f, 4.0f),	// l
	TextCharacterData(30.0f, 28.0f, 1.07f, 0.0f, 7.5f),	// m
	TextCharacterData(22.0f, 27.0f, 0.81f, 0.0f, 7.5f),	// n
	TextCharacterData(23.0f, 26.0f, 0.88f, 0.0f, 8.0f),	// o
	TextCharacterData(22.0f, 35.0f, 0.63f, 0.0f, 12.5f),	// p
	TextCharacterData(22.0f, 34.0f, 0.65f, 0.0f, 12.0f),	// q
	TextCharacterData(21.0f, 26.0f, 0.81f, 0.0f, 8.0f),	// r
	TextCharacterData(22.0f, 27.0f, 0.81f, 0.0f, 7.5f),	// s
	TextCharacterData(22.0f, 31.0f, 0.71f, 0.0f, 5.5f),	// t
	TextCharacterData(22.0f, 26.0f, 0.85f, 0.0f, 8.0f),	// u
	TextCharacterData(23.0f, 26.0f, 0.88f, 0.0f, 8.0f),	// v
	TextCharacterData(28.0f, 26.0f, 1.08f, 0.0f, 8.0f),	// w
	TextCharacterData(26.0f, 26.0f, 1.00f, 0.0f, 8.0f),	// x
	TextCharacterData(25.0f, 34.0f, 0.74f, 0.0f, 13.0f),	// y
	TextCharacterData(23.0f, 26.0f, 0.88f, 0.0f, 8.0f),	// z
	TextCharacterData(19.0f, 40.0f, 0.47f, 0.0f, 0.0f),	// {
	TextCharacterData(11.0f, 41.0f, 0.27f, 0.0f, 0.0f),	// |
	TextCharacterData(19.0f, 40.0f, 0.47f, 0.0f, 0.0f),	// }
	TextCharacterData(25.0f, 16.0f, 1.56f, 0.0f, 0.0f),	// ~
};

static const int FontAnimLength = 95;

FunctionPointer(void, ReleaseTextureList, (NJS_TEXLIST* a1), 0x77F9F0);

static const int FontTexCount = 1;

static NJS_TEXNAME FontTexName[FontTexCount];
static NJS_TEXLIST FontTexList = { FontTexName, FontTexCount };

static TexPackInfo FontTexPacks[] = {
	{ "AP_FONT_ATLAS", &FontTexList },
	{ nullptr, nullptr }, //Needs to end in a null entry to prevent the LoadTextures call from iterating past the packs
};

NJS_TEXANIM* TextDisplayData::GetAnim(char character)
{
	return &FontAnim[character - 32];
}

TextCharacterData* TextDisplayData::GetCharacterData(char character)
{
	return &TextVec[character - 32];
}

TextDataAndAnim TextDisplayData::GetAnimAndData(char character)
{
	return TextDataAndAnim(GetAnim(character), GetCharacterData(character));
}

void TextDisplayData::LoadIcons()
{
	LoadTextures(&FontTexPacks[0]);
	this->FontAnims = &FontAnim[0];
	this->FontTex = &FontTexList;
	this->AnimLength = FontAnimLength;
}

void TextDisplayData::ReleaseIcons()
{
	ReleaseTextureList(&FontTexList);
}