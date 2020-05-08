#pragma once
#include "IRenderable.h"
#include "IActor.h"
#include "Transform.h"
#include "GameObjectComponent.h"

class GameObject : public IRenderable, public IActor
{

public:
	GameObject();
	~GameObject();

	static void										SetupDevice(ID3D11DeviceContext2* contex);

	virtual void									Render(Matrix const& parentTransform, Matrix const& view, Matrix const& proj) override;
	Transform*										GetTransform();


	// Inherited via IActor
	virtual void									Setup() override;
	virtual void									Update(DX::StepTimer const& timer) override;

	void											RemoveComponent(GameObjectComponent* component);

protected:
	Transform*										transform;
	static std::unique_ptr<DirectX::GeometricPrimitive>	GameObject::cone;
	std::vector<GameObjectComponent*>				components;
};

