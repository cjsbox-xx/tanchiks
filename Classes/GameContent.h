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
private:
	std::vector<BaseGameObject*> _gameObjects;
	SimplePhysicsWorld *_physicsWorld;
};
