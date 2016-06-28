#include "GameContent.h"

void GameContent::addGameObject(BaseGameObject *gameObject)
{
	_gameObjects.push_back(gameObject);
}

std::vector<BaseGameObject*> GameContent::getAllObjects()
{
	return _gameObjects;
}

BaseGameObject * GameContent::getObjectByName(std::string name)
{
	for (auto object : _gameObjects)
	{
		if (object->getName() == name)
		{
			return object;
		}
	}
	return nullptr;
}

void GameContent::setPhysicsWorld(SimplePhysicsWorld *physicsWorld)
{
	_physicsWorld = physicsWorld;
}

SimplePhysicsWorld * GameContent::getPhysicsWorld()
{
	return _physicsWorld;
}
