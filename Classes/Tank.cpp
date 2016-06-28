#include "Tank.h"
#include "GameWorld.h"

const float Tank::ROTATION_SPEED = 25.0f;

const float Tank::MOVEMENT_SPEED = 50.0f;

void Tank::init()
{
	_tankRoot = Node::create();
	_tankRoot->schedule([&](float dt)
	{
		update(dt);
	}, "TankUpdate");
	_wheelTopLeft = Sprite::create("tank_wheel.png");
	_wheelTopRight = Sprite::create("tank_wheel.png");
	_wheelBottomRight = Sprite::create("tank_wheel.png");
	_wheelBottomLeft = Sprite::create("tank_wheel.png");

	_body = Sprite::create("tank_body.png");

	_cannonRoot = Node::create();
	_body->addChild(_cannonRoot);

	_tankRoot->addChild(_wheelTopLeft);
	_wheelTopLeft->setPosition(Vec2(-_body->getContentSize().width / 2.7f, _body->getContentSize().height / 2.7f));

	_tankRoot->addChild(_wheelTopRight);
	_wheelTopRight->setPosition(Vec2(_body->getContentSize().width / 2.7f, _body->getContentSize().height / 2.7f));

	_tankRoot->addChild(_wheelBottomRight);
	_wheelBottomRight->setPosition(Vec2(_body->getContentSize().width / 2.7f, -_body->getContentSize().height / 2.7f));

	_tankRoot->addChild(_wheelBottomLeft);
	_wheelBottomLeft->setPosition(Vec2(-_body->getContentSize().width / 2.7f, -_body->getContentSize().height / 2.7f));

	_tankRoot->addChild(_body);
}

void Tank::attachToWorld()
{
	_world->getLayerByName(GameWorld::MAIN_LAYER)->addChild(_tankRoot);
}

GameObjectType Tank::getType() const
{
	return GameObjectType::TANK;
}

void Tank::onDeath()
{

}

void Tank::update(float dt)
{
	_tankRoot->setPosition(_point->getPosition());
	_tankRoot->setRotation(_point->getAngle());
}

void Tank::setPhysicsPoint(SimplePhysicsPoint *point)
{
	_point = point;
}

void Tank::moveLeft()
{
	_point->setAngularVelocity(-ROTATION_SPEED);
}

void Tank::moveRight()
{
	_point->setAngularVelocity(ROTATION_SPEED);
}

void Tank::stopMoveLeft()
{
	stopRotate();
}

void Tank::stopMoveRight()
{
	stopRotate();
}

void Tank::moveForward()
{
	float angle = CC_DEGREES_TO_RADIANS(_point->getAngle() + 90.0f);
	Vec2 velocity(-cosf(angle), sinf(angle));
	velocity *= MOVEMENT_SPEED;
	_point->setVelocity(velocity);
}

void Tank::stopMoveForward()
{
	stopMove();
}

void Tank::moveBackward()
{
	float angle = CC_DEGREES_TO_RADIANS(_point->getAngle() + 90.0f);
	Vec2 velocity(-cosf(angle), sinf(angle));
	velocity *= -MOVEMENT_SPEED;
	_point->setVelocity(velocity);
}

void Tank::stopMoveBackward()
{
	stopMove();
}

void Tank::fire()
{

}

void Tank::nextWeapon()
{

}

void Tank::prevWeapon()
{

}

void Tank::stopRotate()
{
	_point->setAngularVelocity(0.0f);
}

void Tank::stopMove()
{
	_point->setVelocity(Vec2(0.0f, 0.0f));
}

void TankBullet::init()
{

}

void TankBullet::attachToWorld()
{

}

GameObjectType TankBullet::getType() const
{
	return GameObjectType::TANK_BULLET;
}

float TankBullet::getDamageValue()
{
	return 1.0f;
}
