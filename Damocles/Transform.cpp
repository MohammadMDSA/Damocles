#include "pch.h"
#include "Transform.h"

using namespace DirectX::SimpleMath;

Transform::Transform():
	position(Vector3()),
	rotation(Vector3()),
	scale(Vector3(1.f))
{
	ComputeTransform();
}

Transform::~Transform()
{
}

DirectX::SimpleMath::Matrix Transform::GetWorld()
{
	return transform;
}

void Transform::SetPosition(DirectX::SimpleMath::Vector3 pos)
{
	this->position = pos;
	ComputeTransform();
}

void Transform::SetPosition(float x, float y, float z)
{
	this->position = Vector3(x, y, z);
	ComputeTransform();
}

void Transform::SetRotation(DirectX::SimpleMath::Vector3 rot)
{
	this->rotation = rot;
	ComputeTransform();
}

void Transform::SetRotation(float x, float y, float z)
{
	this->rotation = Vector3(x, y, z);
	ComputeTransform();
}

void Transform::SetScale(DirectX::SimpleMath::Vector3 scl)
{
	this->scale = scl;
	ComputeTransform();
}

void Transform::SetScale(float x, float y, float z)
{
	this->scale = Vector3(x, y, z);
	ComputeTransform();
}

DirectX::SimpleMath::Vector3 Transform::GetPosition()
{
	return this->position;
}

DirectX::SimpleMath::Vector3 Transform::GetScale()
{
	return this->scale;
}

DirectX::SimpleMath::Vector3 Transform::GetRotation()
{
	return this->rotation;
}

DirectX::SimpleMath::Matrix Transform::GetViewMatrix()
{
	return view;
}

void Transform::ComputeTransform()
{
	transform = Matrix::CreateScale(scale);
	transform *= Matrix::CreateFromYawPitchRoll(rotation.y, rotation.x, rotation.z);
	transform *= Matrix::CreateTranslation(position);
	ComputeView();
}

void Transform::ComputeView()
{
	this->view = Matrix::CreateLookAt(position, transform.Forward(), transform.Up());
}
