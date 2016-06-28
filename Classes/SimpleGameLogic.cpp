#include "SimpleGameLogic.h"
#include "GameWorld.h"

void SimpleGameLogic::worldLoaded()
{
	_physicsWorld = _world->getGameContent()->getPhysicsWorld();

	_tank = static_cast<Tank*>(_world->getGameContent()->getObjectByName("Player"));

	//ToDo Move to some controllers manager
	EventListenerKeyboard *keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = [&](EventKeyboard::KeyCode keyCode, Event*event)
	{
		if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
		{
			_tank->moveLeft();
		} else if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
		{
			_tank->moveRight();
		} else if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
		{
			_tank->moveForward();
		} else if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
		{
			_tank->moveBackward();
		}
	};

	keyboardListener->onKeyReleased = [&](EventKeyboard::KeyCode keyCode, Event*event)
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
	};

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);
}

void SimpleGameLogic::update(float delta)
{
	_physicsWorld->update(delta);
}
