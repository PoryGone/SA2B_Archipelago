#include "../../../pch.h"
#include "NumberSequence.h"

void NumberSequence::OnGameStart(MinigameManagerData data)
{
	currentState = MGS_InProgress;
	std::shuffle(numbers.begin(), numbers.end(), RNG());
	for (int i = 0; i < numberObjs.size(); i++)
	{
		numberObjs[i] = NumberSequenceNumber();
		numberObjs[i].correct = numbers[i];
		numberObjs[i].current = i;
	}
	selectedIndex = 0;
	state = NSS_InGame;
	data.timers->push_back(&timer);
	CreateHierarchy(data);
	SetSelectedIndex(selectedIndex);
}

void NumberSequence::OnFrame(MinigameManagerData data)
{
	if (data.managerState != MGS_InProgress)
	{
		return;
	}
	switch (state)
	{
	case NSS_InGame:
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
		break;
	case NSS_Win:
		if (timer.IsElapsed())
		{
			currentState = MGS_Victory;
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
			n = n < 9 ? n + 1 : 0;
		}
	}
	nsNumber->current = n;
	nsNumber->text->UpdateText(std::to_string(n));
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
			n = n > 0 ? n - 1 : 9;
		}
	}
	nsNumber->current = n;
	nsNumber->text->UpdateText(std::to_string(n));
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
		if (numberObjs[i].correct == numberObjs[i].current)
		{
			correctCount++;
			numberObjs[i].textNode->color = { 1.0f, 0.0f, 1.0f, 0.0f };
		}
		else if (AnySequenceContains(numberObjs[i].current))
		{
			numberObjs[i].textNode->color = { 1.0f, 1.0f, 1.0f, 0.0f };
		}
		else
		{
			numberObjs[i].textNode->color = { 1.0f, 1.0f, 0.0f, 0.0f };
		}
	}
	if (correctCount == numberObjs.size())
	{
		state = NSS_Win;
		timer.Start(1.0f);
	}
}

void NumberSequence::CreateHierarchy(MinigameManagerData data)
{
	AddDPadToHierarchy(anyDPad, { 65.0f, 130.0f, 0.0f }, 45.0f, *data.icons, *data.hierarchy);
	
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
		numberObjs[i].parent->SetPositionGlobal({ xPos, data.icons->yCenter });
		xPos += 70.0f;
	}

	submitParent = data.hierarchy->CreateNode("Submit_Parent", data.icons->GetAnim(MGI_Circle), { 30.0f, 30.0f }, { xPos, data.icons->yCenter }, nullptr);
	submitUp = data.hierarchy->CreateNode("Submit_Parent", submitParent);
	submitUp->SetPosition({ 0.0f, -60.0f });
	submitUp->displaySize = { 50.0f, smallTextSize };
	submitDown = data.hierarchy->CreateNode("Submit_Parent", submitParent);
	submitDown->SetPosition({ 0.0f, 60.0f });
	submitDown->displaySize = { 50.0f, smallTextSize };
	submitText = new TextBox("Submit", smallTextSize, TextAlignment::Center, data.text);
	submitUp->renderComponents.push_back(submitText);
	submitDown->renderComponents.push_back(submitText);

}	
