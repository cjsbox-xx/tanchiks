#include "GameContent.h"

void GameContent::addGameObject(BaseGameObject *gameObject)
{
	_gameObjects.push_back(gameObject);
}

std::vector<BaseGameObject*> GameContent::getAllObjects()
{
	return _gameObjects;
}
