#include "pch.h"
#include "Camera.h"
#include <math.h>

using namespace DirectX::SimpleMath;

Camera::Camera():
	screenWidth(800),
	screenHeight(600),
	nearPlane(0.01),
	farPlane(1000),
	fieldOfView(45.f)
{
	ComputeProjection();
}

Camera::~Camera()
{
	delete transform;
}

void Camera::SetSize(float width, float height)
{
	this->screenWidth = width;
	this->screenHeight = height;
	ComputeProjection();
}

void Camera::GetSize(float& width, float& height)
{
	width = this->screenWidth;
	height = this->screenHeight;
}

void Camera::Update(DX::StepTimer const& timer)
{
	/*auto pos = transform->GetPosition();
	pos.z += sinf(timer.GetTotalSeconds());
	transform->SetPosition(pos);*/
}

DirectX::SimpleMath::Matrix Camera::GetView()
{
	return transform->GetViewMatrix();
}

DirectX::SimpleMath::Matrix Camera::GetProjection()
{
	return projection;
}

void Camera::ComputeProjection()
{
	projection = Matrix::CreatePerspectiveFieldOfView(fieldOfView, screenWidth / screenHeight, nearPlane, farPlane);
}
