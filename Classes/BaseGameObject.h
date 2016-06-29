#pragma once

class GameWorld;

enum class GameObjectType
{
	SIMPLE_OBJECT,
	TANK,
	TANK_BULLET
};

class BaseGameObject
{
public:
	virtual void initWithWorld(GameWorld *gameWorld);
	virtual void init() = 0;
	virtual void attachToWorld() = 0;
	virtual void detachFromWorld() = 0;
	virtual GameObjectType getType() const = 0;

	virtual std::string getName() const
	{
		return _name;
	}

	virtual void setName(const std::string& name)
	{
		_name = name;
	}

protected:
	GameWorld *_world;
	std::string _name;
};
