#pragma once
#include "GameObject.h"

class GameObject;

class Transform
{
public:
	Transform(GameObject* obj);
	~Transform();

	DirectX::SimpleMath::Matrix					GetWorld();
	DirectX::SimpleMath::Matrix					GetLocal();

	void										SetParent(Transform* transform);
	void										SetParent(GameObject* obj);
	Transform*									GetParent() const;
	const GameObject*							GetGameObject() const;

	void										SetPosition(DirectX::SimpleMath::Vector3);
	void										SetPosition(float x, float y, float z);
	void										SetRotation(DirectX::SimpleMath::Vector3);
	void										SetRotation(float x, float y, float z);
	void										SetScale(DirectX::SimpleMath::Vector3);
	void										SetScale(float x, float y, float z);

	DirectX::SimpleMath::Vector3				GetPosition();
	DirectX::SimpleMath::Vector3				GetScale();
	DirectX::SimpleMath::Vector3				GetRotation();
	DirectX::SimpleMath::Matrix					GetViewMatrix();

private:

	void										ComputeTransform();
	void										ComputeView();

	DirectX::SimpleMath::Vector3				position;
	DirectX::SimpleMath::Vector3				rotation;
	DirectX::SimpleMath::Vector3				scale;
	DirectX::SimpleMath::Matrix					transform;
	DirectX::SimpleMath::Matrix					view;

	Transform*									parent;
	const GameObject*							object;
};

