#pragma once
#include "IRenderable.h"
#include "IActor.h"
#include "Transform.h"
#include "GameObjectComponent.h"

class GameObjectComponent;
class Transform;

class GameObject : public IRenderable, public IActor
{

public:
	GameObject();
	GameObject(std::string name);
	~GameObject();

	virtual void									Render(Matrix const& view, Matrix const& proj) override;
	Transform*										GetTransform();


	// Inherited via IActor
	virtual void									Setup() override;
	virtual void									Update(DX::StepTimer const& timer) override;

	void											AddComponent(GameObjectComponent* component);
	void											RemoveComponent(GameObjectComponent* component);

	std::string										GetName();
	void											SetName(std::string name);
	static GameObject*								GetByName(std::string name);

	static std::set<GameObject*>*					GetGameObjects();


protected:
	Transform*										transform;
	std::vector<GameObjectComponent*>*				components;

private:
	std::string										name;
	static std::set<GameObject*>					objects;
	static std::map<std::string, GameObject*>		namedObjects;
};

