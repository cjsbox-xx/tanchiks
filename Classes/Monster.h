#pragma once
#include "BaseGameObject.h"
#include "DamageObject.h"
#include "SimplePhysicsWorld.h"

class Monster : public BaseGameObject, public SimpleDamageableObject, public SimpleDamageObject
{
public:
	virtual void init() override;
	virtual void attachToWorld() override;
	virtual void detachFromWorld() override;
	virtual GameObjectType getType() const = 0;

	virtual float getDamageValue() = 0;
	virtual float getLife() = 0;
	virtual float getArmor() = 0;
	virtual void onDeath() override;

	virtual std::string getSpriteName() = 0;
	void update(float dt);

	SimplePhysicsPoint* getPhysicsPoint() const;
	void setPhysicsPoint(SimplePhysicsPoint* physicsPoint);

	std::function<void(Monster *)> onDeathEvent = nullptr;

private:
	SimplePhysicsPoint *_physicsPoint;
	Sprite *_sprite;
};

class Monster1 : public Monster
{
public:
	virtual GameObjectType getType() const override;
	virtual float getDamageValue() override;
	virtual std::string getSpriteName() override;
	virtual float getLife() override;
	virtual float getArmor() override;
};
class Monster2 : public Monster
{
public:
	virtual GameObjectType getType() const override;
	virtual float getDamageValue() override;
	virtual std::string getSpriteName() override;
	virtual float getLife() override;
	virtual float getArmor() override;
};
class Monster3 : public Monster
{
public:
	virtual GameObjectType getType() const override;
	virtual float getDamageValue() override;
	virtual std::string getSpriteName() override;
	virtual float getLife() override;
	virtual float getArmor() override;
};