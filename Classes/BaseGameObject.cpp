#include "BaseGameObject.h"

void BaseGameObject::initWithWorld(GameWorld *gameWorld)
{
	_world = gameWorld;
	init();
	attachToWorld();
}
