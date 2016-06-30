#include "Monster.h"
#include "GameWorld.h"

void Monster::init()
{
	_sprite = Sprite::create(getSpriteName());
	_sprite->schedule([&](float dt)
	{
		update(dt);
	}, "MonsterUpdate");
	setLifeValue(getLife());
	setArmourValue(getArmor());
}

void Monster::attachToWorld()
{
	_world->getLayerByName(GameWorld::MAIN_LAYER)->addChild(_sprite);
}

void Monster::detachFromWorld()
{
	_world->getLayerByName(GameWorld::MAIN_LAYER)->removeChild(_sprite);
	_physicsPoint->getPhysicsWorld()->destroyPoint(_physicsPoint);
}

void Monster::onDeath()
{
	if (onDeathEvent)
	{
		onDeathEvent(this);
	}
}

void Monster::update(float dt)
{
	_sprite->setPosition(_physicsPoint->getPosition());
	_sprite->setRotation(_physicsPoint->getAngle());
}

SimplePhysicsPoint* Monster::getPhysicsPoint() const
{
	return _physicsPoint;
}

void Monster::setPhysicsPoint(SimplePhysicsPoint* physicsPoint)
{
	_physicsPoint = physicsPoint;
	_physicsPoint->setUserData(this);
}


GameObjectType Monster1::getType() const
{
	return GameObjectType::MONSTER1;
}

float Monster1::getDamageValue()
{
	return 1.0f;
}

std::string Monster1::getSpriteName()
{
	return "monster_1.png";
}

float Monster1::getLife()
{
	return 100.0f;
}

float Monster1::getArmor()
{
	return 0.1f;
}

GameObjectType Monster2::getType() const
{
	return GameObjectType::MONSTER2;
}

float Monster2::getDamageValue()
{
	return 2.0f;
}

std::string Monster2::getSpriteName()
{
	return "monster_2.png";
}

float Monster2::getLife()
{
	return 200.0f;
}

float Monster2::getArmor()
{
	return 0.2f;
}

GameObjectType Monster3::getType() const
{
	return GameObjectType::MONSTER3;
}

float Monster3::getDamageValue()
{
	return 3.0f;
}

std::string Monster3::getSpriteName()
{
	return "monster_3.png";
}

float Monster3::getLife()
{
	return 300.0f;
}

float Monster3::getArmor()
{
	return 0.4f;
}
