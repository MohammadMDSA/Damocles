#pragma once
#include "IRenderable.h"
#include "IActor.h"
#include "GameObject.h"

class GameObject;

class GameObjectComponent : public IRenderable, public IActor
{
public:
	GameObjectComponent();
	~GameObjectComponent();

	void								SetGameObject(GameObject* object);
	GameObject*							GetGameObject() const;

	// Inherited via IRenderable
	virtual void						Render(Matrix const& parentTransform, Matrix const& view, Matrix const& proj) = 0;

	// Inherited via IActor
	virtual void						Setup() = 0;
	virtual void						Update(DX::StepTimer const& timer) = 0;

private:

	GameObject*							gameObject;
};

