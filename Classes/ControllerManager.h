#pragma once

class KeyboardListener
{
public:
	virtual void onKeyDown(EventKeyboard::KeyCode keyCode) = 0;
	virtual void onKeyPress(EventKeyboard::KeyCode keyCode) = 0;
	virtual void onKeyUp(EventKeyboard::KeyCode keyCode) = 0;
};

class ControllerManager
{
public:
	static ControllerManager *getInstance();
	void init();
	void update(float dt);
	void registerListener(KeyboardListener *listener);
	void unregisterListener(KeyboardListener *listener);
private:
	static ControllerManager *_instance;
	ControllerManager();
	void notifyKeyPressed(EventKeyboard::KeyCode keyCode);
	void notifyKeyDown(EventKeyboard::KeyCode keyCode);
	void notifyKeyUp(EventKeyboard::KeyCode keyCode);
	std::vector<KeyboardListener*> _listeners;
	std::set<EventKeyboard::KeyCode> _pressedKeys;
};