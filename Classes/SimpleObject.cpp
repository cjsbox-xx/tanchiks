#include "SimpleObject.h"
#include "GameWorld.h"

void SimpleObject::init()
{
	_sprite = Sprite::create("HelloWorld.png");
	_sprite->setPosition(Vec2(0.0f, 0.0f));
}

void SimpleObject::attachToWorld()
{
	_world->getLayerByName(GameWorld::MAIN_LAYER)->addChild(_sprite);
}

GameObjectType SimpleObject::getType() const
{
	return GameObjectType::SIMPLE_OBJECT;
}
