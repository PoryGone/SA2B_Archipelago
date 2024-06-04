#pragma once
#include "../Backend/SpriteNode.h"
#include "../../../Utilities/EasingUtilities.h"
#include "../MinigameUtilities.h"
#include <vector>

enum ParticleEmitZoneType
{
	PEZ_Point,
	PEZ_Box,
	PEZ_Circle,
};

class ParticleEmitter : public SpriteRenderComponent
{
	struct ParticleData
	{
		bool active;
		NJS_POINT3 pos;
		NJS_POINT3 velocity;
		float time;
	};

	struct ParticleTimelinePoint
	{
		float t;
		EasingType easing;
		NJS_ARGB color;
		NJS_POINT3 size;
	};

public:
	void OnRender(SpriteNode& node, NJS_SPRITE& sprite) override;
	void Play();
	void Stop(); 
	void ClearAllParticles(); // Does not stop the emitter
	bool IsPlaying();

	NJS_TEXANIM* anim = nullptr;
	float emitterDuration = 1.0f;
	float rate = 10.0f; //per second
	bool looping = false;
	float particleDuration = 3.0f;
	NJS_POINT2 angleRange = { 0.0f, 360.0f }; // 0 / 360 is down
	NJS_POINT2 initialVelocityRange = { 0.0f, 0.0f };
	NJS_POINT3 velocityRateMin = { 0.0f, 0.0f };
	NJS_POINT3 velocityRateMax = { 0.0f, 0.0f };
	float velocityRateMultiplier = 1.0f; //Decay of velocity over a second
	ParticleEmitZoneType emitZoneType = PEZ_Point;
	NJS_POINT3 boxSize = { 5.0f, 5.0f };
	float radius = 5.0f;

	std::vector<ParticleTimelinePoint> particleTimeline = {
		{ 0.0f, ET_Linear, { 0.0f, 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f }},
		{ 0.25f, ET_SineOut, { 1.0f, 1.0f, 1.0f, 1.0f }, { 5.0f, 5.0f }},
		{ 0.75f, ET_Linear, { 1.0f, 1.0f, 1.0f, 1.0f }, { 5.0f, 5.0f }},
		{ 1.0f, ET_SineIn, { 0.0f, 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f }},
	};

private:
	void SpawnParticle(SpriteNode& node);
	void UpdateParticles();
	void RenderParticles(SpriteNode& node, NJS_SPRITE& sprite);

	std::vector<ParticleData> particles;
	bool isPlaying = false;
	bool anyParticleActive = false;
	float time = 0.0f;
	float spawnProgress = 0.0f;
	const float deltaTime = 1.0f / 60.0f;
};