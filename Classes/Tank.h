#pragma once
#include "BaseGameObject.h"
#include "SimplePhysicsWorld.h"
#include "DamageObject.h"

class TankBullet : public BaseGameObject, public SimpleDamageObject
{
public:
	virtual void init() override;
	virtual void attachToWorld() override;
	virtual void detachFromWorld() override;
	virtual GameObjectType getType() const override;
	virtual void setInitialAngle(float angle);
	virtual void setInitialPosition(Vec2 position);
	virtual float getDamageValue()  = 0;
	virtual float getBulletSpeed() = 0;
	virtual std::string getSpriteName() = 0;
	SimplePhysicsPoint *getPhysicsPoint();
	void update(float dt);
private:
	SimplePhysicsPoint *_point;
	Sprite *_sprite;
};

class TankBullet1 : public TankBullet
{
public:
	virtual float getDamageValue() override;
	virtual float getBulletSpeed() override;
	virtual std::string getSpriteName() override;
};

class TankBullet2 : public TankBullet
{
public:
	virtual float getDamageValue() override;
	virtual float getBulletSpeed() override;
	virtual std::string getSpriteName() override;
};

class TankBullet3 : public TankBullet
{
public:
	virtual float getDamageValue() override;
	virtual float getBulletSpeed() override;
	virtual std::string getSpriteName() override;
};

class TankCannon
{
public:
	virtual void init() = 0;
	virtual void attachToNode(Node *node) = 0;
	virtual void detachFromNode(Node *node) = 0;
	virtual void setPosition(Vec2 position) = 0;
	virtual bool isAbleToFire() = 0;
	virtual TankBullet *tryCreateBullet();
protected:
	virtual TankBullet *createBullet() = 0;
};

class SimpleSpriteCannon : public TankCannon
{
public:
	virtual void init() override;
	virtual void attachToNode(Node* node) override;
	virtual void detachFromNode(Node* node) override;
	virtual void setPosition(Vec2 position) override;
	virtual std::string getSpriteName() = 0;
	virtual float getReloadTime() = 0;
	void update(float dt);
	virtual bool isAbleToFire() override;
protected:
	float _currentTime = 0.0f;
	Sprite *_sprite;
};

class TankCannon1 : public SimpleSpriteCannon
{
public:
	virtual TankBullet* createBullet() override;
	virtual float getReloadTime() override;
	virtual std::string getSpriteName() override;
};

class TankCannon2 : public SimpleSpriteCannon
{
public:
	virtual TankBullet* createBullet() override;
	virtual float getReloadTime() override;
	virtual std::string getSpriteName() override;
};

class TankCannon3 : public SimpleSpriteCannon
{
public:
	virtual TankBullet* createBullet() override;
	virtual float getReloadTime() override;
	virtual std::string getSpriteName() override;
};

class Tank : public BaseGameObject, public SimpleDamageableObject
{
public:
	static const float ROTATION_SPEED;
	static const float MOVEMENT_SPEED;
	virtual void init() override;
	virtual void attachToWorld() override;
	virtual void detachFromWorld() override;
	virtual GameObjectType getType() const override;

	virtual void onDeath() override;

	virtual void update(float dt);

	void setPhysicsPoint(SimplePhysicsPoint *point);
	SimplePhysicsPoint *getPhysicsPoint();

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

	void attachCannon(TankCannon *cannon);
	void attachCannon(int index);

	void detachCurrentCannon();
private:
	SimplePhysicsPoint *_point = nullptr;
	Node *_tankRoot;
	Sprite *_wheelTopLeft;
	Sprite *_wheelTopRight;
	Sprite *_wheelBottomRight;
	Sprite *_wheelBottomLeft;
	Sprite *_body;
	Node *_cannonRoot;
	int _currentCannonIndex = 0;
	std::vector<TankCannon*> _cannons;
};
