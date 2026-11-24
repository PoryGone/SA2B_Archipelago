#include "../../../pch.h"
#include "SpriteHierarchyManager.h"

std::vector<std::shared_ptr<HierarchyItem>> SpriteHierarchyManager::hierarchies = {};

void SpriteManagerObj_Delete(ObjectMaster* obj)
{
	SpriteHierarchyManager::GetInstance().iconData.ReleaseIcons();
	SpriteHierarchyManager::GetInstance().textData.ReleaseIcons();
	SpriteHierarchyManager::GetInstance().managerObjPtr = nullptr;
    SpriteHierarchyManager::GetInstance().SceneObjectDestroyed();
}

void SpriteManagerObj_Display(ObjectMaster* obj)
{
	SpriteHierarchyManager::GetInstance().DisplayUpdate();
}

void SpriteManagerObj_Main(ObjectMaster* obj)
{
    if (GameState != GameStates_LoadFinished && GameState != GameStates_LoadLevel)
    {
        return;
    }

    if (obj->Data1.Entity->Action == 0) {
        obj->DeleteSub = SpriteManagerObj_Delete;
        obj->DisplaySub_Delayed3 = SpriteManagerObj_Display;
        obj->Data1.Entity->Action = 1;
    }
    SpriteHierarchyManager::GetInstance().SceneObjectCreated();
}

void SpriteHierarchyManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
    _helperFunctions = &helperFunctions;
}

void SpriteHierarchyManager::OnFrameFunction()
{
    if (!this->managerObjPtr && (GameState == GameStates_Ingame || CurrentMenu == Menus_Main))
    {
        std::string str = "Hierarchy Manager: Create Display Object ";
        str.append(std::to_string(hierarchies.size()));
        PrintDebug(str.c_str());
        this->iconData.LoadIcons();
        this->textData.LoadIcons();
        this->managerObjPtr = LoadObject(0, "SpriteManager", SpriteManagerObj_Main, LoadObj_Data1 | LoadObj_Data2);
        this->managerObjPtr->DeleteSub = SpriteManagerObj_Delete;
        this->managerObjPtr->MainSub = SpriteManagerObj_Main;
        this->managerObjPtr->DisplaySub_Delayed3 = SpriteManagerObj_Display;
        this->managerObjPtr->Data1.Entity->Action = 1;
        for (auto item : hierarchies)
        {
            item->hierarchy->iconData = &this->iconData;
        }
        SceneObjectCreated();
    }
}

bool SpriteHierarchyManager::IsSceneObjectActive()
{
    return this->_isSceneObjectActive;
}

std::shared_ptr<SpriteHierarchy> SpriteHierarchyManager::GetHierarchy(int priority)
{
    return this->GetHierarchyItem(priority)->hierarchy;
}

bool CompareHeirarchyItems(std::shared_ptr<HierarchyItem> a, std::shared_ptr<HierarchyItem> b)
{
    return a->priority < b->priority;
}

std::shared_ptr<HierarchyItem> SpriteHierarchyManager::GetHierarchyItem(int priority)
{
    for (auto item : hierarchies)
    {
        if (item->priority == priority)
        {
            return item;
        }
    }
    auto itemPtr = std::make_shared<HierarchyItem>();
    itemPtr->priority = priority;
    itemPtr->hierarchy = std::make_shared<SpriteHierarchy>();
    itemPtr->hierarchy->iconData = &this->iconData;
    hierarchies.push_back(itemPtr);
    std::string str = "Hierarchy Manager: Create Hierarchy ";
    str.append(std::to_string(hierarchies.size()));
    sort(hierarchies.begin(), hierarchies.end(), CompareHeirarchyItems);
    str.append(", ");
    str.append(std::to_string(hierarchies.size()));
    PrintDebug(str.c_str());
    return itemPtr;
}

void SpriteHierarchyManager::DisplayUpdate()
{
    for (auto item : hierarchies)
    {
        if (item->callbacks)
        {
            item->callbacks->OnBeforeFrameUpdate(*item->hierarchy);
        }
        if (item->isFrameUpdateActive)
        {
            item->hierarchy->OnFrame();
        }
        if (item->isRenderActive)
        {
            item->hierarchy->Render();
        }
        if (item->callbacks)
        {
            item->callbacks->OnAfterFrameRender(*item->hierarchy);
        }
    }
}

void SpriteHierarchyManager::SceneObjectCreated()
{
    this->_isSceneObjectActive = true;
    for (auto item : hierarchies)
    {
        if (item->callbacks)
        {
            item->callbacks->OnSceneObjectCreation();
        }
    }
}

void SpriteHierarchyManager::SceneObjectDestroyed()
{
    this->_isSceneObjectActive = false;
    for (auto item : hierarchies)
    {
        if (item->callbacks)
        {
            item->callbacks->OnSceneObjectDelete();
        }
    }
}