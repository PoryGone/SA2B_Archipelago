#include "../../../pch.h"
#include "MinigameFinalBoss.h"
#include <math.h>

void MinigameFinalBoss::OnGameStart(MinigameManagerData data)
{
	currentState = MGS_InProgress;
	state = FBS_Intro;
	introState = FBIS_FadeIn;
	sonicIsActive = true;
	bossHealth = bossMaxHealth;
	sonicRingCount = 50;
	shadowRingCount = 50;
	data.timers->push_back(&characterShootTimer);
	data.timers->push_back(&ringDecayTimer);
	data.timers->push_back(&ringGrowthTimer);
	data.timers->push_back(&weakPointTimer);
	weakSpotIndex = 0;
	std::shuffle(weakPointPositions.begin(), weakPointPositions.end(), RNG());
	for (int i = 0; i < patternTimers.size(); i++)
	{
		data.timers->push_back(&patternTimers[i]);
	}
	CreateHierarchy(data);
}

void MinigameFinalBoss::OnFrame(MinigameManagerData data)
{
	if (data.managerState == MGS_InProgress)
	{
		switch (state)
		{
		case FBS_Intro:
			RunIntro(data);
			break;
		case FBS_InGame:
			RunInGame(data);
			break;
		case FBS_Swap:
			RunSwap(data);
			break;
		case FBS_Win:

			break;
		case FBS_Loss:

			break;
		}
	}
	if (data.inputPress & RIF_Y)
	{
		currentState = MGS_Draw;
	}
}

void MinigameFinalBoss::RunIntro(MinigameManagerData data)
{
	if (data.inputPress & RIF_B)
	{
		sonic->SetPosition({ 0.0f, 0.0f });
		shadow->SetPosition({ 0.0f, 0.0f });
		shadow->SetEnabled(false);
		FHParent->SetPositionGlobal({ 320.0f, 0.0f });
		ringDecayTimer.Start(ringDecayCooldown);
		ringGrowthTimer.Start(ringGrowthCooldown);
		FHHealthBarBG->SetEnabled(true);
		state = FBS_InGame;
	}
	switch (introState)
	{
	case FBIS_FadeIn:
		if (background->color.a < 1.0f)
		{
			background->color.a = min(background->color.a + 0.05f, 1.0f);
		}
		else
		{
			introState = FBIS_CharacterEntrance;
		}
		break;
	case FBIS_CharacterEntrance:
		sonic->SetPositionGlobal(Point3MoveTowards(sonic->GetPositionGlobal(), { 230.0f , 420.0f }, characterSpeed));
		shadow->SetPositionGlobal(Point3MoveTowards(shadow->GetPositionGlobal(), { 410.0f , 420.0f }, characterSpeed));
		if (Point3Approximatly(sonic->GetPositionGlobal(), { 230.0f , 420.0f }) && Point3Approximatly(shadow->GetPositionGlobal(), { 410.0f , 420.0f }))
		{
			introState = FBIS_BossEntrance;
		}
		break;
	case FBIS_BossEntrance:
		if (FHParent->GetPositionGlobal().y < 0.0f)
		{
			FHParent->Translate({ 0.0f, 0.25f, 0.0f, });
		}
		else
		{
			introState = FBIS_CharacterToStart;
		}
		break;
	case FBIS_CharacterToStart:
		sonic->SetPosition(Point3MoveTowards(sonic->GetPosition(), { 0.0f , 0.0f }, characterSpeed * 2.0f));
		shadow->SetPositionGlobal(Point3MoveTowards(shadow->GetPositionGlobal(), shadowOffScreenPos, characterSpeed * 2.0f));
		if (Point3Approximatly(sonic->GetPosition(), { 0.0f , 0.0f }) && Point3Approximatly(shadow->GetPositionGlobal(), shadowOffScreenPos))
		{
			sonic->SetPosition({ 0.0f, 0.0f });
			shadow->SetEnabled(false);
			ringDecayTimer.Start(ringDecayCooldown);
			ringGrowthTimer.Start(ringGrowthCooldown);
			FHHealthBarBG->SetEnabled(true);
			state = FBS_InGame;
		}
		break;
	}
}

void MinigameFinalBoss::RunInGame(MinigameManagerData data)
{
	UpdateCharacterPosition(data);
	UpdateBullets(data);
	UpdateWeakPoint();
	if (data.input & RIF_A && characterShootTimer.IsElapsed())
	{
		CharacterShoot(data);
	}
	if (data.inputPress & RIF_B)
	{
		if (sonicIsActive)
		{
			shadow->SetPositionGlobal(shadowOffScreenPos);
		}
		else
		{
			sonic->SetPositionGlobal(sonicOffScreenPos);
		}
		sonicIsActive = !sonicIsActive;
		state = FBS_Swap;
	}
	UpdateCharacterRingGrowthDecay(data);
}

void MinigameFinalBoss::RunSwap(MinigameManagerData data)
{
	characterShootTimer.Pause();
	ringDecayTimer.Pause();
	ringGrowthTimer.Pause();
	weakPointTimer.Pause();
	for (int i = 0; i < patternTimers.size(); i++)
	{
		patternTimers[i].Pause();
	}
	sonic->SetEnabled(true);
	shadow->SetEnabled(true);
	NJS_POINT3 sonicToPos = sonicIsActive ? characterParent->GetPositionGlobal() : sonicOffScreenPos;
	NJS_POINT3 shadowToPos = sonicIsActive ? shadowOffScreenPos : characterParent->GetPositionGlobal();
	sonic->SetPositionGlobal(Point3MoveTowards(sonic->GetPositionGlobal(), sonicToPos, characterSpeed * 2.0f));
	shadow->SetPositionGlobal(Point3MoveTowards(shadow->GetPositionGlobal(), shadowToPos, characterSpeed * 2.0f));
	if (Point3Approximatly(sonic->GetPositionGlobal(), sonicToPos) && Point3Approximatly(shadow->GetPositionGlobal(), shadowToPos))
	{
		sonic->SetEnabled(sonicIsActive);
		shadow->SetEnabled(!sonicIsActive);
		state = FBS_InGame;
		characterShootTimer.Resume();
		ringDecayTimer.Resume();
		ringGrowthTimer.Resume();
		for (int i = 0; i < patternTimers.size(); i++)
		{
			patternTimers[i].Resume();
		}
	}
}

void MinigameFinalBoss::CharacterShoot(MinigameManagerData data)
{
	for (int i = 0; i < characterBullets.size(); i++)
	{
		if (!characterBullets[i].node->IsEnabled())
		{
			characterBullets[i].node->SetEnabled(true);
			characterBullets[i].node->SetPositionGlobal(characterParent->GetPositionGlobal());
			characterBullets[i].velocity = Point3Scale({ 0.0f,-1.0f }, characterBulletSpeed);
			characterShootTimer.Start(characterBulletCooldown);
			return;
		}
	}
}

void MinigameFinalBoss::UpdateBullets(MinigameManagerData data)
{
	//Character Bullets
	float yMin = 0.0f - (characterBulletSize.y * 0.5f) - 5.0f;
	float yMax = 480.0f + (characterBulletSize.y * 0.5f) + 5.0f;
	float xMin = 20.0f - (characterBulletSize.x * 0.5f) - 5.0f;
	float xMax = 620.0f + (characterBulletSize.x * 0.5f) + 5.0f;
	for (int i = 0; i < characterBullets.size(); i++)
	{
		if (characterBullets[i].node->IsEnabled())
		{
			characterBullets[i].node->Translate(characterBullets[i].velocity);
			if (data.collision->IsColliding(FHWeakPoint, characterBullets[i].node))
			{
				bossHealth -= 1.0f;
				characterBullets[i].node->SetEnabled(false);
				UpdateHealthBarFill();
			}
			NJS_POINT3 pos = characterBullets[i].node->GetPositionGlobal();
			if (pos.x < xMin || pos.x > xMax || pos.y < yMin || pos.y > yMax)
			{
				characterBullets[i].node->SetEnabled(false);
			}
		}
	}
	//Boss Bullets
	yMin = 0.0f - (bossBulletSize.y * 0.5f) - 5.0f;
	yMax = 480.0f + (bossBulletSize.y * 0.5f) + 5.0f;
	xMin = 20.0f - (bossBulletSize.x * 0.5f) - 5.0f;
	xMax = 620.0f + (bossBulletSize.x * 0.5f) + 5.0f;
	for (int i = 0; i < bossBullets.size(); i++)
	{
		if (bossBullets[i].node->IsEnabled())
		{
			bossBullets[i].node->Translate(bossBullets[i].velocity);
			NJS_POINT3 pos = bossBullets[i].node->GetPositionGlobal();
			if (pos.x < xMin || pos.x > xMax || pos.y < yMin || pos.y > yMax)
			{
				bossBullets[i].node->SetEnabled(false);
			}
		}
	}
}

void MinigameFinalBoss::UpdateCharacterPosition(MinigameManagerData data)
{
	float x = 0.0f;
	float y = 0.0f;
	if (data.input & RIF_Up)
	{
		y -= 1.0f;
	}
	if (data.input & RIF_Down)
	{
		y += 1.0f;
	}
	if (data.input & RIF_Left)
	{
		x -= 1.0f;
	}
	if (data.input & RIF_Right)
	{
		x += 1.0f;
	}
	if (x != 0.0f && y != 0.0f)
	{
		x *= 0.707f;
		y *= 0.707f;
	}
	characterParent->Translate(Point3Scale({ x, y }, characterSpeed));
	NJS_POINT3 pos = characterParent->GetPositionGlobal();
	x = characterParent->displaySize.x * 0.5f;
	y = characterParent->displaySize.y * 0.5f;
	pos.y = max(0.0f + y, pos.y);
	pos.y = min(480.0f - y, pos.y);
	pos.x = max(20.0f + x, pos.x);
	pos.x = min(620.0f - x, pos.x);
	characterParent->SetPositionGlobal(pos);
}

void MinigameFinalBoss::UpdateCharacterRingGrowthDecay(MinigameManagerData data)
{
	if (ringGrowthTimer.IsElapsed())
	{
		if (sonicIsActive)
		{
			shadowRingCount = shadowRingCount < 999 ? shadowRingCount + 1 : shadowRingCount;
		}
		else
		{
			sonicRingCount = sonicRingCount < 999 ? sonicRingCount + 1 : sonicRingCount;
		}
		ringGrowthTimer.Start(ringGrowthCooldown);
	}
	if (ringDecayTimer.IsElapsed())
	{
		if (sonicIsActive)
		{
			sonicRingCount = sonicRingCount > 0 ? sonicRingCount - 1 : sonicRingCount;
		}
		else
		{
			shadowRingCount = shadowRingCount > 0 ? shadowRingCount - 1 : shadowRingCount;
		}
		ringDecayTimer.Start(ringDecayCooldown);
	}
	std::string text = "Sonic\n";
	text.append(std::to_string(sonicRingCount));
	sonicRingsText->UpdateText(text);
	text = "Shadow\n";
	text.append(std::to_string(shadowRingCount));
	shadowRingsText->UpdateText(text);
}

void MinigameFinalBoss::UpdateWeakPoint()
{
	if (weakPointTimer.IsElapsed())
	{
		weakSpotIndex++;
		if (weakSpotIndex >= weakPointPositions.size())
		{
			weakSpotIndex = 0;
		}
		FHWeakPoint->SetPosition(weakPointPositions[weakSpotIndex]);
		FHWeakPoint->SetEnabled(true);
		weakPointTimer.Start(weakPointCooldown);
	}
}

void MinigameFinalBoss::UpdateHealthBarFill()
{
	float amount = bossHealth / bossMaxHealth;
	amount = amount < 0.0f ? 0.0f : amount;
	amount = amount > 1.0f ? 1.0f : amount;
	float width = FHHealthBarBG->displaySize.x * amount;
	float bgX = -(FHHealthBarBG->displaySize.x * 0.5f);
	NJS_POINT3 pos = { bgX + width * 0.5f, 0.0f};
	FHHealthBar->displaySize.x = width;
	FHHealthBar->SetPosition(pos);
}

void MinigameFinalBoss::CreateHierarchy(MinigameManagerData data)
{
	//Create Background
	background = data.hierarchy->CreateNode("BG", data.icons->GetAnim(MGI_White_Box), { data.icons->xMax - data.icons->xMin + 2.0f, data.icons->yMax + 2.0f, 0.0f }, { data.icons->xCenter, data.icons->yCenter, 0.0f });
	background->color = { 0.0f, 0.0f, 0.0f, 0.0f };

	//Create Boss Bullets
	bossBulletParent = data.hierarchy->CreateNode("Boss_Bullets");
	bossBullets.clear();
	for (int i = 0; i < 50; i++)
	{
		MinigameBulletData bullet{};
		bullet.node = data.hierarchy->CreateNode("Boss_Bullet", data.icons->GetAnim(MGI_Bio_Bullet), bossBulletSize, {}, characterBulletParent);
		bullet.node->SetEnabled(false);
		bossBullets.push_back(bullet);
	}

	//Create Boss
	FHParent = data.hierarchy->CreateNode("Final_Hazard_Parent");
	FHParent->SetPositionGlobal({ 320.0f, -120.0f });
	FHLArmBase = data.hierarchy->CreateNode("Final_Hazard_Arm_Base_L", FHParent);
	FHLArmBase->SetPosition({ -128.0f, 0.0f });
	FHLArmBase->SetRotation(320.0f);
	FHLWiggle = new Wiggle(0.25f, 310.0f, 330.0f, true);
	FHLArmBase->components.push_back(FHLWiggle);
	FHRArmBase = data.hierarchy->CreateNode("Final_Hazard_Arm_Base_R", FHParent);
	FHRArmBase->SetPosition({ 128.0f, 0.0f });
	FHRArmBase->SetRotation(40.0f);
	FHRWiggle = new Wiggle(0.25f, 30.0f, 50.0f, false);
	FHRArmBase->components.push_back(FHRWiggle);
	FHLArm = data.hierarchy->CreateNode("Final_Hazard_Arm_L", data.icons->GetAnim(MGI_Square), { 100.0f, 45.0f }, { 0.0f, 0.0f }, FHLArmBase);
	FHLArm->SetPosition({ -50.0f, 0.0f });
	FHLArm->color = { 1.0f, 1.0f, 0.5f, 0.0f };
	FHRArm = data.hierarchy->CreateNode("Final_Hazard_Arm_R", data.icons->GetAnim(MGI_Square), { 100.0f, 45.0f }, { 0.0f, 0.0f}, FHRArmBase);
	FHRArm->SetPosition({ 50.0f, 0.0f });
	FHRArm->color = { 1.0f, 1.0f, 0.5f, 0.0f };
	FHBody = data.hierarchy->CreateNode("Final_Hazard_Body", data.icons->GetAnim(MGI_Circle), { 300.0f, 100.0f }, { 0.0f, 0.0f }, FHParent);
	FHBody->SetPosition({ 0.0f, 0.0f });
	FHBody->color = { 1.0f, 1.0f, 0.5f, 0.0f };
	FHHead = data.hierarchy->CreateNode("Final_Hazard_Head", data.icons->GetAnim(MGI_Circle), { 75.0f, 100.0f }, { 0.0f, 0.0f }, FHParent);
	FHHead->SetPosition({ 0.0f, 60.0f });
	FHHead->color = { 1.0f, 1.0f, 0.5f, 0.0f };
	FHWeakPoint = data.hierarchy->CreateNode("Final_Hazard_Weak_Point", data.icons->GetAnim(MGI_Circle), { 50.0f,50.0f }, {}, FHParent);
	FHWeakPoint->SetEnabled(false);
	FHWeakPoint->color = { 1.0f, 1.0f, 0.0f, 0.0f };
	data.collision->AddCollision(FHWeakPoint, std::make_shared<CircleCollider>(25.0f));

	//Create Character Bullets
	characterBulletParent = data.hierarchy->CreateNode("Character_Bullets");
	characterBullets.clear();
	for (int i = 0; i < 30; i++)
	{
		MinigameBulletData bullet{};
		bullet.node = data.hierarchy->CreateNode("Character_Bullet", data.icons->GetAnim(MGI_Super_Bullet), characterBulletSize, {}, characterBulletParent);
		bullet.node->SetEnabled(false);
		data.collision->AddCollision(bullet.node, std::make_shared<CircleCollider>(10.0f, NJS_POINT3({ 0.0f, 10.0f })));
		characterBullets.push_back(bullet);
	}

	//Create Characters
	characterParent = data.hierarchy->CreateNode("Characters");
	characterParent->SetPositionGlobal({ 320.f, 420.0f });
	characterParent->displaySize = { 64.0f, 64.0f };
	sonic = data.hierarchy->CreateNode("Sonic", data.icons->GetAnim(MGI_Super_Sonic), { 64.0f, 64.0f }, { 0.0f, 0.0f }, characterParent);
	sonic->SetPositionGlobal(sonicOffScreenPos);
	data.collision->AddCollision(sonic, std::make_shared<CircleCollider>(20.0f, NJS_POINT3({ 0.0f, 7.0f })));
	shadow = data.hierarchy->CreateNode("Shadow", data.icons->GetAnim(MGI_Super_Shadow), { 64.0f, 64.0f }, { 0.0f, 0.0f }, characterParent);
	shadow->SetPositionGlobal(shadowOffScreenPos);
	data.collision->AddCollision(shadow, std::make_shared<CircleCollider>(20.0f, NJS_POINT3({ 0.0f, 7.0f})));

	//Create Health Bar
	FHHealthBarBG = data.hierarchy->CreateNode("Boss_Health_Bar_Background", data.icons->GetAnim(MGI_White_Box), { 200.0f, 10.0f }, { 320.0f, 6.0f });
	FHHealthBarBG->color = { 1.0f, 1.0f, 0.0f, 0.0f };
	FHHealthBarBG->SetEnabled(false);
	FHHealthBar = data.hierarchy->CreateNode("Boss_Health_Bar_Fill", data.icons->GetAnim(MGI_White_Box), { 200.0f, 10.0f }, { 320.0f, 6.0f }, FHHealthBarBG);
	FHHealthBar->color = { 1.0f, 0.0f, 0.0f, 1.0f };

	//Create Text
	sonicRings = data.hierarchy->CreateNode("Sonic_Rings", nullptr, { 100.0f, 30.0f }, { 70.0f, 450.0f });
	sonicRingsText = new TextBox("Sonic\n50", 15.0f, TextAlignment::Left, data.text);
	sonicRings->renderComponents.push_back(sonicRingsText);
	shadowRings = data.hierarchy->CreateNode("Shadow_Rings", nullptr, { 100.0f, 30.0f }, { 570.0f, 450.0f });
	shadowRingsText = new TextBox("Shadow\n50", 15.0f, TextAlignment::Right, data.text);
	shadowRings->renderComponents.push_back(shadowRingsText);
}