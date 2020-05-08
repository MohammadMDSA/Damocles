#pragma once
#include "GameObjectComponent.h"
#include "GraphicResource.h"

class MeshRendererComponent : public GameObjectComponent, public GraphicResource
{
public:

	// Inherited via GameObjectComponent
	virtual void Render(Matrix const& view, Matrix const& proj) = 0;

	virtual void Setup()  = 0;

	virtual void Update(DX::StepTimer const& timer) = 0;

	virtual void SetupDevice(ID3D11DeviceContext2* context) = 0;

	virtual void DeviceLost() = 0;

};

