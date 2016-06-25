#pragma once
#include "BaseGameObject.h"

class GameContent
{
public:
	void addGameObject(BaseGameObject *gameObject);
	std::vector<BaseGameObject*> getAllObjects();
private:
	std::vector<BaseGameObject*> _gameObjects;
};
