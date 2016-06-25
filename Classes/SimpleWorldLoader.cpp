#include "SimpleWorldLoader.h"
#include "GameContent.h"
#include "GameContentLoader.h"
#include "GameLogic.h"
#include "SimpleGameLogic.h"
#include "GameWorld.h"
#include "SimpleGameContentLoader.h"

void SimpleWorldLoader::load()
{
	GameContentLoader *gameContentProvider = new SimpleGameContentLoader();
	gameContentProvider->load();
	GameContent *content = gameContentProvider->getGameContent();
	delete gameContentProvider;

	GameLogic *logic = new SimpleGameLogic();
	logic->init();

	_world = new GameWorld();
	_world->init();
	_world->initContent(content);
	_world->initLogic(logic);
}

GameWorld* SimpleWorldLoader::getWorld()
{
	return _world;
}
