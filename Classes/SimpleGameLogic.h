#pragma once
#include "GameLogic.h"
#include "SimplePhysicsWorld.h"
#include "Tank.h"
#include "ControllerManager.h"

class SimpleGameLogic : public GameLogic, public KeyboardListener, public SimplePhysicsWorldCollisionCallback
{
public:
	virtual void worldLoaded() override;
	virtual void update(float delta) override;

	virtual void onKeyDown(EventKeyboard::KeyCode keyCode) override;
	virtual void onKeyPress(EventKeyboard::KeyCode keyCode) override;
	virtual void onKeyUp(EventKeyboard::KeyCode keyCode) override;

	virtual void onPointsBeginContact(SimplePhysicsPoint* pointA, SimplePhysicsPoint* pointB) override;
	virtual void onPointReachedBorder(SimplePhysicsPoint* point) override;
private:
	SimplePhysicsWorld *_physicsWorld;
	Tank *_tank;
};
