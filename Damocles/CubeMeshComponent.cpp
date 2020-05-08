#include "pch.h"
#include "CubeMeshComponent.h"

using namespace DirectX::SimpleMath;

std::unique_ptr<DirectX::GeometricPrimitive> CubeMeshComponent::cube = std::unique_ptr<DirectX::GeometricPrimitive>();
CubeMeshComponent* CubeMeshComponent::instance = nullptr;

CubeMeshComponent::CubeMeshComponent()
{
}

CubeMeshComponent::~CubeMeshComponent()
{
}

void CubeMeshComponent::Render(Matrix const& view, Matrix const& proj)
{
	cube->Draw(gameObject->GetTransform()->GetWorld(), view, proj);
}

void CubeMeshComponent::Setup()
{
}

void CubeMeshComponent::Update(DX::StepTimer const& timer)
{
}

void CubeMeshComponent::SetupDevice(ID3D11DeviceContext2* context)
{
	cube = DirectX::GeometricPrimitive::CreateCube(context, 1.f);
}

void CubeMeshComponent::DeviceLost()
{
	cube.reset();
}

CubeMeshComponent* CubeMeshComponent::GetInstance()
{
	if (!instance)
		instance = new CubeMeshComponent();

	return instance;
}
