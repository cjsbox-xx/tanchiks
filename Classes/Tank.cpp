#include "Tank.h"
#include "GameWorld.h"

const float Tank::ROTATION_SPEED = 55.0f;

const float Tank::MOVEMENT_SPEED = 150.0f;

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

	TankCannon1 *cannon1 = new TankCannon1();
	cannon1->init();
	TankCannon2 *cannon2 = new TankCannon2();
	cannon2->init();
	TankCannon3 *cannon3 = new TankCannon3();
	cannon3->init();

	_cannons.push_back(cannon1);
	_cannons.push_back(cannon2);
	_cannons.push_back(cannon3);

	_currentCannonIndex = 0;
	attachCannon(_currentCannonIndex);
}

void Tank::attachToWorld()
{
	_world->getLayerByName(GameWorld::MAIN_LAYER)->addChild(_tankRoot);
}

void Tank::detachFromWorld()
{

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
	_point->setUserData(this);
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
	auto bullet = _cannons[_currentCannonIndex]->tryCreateBullet();
	if (bullet)
	{
		bullet->initWithWorld(_world);
		bullet->setInitialAngle(_point->getAngle());
		bullet->setInitialPosition(_point->getPosition());
	}
}

void Tank::nextWeapon()
{
	detachCurrentCannon();
	_currentCannonIndex++;
	_currentCannonIndex %= _cannons.size();
	attachCannon(_currentCannonIndex);
}

void Tank::prevWeapon()
{
	detachCurrentCannon();
	_currentCannonIndex--;
	if (_currentCannonIndex < 0)
		_currentCannonIndex += _cannons.size();
	attachCannon(_currentCannonIndex);
}

void Tank::stopRotate()
{
	_point->setAngularVelocity(0.0f);
}

void Tank::stopMove()
{
	_point->setVelocity(Vec2(0.0f, 0.0f));
}

void Tank::attachCannon(TankCannon *cannon)
{
	cannon->attachToNode(_body);
	cannon->setPosition(Vec2(_body->getContentSize().width / 2.0f, _body->getContentSize().height / 2.0f));
}

void Tank::attachCannon(int index)
{
	attachCannon(_cannons[index]);
}

void Tank::detachCurrentCannon()
{
	_cannons[_currentCannonIndex]->detachFromNode(_body);
}

void TankBullet::init()
{
	_sprite = Sprite::create(getSpriteName());
	_sprite->schedule([&](float dt)
	{
		update(dt);
	}, "BulletUpdate");
	_point = _world->getGameContent()->getPhysicsWorld()->createPoint(Vec2(0.0f, 0.0f), 0.0f, 5.0f);
	_point->setUserData(this);
}

void TankBullet::attachToWorld()
{
	_world->getLayerByName(GameWorld::MAIN_LAYER)->addChild(_sprite);
}

void TankBullet::detachFromWorld()
{
	_world->getLayerByName(GameWorld::MAIN_LAYER)->removeChild(_sprite);
	_world->getGameContent()->getPhysicsWorld()->destroyPoint(_point);
}

GameObjectType TankBullet::getType() const
{
	return GameObjectType::TANK_BULLET;
}

void TankBullet::setInitialAngle(float angle)
{
	_point->setAngle(angle);
	float radians = CC_DEGREES_TO_RADIANS(angle + 90.0f);
	Vec2 velocity(-cosf(radians), sinf(radians));
	velocity *= getBulletSpeed();
	_point->setVelocity(velocity);
}

void TankBullet::setInitialPosition(Vec2 position)
{
	_point->setPosition(position);
}

SimplePhysicsPoint * TankBullet::getPhysicsPoint()
{
	return _point;
}

void TankBullet::update(float dt)
{
	_sprite->setPosition(_point->getPosition());
	_sprite->setRotation(_point->getAngle());
}

void SimpleSpriteCannon::init()
{
	_sprite = Sprite::create(getSpriteName());
	_sprite->retain();
	_sprite->schedule([&](float dt)
	{
		update(dt);
	}, "CannonUpdate");
}

void SimpleSpriteCannon::attachToNode(Node* node)
{
	node->addChild(_sprite);
}

void SimpleSpriteCannon::detachFromNode(Node* node)
{
	node->removeChild(_sprite, false);
}

void SimpleSpriteCannon::setPosition(Vec2 position)
{
	_sprite->setPosition(position);
}

void SimpleSpriteCannon::update(float dt)
{
	_currentTime += dt;
}

bool SimpleSpriteCannon::isAbleToFire()
{
	return _currentTime >= getReloadTime();
}

TankBullet* TankCannon1::createBullet()
{
	//ToDo Тупо. Переделать.
	_currentTime = 0.0f;
	return new TankBullet1();
}

float TankCannon1::getReloadTime()
{
	return 0.2f;
}

std::string TankCannon1::getSpriteName()
{
	return "tank_gun_1.png";
}

TankBullet* TankCannon2::createBullet()
{
	//ToDo Тупо. Переделать.
	_currentTime = 0.0f;
	return new TankBullet2();
}

float TankCannon2::getReloadTime()
{
	return 1.0f;
}

std::string TankCannon2::getSpriteName()
{
	return "tank_gun_2.png";
}

TankBullet* TankCannon3::createBullet()
{
	//ToDo Тупо. Переделать.
	_currentTime = 0.0f;
	return new TankBullet3();
}

float TankCannon3::getReloadTime()
{
	return 0.1f;
}

std::string TankCannon3::getSpriteName()
{
	return "tank_gun_3.png";
}

float TankBullet1::getDamageValue()
{
	return 1.0f;
}

float TankBullet1::getBulletSpeed()
{
	return 300.0f;
}

std::string TankBullet1::getSpriteName()
{
	return "bullet_1.png";
}

float TankBullet2::getDamageValue()
{
	return 0.5f;
}

float TankBullet2::getBulletSpeed()
{
	return 250.0f;
}

std::string TankBullet2::getSpriteName()
{
	return "bullet_2.png";
}

float TankBullet3::getDamageValue()
{
	return 0.8f;
}

float TankBullet3::getBulletSpeed()
{
	return 580.0f;
}

std::string TankBullet3::getSpriteName()
{
	return "bullet_3.png";
}

TankBullet * TankCannon::tryCreateBullet()
{
	if (isAbleToFire())
	{
		return createBullet();
	}
	return nullptr;
}
