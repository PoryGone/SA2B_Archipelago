#include "../../../../pch.h"
#include "CollisionManager.h"
#include <memory>
#include <cmath>

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

void CollisionManager::DebugDrawCollision(MinigameIconData* iconData)
{
	NJS_SPRITE sprite = { { 0.0f, 0.0f, 0.0f }, 1.0f, 1.0f, 0, iconData->MinigameTex, iconData->MinigameAnims };
	for (auto& cVector : colliderMap)
	{
		if (cVector.first->IsEnabled())
		{
			for (int i = 0; i < cVector.second.size(); i++)
			{
				auto c = cVector.second[i].get();
				auto b = c->GetBoundingBox();
				NJS_TEXANIM* anim = iconData->GetAnim(MGI_White_Box);
				NJS_TEXANIM* tempAnim = anim;
				tempAnim--;
				sprite.tanim = tempAnim;
				sprite.p = b.center;
				sprite.ang = NJM_DEG_ANG(0.0f);
				sprite.sx = b.size.x / (float)anim->sx;
				sprite.sy = b.size.y / (float)anim->sy;
				ConstantMaterial = { 0.4f, 0.0f, 0.0f, 1.0f };
				DrawSprite2D(&sprite, 1, 1.0f, NJD_SPRITE_ALPHA | NJD_SPRITE_COLOR);
				if (auto polygon = dynamic_cast<PolygonCollider*>(c))
				{
					auto points = polygon->GetAdjustedPoints();
					for (int p = 1; p < points.size() + 1; p++)
					{
						int p1 = p == points.size() ? 0 : p;
						int p2 = p - 1;
						NJS_POINT3 toPoint = Point3Normalize(Point3Substract(points[p1], points[p2]));
						float ang = atan2(toPoint.y, toPoint.x) - atan2(1.0f, 0.0f);
						ang = NJM_RAD_DEG(ang);
						while (ang > 180.0f) ang -= 360.0f;
						while (ang < -180.0f) ang += 360.0f;
						NJS_POINT3 center = { 0.0f, 0.0f };
						center.x = 0.5f * points[p1].x + 0.5f * points[p2].x;
						center.y = 0.5f * points[p1].y + 0.5f * points[p2].y;
						tempAnim = anim;
						tempAnim--;
						sprite.tanim = tempAnim;
						sprite.p = center;
						sprite.ang = NJM_DEG_ANG(ang);
						sprite.sx = 2.0f / (float)anim->sx;
						sprite.sy = Point3Distance(points[p1], points[p2]) / (float)anim->sy;
						ConstantMaterial = { 0.8f, 0.0f, 1.0f, 0.0f };
						DrawSprite2D(&sprite, 1, 1.0f, NJD_SPRITE_ALPHA | NJD_SPRITE_ANGLE | NJD_SPRITE_COLOR);
					}
				}
				if (auto circle = dynamic_cast<CircleCollider*>(c))
				{
					anim = iconData->GetAnim(MGI_Circle_Outline);
					tempAnim = anim;
					tempAnim--;
					sprite.tanim = tempAnim;
					sprite.p = circle->GetCenter();
					sprite.ang = NJM_DEG_ANG(0.0f);
					sprite.sx = circle->radius * 2.0f / (float)anim->sx;
					sprite.sy = circle->radius * 2.0f / (float)anim->sy;
					ConstantMaterial = { 0.8f, 0.0f, 1.0f, 0.0f };
					DrawSprite2D(&sprite, 1, 1.0f, NJD_SPRITE_ALPHA | NJD_SPRITE_COLOR);
				}
			}
		}
	}
	ResetMaterial();
}
