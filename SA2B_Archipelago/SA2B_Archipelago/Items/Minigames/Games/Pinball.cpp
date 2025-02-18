#include "../../../pch.h"
#include "Pinball.h"
#include "../Components/Rotator.h"

void Pinball::OnGameStart(MinigameManagerData data)
{
	//normIndex = 0;
	this->currentState = MGS_InProgress;
	data.timers->push_back(&endTimer);
	data.stopwatches->push_back(&resetSW);
	switch (data.difficulty)
	{
	case MGD_Easy:
		lives = 6;
		goalScore = 100;
		break;
	case MGD_Medium:
		lives = 4;
		goalScore = 100;
		break;
	case MGD_Hard:
		lives = 3;
		goalScore = 150;
		break;
	}
	totalScore = 0;
	scoreMult = 1;
	countdown = 3;
	state = PS_Countdown;
	endTimer.Start(1.0f);

	CreateHierarchy(data);
	SpawnBall();

	PlaySoundProbably((int)MinigameSounds::LevelStart, 0, 0, 0);
}

void Pinball::OnFrame(MinigameManagerData data)
{
	if (data.managerState == MGS_InProgress)
	{
		if (state == PS_Countdown)
		{
			UpdateCountdown(data);
		}
		else if (state == PS_BallActive)
		{
			UpdateBallActive(data);
		}
		else if (state == PS_Victory || state == PS_Defeat)
		{
			UpdateGameEnd(data);
		}
	}
}

void Pinball::UpdateCountdown(MinigameManagerData data)
{
	if (endTimer.IsElapsed())
	{
		countdown--;
		if (countdown > 0)
		{
			countdownBox->UpdateText(std::to_string(countdown));
			endTimer.Start(1.0f);
		}
		else
		{
			countdownNode->SetEnabled(false);
			state = PS_BallActive;
			resetSW.Start();
			ballStuckPosition = ball->GetPositionGlobal();
		}
	}
}

void Pinball::UpdateBallActive(MinigameManagerData data)
{
	NJS_POINT3 prevVel = ballVelocity;
	NJS_POINT3 prevPos = ball->GetPositionGlobal();
	ballVelocity.y += gravity;
	bool flipperUsed = false;
	float flipperRange = flipperLength + ballRadius;
	if (data.inputPress & leftFlipperInput)
	{
		NJS_POINT3 toBall = Point3Substract(ball->GetPositionGlobal(), leftFlipper->GetPositionGlobal());
		NJS_POINT3 toTip = Point3RotateAround({ 1.0f, 0.0f }, { 0.0f, 0.0f }, 9.5f);
		float ballAng = Point3SignedAngleDegrees(toTip, toBall);
		float ballDist = Point3Distance(leftFlipper->GetPositionGlobal(), ball->GetPositionGlobal());
		if (ballAng < 0.0f && abs(ballAng) < flipperAngle && ballDist <= flipperRange)
		{
			float flipT = ballDist / flipperRange;
			NJS_POINT3 awayVector = Point3RotateAround(toTip, { 0.0f, 0.0f }, -EaseInterpolate(flipperAngForceAngMax, flipperAngForceAngMin, flipT, ET_QuadIn));
			awayVector = Point3Scale(awayVector, Lerp(flipperForceMin, flipperForceMax, flipT));
			ballVelocity = awayVector;
			flipperUsed = true;
		}
		/*std::string dbgStr = "Left Flipper: ";
		dbgStr.append(std::to_string(ballDist));
		dbgStr.append(", ");
		dbgStr.append(std::to_string(ballAng));
		PrintDebug(dbgStr.c_str());*/
	}
	if (data.inputPress & rightFlipperInput)
	{
		if (Point3Distance(rightFlipper->GetPositionGlobal(), ball->GetPositionGlobal()) <= flipperRange)
		{
			NJS_POINT3 toBall = Point3Substract(ball->GetPositionGlobal(), rightFlipper->GetPositionGlobal());
			NJS_POINT3 toTip = Point3RotateAround({ 1.0f, 0.0f }, { 0.0f, 0.0f }, -189.5f);
			float ballAng = Point3SignedAngleDegrees(toTip, toBall);
			float ballDist = Point3Distance(rightFlipper->GetPositionGlobal(), ball->GetPositionGlobal());
			if (ballAng > 0.0f && abs(ballAng) < flipperAngle && ballDist <= flipperRange)
			{
				float flipT = ballDist / flipperRange;
				NJS_POINT3 awayVector = Point3RotateAround(toTip, { 0.0f, 0.0f }, EaseInterpolate(flipperAngForceAngMax, flipperAngForceAngMin, flipT, ET_QuadIn));
				awayVector = Point3Scale(awayVector, Lerp(flipperForceMin, flipperForceMax, flipT));
				ballVelocity = awayVector;
				flipperUsed = true;
			}
			/*std::string dbgStr = "Right Flipper: ";
			dbgStr.append(std::to_string(ballDist));
			dbgStr.append(", ");
			dbgStr.append(std::to_string(ballAng));
			PrintDebug(dbgStr.c_str());*/
		}
	}
	leftFlipper->SetRotation(9.5f - (data.input & leftFlipperInput ? 60.0f : 0.0f));
	rightFlipper->SetRotation(-189.5f + (data.input & rightFlipperInput ? 60.0f : 0.0f));
	if (data.inputPress & (leftFlipperInput | rightFlipperInput))
	{
		PlaySoundProbably((int)MinigameSounds::Punch, 0, 0, 0);
	}
	auto results = data.collision->CastCollision(ball, ballVelocity, flipperUsed ? boardObjsNoFlippers : boardObjs);
	float distanceRemaining = Point3Magnitude(ballVelocity);
	int loops = 0;
	while (loops < 5 && distanceRemaining > 0.001f && results.isHit)
	{
		float surfaceDampening = baseDampening;
		if (results.firstHitObject->name == "TriBumper")
		{
			if (Point3AngleDegrees({ 0.0f, -1.0f }, results.surfaceNormal) < 80.0f)
			{
				surfaceDampening = bumperDampening;

				PlaySoundProbably((int)MinigameSounds::Spring, 0, 0, 0);
				AddScore(5, data);
			}
		}
		else if (results.firstHitObject->name == "Bumper")
		{
			surfaceDampening = bumperDampening;

			PlaySoundProbably((int)MinigameSounds::Spring, 0, 0, 0);
			AddScore(10, data);
		}
		NJS_POINT3 initialPosition = ball->GetPositionGlobal();
		float initialVelocity = Point3Magnitude(ballVelocity);
		float finalVelocity = min(sqrt(surfaceDampening) * initialVelocity, maxVelocity); //Change in KE
		//float theta = 180.0f - Point3AngleDegrees(Point3Normalize(ballVelocity), results.surfaceNormal);

		float displacementAng = Point3SignedAngleDegrees({ 1.0f, 0.0f }, { results.surfaceNormal.x, -results.surfaceNormal.y });
		//displacementAng = displacementAng < 0.0f ? displacementAng + 360.0f : displacementAng;

		NJS_POINT3 displacedBallVelocity = Point3RotateAround(ballVelocity, {}, displacementAng);

		finalVelocity = max(finalVelocity, abs(displacedBallVelocity.y));
		float finalX = -sqrt(pow(finalVelocity, 2.0f) - pow(displacedBallVelocity.y, 2.0f));
		float finalY = -displacedBallVelocity.y;

		NJS_POINT3 undisplacedBallVelocity = Point3RotateAround({ finalX, finalY }, {}, -displacementAng);
		ballVelocity = Point3Scale(undisplacedBallVelocity, -1.0f);
		
		NJS_POINT3 colPoint = Point3Add(results.collisionPoint, Point3Scale(results.surfaceNormal, ballRadius + 0.25f ));
		ball->SetPositionGlobal(colPoint);

		//Debug Norm
		/*
		NJS_POINT3 refNormal = Point3Normalize(ballVelocity);
		SpriteNode* normObj = normObjs[normIndex];
		normObj->SetPositionGlobal(Point3Add(results.collisionPoint, Point3Scale(refNormal, normObj->displaySize.y * 0.5f)));
		float normAng = Point3SignedAngleDegrees({ 0.0f, 1.0f }, refNormal);
		normObj->SetRotation(normAng);
		normObj->SetEnabled(true);
		normObj = colPtObjs[normIndex];
		normIndex = normIndex < (normObjs.size() - 1) ? normIndex + 1 : 0;
		normObj->SetPositionGlobal(results.collisionPoint);
		normObj->SetEnabled(true);
		std::string dbgStr = std::to_string(Point3Magnitude(ballVelocity));
		dbgStr.append(" --> ");
		dbgStr.append(std::to_string(displacementAng));
		dbgStr.append(" --> ");
		dbgStr.append(std::to_string(initialVelocity));
		dbgStr.append(" --> ");
		dbgStr.append(std::to_string(finalVelocity));
		dbgStr.append(" --> ");
		dbgStr.append(std::to_string(finalX));
		dbgStr.append(" --> ");
		dbgStr.append(std::to_string(finalY));
		dbgStr.append(" --> ");
		dbgStr.append(Point3String(ballVelocity));
		dbgStr.append(" --> ");
		dbgStr.append(Point3String(results.collisionPoint));
		PrintDebug(dbgStr.c_str());
		*/

		loops++;
		distanceRemaining -= Point3Distance(initialPosition, ball->GetPositionGlobal());
		distanceRemaining *= finalVelocity / initialVelocity;
		results = data.collision->CastCollision(ball, Point3Scale(Point3Normalize(ballVelocity), distanceRemaining), flipperUsed ? boardObjsNoFlippers : boardObjs);
		
		if (!results.isHit)
		{
			ball->Translate(Point3Scale(Point3Normalize(ballVelocity), distanceRemaining));
		}
	}
	if(loops == 0)
	{
		ball->Translate(ballVelocity);
	}
	if (data.collision->IsColliding(ball, drain) || ball->GetPositionGlobal().y > 485.0f)
	{
		PlaySoundProbably((int)MinigameSounds::MenuBack, 0, 0, 0);
		if (lives <= 0)
		{
			Lose(data);
		}
		else
		{
			SpawnBall();
		}
	}
	if (Point3Distance(ball->GetPositionGlobal(), ballStuckPosition) > ballStuckThreshold)
	{
		ballStuckPosition = ball->GetPositionGlobal();
		resetSW.Start();
	}
	if (resetSW.TimeElapsed() > ballStuckTime)
	{
		SpawnBall(true);
	}
}

void Pinball::UpdateGameEnd(MinigameManagerData data)
{
	if (endIcon->color.a < 1.0f)
	{
		// TODO RAS: Figure out how to time playing the Rank Reveal sound once here when it's done animating
		endIcon->color.a += 1.0f / 30.0f;
		endIcon->displaySize = Point3MoveTowards(endIcon->displaySize, { 200.0f, 200.0f }, 200.0f / 30.0f);
		if (endIcon->color.a >= 1.0f)
		{
			PlaySoundProbably((int)MinigameSounds::RankReveal, 0, 0, 0);
		}
	}
	if (endTimer.IsElapsed())
	{
		if (state == PS_Victory)
		{
			this->currentState = MinigameState::MGS_Victory;
		}
		else
		{
			this->currentState = MinigameState::MGS_Loss;
		}
	}
}

void Pinball::SpawnBall(bool isFree)
{
	if (!isFree)
	{
		lives--;
	}
	for (int i = 0; i < livesCounter.size(); i++)
	{
		livesCounter[i]->SetEnabled(i < lives);
	}
	ballVelocity = { 0.0f, 0.0f, 0.0f };
	float randOffset = RandomFloat(50.0f, 120.0f);
	ball->SetPositionGlobal({ (RandomFloat(0.0, 1.0f) < 0.5 ? 320.0f - randOffset : 320.0f + randOffset), 290.0f });
	resetSW.Start();
	ballStuckPosition = ball->GetPositionGlobal();
}

void Pinball::AddScore(int score, MinigameManagerData data)
{
	totalScore += score * scoreMult;
	std::string text = "Score:\n";
	text.append(std::to_string(totalScore));
	text.append("\nGoal:\n");
	text.append(std::to_string(goalScore));
	scoreBox->UpdateText(text);
	if (totalScore >= goalScore)
	{
		Win(data);
	}
}

void Pinball::Win(MinigameManagerData data)
{
	state = PS_Victory;
	endIcon->anim = data.icons->GetAnim(MGI_Green_Check);
	endIcon->SetEnabled(true);
	endTimer.Start(2.0f);
}

void Pinball::Lose(MinigameManagerData data)
{
	state = PS_Defeat;
	endIcon->anim = data.icons->GetAnim(MGI_Red_X);
	endIcon->SetEnabled(true);
	endTimer.Start(2.0f);
}

void Pinball::OnCleanup(MinigameManagerData data)
{
	boardObjs.clear();
	boardObjsNoFlippers.clear();
	livesCounter.clear();
	//normObjs.clear();
	//colPtObjs.clear();
}

void Pinball::CreateHierarchy(MinigameManagerData data)
{
	float ballDiameter = ballRadius * 2.0f;

	AddDPadToHierarchy(RIF_ANY_D_PAD, { 65.0f, 130.0f, 0.0f }, 45.0f, *data.icons, *data.hierarchy);

	drain = data.hierarchy->CreateNode("Drain");
	drain->SetPositionGlobal({ 320.0f, 450.0f });
	data.collision->AddCollision(drain, std::make_shared<PolygonCollider>(NJS_POINT3({ 200.0f, 50.0f })));

	//Basic pinball walls
	boardParent = data.hierarchy->CreateNode("Board_Parent");
	SpriteNode* wall_1 = data.hierarchy->CreateNode("Static", data.icons->GetAnim(MGI_White_Box), { 5.0f, 256.0f }, {120.0f, 261.5f }, boardParent);
	data.collision->AddCollision(wall_1, std::make_shared<PolygonCollider>(NJS_POINT3({ 5.0f, 256.0f })));
	boardObjs.push_back(wall_1);
	SpriteNode* wall_2 = data.hierarchy->CreateNode("Static", data.icons->GetAnim(MGI_White_Box), { 5.0f, 256.0f }, { 520.0f, 261.5f }, boardParent);
	data.collision->AddCollision(wall_2, std::make_shared<PolygonCollider>(NJS_POINT3({ 5.0f, 256.0f })));
	boardObjs.push_back(wall_2);
	SpriteNode* wall_3 = data.hierarchy->CreateNode("Static", data.icons->GetAnim(MGI_White_Box), { 160.0f, 5.0f }, { 196.0f, 400.0f }, boardParent);
	data.collision->AddCollision(wall_3, std::make_shared<PolygonCollider>(NJS_POINT3({ 160.0f, 5.0f })));
	wall_3->SetRotation(9.5f);
	boardObjs.push_back(wall_3);
	SpriteNode* wall_4 = data.hierarchy->CreateNode("Static", data.icons->GetAnim(MGI_White_Box), { 160.0f, 5.0f }, { 444.0f, 400.0f }, boardParent);
	data.collision->AddCollision(wall_4, std::make_shared<PolygonCollider>(NJS_POINT3({ 160.0f, 5.0f })));
	wall_4->SetRotation(-9.5f);
	boardObjs.push_back(wall_4);
	SpriteNode* wall_5 = data.hierarchy->CreateNode("Static", data.icons->GetAnim(MGI_White_Box), { 203.0f, 5.0f }, { 220.0f, 120.0f }, boardParent);
	data.collision->AddCollision(wall_5, std::make_shared<PolygonCollider>(NJS_POINT3({ 203.0f, 5.0f })));
	wall_5->SetRotation(-9.5f);
	boardObjs.push_back(wall_5);
	SpriteNode* wall_6 = data.hierarchy->CreateNode("Static", data.icons->GetAnim(MGI_White_Box), { 203.0f, 5.0f }, { 420.0f, 120.0f }, boardParent);
	data.collision->AddCollision(wall_6, std::make_shared<PolygonCollider>(NJS_POINT3({ 203.0f, 5.0f })));
	wall_6->SetRotation(9.5f);
	boardObjs.push_back(wall_6);
	SpriteNode* wall_7 = data.hierarchy->CreateNode("Static", data.icons->GetAnim(MGI_White_Box), { 120.0f, 5.0f }, { 207.0f, 372.9f }, boardParent);
	data.collision->AddCollision(wall_7, std::make_shared<PolygonCollider>(NJS_POINT3({ 120.0f, 5.0f })));
	wall_7->SetRotation(9.5f);
	boardObjs.push_back(wall_7);
	SpriteNode* wall_8 = data.hierarchy->CreateNode("Static", data.icons->GetAnim(MGI_White_Box), { 120.0f, 5.0f }, { 433.0f, 372.9f }, boardParent);
	data.collision->AddCollision(wall_8, std::make_shared<PolygonCollider>(NJS_POINT3({ 120.0f, 5.0f })));
	wall_8->SetRotation(-9.5f);
	boardObjs.push_back(wall_8);
	SpriteNode* wall_9 = data.hierarchy->CreateNode("Static", data.icons->GetAnim(MGI_White_Box), { 5.0f, 50.0f }, { 150.0f, 340.0f }, boardParent);
	data.collision->AddCollision(wall_9, std::make_shared<PolygonCollider>(NJS_POINT3({ 5.0f, 50.0f })));
	boardObjs.push_back(wall_9);
	SpriteNode* wall_10 = data.hierarchy->CreateNode("Static", data.icons->GetAnim(MGI_White_Box), { 5.0f, 50.0f }, { 490.0f, 340.0f }, boardParent);
	data.collision->AddCollision(wall_10, std::make_shared<PolygonCollider>(NJS_POINT3({ 5.0f, 50.0f })));
	boardObjs.push_back(wall_10);
	//Tri-Bumpers
	SpriteNode* triBump_0 = data.hierarchy->CreateNode("TriBumper", data.icons->GetAnim(MGI_Tri_Bumper_Right), { 85.0f, 30.0f }, { 197.0f, 326.0f }, boardParent);
	data.collision->AddCollision(triBump_0, std::make_shared<PolygonCollider>(std::vector<NJS_POINT3>({ {-42.0f, 14.5f}, {42.0f, 14.5f}, {21.0f, -15.0f} })));
	triBump_0->SetRotation(220.0f);
	boardObjs.push_back(triBump_0);
	data.hierarchy->CreateNode("Star", data.icons->GetAnim(MGI_Star), { 12.0f, 12.0f }, { 197.0f - 15.0f, 317.0f }, boardParent);
	SpriteNode* triBump_1 = data.hierarchy->CreateNode("TriBumper", data.icons->GetAnim(MGI_Tri_Bumper_Left), { 85.0f, 30.0f }, { 443.0f, 326.0f }, boardParent);
	data.collision->AddCollision(triBump_1, std::make_shared<PolygonCollider>(std::vector<NJS_POINT3>({ {-42.0f, 14.5f}, {42.0f, 14.5f}, {-21.0f, -15.0f} })));
	triBump_1->SetRotation(140.0f);
	boardObjs.push_back(triBump_1);
	data.hierarchy->CreateNode("Star", data.icons->GetAnim(MGI_Star), { 12.0f, 12.0f }, { 443.0f + 15.0f, 317.0f }, boardParent);
	//Circle Bumpers
	SpriteNode* Bump_0 = data.hierarchy->CreateNode("Bumper", data.icons->GetAnim(MGI_Bumper), { 40.0f, 40.0f }, { 185.0f, 210.0f }, boardParent);
	data.collision->AddCollision(Bump_0, std::make_shared<CircleCollider>(20.0f, NJS_POINT3({ 0.0f, 0.0f })));
	boardObjs.push_back(Bump_0);
	SpriteNode* Bump_1 = data.hierarchy->CreateNode("Bumper", data.icons->GetAnim(MGI_Bumper), { 40.0f, 40.0f }, { 270.0f, 165.0f }, boardParent);
	data.collision->AddCollision(Bump_1, std::make_shared<CircleCollider>(20.0f, NJS_POINT3({ 0.0f, 0.0f })));
	boardObjs.push_back(Bump_1);
	SpriteNode* Bump_2 = data.hierarchy->CreateNode("Bumper", data.icons->GetAnim(MGI_Bumper), { 40.0f, 40.0f }, { 370.0f, 165.0f }, boardParent);
	data.collision->AddCollision(Bump_2, std::make_shared<CircleCollider>(20.0f, NJS_POINT3({ 0.0f, 0.0f })));
	boardObjs.push_back(Bump_2);
	SpriteNode* Bump_3 = data.hierarchy->CreateNode("Bumper", data.icons->GetAnim(MGI_Bumper), { 40.0f, 40.0f }, { 455.0f, 210.0f }, boardParent);
	data.collision->AddCollision(Bump_3, std::make_shared<CircleCollider>(20.0f, NJS_POINT3({ 0.0f, 0.0f })));
	boardObjs.push_back(Bump_3);
	
	for (int i = 0; i < boardObjs.size(); i++)
	{
		boardObjsNoFlippers.push_back(boardObjs[i]);
	}

	//Create Flippers
	leftFlipper = data.hierarchy->CreateNode("Flipper", boardParent);
	leftFlipper->SetPositionGlobal({ 265.75f, 382.76f });
	SpriteNode* leftFlipperImage = data.hierarchy->CreateNode("LeftFlipper", data.icons->GetAnim(MGI_Flipper), { 5.0f, flipperLength }, { 0.0f, 0.0f }, leftFlipper);
	leftFlipperImage->SetPosition({ flipperLength * 0.64f, 0.0f });
	leftFlipperImage->SetRotation(90.0f);
	//data.collision->AddCollision(leftFlipper, std::make_shared<CapsuleCollider>(2.4f, leftFlipper, NJS_POINT3({ 0.0f, 0.0f }), NJS_POINT3({ flipperLength - 2.4f, 0.0f })));
	data.collision->AddCollision(leftFlipper, std::make_shared<PolygonCollider>(std::vector<NJS_POINT3>({ {-0.2f, 2.4f}, {flipperLength, 0.0f}, {-0.2f, -2.4f} })));
	leftFlipper->SetRotation(9.5f);
	boardObjs.push_back(leftFlipper);

	rightFlipper = data.hierarchy->CreateNode("Flipper", boardParent);
	rightFlipper->SetPositionGlobal({ 374.25f, 382.76 });
	SpriteNode* rightFlipperImage = data.hierarchy->CreateNode("LeftFlipper", data.icons->GetAnim(MGI_Flipper), { 5.0f, flipperLength }, { 0.0f, 0.0f }, rightFlipper);
	rightFlipperImage->SetPosition({ flipperLength * 0.64f, 0.0f });
	rightFlipperImage->SetRotation(90.0f);
	//data.collision->AddCollision(rightFlipper, std::make_shared<CapsuleCollider>(2.4f, rightFlipper, NJS_POINT3({ 0.0f, 0.0f }), NJS_POINT3({ flipperLength - 2.4f, 0.0f })));
	data.collision->AddCollision(rightFlipper, std::make_shared<PolygonCollider>(std::vector<NJS_POINT3>({ {-0.2f, 2.4f}, {flipperLength, 0.0f}, {-0.2f, -2.4f} })));
	rightFlipper->SetRotation(-189.5f);
	boardObjs.push_back(rightFlipper);

	ball = data.hierarchy->CreateNode("Ball", data.icons->GetAnim(MGI_Spinball), { ballDiameter, ballDiameter }, { 320.0f, 290.0f });
	data.collision->AddCollision(ball, std::make_shared<CircleCollider>(ballRadius, NJS_POINT3({ 0.0f, 0.0f })));
	ball->components.push_back(new Rotator(ballRotationDelta));

	for (int i = 0; i < lives; i++)
	{
		SpriteNode* lifeIcon = data.hierarchy->CreateNode("LifeIcon", data.icons->GetAnim(MGI_Life_Box), { 24.0f, 24.0f }, { 545.0f, 350.0f - (i * (24.0f + 2.0f)) });
		livesCounter.push_back(lifeIcon);
	}

	scoreBoxNode = data.hierarchy->CreateNode("Score Box");
	scoreBoxNode->SetPositionGlobal({ 540.0f, 100.0f});
	scoreBox = new TextBox("", 20.0f, TextAlignment::Left, data.text);
	scoreBoxNode->renderComponents.push_back(scoreBox);
	AddScore(0, data);

	countdownNode = data.hierarchy->CreateNode("Coundown");
	countdownNode->SetPositionGlobal({ data.icons->xCenter, 100.0f });
	countdownBox = new TextBox("3", 100.0f, TextAlignment::Center, data.text);
	countdownNode->renderComponents.push_back(countdownBox);

	endIcon = data.hierarchy->CreateNode("End Icon", data.icons->GetAnim(MGI_Green_Check), { 400.0f, 400.0f }, {data.icons->xCenterSafe, data.icons->yCenterSafe});
	endIcon->color.a = 0.0f;
	endIcon->SetEnabled(false);

	//DEBUG
	/*
	for (int i = 0; i < 10; i++)
	{
		SpriteNode* normObj = data.hierarchy->CreateNode("Norm", data.icons->GetAnim(MGI_White_Box), { 2.0f, 15.0f }, { 0.0f, 0.0f }, boardParent);
		normObj->color = { 1.0f, 1.0f, 0.0f, 0.0f };
		normObj->SetEnabled(false);
		normObjs.push_back(normObj);
		SpriteNode* ptObj = data.hierarchy->CreateNode("Pt", data.icons->GetAnim(MGI_Circle), { 4.0f, 4.0f }, { 0.0f, 0.0f }, boardParent);
		ptObj->color = { 1.0f, 0.0f, 1.0f, 0.0f };
		ptObj->SetEnabled(false);
		colPtObjs.push_back(ptObj);
	}
	*/
}
