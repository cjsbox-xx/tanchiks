#pragma once

class GameWorld;

enum class GameObjectType
{
	SIMPLE_OBJECT
};

class BaseGameObject
{
public:
	virtual void initWithWorld(GameWorld *gameWorld);
	virtual void init() = 0;
	virtual void attachToWorld() = 0;
	virtual GameObjectType getType() const = 0;
protected:
	GameWorld *_world;
};
