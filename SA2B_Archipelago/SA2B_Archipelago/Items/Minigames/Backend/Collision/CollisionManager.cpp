#include "../../../../pch.h"
#include "CollisionManager.h"
#include <memory>

void CollisionManager::Reset()
{
	colliderMap.clear();
}

void CollisionManager::AddCollision(SpriteNode* node, std::shared_ptr<Collider> collider)
{
	collider->node = node;
	colliderMap[node].push_back(collider);
}

void CollisionManager::AddCollision(SpriteNode* node, std::vector<std::shared_ptr<Collider>> colliders)
{
	for (int i = 0; i < colliders.size(); i++)
	{
		colliders[i]->node = node;
		colliderMap[node].push_back(colliders[i]);
	}
}

bool CollisionManager::IsColliding(SpriteNode* nodeA, SpriteNode* nodeB)
{
	if (!colliderMap.count(nodeA) || !colliderMap.count(nodeB)) return false;

	auto colA = colliderMap[nodeA];
	auto colB = colliderMap[nodeB];

	for (int a = 0; a < colA.size(); a++)
	{
		auto boundA = colA[a]->GetBoundingBox();
		for (int b = 0; b < colB.size(); b++)
		{
			auto boundB = colB[b]->GetBoundingBox();
			if (boundA.IsOverlapping(boundB) && colA[a]->IsColliding(*colB[b])) return true;
		}
	}

	return false;
}
