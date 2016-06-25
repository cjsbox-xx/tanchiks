#include "GameWorld.h"

const std::string GameWorld::MAIN_LAYER = "MainLayer";

bool GameWorld::init()
{
	if (!Layer::init())
	{
		return false;
	}
	addLayer(MAIN_LAYER, this);

	return true;
}

void GameWorld::initLogic(GameLogic *logic)
{
	_gameLogic = logic;
}

void GameWorld::initContent(GameContent *content)
{
	_content = content;
}

void GameWorld::startWorld()
{
	this->addChild(_gameLogic);
	auto worldObjects = _content->getAllObjects();
	for (auto worldObject : worldObjects)
	{
		worldObject->initWithWorld(this);
	}
	_gameLogic->worldLoaded();
}

Layer * GameWorld::getLayerByName(std::string name)
{
	return _layers.at(name);
}

void GameWorld::addLayer(std::string name, Layer *layer)
{
	_layers[name] = layer;
}
