#include "../../../pch.h"
#include "ParticleEmitter.h"

void ParticleEmitter::OnRender(SpriteNode& node, NJS_SPRITE& sprite)
{
	if (anyParticleActive)
	{
		UpdateParticles();
	}
	if (isPlaying)
	{
		time += deltaTime;
		spawnProgress += deltaTime * rate;
		while (spawnProgress >= 1.0f)
		{
			SpawnParticle(node);
			spawnProgress -= 1.0f;
		}
		if (time > emitterDuration)
		{
			if (looping)
			{
				time -= emitterDuration;
			}
			else
			{
				isPlaying = false;
			}
		}
	}
	if (anyParticleActive)
	{
		RenderParticles(node, sprite);
	}
}

void ParticleEmitter::Play()
{
	particles.clear();
	time = 0.0f;
	spawnProgress = 0.0f;
	isPlaying = true;
	anyParticleActive = true;
}

void ParticleEmitter::Stop()
{
	isPlaying = false;
}

void ParticleEmitter::ClearAllParticles()
{
	for (int i = 0; i < particles.size(); i++)
	{
		particles[i].active = false;
	}
	anyParticleActive = false;
}

bool ParticleEmitter::IsPlaying()
{
	return isPlaying;
}

void ParticleEmitter::SpawnParticle(SpriteNode& node)
{
	ParticleData* pd = nullptr;
	for (int i = 0; i < particles.size(); i++)
	{
		if (!particles[i].active)
		{
			pd = &particles[i];
			break;
		}
	}
	if (pd == nullptr)
	{
		particles.push_back({});
		pd = &particles[particles.size() - 1];
	}
	NJS_POINT3 velocity = { 0.0f, 1.0f };
	NJS_POINT3 pos = node.GetPositionGlobal();
	switch (emitZoneType)
	{
		case ParticleEmitZoneType::PEZ_Box:
			pos.x += RandomFloat(-boxSize.x * 0.5f, boxSize.x * 0.5f);
			pos.y += RandomFloat(-boxSize.y * 0.5f, boxSize.y * 0.5f);
			break;
		case ParticleEmitZoneType::PEZ_Circle:
			NJS_POINT3 offset = { 0.0f, RandomFloat(0.0f, radius) };
			offset = Point3RotateAround(offset, { 0.0f, 0.0f }, RandomFloat(0.0f, 360.0f));
			pos = Point3Add(pos, offset);
		break;
	}
	velocity = Point3RotateAround(velocity, { 0.0f, 0.0f }, RandomFloat(angleRange.x, angleRange.y));
	velocity = Point3Scale(velocity, RandomFloat(initialVelocityRange.x, initialVelocityRange.y));
	pd->active = true;
	pd->pos = pos;
	pd->time = 0.0f;
	pd->velocity = velocity;
}

void ParticleEmitter::UpdateParticles()
{
	bool anyActive = false;
	for (int i = 0; i < particles.size(); i++)
	{
		if (particles[i].active)
		{
			anyActive = true;
			float xChange = RandomFloat(velocityRateMin.x, velocityRateMax.x) * deltaTime;
			float yChange = RandomFloat(velocityRateMin.y, velocityRateMax.y) * deltaTime;
			float velocityScale = 1.0f - ((1.0f - velocityRateMultiplier) * deltaTime);
			particles[i].velocity = Point3Add(particles[i].velocity, { xChange, yChange });
			particles[i].velocity = Point3Scale(particles[i].velocity, velocityScale);
			particles[i].pos = Point3Add(particles[i].pos, Point3Scale(particles[i].velocity, deltaTime));
			particles[i].time += deltaTime;
			if (particles[i].time >= particleDuration)
			{
				particles[i].active = false;
			}
		}
	}
	anyParticleActive = isPlaying || anyActive;
}

void ParticleEmitter::RenderParticles(SpriteNode& node, NJS_SPRITE& sprite)
{
	NJS_TEXANIM* tempAnim = anim;
	tempAnim--;
	sprite.tanim = tempAnim;
	for (int i = 0; i < particles.size(); i++)
	{
		if (particles[i].active)
		{
			float nTime = particles[i].time / particleDuration;
			NJS_POINT3 size = { 1.0f, 1.0f };
			NJS_ARGB color = { 1.0f, 1.0f, 1.0f, 1.0f };
			for (int p = 1; p < particleTimeline.size(); p++)
			{
				if (nTime >= particleTimeline[p - 1].t && nTime <= particleTimeline[p].t)
				{
					float t = (nTime - particleTimeline[p - 1].t) / (particleTimeline[p].t - particleTimeline[p - 1].t);
					size = EaseInterpolate(particleTimeline[p - 1].size, particleTimeline[p].size, t, particleTimeline[p].easing);
					color = EaseInterpolate(particleTimeline[p - 1].color, particleTimeline[p].color, t, particleTimeline[p].easing);
					break;
				}
			}
			sprite.p = particles[i].pos;
			sprite.ang = NJM_DEG_ANG(0.0f);
			sprite.sx = size.x / (float)anim->sx;
			sprite.sy = size.y / (float)anim->sy;
			ConstantMaterial = color;
			DrawSprite2D(&sprite, 1, 1.0f, NJD_SPRITE_ALPHA | NJD_SPRITE_COLOR);
		}
	}
}