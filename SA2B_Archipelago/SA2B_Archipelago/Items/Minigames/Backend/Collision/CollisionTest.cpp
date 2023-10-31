#include "../../../../pch.h"
#include "CollisionTest.h"
#include "../MinigameBackend.h"

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
