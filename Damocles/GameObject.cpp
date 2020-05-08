#include "pch.h"
#include "GameObject.h"
#include <algorithm>

using namespace DirectX;
using namespace DirectX::SimpleMath;


GameObject::GameObject() :
	transform(new Transform()),
	components(new std::vector<GameObjectComponent*>())
{
}

GameObject::~GameObject()
{
	delete transform;
	for (auto el = components->begin(); el != components->end(); el++)
		delete (*el);
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
