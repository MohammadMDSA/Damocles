#pragma once

#include "GameObject.h"


class Camera : public GameObject
{
public:

	Camera();
	~Camera();

	void									SetSize(float width, float height);
	void									GetSize(float& width, float& height);

	virtual void							Update(DX::StepTimer const& timer) override;

	DirectX::SimpleMath::Matrix				GetView();
	DirectX::SimpleMath::Matrix				GetProjection();
private:
	void									ComputeProjection();

	DirectX::SimpleMath::Matrix				projection;
	float									screenWidth;
	float									screenHeight;
	float									nearPlane;
	float									farPlane;
	float									fieldOfView;

};

