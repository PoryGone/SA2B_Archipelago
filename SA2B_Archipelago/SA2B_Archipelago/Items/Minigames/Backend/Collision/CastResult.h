#pragma once
#include "../../../../pch.h"


struct CastResult
{
public:
	bool isHit;
	NJS_POINT3 collisionPoint;
	NJS_POINT3 surfaceNormal;
	SpriteNode* firstHitObject;

	CastResult() : isHit(false), collisionPoint({}), surfaceNormal({}), firstHitObject(nullptr) {}
	CastResult(NJS_POINT3 _collisionPoint, NJS_POINT3 _surfaceNormal, SpriteNode* _firstHitObject) : isHit(true), collisionPoint(_collisionPoint), surfaceNormal(_surfaceNormal), firstHitObject(_firstHitObject) {}
};