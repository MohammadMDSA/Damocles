#pragma once
class Transform
{
public:
	Transform();
	~Transform();

	DirectX::SimpleMath::Matrix					GetWorld();

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
};

