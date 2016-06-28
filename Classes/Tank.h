#pragma once
#include "BaseGameObject.h"
#include "SimplePhysicsWorld.h"
#include "DamageObject.h"

class TankBullet : public BaseGameObject, public SimpleDamageObject
{
public:
	virtual void init() override;
	virtual void attachToWorld() override;
	virtual GameObjectType getType() const override;
	virtual float getDamageValue() override;
private:
	SimplePhysicsPoint *_point;
	Sprite *_sprite;
};

class TankCannon
{
public:
	virtual void attachToNode(Node *node) = 0;
};

class Tank : public BaseGameObject, public SimpleDamageableObject
{
public:
	static const float ROTATION_SPEED;
	static const float MOVEMENT_SPEED;
	virtual void init() override;
	virtual void attachToWorld() override;
	virtual GameObjectType getType() const override;

	virtual void onDeath() override;

	virtual void update(float dt);

	void setPhysicsPoint(SimplePhysicsPoint *point);

	void moveLeft();
	void moveRight();
	void stopMoveLeft();
	void stopMoveRight(); 
	void moveForward();
	void stopMoveForward();
	void moveBackward();
	void stopMoveBackward();
	void fire();
	void nextWeapon();
	void prevWeapon();

	void stopRotate();
	void stopMove();
private:
	SimplePhysicsPoint *_point = nullptr;
	Node *_tankRoot;
	Sprite *_wheelTopLeft;
	Sprite *_wheelTopRight;
	Sprite *_wheelBottomRight;
	Sprite *_wheelBottomLeft;
	Sprite *_body;
	Node *_cannonRoot;
};
