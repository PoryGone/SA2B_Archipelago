#pragma once
#include <algorithm>
#include <vector>
#include <functional>
#include <memory>

#include "SpriteHierarchy.h"
#include "../MinigameIconData.h"
#include "../TextDisplayData.h"

enum HierarchyPriorityTypes
{
    HPT_Minigames = 50,
    HPT_APIcons = 60,
};

class HierarchyCallbacks
{
public:
    virtual void OnSceneObjectCreation() = 0;
    virtual void OnSceneObjectDelete() = 0;
    virtual void OnBeforeFrameUpdate(SpriteHierarchy& hierarchy) = 0;
    virtual void OnAfterFrameRender(SpriteHierarchy& hierarchy) = 0;
};

struct HierarchyItem
{
    ~HierarchyItem()
    {
        PrintDebug("Hierarchy Item Destroyed");
    }
    
    bool isFrameUpdateActive = true;
    bool isRenderActive = true;
    int priority;
    std::shared_ptr<SpriteHierarchy> hierarchy;
    HierarchyCallbacks* callbacks;
};

class SpriteHierarchyManager
{
public:
    SpriteHierarchyManager(const SpriteHierarchyManager&) = delete;
    SpriteHierarchyManager& operator=(const SpriteHierarchyManager&) = delete;
    
    static SpriteHierarchyManager& GetInstance()
    {
        static SpriteHierarchyManager instance;
        return instance;
    }
    
    ~SpriteHierarchyManager()
    {
        PrintDebug("SpriteHierarchyManager Destroyed");
    }
    
    bool IsSceneObjectActive();
    
    ObjectMaster* managerObjPtr;
    MinigameIconData iconData = MinigameIconData();
    TextDisplayData textData = TextDisplayData();
    
    void OnInitFunction(const char* path, const HelperFunctions& helperFunctions);
    void OnFrameFunction();
    
    std::shared_ptr<SpriteHierarchy> GetHierarchy(int priority);
    std::shared_ptr<HierarchyItem> GetHierarchyItem(int priority);

	void DisplayUpdate();
    void SceneObjectCreated();
    void SceneObjectDestroyed();
    
private:
    const HelperFunctions* _helperFunctions;
    
    bool _isSceneObjectActive;
    
    static std::vector<std::shared_ptr<HierarchyItem>> hierarchies;
    
    SpriteHierarchyManager() {}
};


