#include "SimpleGameContentLoader.h"
#include "GameContent.h"
#include "SimpleObject.h"

void SimpleGameContentLoader::load()
{
	_gameContent = new GameContent();
	BaseGameObject *gameObject = new SimpleObject();
	_gameContent->addGameObject(gameObject);
}

GameContent* SimpleGameContentLoader::getGameContent()
{
	return _gameContent;
}
