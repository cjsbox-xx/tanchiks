#include "GameLogic.h"

bool GameLogic::init()
{
	if (!Node::init())
	{
		return false;
	}
	return true;
}

void GameLogic::setWorld(GameWorld *world)
{
	_world = world;
}
