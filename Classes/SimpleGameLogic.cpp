#include "SimpleGameLogic.h"
#include "GameWorld.h"

void SimpleGameLogic::worldLoaded()
{
	_physicsWorld = _world->getGameContent()->getPhysicsWorld();
}

void SimpleGameLogic::update(float delta)
{
	_physicsWorld->update(delta);
}
