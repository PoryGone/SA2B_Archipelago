#include "../../../../pch.h"
#include "CollisionTest.h"
#include "../MinigameBackend.h"
#include <vector>

void CollisionTest::RunTests()
{
	if (hasRun) return;
	PrintDebug("-----Run Tests Start-----");
	//Positive overlap
	BoundingBox box1 = BoundingBox({ 5.0f, 5.0f, 0.0f }, { 1.0f, 1.0f, 0.0f });
	BoundingBox box2 = BoundingBox({ 7.0f, 5.0f, 0.0f }, { 1.0f, 1.0f, 0.0f });

	AssertFalse(box1.IsOverlapping(box2), "NonOverlapPositive");
	AssertFalse(box1.IsOverlapping({ 7.0f, 5.0f, 0.0f }), "NonOverlapPositivePoint");

	box2 = BoundingBox({ 6.0f, 5.0f, 0.0f }, { 1.0f, 1.0f, 0.0f });

	AssertFalse(box1.IsOverlapping(box2), "NonOverlapPositiveTouching");

	box2 = BoundingBox({ 5.5f, 5.0f, 0.0f }, { 1.0f, 1.0f, 0.0f });

	AssertTrue(box1.IsOverlapping(box2), "OverlapPositive");
	AssertTrue(box1.IsOverlapping({ 5.1f, 4.9f, 0.0f }), "OverlapPositivePoint");

	box2 = BoundingBox({ 5.0f, 5.0f, 0.0f }, { 1.0f, 1.0f, 0.0f });

	AssertTrue(box1.IsOverlapping(box2), "CompleteOverlapPositive");

	//Negative overlap
	box1 = BoundingBox({ -5.0f, -5.0f, 0.0f }, { 1.0f, 1.0f, 0.0f });
	box2 = BoundingBox({ -7.0f, -5.0f, 0.0f }, { 1.0f, 1.0f, 0.0f });

	AssertFalse(box1.IsOverlapping(box2), "NonOverlapNegative");
	AssertFalse(box1.IsOverlapping({ -7.0f, -5.0f, 0.0f }), "NonOverlapNegativePoint");

	box2 = BoundingBox({ -6.0f, -5.0f, 0.0f }, { 1.0f, 1.0f, 0.0f });

	AssertFalse(box1.IsOverlapping(box2), "NonOverlapNegativeTouching");

	box2 = BoundingBox({ -5.5f, -5.0f, 0.0f }, { 1.0f, 1.0f, 0.0f });

	AssertTrue(box1.IsOverlapping(box2), "OverlapNegative");
	AssertTrue(box1.IsOverlapping({ -5.1f, -4.9f, 0.0f }), "OverlapNegativePoint");

	box2 = BoundingBox({ -5.0f, -5.0f, 0.0f }, { 1.0f, 1.0f, 0.0f });

	AssertTrue(box1.IsOverlapping(box2), "CompleteOverlapNegative");

	//Adding
	box1 = BoundingBox({ 5.0f, 5.0f, 0.0f }, { 1.0f, 1.0f, 0.0f });
	box2 = BoundingBox({ 5.0f, 5.0f, 0.0f }, { 1.0f, 1.0f, 0.0f });
	BoundingBox box3 = BoundingBox({ 5.0f, 5.0f, 0.0f }, { 1.0f, 1.0f, 0.0f });

	box1.Add(box2);
	AssertTrue(box1.IsEqual(box3), "AddSameBoxResultsInNoChange");

	box1 = BoundingBox({ 5.0f, 5.0f, 0.0f }, { 1.0f, 1.0f, 0.0f });
	box2 = BoundingBox({ 5.0f, 5.0f, 0.0f }, { 0.5f, 0.5f, 0.0f });
	box3 = BoundingBox({ 5.0f, 5.0f, 0.0f }, { 1.0f, 1.0f, 0.0f });

	box1.Add(box2);
	AssertTrue(box1.IsEqual(box3), "AddSmallerBoxResultsInNoChange");

	box1 = BoundingBox({ 5.0f, 5.0f, 0.0f }, { 1.0f, 1.0f, 0.0f });
	box2 = BoundingBox({ 5.0f, 5.0f, 0.0f }, { 2.0f, 2.0f, 0.0f });
	box3 = BoundingBox({ 5.0f, 5.0f, 0.0f }, { 2.0f, 2.0f, 0.0f });

	box1.Add(box2);
	AssertTrue(box1.IsEqual(box3), "AddLargerBoxResultsInLargerSize");

	box1 = BoundingBox({ 5.0f, 5.0f, 0.0f }, { 1.0f, 1.0f, 0.0f });
	box2 = BoundingBox({ 6.0f, 5.0f, 0.0f }, { 1.0f, 1.0f, 0.0f });
	box3 = BoundingBox({ 5.5f, 5.0f, 0.0f }, { 2.0f, 1.0f, 0.0f });

	box1.Add(box2);
	AssertTrue(box1.IsEqual(box3), "AddXOffsetBoxResultsInLargerSize");

	box1 = BoundingBox({ 5.0f, 5.0f, 0.0f }, { 1.0f, 1.0f, 0.0f });
	box2 = BoundingBox({ 5.0f, 6.0f, 0.0f }, { 1.0f, 1.0f, 0.0f });
	box3 = BoundingBox({ 5.0f, 5.5f, 0.0f }, { 1.0f, 2.0f, 0.0f });

	box1.Add(box2);
	AssertTrue(box1.IsEqual(box3), "AddYOffsetBoxResultsInLargerSize");

	box1 = BoundingBox({ 5.0f, 5.0f, 0.0f }, { 1.0f, 1.0f, 0.0f });
	box3 = BoundingBox({ 5.0f, 5.0f, 0.0f }, { 1.0f, 1.0f, 0.0f });

	box1.Add({ 5.1f, 4.9f, 0.0f });
	AssertTrue(box1.IsEqual(box3), "AddInsidePointResultsInNoChange");

	box1 = BoundingBox({ 5.0f, 5.0f, 0.0f }, { 1.0f, 1.0f, 0.0f });
	box3 = BoundingBox({ 5.5f, 5.0f, 0.0f }, { 2.0f, 1.0f, 0.0f });

	box1.Add({ 6.5f, 5.3f, 0.0f });
	AssertTrue(box1.IsEqual(box3), "AddXOffsetPointResultsInLargerSize");

	box1 = BoundingBox({ 5.0f, 5.0f, 0.0f }, { 1.0f, 1.0f, 0.0f });
	box3 = BoundingBox({ 5.0f, 5.5f, 0.0f }, { 1.0f, 2.0f, 0.0f });

	box1.Add({ 5.3f, 6.5f, 0.0f });
	AssertTrue(box1.IsEqual(box3), "AddYOffsetPointResultsInLargerSize");

	CircleCollider cCol1 = CircleCollider(1.0f);
	CircleCollider cCol2 = CircleCollider(1.0f);

	AssertTrue(cCol1.IsColliding(cCol2), "IdenticalCirclesResultsInCollision");

	cCol1 = CircleCollider(1.0f);
	cCol2 = CircleCollider(1.0f, { 1.0f, 0.0f, 0.0f });

	AssertTrue(cCol1.IsColliding(cCol2), "OverlappingCirclesResultsInCollision");

	cCol1 = CircleCollider(1.0f);
	cCol2 = CircleCollider(1.0f, { 2.0f, 0.0f, 0.0f });

	AssertFalse(cCol1.IsColliding(cCol2), "TouchingCirclesResultsInNoCollision");

	cCol1 = CircleCollider(1.0f);
	cCol2 = CircleCollider(1.0f, { 4.0f, 0.0f, 0.0f });

	AssertFalse(cCol1.IsColliding(cCol2), "ApartCirclesResultsInNoCollision");

	PolygonCollider pCol1 = PolygonCollider({ 1.0f,1.0f,1.0f }, 0.0f, { 0.0f,0.0f,0.0f });
	PolygonCollider pCol2 = PolygonCollider({ 1.0f,1.0f,1.0f }, 0.0f, { 0.0f,0.0f,0.0f });

	AssertTrue(pCol1.IsColliding(pCol2), "IdenticalBoxesResultsInCollision");

	pCol2 = PolygonCollider({ 1.0f,1.0f,1.0f }, 0.0f, { 0.5f,0.0f,0.0f });

	AssertTrue(pCol1.IsColliding(pCol2), "OverlappingBoxesResultsInCollision");

	pCol2 = PolygonCollider({ 1.0f,1.0f,1.0f }, 45.0f, { 1.1f,0.0f,0.0f });

	AssertTrue(pCol1.IsColliding(pCol2), "OverlappingRotatedBoxesResultsInCollision");

	pCol2 = PolygonCollider({ 1.0f,1.0f,1.0f }, 0.0f, { 1.0f,0.0f,0.0f });

	AssertTrue(pCol1.IsColliding(pCol2), "TouchingBoxesResultsInCollision");

	pCol2 = PolygonCollider({ 1.0f,1.0f,1.0f }, 0.0f, { 1.1f,0.0f,0.0f });

	AssertFalse(pCol1.IsColliding(pCol2), "ApartBoxesResultsInNoCollision");

	AssertTrue(pCol1.ContainsPoint({ 0.0f,0.0f,0.0f }), "PointInPolygonResultsInContainingTrue");

	AssertFalse(pCol1.ContainsPoint({ 2.0f,0.0f,0.0f }), "PointOutsidePolygonResultsInContainingFalse");

	cCol1 = CircleCollider(0.5f);

	AssertTrue(pCol1.IsColliding(cCol1), "CircleContainedByPolygonResultsInCollision");
	AssertTrue(cCol1.IsColliding(pCol1), "CircleContainedByPolygonResultsInCollision_Reverse");

	cCol1 = CircleCollider(0.5f, { 1.0f,0.0f,0.0f });

	AssertTrue(pCol1.IsColliding(cCol1), "CircleTouchingPolygonResultsInCollision");
	AssertTrue(cCol1.IsColliding(pCol1), "CircleTouchingPolygonResultsInCollision_Reverse");

	cCol1 = CircleCollider(0.5f, { 2.0f,0.0f,0.0f });

	AssertFalse(pCol1.IsColliding(cCol1), "CircleApartFromPolygonResultsInNoCollision");
	AssertFalse(cCol1.IsColliding(pCol1), "CircleApartFromPolygonResultsInNoCollision_Reverse");

	SpriteHierarchy hierarchy = SpriteHierarchy();
	CollisionManager colManager = CollisionManager();

	SpriteNode* spr1 = hierarchy.CreateNode("Sprite 1");
	SpriteNode* spr2 = hierarchy.CreateNode("Sprite 2");

	colManager.Reset();
	colManager.AddCollision(spr1, std::make_shared<CircleCollider>(1.0f));
	colManager.AddCollision(spr2, std::make_shared<CircleCollider>(1.0f));

	AssertTrue(colManager.IsColliding(spr1, spr2), "Manager_OverlappingCirclesResultsInCollision");

	spr2->SetPositionGlobal({ 3.0f,0.0f,0.0f });

	AssertFalse(colManager.IsColliding(spr1, spr2), "Manager_ApartCirclesResultsInNoCollision");

	colManager.Reset();

	spr2->SetPositionGlobal({ 0.0f,0.0f,0.0f });

	colManager.AddCollision(spr1, std::make_shared<PolygonCollider>(NJS_POINT3({ 1.0f,1.0f,1.0f })));
	colManager.AddCollision(spr2, std::make_shared<PolygonCollider>(NJS_POINT3({ 1.0f,1.0f,1.0f })));

	AssertTrue(colManager.IsColliding(spr1, spr2), "Manager_OverlappingPolygonsResultsInCollision");

	spr2->SetPositionGlobal({ 3.0f,0.0f,0.0f });

	AssertFalse(colManager.IsColliding(spr1, spr2), "Manager_ApartPolygonsResultsInNoCollision");

	colManager.Reset();

	spr2->SetPositionGlobal({ 0.0f,0.0f,0.0f });

	colManager.AddCollision(spr1, std::make_shared<CircleCollider>(1.0f));
	colManager.AddCollision(spr2, std::make_shared<PolygonCollider>(NJS_POINT3({ 1.0f,1.0f,1.0f })));

	AssertTrue(colManager.IsColliding(spr1, spr2), "Manager_OverlappingCircleAndPolygonResultsInCollision");
	AssertTrue(colManager.IsColliding(spr2, spr1), "Manager_OverlappingCircleAndPolygonResultsInCollision_Reverse");

	spr2->SetPositionGlobal({ 3.0f,0.0f,0.0f });

	AssertFalse(colManager.IsColliding(spr1, spr2), "Manager_ApartCircleAndPolygonResultsInNoCollision");
	AssertFalse(colManager.IsColliding(spr2, spr1), "Manager_ApartCircleAndPolygonResultsInNoCollision_Reverse");

	AssertTrue(TestLineSegmentIntersection({ -1.0f, 0.0f }, { 1.0f, 0.0f }, { 0.0f, 1.0f }, { 0.0f, -1.0f }).isIntersecting, "Util_PerpendicularOverlappingLineSegmentsResultsInIntersection");
	AssertFalse(TestLineSegmentIntersection({ -1.0f, 1.0f }, { -1.0f, -1.0f }, { 0.0f, 1.0f }, { 0.0f, -1.0f }).isIntersecting, "Util_ParallelLineSegmentsResultsInNoIntersection");

	CapsuleCollider capCol1 = CapsuleCollider(1.0f, nullptr, { 2.0f, 0.0f }, { 1.0f, 0.0f });
	CapsuleCollider capCol2 = CapsuleCollider(1.0f, nullptr, { -2.0f, 0.0f }, { 0.5f, 0.0f });

	AssertTrue(TestCapsuleCapsuleIntersection(capCol1, capCol2).isIntersecting, "Util_CapsultCapsuleIntersection");

	capCol2 = CapsuleCollider(1.0f, nullptr, { -2.0f, 0.0f }, { -2.0f, 1.0f });

	AssertFalse(TestCapsuleCapsuleIntersection(capCol1, capCol2).isIntersecting, "Util_CapsultCapsuleNoIntersection");
	AssertFalse(capCol1.IsColliding(capCol2), "Util_CapsultCapsuleNoCollision");
	box1 = capCol1.GetBoundingBox();
	box2 = capCol2.GetBoundingBox();
	AssertFalse(box1.IsOverlapping(box2), "Util_CapsultCapsuleNoOverlap");

	colManager.Reset();

	spr1->SetPositionGlobal({});
	spr2->SetPositionGlobal({ 235.0f, 375.0f });
	spr2->SetRotation(15.0f);

	colManager.AddCollision(spr1, std::make_shared<CapsuleCollider>(5.0f, spr1, NJS_POINT3({ 238.982544f, 383.645325f }), NJS_POINT3({ 240.926193f, 382.061707f })));
	colManager.AddCollision(spr2, std::make_shared<PolygonCollider>(NJS_POINT3({ 90.0f, 5.0f }), 0.0f, NJS_POINT3({})));
	
	AssertTrue(colManager.IsColliding(spr1, spr2), "Manager_OverlappingCapsuleAndPolygon");

	colManager.Reset();

	spr1->SetPositionGlobal({ 238.982544f, 383.645325f });
	spr2->SetPositionGlobal({ 235.0f, 375.0f });
	spr2->SetRotation(15.0f);

	colManager.AddCollision(spr1, std::make_shared<CircleCollider>(5.0f));
	colManager.AddCollision(spr2, std::make_shared<PolygonCollider>(NJS_POINT3({ 90.0f, 5.0f }), 0.0f, NJS_POINT3({})));

	std::vector<SpriteNode*> castAgainst = { spr2 };
	AssertTrue(colManager.CastCollision(spr1, { 1.943644f, -1.633612f }, castAgainst).isHit, "Manager_CastCirceAgainstPolygon");

	PrintDebug("-----Run Tests End-----");
	hasRun = true;
}

void CollisionTest::AssertTrue(bool value, std::string testName)
{
	std::string testResult = value ? "Passed : " : "-Failed- : ";
	testResult.append(testName);
	PrintDebug(testResult.c_str());
}

void CollisionTest::AssertFalse(bool value, std::string testName)
{
	std::string testResult = !value ? "Passed : " : "-Failed- : ";
	testResult.append(testName);
	PrintDebug(testResult.c_str());
}
