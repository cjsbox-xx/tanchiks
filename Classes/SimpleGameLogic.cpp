#include "SimpleGameLogic.h"
#include "GameWorld.h"

void SimpleGameLogic::worldLoaded()
{
	_physicsWorld = _world->getGameContent()->getPhysicsWorld();
	_physicsWorld->setCollisionCallback(this);

	_tank = static_cast<Tank*>(_world->getGameContent()->getObjectByName("Player"));

	ControllerManager::getInstance()->registerListener(this);
}

void SimpleGameLogic::update(float delta)
{
	_physicsWorld->update(delta);
}

void SimpleGameLogic::onKeyDown(EventKeyboard::KeyCode keyCode)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		_tank->moveLeft();
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		_tank->moveRight();
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		_tank->moveForward();
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
	{
		_tank->moveBackward();
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_X)
	{
		_tank->fire();
	}
}

void SimpleGameLogic::onKeyPress(EventKeyboard::KeyCode keyCode)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_Q)
	{
		_tank->prevWeapon();
	} else if (keyCode == EventKeyboard::KeyCode::KEY_W)
	{
		_tank->nextWeapon();
	}
}

void SimpleGameLogic::onKeyUp(EventKeyboard::KeyCode keyCode)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		_tank->stopMoveLeft();
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		_tank->stopMoveRight();
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		_tank->stopMoveBackward();
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
	{
		_tank->stopMoveBackward();
	}
}

void SimpleGameLogic::onPointsBeginContact(SimplePhysicsPoint* pointA, SimplePhysicsPoint* pointB)
{

}

void SimpleGameLogic::onPointReachedBorder(SimplePhysicsPoint* point)
{
	BaseGameObject *gameObject = static_cast<BaseGameObject*>(point->getUserData());
	if (gameObject)
	{
		if (gameObject->getType() == GameObjectType::TANK_BULLET)
		{
			scheduleOnce([=](float dt){
				gameObject->detachFromWorld();
				delete gameObject;
			}, 0.0f, "DestroyGameObject");
		}
	}
}
