#include "pch.h"
#include "GameObjectComponent.h"

GameObjectComponent::GameObjectComponent()
{
}

GameObjectComponent::~GameObjectComponent()
{
	delete gameObject;
}

void GameObjectComponent::SetGameObject(GameObject* object)
{
	if (this->gameObject != object)
		this->gameObject->RemoveComponent(this);

	this->gameObject = object;
}

GameObject* GameObjectComponent::GetGameObject() const
{
	return gameObject;
}
