#include "MonstersPlace.h"
#include "GameWorld.h"

void MonstersPlace::init()
{
	_home = Sprite::create("monsters_place.png");
	_home->schedule([&](float dt)
	{
		update(dt);
	}, "MonstersPlaceUpdate");
}

void MonstersPlace::attachToWorld()
{
	_world->getLayerByName(GameWorld::MAIN_LAYER)->addChild(_home);
}

void MonstersPlace::detachFromWorld()
{
	_world->getLayerByName(GameWorld::MAIN_LAYER)->removeChild(_home);
}

GameObjectType MonstersPlace::getType() const
{
	return GameObjectType::MONSTERS_PLACE;
}

void MonstersPlace::update(float dt)
{
	_home->setPosition(_physicsPoint->getPosition());
	_home->setRotation(_physicsPoint->getAngle());
}

SimplePhysicsPoint* MonstersPlace::getPhysicsPoint() const
{
	return _physicsPoint;
}

void MonstersPlace::setPhysicsPoint(SimplePhysicsPoint* physicsPoint)
{
	_physicsPoint = physicsPoint;
	_physicsPoint->setUserData(this);
}

float MonstersPlace::getMonstersRadius() const
{
	return _monstersRadius;
}

void MonstersPlace::setMonstersRadius(float monstersRadius)
{
	_monstersRadius = monstersRadius;
}

int MonstersPlace::getMaxMonstersNumber() const
{
	return _maxMonstersNumber;
}

void MonstersPlace::setMaxMonstersNumber(int maxMonstersNumber)
{
	_maxMonstersNumber = maxMonstersNumber;
}
