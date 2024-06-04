#include "../../../pch.h"
#include "MinigameFinalBoss.h"
#include <math.h>

void MinigameFinalBoss::OnGameStart(MinigameManagerData data)
{
	ResetMusic();
	PlayMusic("mg_boss.adx");
	currentState = MGS_InProgress;
	state = FBS_Intro;
	introState = FBIS_FadeIn;
	sonicIsActive = true;
	bossHealth = bossMaxHealth;
	sonicRingCount = 50;
	shadowRingCount = 50;
	characterShootTimer.Start(0.0f);
	ringDecayTimer.Start(0.0f);
	ringGrowthTimer.Start(0.0f);
	weakPointTimer.Start(0.0f);
	sequenceTimer.Start(0.0f);
	data.timers->push_back(&characterShootTimer);
	data.timers->push_back(&ringDecayTimer);
	data.timers->push_back(&ringGrowthTimer);
	data.timers->push_back(&weakPointTimer);
	data.timers->push_back(&sequenceTimer);
	for (int i = 0; i < patternProgress.size(); i++)
	{
		patternProgress[i] = BossPatternRuntimeData();
		data.timers->push_back(&patternProgress[i].timer);
	}
	for (int i = 0; i < beamProgress.size(); i++)
	{
		beamProgress[i] = BossBeamRuntimeData();
		data.timers->push_back(&beamProgress[i].timer);
	}
	weakSpotIndex = 0;
	sequenceIndex = 0;
	ringEmitterIndex = 0;
	std::shuffle(weakPointPositions.begin(), weakPointPositions.end(), RNG());
	std::shuffle(earlySequences.begin(), earlySequences.end(), RNG());
	std::shuffle(lateSequences.begin(), lateSequences.end(), RNG());
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
			RunWin(data);
			break;
		case FBS_Loss:
			RunLose(data);
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
		currentSequence = nullptr;
		sequenceTimer.Start(RandomFloat(1.0f, 2.0f));
		background->color.a = 1.0f;
		leftBar->color.a = 1.0f;
		rightBar->color.a = 1.0f;
		state = FBS_InGame;
	}
	switch (introState)
	{
	case FBIS_FadeIn:
		if (background->color.a < 1.0f)
		{
			float a = min(background->color.a + 0.05f, 1.0f);
			background->color.a = a;
			leftBar->color.a = a;
			rightBar->color.a = a;
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
			currentSequence = nullptr;
			sequenceTimer.Start(RandomFloat(1.0f, 2.0f));
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
	UpdateSequence();
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
	CheckCharacterCollision(data);
	UpdateCharacterRingGrowthDecay(data);
}

void MinigameFinalBoss::RunSwap(MinigameManagerData data)
{
	characterShootTimer.Pause();
	ringDecayTimer.Pause();
	ringGrowthTimer.Pause();
	weakPointTimer.Pause();
	sequenceTimer.Pause();
	for (int i = 0; i < patternProgress.size(); i++)
	{
		patternProgress[i].timer.Pause();
	}
	for (int i = 0; i < beamProgress.size(); i++)
	{
		beamProgress[i].timer.Pause();
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
		weakPointTimer.Resume();
		sequenceTimer.Resume();
		for (int i = 0; i < patternProgress.size(); i++)
		{
			patternProgress[i].timer.Resume();
		}
		for (int i = 0; i < beamProgress.size(); i++)
		{
			beamProgress[i].timer.Resume();
		}
	}
}

void MinigameFinalBoss::RunWin(MinigameManagerData data)
{
	UpdateBullets(data);
	if (sequenceTimer.IsElapsed())
	{
		currentState = MGS_Victory;
	}
}

void MinigameFinalBoss::RunLose(MinigameManagerData data)
{
	UpdateBullets(data);
	if (sequenceTimer.IsElapsed())
	{
		currentState = MGS_Loss;
	}
}

void MinigameFinalBoss::Victory(MinigameManagerData data)
{
	for (int i = 0; i < beamProgress.size(); i++)
	{
		beamProgress[i].node->SetEnabled(false);
		beamProgress[i].active = false;
		beamProgress[i].collisionActive = false;
	}
	endText->UpdateText("Victory!");
	endTextNode->SetEnabled(true);
	sequenceTimer.Start(2.0f);
	FHExplosionEmitter->Play();
	state = FBS_Win;
}

void MinigameFinalBoss::Defeat(MinigameManagerData data)
{
	for (int i = 0; i < beamProgress.size(); i++)
	{
		beamProgress[i].node->SetEnabled(false);
		beamProgress[i].active = false;
		beamProgress[i].collisionActive = false;
	}
	endText->UpdateText("Defeat");
	endTextNode->SetEnabled(true);
	sequenceTimer.Start(2.0f);
	state = FBS_Loss;
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
				if (bossHealth <= 0.0f)
				{
					Victory(data);
				}
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
	if (shadowRingCount <= 0 || sonicRingCount <= 0)
	{
		Defeat(data);
	}
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

void MinigameFinalBoss::UpdateSequence()
{
	if (currentSequence == nullptr)
	{
		if (sequenceTimer.IsElapsed())
		{
			if (bossHealth / bossMaxHealth >= 0.5f)
			{
				if (sequenceIndex >= earlySequences.size())
				{
					sequenceIndex = 0;
				}
				currentSequence = &earlySequences[sequenceIndex];
			}
			else
			{
				if (sequenceIndex >= lateSequences.size())
				{
					sequenceIndex = 0;
				}
				currentSequence = &lateSequences[sequenceIndex];
			}
			sequenceIndex++;
			for (int i = 0; i < patternProgress.size(); i++)
			{
				bool active = i < currentSequence->patterns.size();
				patternProgress[i].active = active;
				if (active)
				{
					BossBulletPattern* pattern = &patterns[currentSequence->patterns[i].dataIndex];
					patternProgress[i].count = 0;
					patternProgress[i].timer.Start(currentSequence->patterns[i].initialDelay);
					//NJS_POINT3 spawn = bulletSpawns[currentSequence->patterns[i].spawnPoint];
					//patternProgress[i].characterStart = Point3Normalize(Point3Substract(characterParent->GetPositionGlobal(), spawn));
					patternProgress[i].increasing = pattern->startIncrementing;
					patternProgress[i].rotation = pattern->startAngle;
				}
			}
			for (int i = 0; i < beamProgress.size(); i++)
			{
				bool active = i < currentSequence->beams.size();
				beamProgress[i].active = active;
				if (active)
				{
					beamProgress[i].currentRotation = 0.0f;
					beamProgress[i].toRotation = 0.0f;
					beamProgress[i].progress = -1;
					beamProgress[i].timer.Start(currentSequence->beams[i].initialDelay);
				}
			}
		}
	}
	else
	{
		bool anyActive = false;
		for (int i = 0; i < patternProgress.size(); i++)
		{
			if (patternProgress[i].active)
			{
				anyActive = true;
			}
		}
		for (int i = 0; i < beamProgress.size(); i++)
		{
			if (beamProgress[i].active)
			{
				anyActive = true;
			}
		}
		if (!anyActive)
		{
			currentSequence = nullptr;
			sequenceTimer.Start(RandomFloat(2.5f, 3.5f));
		}
	}
	for (int i = 0; i < patternProgress.size(); i++)
	{
		if (patternProgress[i].active)
		{
			UpdatePattern(i);
		}
	}
	for (int i = 0; i < beamProgress.size(); i++)
	{
		if (beamProgress[i].active)
		{
			UpdateBeam(i);
		}
	}
}

void MinigameFinalBoss::UpdatePattern(int index)
{
	if (!currentSequence || index >= currentSequence->patterns.size()) return;
	BossBulletPattern* pattern = &patterns[currentSequence->patterns[index].dataIndex];
	NJS_POINT3 spawn = bulletSpawns[currentSequence->patterns[index].spawnPoint];
	while (patternProgress[index].timer.IsElapsed() && patternProgress[index].count < pattern->bulletCount)
	{
		float rotation = patternProgress[index].rotation;
		NJS_POINT3 down = { 0.0f, 1.0f };
		switch (pattern->aimType)
		{
		case BAT_CharacterContinuous:
			down = Point3Normalize(Point3Substract(characterParent->GetPositionGlobal(), spawn));
			break;
		case BAT_CharacterStart:
			if (patternProgress[index].count == 0)
			{
				patternProgress[index].characterStart = Point3Normalize(Point3Substract(characterParent->GetPositionGlobal(), spawn));
			}
			down = patternProgress[index].characterStart;
			break;
		}
		down = Point3RotateAround(down, { 0.0f,0.0f }, rotation);

		for (int i = 0; i < bossBullets.size(); i++)
		{
			if (!bossBullets[i].node->IsEnabled())
			{
				bossBullets[i].velocity = Point3Scale(down, enemyBulletSpeed);
				bossBullets[i].node->SetPositionGlobal(spawn);
				bossBullets[i].node->SetEnabled(true);
				break;
			}
		}
		
		rotation += patternProgress[index].increasing ? pattern->angleBetween : -pattern->angleBetween;

		if (pattern->pingPong)
		{
			if (rotation < pattern->minAngle)
			{
				rotation += pattern->minAngle - rotation;
				patternProgress[index].increasing = !patternProgress[index].increasing;
			}
			if (rotation > pattern->maxAngle)
			{
				rotation -= rotation - pattern->maxAngle;
				patternProgress[index].increasing = !patternProgress[index].increasing;
			}
		}
		else
		{
			if (patternProgress[index].increasing && rotation > pattern->maxAngle)
			{
				rotation = pattern->minAngle + (rotation - pattern->maxAngle);
			}
			if (!patternProgress[index].increasing && rotation < pattern->minAngle)
			{
				rotation = pattern->maxAngle - (pattern->minAngle - rotation);
			}
		}

		patternProgress[index].rotation = rotation;
		patternProgress[index].timer.Start(pattern->timeBetween);
		patternProgress[index].count++;
		patternProgress[index].active = patternProgress[index].count < pattern->bulletCount;
	}
}

void MinigameFinalBoss::UpdateBeam(int index)
{
	if (!currentSequence || index >= currentSequence->beams.size()) return;
	BossBeamSequence* beamSequence = &beamSequences[currentSequence->beams[index].dataIndex];
	float distance = abs(beamProgress[index].toRotation - beamProgress[index].currentRotation);
	if (beamProgress[index].timer.IsElapsed() && distance < 0.01f)
	{
		if (beamProgress[index].progress == -1)
		{
			//initialize beam
			if (beamSequence->startAimAtPlayer)
			{
				NJS_POINT3 toCharacter = Point3Normalize(Point3Substract(characterParent->GetPositionGlobal(), bossBeamParent->GetPositionGlobal()));
				float ang = atan2(toCharacter.y, toCharacter.x) - atan2(1.0f, 0.0f);
				ang = NJM_RAD_DEG(ang);
				while (ang > 180.0f) ang -= 360.0f;
				while (ang < -180.0f) ang += 360.0f;
				beamProgress[index].currentRotation = ang;
			}
			else
			{
				beamProgress[index].currentRotation = beamSequence->startAngle;
			}
			beamProgress[index].toRotation = beamProgress[index].currentRotation;
			beamProgress[index].node->SetEnabled(true);
		}
		beamProgress[index].progress++;
		if (beamProgress[index].progress < beamSequence->sequence.size())
		{
			switch (beamSequence->sequence[beamProgress[index].progress].type)
			{
			case BST_Hold:
				beamProgress[index].timer.Start(beamSequence->sequence[beamProgress[index].progress].time);
				break;
			case BST_RotateToAngle:
				beamProgress[index].toRotation = beamSequence->sequence[beamProgress[index].progress].angle;
				break;
			}
			beamProgress[index].collisionActive = beamSequence->sequence[beamProgress[index].progress].active;
			beamProgress[index].node->color.a = beamProgress[index].collisionActive ? 1.0f : 0.2f;
		}
		else
		{
			beamProgress[index].node->SetEnabled(false);
			beamProgress[index].active = false;
			beamProgress[index].collisionActive = false;
		}
	}
	if (beamProgress[index].active)
	{
		if (beamProgress[index].progress >=0 && beamProgress[index].toRotation != beamProgress[index].currentRotation)
		{
			float dist = beamSequence->sequence[beamProgress[index].progress].speed / 60.0f;
			dist = min(dist, distance);
			beamProgress[index].currentRotation += beamProgress[index].toRotation > beamProgress[index].currentRotation ? dist : -dist;
		}
		beamProgress[index].node->SetRotation(beamProgress[index].currentRotation);
	}
}

void MinigameFinalBoss::CheckCharacterCollision(MinigameManagerData data)
{
	if (remainingIFrames <= 0)
	{
		SpriteNode* currentCharacter = sonicIsActive ? sonic : shadow;
		bool isHit = false;
		for (int i = 0; i < bossBullets.size(); i++)
		{
			if (!isHit && bossBullets[i].node->IsEnabled() && data.collision->IsColliding(currentCharacter, bossBullets[i].node))
			{
				OnCharacterHit();
				isHit = true;
			}
		}
		for (int i = 0; i < beamProgress.size(); i++)
		{
			if (!isHit && beamProgress[i].collisionActive && data.collision->IsColliding(currentCharacter, beamProgress[i].node))
			{
				OnCharacterHit();
				isHit = true;
			}
		}

	}
	else
	{
		remainingIFrames--;
	}
	sonic->color = (sonicIsActive && remainingIFrames > 0) ? NJS_ARGB({0.6f, 1.0f, 0.5f, 0.5f}) : NJS_ARGB({1.0f, 1.0f, 1.0f, 1.0f});
	shadow->color = (!sonicIsActive && remainingIFrames > 0) ? NJS_ARGB({ 0.6f, 1.0f, 0.5f, 0.5f }) : NJS_ARGB({ 1.0f, 1.0f, 1.0f, 1.0f });
}

void MinigameFinalBoss::OnCharacterHit()
{
	ringEmitters[ringEmitterIndex]->Play();
	ringEmitterIndex++;
	if (ringEmitterIndex >= ringEmitters.size())
	{
		ringEmitterIndex = 0;
	}
	remainingIFrames = onHitIFrames;
	if (sonicIsActive)
	{
		sonicRingCount -= onHitRingDamage;
		sonicRingCount = max(sonicRingCount, 0);
	}
	else
	{
		shadowRingCount -= onHitRingDamage;
		shadowRingCount = max(shadowRingCount, 0);
	}
}

void MinigameFinalBoss::CreateHierarchy(MinigameManagerData data)
{
	//Create Background
	background = data.hierarchy->CreateNode("BG", data.icons->GetAnim(MGI_White_Box), { data.icons->xMax - data.icons->xMin + 2.0f, data.icons->yMax + 2.0f, 0.0f }, { data.icons->xCenter, data.icons->yCenter, 0.0f });
	background->color = { 0.0f, 0.0f, 0.0f, 0.0f };

	//Create Boss Beams
	bossBeamParent = data.hierarchy->CreateNode("Boss_Beams");
	bossBeamParent->SetPositionGlobal({ 320.0f, 0.0f });
	for (int i = 0; i < beamProgress.size(); i++)
	{
		beamProgress[i].node = data.hierarchy->CreateNode("Boss_Beam", bossBeamParent);
		beamProgress[i].node->components.push_back(new AssignColorToChildren());
		beamProgress[i].node->SetPosition({ 0.0f, 0.0f });
		float height = 0.0f;
		float startY = (beamWidth * 0.5f);
		while (height < 600.0f)
		{
			SpriteNode* beamNode = data.hierarchy->CreateNode("Beam_Chunk", data.icons->GetAnim(MGI_Bio_Beam), { beamWidth, beamWidth }, {}, beamProgress[i].node);
			beamNode->SetPosition({ 0.0f, startY });
			startY += beamWidth;
			height += beamWidth;
		}
		data.collision->AddCollision(beamProgress[i].node, std::make_shared<PolygonCollider>(NJS_POINT3({ beamWidth, 600.0f }), 0.0f, NJS_POINT3({ 0.0f, 300.0f })));
		beamProgress[i].node->SetEnabled(false);
	}

	//Create Boss Bullets
	bossBulletParent = data.hierarchy->CreateNode("Boss_Bullets");
	bossBullets.clear();
	for (int i = 0; i < 100; i++)
	{
		MinigameBulletData bullet{};
		bullet.node = data.hierarchy->CreateNode("Boss_Bullet", data.icons->GetAnim(MGI_Bio_Bullet), bossBulletSize, {}, bossBulletParent);
		bullet.node->SetEnabled(false);
		data.collision->AddCollision(bullet.node, std::make_shared<CircleCollider>(bossBulletSize.x * 0.5f, NJS_POINT3({ 0.0f, 0.0f })));
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

	FHExplostion = data.hierarchy->CreateNode("Final_Hazard_Explosion");
	FHExplostion->SetPositionGlobal({ 320.0f, 25.0f });
	FHExplosionEmitter = new ParticleEmitter();
	FHExplosionEmitter->anim = data.icons->GetAnim(MGI_Circle);
	FHExplosionEmitter->emitZoneType = PEZ_Box;
	FHExplosionEmitter->boxSize = { 300.0f, 50.0f };
	FHExplosionEmitter->particleTimeline = {
		{ 0.0f, ET_Linear, { 0.0f, 1.0f, 1.0f, 0.0f }, { 0.0f, 0.0f }},
		{ 0.2f, ET_CubicOut, { 1.0f, 1.0f, 1.0f, 0.0f }, { 30.0f, 30.0f }},
		{ 0.75f, ET_Linear, { 1.0f, 1.0f, 0.6f, 0.0f }, { 30.0f, 30.0f }},
		{ 1.0f, ET_CubicOut, { 0.0f, 1.0f, 0.4f, 0.0f }, { 30.0f, 30.0f }},
	};
	FHExplosionEmitter->looping = true;
	FHExplosionEmitter->rate = 15.0f;
	FHExplosionEmitter->particleDuration = 1.5f;
	FHExplostion->renderComponents.push_back(FHExplosionEmitter);

	//Create Character Bullets
	characterBulletParent = data.hierarchy->CreateNode("Character_Bullets");
	characterBullets.clear();
	for (int i = 0; i < 30; i++)
	{
		MinigameBulletData bullet{};
		bullet.node = data.hierarchy->CreateNode("Character_Bullet", data.icons->GetAnim(MGI_Super_Bullet), characterBulletSize, {}, characterBulletParent);
		bullet.node->SetEnabled(false);
		data.collision->AddCollision(bullet.node, std::make_shared<CircleCollider>(10.0f, NJS_POINT3({ 0.0f, -10.0f })));
		characterBullets.push_back(bullet);
	}

	//Create Characters
	characterParent = data.hierarchy->CreateNode("Characters");
	characterParent->SetPositionGlobal({ 320.f, 420.0f });
	characterParent->displaySize = { 48.0f, 48.0f };
	sonic = data.hierarchy->CreateNode("Sonic", data.icons->GetAnim(MGI_Super_Sonic), { 48.0f, 48.0f }, { 0.0f, 0.0f }, characterParent);
	sonic->SetPositionGlobal(sonicOffScreenPos);
	data.collision->AddCollision(sonic, std::make_shared<CircleCollider>(15.0f, NJS_POINT3({ 0.0f, -8.0f })));
	shadow = data.hierarchy->CreateNode("Shadow", data.icons->GetAnim(MGI_Super_Shadow), { 48.0f, 48.0f }, { 0.0f, 0.0f }, characterParent);
	shadow->SetPositionGlobal(shadowOffScreenPos);
	data.collision->AddCollision(shadow, std::make_shared<CircleCollider>(15.0f, NJS_POINT3({ 0.0f, -8.0f})));

	for (int i = 0; i < 5; i++)
	{
		ringEmitters[i] = new ParticleEmitter();
		ringEmitters[i]->anim = data.icons->GetAnim(MGI_Circle_Outline);
		ringEmitters[i]->emitZoneType = PEZ_Point;
		ringEmitters[i]->angleRange = { 160.0f, 200.0f };
		ringEmitters[i]->initialVelocityRange = { 60.0f, 65.0f };
		ringEmitters[i]->velocityRateMin = { 0.0f, 100.0f };
		ringEmitters[i]->velocityRateMax = { 0.0f, 150.0f };
		ringEmitters[i]->particleTimeline = {
			{ 0.0f, ET_Linear, { 1.0f, 1.0f, 1.0f, 0.0f }, { 0.0f, 0.0f }},
			{ 0.2f, ET_CubicOut, { 1.0f, 1.0f, 1.0f, 0.0f }, { 15.0f, 15.0f }},
			{ 0.75f, ET_Linear, { 1.0f, 1.0f, 1.0f, 0.0f }, { 15.0f, 15.0f }},
			{ 1.0f, ET_CubicOut, { 0.0f, 1.0f, 1.0f, 0.0f }, { 0.0f, 0.0f }},
		};
		ringEmitters[i]->looping = false;
		ringEmitters[i]->emitterDuration = 0.1f;
		ringEmitters[i]->rate = 50.0f;
		ringEmitters[i]->particleDuration = 2.5f;
		characterParent->renderComponents.push_back(ringEmitters[i]);
	}

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

	endTextNode = data.hierarchy->CreateNode("End_Text", nullptr, { 100.0f, 30.0f }, { 320.0f, 240.0f });
	endText = new TextBox("", 40.0f, TextAlignment::Center, data.text);
	endTextNode->renderComponents.push_back(endText);
	endTextNode->SetEnabled(false);

	//Create Background
	rightBar = data.hierarchy->CreateNode("Right_Bar", data.icons->GetAnim(MGI_White_Box), { abs(data.icons->xMin) + 2.0f, data.icons->yMax + 2.0f, 0.0f }, { 640.0f + ((data.icons->xMax - 640.0f) * 0.5f), data.icons->yCenter, 0.0f });
	rightBar->color = { 0.0f, 0.2f, 0.2f, 0.2f };

	leftBar = data.hierarchy->CreateNode("Left_Bar", data.icons->GetAnim(MGI_White_Box), { abs(data.icons->xMin) + 2.0f, data.icons->yMax + 2.0f, 0.0f }, { data.icons->xMin * 0.5f, data.icons->yCenter, 0.0f });
	leftBar->color = { 0.0f, 0.2f, 0.2f, 0.2f };
}

void MinigameFinalBoss::OnCleanup(MinigameManagerData data)
{
	bossBullets.clear();
	characterBullets.clear();
	for (int i = 0; i < patternProgress.size(); i++)
	{
		patternProgress[i] = BossPatternRuntimeData();
	}
	for (int i = 0; i < beamProgress.size(); i++)
	{
		beamProgress[i] = BossBeamRuntimeData();
	}
	for (int i = 0; i < ringEmitters.size(); i++)
	{
		ringEmitters[i] = nullptr;
	}
}