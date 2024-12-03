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

/// <summary>
/// This currently only works on single circle collider nodes. Returns data about the first collision that will occur (if any) when projected along vector.
/// </summary>
CastResult CollisionManager::CastCollision(SpriteNode* node, NJS_POINT3 vector, std::vector<SpriteNode*> others)
{
	CastResult castResults = CastResult();
	float currentDist = 10000.0f;
	if (!colliderMap.count(node)) return CastResult();
	auto colliders = colliderMap[node];
	if (colliders.size() == 1)
	{
		auto col = colliders[0];
		if (auto circle_col = dynamic_cast<CircleCollider*>(&*col))
		{
			CapsuleCollider castCol = CapsuleCollider(*circle_col, vector);
			NJS_POINT3 castPt = castCol.GetPoint1();
			auto castBounds = castCol.GetBoundingBox();
			
			for (int i = 0; i < others.size(); i++)
			{
				auto otherCol = colliderMap[others[i]];
				for (int c = 0; c < otherCol.size(); c++)
				{
					auto otherBound = otherCol[c]->GetBoundingBox();
					if (castBounds.IsOverlapping(otherBound) && castCol.IsColliding(*otherCol[c]))
					{
						if (auto polygon = dynamic_cast<PolygonCollider*>(&*otherCol[c]))
						{
							auto results = TestCapsulePolygonIntersection(castCol, *polygon);
							float dist = Point3Distance(castPt, results.point);
							if (results.isIntersecting && (!castResults.isHit || dist < currentDist))
							{
								castResults = CastResult(results.point, results.surfaceNormal, polygon->node);
								currentDist = dist;
							}
						}
						if (auto circle = dynamic_cast<CircleCollider*>(&*otherCol[c]))
						{
							auto results = TestCapsuleCircleIntersection(castCol, *circle);
							float dist = Point3Distance(castPt, results.point);
							if (results.isIntersecting && (!castResults.isHit || dist < currentDist))
							{
								castResults = CastResult(results.point, results.surfaceNormal, circle->node);
								currentDist = dist;
							}
						}
						if (auto capsule = dynamic_cast<CapsuleCollider*>(&*otherCol[c]))
						{
							auto results = TestCapsuleCapsuleIntersection(castCol, *capsule);
							float dist = Point3Distance(castPt, results.point);
							if (results.isIntersecting && (!castResults.isHit || dist < currentDist))
							{
								castResults = CastResult(results.point, results.surfaceNormal, capsule->node);
								currentDist = dist;
							}
						}
					}
				}
			}
		}
	}
	return castResults;
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
				//Draw Bounding Box
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
				//Draw polygon frame
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
				//Draw circle frame
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
				//Draw capsule frame
				if (auto capsule = dynamic_cast<CapsuleCollider*>(c))
				{
					NJS_POINT3 c1 = capsule->GetPoint1();
					NJS_POINT3 c2 = capsule->GetPoint2();
					anim = iconData->GetAnim(MGI_Circle_Outline);
					tempAnim = anim;
					tempAnim--;
					sprite.tanim = tempAnim;
					sprite.p = c1;
					sprite.ang = NJM_DEG_ANG(0.0f);
					sprite.sx = capsule->radius * 2.0f / (float)anim->sx;
					sprite.sy = capsule->radius * 2.0f / (float)anim->sy;
					ConstantMaterial = { 0.8f, 0.0f, 1.0f, 0.0f };
					DrawSprite2D(&sprite, 1, 1.0f, NJD_SPRITE_ALPHA | NJD_SPRITE_COLOR);
					sprite.p = c2;
					DrawSprite2D(&sprite, 1, 1.0f, NJD_SPRITE_ALPHA | NJD_SPRITE_COLOR);
					anim = iconData->GetAnim(MGI_White_Box);
					tempAnim = anim;
					tempAnim--;
					sprite.tanim = tempAnim;
					NJS_POINT3 centerLine = Point3Normalize(Point3Substract(c2, c1));
					float ang = atan2(centerLine.y, centerLine.x) - atan2(1.0f, 0.0f);
					ang = NJM_RAD_DEG(ang);
					NJS_POINT3 perpendicularLine = Point3RotateAround(centerLine, {}, 90.0f);
					NJS_POINT3 c3 = Point3Add(c1, Point3Scale(perpendicularLine, capsule->radius));
					NJS_POINT3 c4 = Point3Add(c2, Point3Scale(perpendicularLine, capsule->radius));
					NJS_POINT3 c5 = Point3Add(c1, Point3Scale(perpendicularLine, -capsule->radius));
					NJS_POINT3 c6 = Point3Add(c2, Point3Scale(perpendicularLine, -capsule->radius));
					NJS_POINT3 c34 = { 0.0f, 0.0f };
					c34.x = 0.5f * c3.x + 0.5f * c4.x;
					c34.y = 0.5f * c3.y + 0.5f * c4.y;
					NJS_POINT3 c56 = { 0.0f, 0.0f };
					c56.x = 0.5f * c5.x + 0.5f * c6.x;
					c56.y = 0.5f * c5.y + 0.5f * c6.y;
					sprite.ang = NJM_DEG_ANG(ang);
					sprite.sx = 2.0f / (float)anim->sx;
					sprite.p = c34;
					sprite.sy = Point3Distance(c3, c4) / (float)anim->sy;
					DrawSprite2D(&sprite, 1, 1.0f, NJD_SPRITE_ALPHA | NJD_SPRITE_ANGLE | NJD_SPRITE_COLOR);
					sprite.p = c56;
					sprite.sy = Point3Distance(c5, c6) / (float)anim->sy;
					DrawSprite2D(&sprite, 1, 1.0f, NJD_SPRITE_ALPHA | NJD_SPRITE_ANGLE | NJD_SPRITE_COLOR);
				}
			}
		}
	}
	ResetMaterial();
}
