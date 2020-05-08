#include "pch.h"
#include "GameObject.h"
#include <algorithm>

using namespace DirectX;
using namespace DirectX::SimpleMath;

std::set<GameObject*> GameObject::objects = std::set<GameObject*>();
std::map<std::string, GameObject*> GameObject::namedObjects = std::map< std::string, GameObject*>();

GameObject::GameObject() : GameObject("New Object")
{
}

GameObject::GameObject(std::string name) :
	transform(new Transform(this)),
	components(new std::vector<GameObjectComponent*>()),
	name("New Object")
{
	GameObject::objects.insert(this);
	SetName(name);
}

GameObject::~GameObject()
{
	GameObject::objects.erase(this);
	delete transform;
}

void GameObject::Render(Matrix const& view, Matrix const& proj)
{
	for (auto el = components->begin(); el != components->end(); el++)
		(*el)->Render(view, proj);

}

Transform* GameObject::GetTransform()
{
	return transform;
}

void GameObject::Setup()
{
	for (auto el = components->begin(); el != components->end(); el++)
		(*el)->Setup();
}

void GameObject::Update(DX::StepTimer const& timer)
{
	for (auto el = components->begin(); el != components->end(); el++)
		(*el)->Update(timer);
}

void GameObject::AddComponent(GameObjectComponent* component)
{
	component->SetGameObject(this);
	components->push_back(component);
}

void GameObject::RemoveComponent(GameObjectComponent* component)
{
	if (components->size() > 0)
		components->erase(std::remove(components->begin(), components->end(), component), components->end());
}

std::string GameObject::GetName()
{
	return this->name;
}

void GameObject::SetName(std::string name)
{
	if (this->name != "New Object")
		namedObjects.erase(this->name);
	if (name == "New Object")
		return;
	int dup = 0;
	while (namedObjects.count(dup != 0 ? name + "_" + std::to_string(dup) : name) > 0)
	{
		dup++;
	}
	this->name = dup != 0 ? name + "_" + std::to_string(dup) : name;
	GameObject::namedObjects.insert(std::pair<std::string, GameObject*>(name, this));
}

GameObject* GameObject::GetByName(std::string name)
{
	return namedObjects[name];
}

std::set<GameObject*>* GameObject::GetGameObjects()
{
	return &objects;
}
