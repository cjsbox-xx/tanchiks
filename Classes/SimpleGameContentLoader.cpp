#include "SimpleGameContentLoader.h"
#include "GameContent.h"
#include "SimpleObject.h"

void SimpleGameContentLoader::load()
{
	_gameContent = new GameContent();
	BaseGameObject *gameObject = new SimpleObject();

	SimplePhysicsWorld *physicsWorld = new SimplePhysicsWorld(Rect(-100.0f, -100.0f, 100.0f, 100.0f));
	_gameContent->setPhysicsWorld(physicsWorld);
	_gameContent->addGameObject(gameObject);
}

GameContent* SimpleGameContentLoader::getGameContent()
{
	return _gameContent;
}
