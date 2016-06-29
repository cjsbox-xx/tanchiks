#include "ControllerManager.h"

ControllerManager * ControllerManager::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new ControllerManager();
		_instance->init();
	}
	return _instance;
}

void ControllerManager::init()
{
	Director::getInstance()->getScheduler()->schedule([&](float dt)
	{
		update(dt);
	}, this, 0, false, "KeyboardUpdate");
	EventListenerKeyboard *keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = [&](EventKeyboard::KeyCode keyCode, Event*event)
	{
		notifyKeyPressed(keyCode);
		_pressedKeys.insert(keyCode);
	};

	keyboardListener->onKeyReleased = [&](EventKeyboard::KeyCode keyCode, Event*event)
	{
		notifyKeyUp(keyCode);
		_pressedKeys.erase(keyCode);
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(keyboardListener, 1);
}

void ControllerManager::update(float dt)
{
	for (auto keyCode : _pressedKeys)
	{
		notifyKeyDown(keyCode);
	}
}

void ControllerManager::registerListener(KeyboardListener *listener)
{
	_listeners.push_back(listener);
}

void ControllerManager::unregisterListener(KeyboardListener *listener)
{
	_listeners.erase(std::find(_listeners.begin(), _listeners.end(), listener));
}

ControllerManager * ControllerManager::_instance = nullptr;

ControllerManager::ControllerManager()
{

}

void ControllerManager::notifyKeyPressed(EventKeyboard::KeyCode keyCode)
{
	for (auto listener : _listeners)
	{
		listener->onKeyPress(keyCode);
	}
}

void ControllerManager::notifyKeyDown(EventKeyboard::KeyCode keyCode)
{
	for (auto listener : _listeners)
	{
		listener->onKeyDown(keyCode);
	}
}

void ControllerManager::notifyKeyUp(EventKeyboard::KeyCode keyCode)
{
	for (auto listener : _listeners)
	{
		listener->onKeyUp(keyCode);
	}
}
