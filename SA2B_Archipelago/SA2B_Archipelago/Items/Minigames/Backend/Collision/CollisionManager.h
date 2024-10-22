#pragma once
#include "BoundingBox.h"
#include "../SpriteNode.h"
#include "Collider.h"
#include "CircleCollider.h"
#include "PolygonCollider.h"
#include "CapsuleCollider.h"
#include "CastResult.h"
#include <vector>
#include <map>
#include <memory>
#include "../../MinigameIconData.h"
#include "CollisionUtilities.h"

class CollisionManager
{
public:
	void Reset();
	void AddCollision(SpriteNode* node, std::shared_ptr<Collider> collider);
	void AddCollision(SpriteNode* node, std::vector<std::shared_ptr<Collider>> colliders);
	bool IsColliding(SpriteNode* nodeA, SpriteNode* nodeB);
	CastResult CastCollision(SpriteNode* node, NJS_POINT3 vector, std::vector<SpriteNode*> others);
	void DebugDrawCollision(MinigameIconData* iconData);

private:
	std::map<SpriteNode*, std::vector<std::shared_ptr<Collider>>> colliderMap;
};