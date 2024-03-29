#include "../../pch.h"
#include "MinigameIconData.h"


static NJS_TEXANIM MGAnim[] = {
	//-1 padding cause reasons --- Ignore this for the count
	{40, 32, 20, 16, 0x0A, 0x10, 0x34, 0x30, 0, 0},
	//Bars
	{64, 256, 32, 128, 0x00, 0x00, 0x3F, 0xFF, 0, 0},
	{64, 256, 32, 128, 0x40, 0x00, 0x7F, 0xFF, 0, 0},
	{64, 256, 32, 128, 0x80, 0x00, 0xBF, 0xFF, 0, 0},
	{64, 256, 32, 128, 0xC0, 0x00, 0xFF, 0xFF, 0, 0},
	{64, 256, 32, 128, 0x00, 0x00, 0x3F, 0xFF, 2, 0},
	{64, 256, 32, 128, 0x40, 0x00, 0x7F, 0xFF, 2, 0},
	{64, 256, 32, 128, 0x80, 0x00, 0xBF, 0xFF, 2, 0},
	{64, 256, 32, 128, 0xC0, 0x00, 0xFF, 0xFF, 2, 0},
	//D-Pad
	{64, 64, 32, 32, 0x00, 0x00, 0x7F, 0xFF, 3, 0},
	{64, 64, 32, 32, 0x80, 0x00, 0xFF, 0xFF, 3, 0},
	//Single Icons
	{64, 64, 32, 32, 0x00, 0x00, 0x100, 0x100, 1, 0},
	//Padding
	{40, 32, 20, 16, 0x0A, 0x10, 0x34, 0x30, 0, 0},
};

static const int MinigameAnimLength = 11;

FunctionPointer(void, ReleaseTextureList, (NJS_TEXLIST* a1), 0x77F9F0);

static const int MinigameTexCount = 4;

static NJS_TEXNAME MinigameTexName[MinigameTexCount];
static NJS_TEXLIST MinigameTexList = { MinigameTexName, MinigameTexCount };

static TexPackInfo MinigameTexPacks[] = {
	{ "AP_MINIGAME", &MinigameTexList },
	{ nullptr, nullptr }, //Needs to end in a null entry to prevent the LoadTextures call from iterating past the packs
};

NJS_TEXANIM* MinigameIconData::GetAnim(MinigameIcon icon)
{
	return &MGAnim[icon];
}

void MinigameIconData::LoadIcons()
{
	LoadTextures(&MinigameTexPacks[0]);
	this->MinigameAnims = &MGAnim[0];
	this->MinigameTex = &MinigameTexList;
	this->AnimLength = MinigameAnimLength;

	float ratio = 480.0f / VerticalResolution;
	float adjustedHorizontal = HorizontalResolution * ratio;
	float adjustedMin = (adjustedHorizontal - 640.0f) / 2.0f;
	float adjustedMax = adjustedHorizontal - adjustedMin;
	adjustedMin = -adjustedMin;
	this->xMin = adjustedMin;
	this->xMax = adjustedMax;
	this->xCenter = this->xMax / 2.0f + this->xMin / 2.0f;
}

void MinigameIconData::ReleaseIcons()
{
	ReleaseTextureList(&MinigameTexList);
}