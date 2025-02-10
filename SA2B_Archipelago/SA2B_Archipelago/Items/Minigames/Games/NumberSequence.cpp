#include "../../../pch.h"
#include "NumberSequence.h"


void NumberSequence::OnGameStart(MinigameManagerData data)
{
	currentState = MGS_InProgress;
	this->endingTimer = 120;
	std::shuffle(numbers.begin(), numbers.end(), RNG());
	for (int i = 0; i < numberObjs.size(); i++)
	{
		numberObjs[i] = NumberSequenceNumber();
		numberObjs[i].correct = numbers[i];
		numberObjs[i].current = i + 1;
	}
	selectedIndex = 0;
	localState = NSS_Start;
	data.timers->push_back(&timer);

	switch (data.difficulty)
	{
	case MGD_Easy:
		guessTime = 35.0f;
		guessesRemaining = 9;
		break;
	case MGD_Medium:
		guessTime = 30.0f;
		guessesRemaining = 7;
		break;
	case MGD_Hard:
		guessTime = 25.0f;
		guessesRemaining = 5;
		break;
	}
	
	CreateHierarchy(data);
	SetSelectedIndex(selectedIndex);
	for (int i = 0; i < questionMarks.size(); i++)
	{
		questionMarks[i]->SetEnabled(i < guessesRemaining);
	}

	PlaySoundProbably((int)MinigameSounds::LevelStart, 0, 0, 0);
}

void NumberSequence::OnFrame(MinigameManagerData data)
{
	if (data.managerState != MGS_InProgress)
	{
		return;
	}
	switch (localState)
	{
	case NSS_Start:
		this->timer.Start(guessTime);
		localState = NSS_InGame;
		break;
	case NSS_InGame:
		this->UpdateTimerFill();
		if (data.inputPress & RIF_Up && selectedIndex < numberObjs.size())
		{
			Increment(&numberObjs[selectedIndex]);
		}
		if (data.inputPress & RIF_Down && selectedIndex < numberObjs.size())
		{
			Decrement(&numberObjs[selectedIndex]);
		}
		if ((data.inputPress & RIF_Up || data.inputPress & RIF_Down) && selectedIndex == numberObjs.size())
		{
			SubmitSequence();
		}
		if (data.inputPress & RIF_Left)
		{
			SetSelectedIndex(selectedIndex - 1);
		}
		if (data.inputPress & RIF_Right)
		{
			SetSelectedIndex(selectedIndex + 1);
		}
		if (this->timer.IsElapsed())
		{
			this->localState = NSS_Lose;
			this->timer.Start(1.0f);
		}
		break;
	case NSS_Win:
		if (this->resultNode->color.a < 1.0f)
		{
			this->resultNode->SetEnabled(true);
			this->resultNode->anim = data.icons->GetAnim(MGI_Green_Check);
			this->resultNode->color.a += 1.0f / 30.0f;
			this->resultNode->displaySize = Point3MoveTowards(this->resultNode->displaySize, { 128.0f, 128.0f }, 72.0f / 30.0f);
		}
		else
		{
			if (this->endingTimer == 120)
			{
				PlaySoundProbably((int)MinigameSounds::RankReveal, 0, 0, 0);
			}

			this->endingTimer--;

			if (this->endingTimer <= 0)
			{
				this->currentState = MinigameState::MGS_Victory;
			}
		}
		break;
	case NSS_Lose:
		if (this->resultNode->color.a < 1.0f)
		{
			this->resultNode->SetEnabled(true);
			this->resultNode->anim = data.icons->GetAnim(MGI_F_Rank);
			this->resultNode->color.a += 1.0f / 30.0f;
			this->resultNode->displaySize = Point3MoveTowards(this->resultNode->displaySize, { 128.0f, 128.0f }, 72.0f / 30.0f);
		}
		else
		{
			if (this->endingTimer == 120)
			{
				PlaySoundProbably((int)MinigameSounds::RankReveal, 0, 0, 0);
			}

			this->endingTimer--;

			if (this->endingTimer <= 0)
			{
				this->currentState = MinigameState::MGS_Loss;
			}
		}
		break;
	}
	
}

void NumberSequence::OnCleanup(MinigameManagerData data)
{
	for (int i = 0; i < numberObjs.size(); i++)
	{
		numberObjs[i].parent = nullptr;
		numberObjs[i].text = nullptr;
		numberObjs[i].upArrow = nullptr;
		numberObjs[i].downArrow = nullptr;
	}
	for (int i = 0; i < questionMarks.size(); i++)
	{
		questionMarks[i] = nullptr;
	}
}

void NumberSequence::Increment(NumberSequenceNumber* nsNumber)
{
	int n = nsNumber->current;
	bool searching = true;
	while (searching)
	{
		bool any = false;
		for (int i = 0; i < numberObjs.size(); i++)
		{
			if (n == numberObjs[i].current)
			{
				any = true;
			}
		}
		if (!any)
		{
			searching = false;
		}
		else
		{
			n = n < 9 ? n + 1 : 1;
		}
	}
	nsNumber->current = n;
	nsNumber->text->UpdateText(std::to_string(n));
	nsNumber->textNode->color = { 1.0f, 1.0f, 1.0f, 1.0f };
}

void NumberSequence::Decrement(NumberSequenceNumber* nsNumber)
{
	int n = nsNumber->current;
	bool searching = true;
	while (searching)
	{
		bool any = false;
		for (int i = 0; i < numberObjs.size(); i++)
		{
			if (n == numberObjs[i].current)
			{
				any = true;
			}
		}
		if (!any)
		{
			searching = false;
		}
		else
		{
			n = n > 1 ? n - 1 : 9;
		}
	}
	nsNumber->current = n;
	nsNumber->text->UpdateText(std::to_string(n));
	nsNumber->textNode->color = { 1.0f, 1.0f, 1.0f, 1.0f };
}

void NumberSequence::SetSelectedIndex(int index)
{
	if (index < 0)
	{
		index = 0;
	}
	if (index > numberObjs.size())
	{
		index = numberObjs.size();
	}
	selectedIndex = index;
	for (int i = 0; i < numberObjs.size(); i++)
	{
		numberObjs[i].upArrow->displaySize = i == selectedIndex ? bigArrowSize : smallArrowSize;
		numberObjs[i].downArrow->displaySize = i == selectedIndex ? bigArrowSize : smallArrowSize;
	}
	submitText->UpdateFontSize(selectedIndex == numberObjs.size() ? bigTextSize : smallTextSize);
	submitUp->displaySize = { 50.0f, selectedIndex == numberObjs.size() ? bigTextSize : smallTextSize };
	submitDown->displaySize = { 50.0f, selectedIndex == numberObjs.size() ? bigTextSize : smallTextSize };
}

bool NumberSequence::AnySequenceContains(int n)
{
	for (int i = 0; i < numberObjs.size(); i++)
	{
		if (n == numberObjs[i].correct)
		{
			return true;
		}
	}
	return false;
}

void NumberSequence::SubmitSequence()
{
	int correctCount = 0;
	for (int i = 0; i < numberObjs.size(); i++)
	{
		numberObjs[i].prevText->UpdateText(std::to_string(numberObjs[i].current));
		if (numberObjs[i].correct == numberObjs[i].current)
		{
			correctCount++;
			numberObjs[i].textNode->color = { 1.0f, 0.0f, 1.0f, 0.0f };
			numberObjs[i].prevTextNode->color = { 1.0f, 0.0f, 1.0f, 0.0f };
		}
		else if (AnySequenceContains(numberObjs[i].current))
		{
			numberObjs[i].textNode->color = { 1.0f, 1.0f, 1.0f, 0.0f };
			numberObjs[i].prevTextNode->color = { 1.0f, 1.0f, 1.0f, 0.0f };
		}
		else
		{
			numberObjs[i].textNode->color = { 1.0f, 1.0f, 0.0f, 0.0f };
			numberObjs[i].prevTextNode->color = { 1.0f, 1.0f, 0.0f, 0.0f };
		}
	}
	if (correctCount == numberObjs.size())
	{
		PlaySoundProbably((int)MinigameSounds::CollectEmblem, 0, 0, 0);
		this->localState = NSS_Win;
	}
	else if(guessesRemaining == 0)
	{
		PlaySoundProbably((int)MinigameSounds::Explosion, 0, 0, 0);
		this->localState = NSS_Lose;
	}
	else
	{
		PlaySoundProbably((int)MinigameSounds::MenuError, 0, 0, 0);
		guessesRemaining--;
		for (int i = 0; i < questionMarks.size(); i++)
		{
			questionMarks[i]->SetEnabled(i < guessesRemaining);
		}
	}
}

void NumberSequence::UpdateTimerFill()
{
	float amount = this->timer.TimeRemaining() / this->guessTime;
	amount = amount < 0.0f ? 0.0f : amount;
	amount = amount > 1.0f ? 1.0f : amount;
	float width = this->timerBarBG->displaySize.x * amount;
	float bgX = -(this->timerBarBG->displaySize.x * 0.5f);
	NJS_POINT3 pos = { bgX + width * 0.5f, 0.0f };
	this->timerBar->displaySize.x = width;
	this->timerBar->SetPosition(pos);

	NJS_POINT3 bombPos = this->timerBomb->GetPosition();
	bombPos.x = bgX + width;
	this->timerBomb->SetPosition(bombPos);
}

void NumberSequence::CreateHierarchy(MinigameManagerData data)
{
	AddDPadToHierarchy(RIF_ANY_D_PAD, { 65.0f, 130.0f, 0.0f }, 45.0f, *data.icons, *data.hierarchy);
	
	float xPos = 180.0f;
	for (int i = 0; i < numberObjs.size(); i++)
	{
		numberObjs[i].parent = data.hierarchy->CreateNode("Number_Parent");
		numberObjs[i].upArrow = data.hierarchy->CreateNode("Up_Arrow", data.icons->GetAnim(MGI_Triangle), smallArrowSize, { 0.0f, 0.0f }, numberObjs[i].parent);
		numberObjs[i].upArrow->SetPosition({ 0.0f, -60.0f });
		numberObjs[i].downArrow = data.hierarchy->CreateNode("Down_Arrow", data.icons->GetAnim(MGI_Triangle), smallArrowSize, { 0.0f, 0.0f }, numberObjs[i].parent);
		numberObjs[i].downArrow->SetPosition({ 0.0f, 60.0f });
		numberObjs[i].downArrow->SetRotation(180.0f);
		numberObjs[i].text = new TextBox(std::to_string(numberObjs[i].current), 30.0f, TextAlignment::Center, data.text);
		numberObjs[i].textNode = data.hierarchy->CreateNode("Number_Text", numberObjs[i].parent);
		numberObjs[i].textNode->displaySize = { 50.0f, 30.0f };
		numberObjs[i].textNode->renderComponents.push_back(numberObjs[i].text);
		numberObjs[i].textNode->SetPosition({});
		numberObjs[i].prevText = new TextBox("", 30.0f, TextAlignment::Center, data.text);
		numberObjs[i].prevTextNode = data.hierarchy->CreateNode("Number_Text", numberObjs[i].parent);
		numberObjs[i].prevTextNode->displaySize = { 50.0f, 30.0f };
		numberObjs[i].prevTextNode->renderComponents.push_back(numberObjs[i].prevText);
		numberObjs[i].prevTextNode->SetPosition({0.0f, 90.0f});
		numberObjs[i].parent->SetPositionGlobal({ xPos, data.icons->yCenter });
		xPos += 70.0f;
	}

	submitParent = data.hierarchy->CreateNode("Submit_Parent", data.icons->GetAnim(MGI_Safe_Handle), { 50.0f, 50.0f }, { xPos, data.icons->yCenter }, nullptr);
	submitUp = data.hierarchy->CreateNode("Submit_Parent", submitParent);
	submitUp->SetPosition({ 0.0f, -60.0f });
	submitUp->displaySize = { 50.0f, smallTextSize };
	submitDown = data.hierarchy->CreateNode("Submit_Parent", submitParent);
	submitDown->SetPosition({ 0.0f, 60.0f });
	submitDown->displaySize = { 50.0f, smallTextSize };
	submitText = new TextBox("Submit", smallTextSize, TextAlignment::Center, data.text);
	submitUp->renderComponents.push_back(submitText);
	submitDown->renderComponents.push_back(submitText);

	// Timer
	this->timerBarBG = data.hierarchy->CreateNode("Timer_Background", data.icons->GetAnim(MGI_White_Box), { 160.0f, 13.0f }, { 320.0f, 73.0f });
	this->timerBarBG->color = { 1.0f, 0.0f, 0.0f, 0.0f };
	this->timerBar = data.hierarchy->CreateNode("Timer_Fill", data.icons->GetAnim(MGI_White_Box), { 200.0f, 13.0f }, { 320.0f, 73.0f }, this->timerBarBG);
	this->timerBar->color = { 1.0f, 0.0f, 0.0f, 0.84f };
	SpriteNode* timerBarFG = data.hierarchy->CreateNode("Timer_Foreground", data.icons->GetAnim(MGI_Fishing_Bar_Outline), { 16.0f, 200.0f }, { 320.0f, 74.0f });
	timerBarFG->SetRotation(-90.0f);
	SpriteNode* timeCapL = data.hierarchy->CreateNode("Timer_CapL", data.icons->GetAnim(MGI_Fishing_Bar_Cap), { 15.0f, 20.0f }, { 230.0f, 74.0f });
	timeCapL->SetRotation(-90.0f);
	SpriteNode* timeCapR = data.hierarchy->CreateNode("Timer_CapR", data.icons->GetAnim(MGI_Fishing_Bar_Cap), { 15.0f, 20.0f }, { 410.0f, 72.0f });
	timeCapR->SetRotation(90.0f);
	this->timerBarBG->SetEnabled(true);
	this->timerBomb = data.hierarchy->CreateNode("Timer_Sonic", data.icons->GetAnim(MGI_Sonic_Head), { 32.0f, 32.0f }, { 240.0f, 46.0f }, this->timerBarBG);
	this->timerBomb = data.hierarchy->CreateNode("Timer_Bomb", data.icons->GetAnim(MGI_Bomb), { 32.0f, 32.0f }, { 400.0f, 46.0f }, this->timerBarBG);
	Wiggle* bombWiggle = new Wiggle(RandomFloat(0.45f, 0.65f), -25.0f, 25.0f, true);
	timerBomb->components.push_back(bombWiggle);

	xPos = data.icons->xCenter - 95.0f;
	for (int i = 0; i < questionMarks.size(); i++)
	{
		questionMarks[i] = data.hierarchy->CreateNode("Question_Mark", data.icons->GetAnim(MGI_Life_Box), { 20.0f, 20.0f }, { xPos, 100.0f });
		xPos += 25.0f;
	}

	this->resultNode = data.hierarchy->CreateNode("Result", data.icons->GetAnim(MGI_Green_Check), { 200, 200 },
		{ data.icons->xCenter, data.icons->yCenter });
	this->resultNode->color.a = 0.0f;
	this->resultNode->SetEnabled(false);
}	
