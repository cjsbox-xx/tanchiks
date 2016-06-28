#pragma once
#include "GameLogic.h"
#include "SimplePhysicsWorld.h"
#include "Tank.h"

class SimpleGameLogic : public GameLogic
{
public:
	virtual void worldLoaded() override;
	virtual void update(float delta) override;
private:
	SimplePhysicsWorld *_physicsWorld;
	Tank *_tank;
};
