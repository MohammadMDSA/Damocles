#include "pch.h"
#include "GameObject.h"
#include <algorithm>

using namespace DirectX;
using namespace DirectX::SimpleMath;

std::unique_ptr<DirectX::GeometricPrimitive> GameObject::cone = nullptr;

GameObject::GameObject():
	transform(new Transform())
{
}

GameObject::~GameObject()
{
	delete transform;
	for (auto el = components.begin(); el != components.end(); el++)
		delete (*el);
}

void GameObject::SetupDevice(ID3D11DeviceContext2* contex)
{
	GameObject::cone = GeometricPrimitive::CreateCone(contex, 1.f, 1.f, 128);
	//auto modle = GeometricPrimitive::CreateCone(contex);
}

void GameObject::Render(Matrix const& view, Matrix const& proj)
{
	/*for (auto el = components.begin(); el != components.end(); el++)
		(*el)->Render()*/
	GameObject::cone->Draw(transform->GetWorld(), view, proj);

}

Transform* GameObject::GetTransform()
{
	return transform;
}

void GameObject::Setup()
{
}

void GameObject::Update(DX::StepTimer const& timer)
{
}

void GameObject::RemoveComponent(GameObjectComponent* component)
{
	components.erase(std::remove(components.begin(), components.end(), component), components.end());
}
