#pragma once
#include "BaseGameObject.h"
#include "SimplePhysicsWorld.h"

class GameContent
{
public:
	void addGameObject(BaseGameObject *gameObject);
	std::vector<BaseGameObject*> getAllObjects();
	BaseGameObject *getObjectByName(std::string name);
	void setPhysicsWorld(SimplePhysicsWorld *physicsWorld);
	SimplePhysicsWorld *getPhysicsWorld();
	template<typename T>
	std::vector<T*> getObjectsByTypeName(GameObjectType objectType)
	{
		std::vector<T*> foundObjects;
		for (auto gameObject : _gameObjects)
		{
			if (gameObject->getType() == objectType)
			{
				foundObjects.push_back(static_cast<T*>(gameObject));
			}
		}
		return foundObjects;
	}
private:
	std::vector<BaseGameObject*> _gameObjects;
	SimplePhysicsWorld *_physicsWorld;
};
