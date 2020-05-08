#pragma once
#include "IRenderable.h"
#include "IActor.h"
#include "Transform.h"
#include "GameObjectComponent.h"

class GameObjectComponent;

class GameObject : public IRenderable, public IActor
{

public:
	GameObject();
	~GameObject();

	virtual void									Render(Matrix const& view, Matrix const& proj) override;
	Transform*										GetTransform();


	// Inherited via IActor
	virtual void									Setup() override;
	virtual void									Update(DX::StepTimer const& timer) override;

	void											AddComponent(GameObjectComponent* component);
	void											RemoveComponent(GameObjectComponent* component);

protected:
	Transform*										transform;
	std::vector<GameObjectComponent*>*				components;
};

