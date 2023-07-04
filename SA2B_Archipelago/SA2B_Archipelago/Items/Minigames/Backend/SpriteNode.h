#pragma once
#include <vector>
#include <string>
#include <functional>

//Node -> Components, parent ptr, children ptrs

class SpriteNode;

class SpriteComponent
{
public:
	virtual void OnFrame(SpriteNode& node) = 0;
};

class SpriteNode
{
public:
	std::string Name;
	SpriteNode* parent;
	std::vector<SpriteNode*> children;
	std::vector<SpriteComponent> components;

	NJS_POINT3 displaySize;
	NJS_POINT3 scale;
	float rotation;
	NJS_TEXANIM* anim;

	void RemoveFromChildren(SpriteNode* child);
	void SetPositionGlobal(NJS_POINT3 pos);
	void SetPosition(NJS_POINT3 pos);
	NJS_POINT3 GetPosition();
	NJS_POINT3 GetPositionGlobal();
	void Render(NJS_SPRITE& sprite);
	void OnFrame();
	void RunMethodOnHeirarchy(std::function<void(SpriteNode&)> func, bool depthFirst = false);

	void SetPositionDirty();

	SpriteNode() : Name("") {}
	SpriteNode(std::string name) : Name(name) {}

private:
	bool isGlobalPositionDirty;
	NJS_POINT3 globalPosition;
	NJS_POINT3 localPosition;

	void UpdateGlobalPosition();
};
