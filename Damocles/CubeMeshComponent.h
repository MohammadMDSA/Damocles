#pragma once
#include "MeshRendererComponent.h"

class CubeMeshComponent : public MeshRendererComponent
{
public:

	// Inherited via MeshRendererComponent
	static CubeMeshComponent*								GetInstance();

	// Inherited via MeshRendererComponent
	virtual void											 Render(Matrix const& view, Matrix const& proj) override;
	virtual void											 Setup() override;
	virtual void											 Update(DX::StepTimer const& timer) override;
	virtual void											 SetupDevice(ID3D11DeviceContext2* context) override;
	virtual void											 DeviceLost() override;

private:
	static std::unique_ptr<DirectX::GeometricPrimitive>		cube;

	CubeMeshComponent();
	~CubeMeshComponent();

	static CubeMeshComponent*								instance;

};

