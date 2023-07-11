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
	std::string name;
	SpriteNode* parent;
	std::vector<SpriteNode*> children;
	std::vector<SpriteComponent*> components;

	NJS_POINT3 displaySize;
	NJS_POINT3 scale;
	float rotation;
	NJS_TEXANIM* anim;

	void RemoveFromChildren(SpriteNode* child);
	void SetPositionGlobal(NJS_POINT3 pos);
	void SetPosition(NJS_POINT3 pos);
	NJS_POINT3 GetPosition();
	NJS_POINT3 GetPositionGlobal();
	void Translate(NJS_POINT3 delta);
	void Render(NJS_SPRITE& sprite);
	void OnFrame();
	void RunMethodOnHeirarchy(std::function<void(SpriteNode&)> func, bool depthFirst = false);

	SpriteNode() : name(""), anim(nullptr), displaySize({ 1.0f,1.0f,0.0f }), globalPosition({ 0.0f,0.0f,0.0f }), localPosition({ 0.0f,0.0f,0.0f }), isGlobalPositionDirty(false), parent(nullptr), scale({ 1.0f,1.0f,1.0f }), rotation(0.0f), children(std::vector<SpriteNode*>()), components(std::vector<SpriteComponent*>()) {}
	SpriteNode(std::string _name) : name(_name), anim(nullptr), displaySize({ 1.0f,1.0f,0.0f }), globalPosition({0.0f,0.0f,0.0f}), localPosition({ 0.0f,0.0f,0.0f }), isGlobalPositionDirty(false), parent(nullptr), scale({ 1.0f,1.0f,1.0f }), rotation(0.0f), children(std::vector<SpriteNode*>()), components(std::vector<SpriteComponent*>()) {}
	SpriteNode(std::string _name, NJS_TEXANIM* _anim, NJS_POINT3 _displaySize, NJS_POINT3 _globalPosition) : name(_name), anim(_anim), displaySize(_displaySize), globalPosition(_globalPosition), localPosition(_globalPosition), isGlobalPositionDirty(false), parent(nullptr), scale({1.0f,1.0f,1.0f}), rotation(0.0f), children(std::vector<SpriteNode*>()), components(std::vector<SpriteComponent*>()) {}

private:
	bool isGlobalPositionDirty;
	NJS_POINT3 globalPosition;
	NJS_POINT3 localPosition;

	void SetPositionDirty();
	void SetBranchDirty();
	void UpdateGlobalPosition();

};
