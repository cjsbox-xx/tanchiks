#pragma once
#include "BaseGameObject.h"
#include "SimplePhysicsWorld.h"

class MonstersPlace : public BaseGameObject
{
public:
	virtual void init() override;
	virtual void attachToWorld() override;
	virtual void detachFromWorld() override;
	virtual GameObjectType getType() const override;
	void update(float dt);

	SimplePhysicsPoint* getPhysicsPoint() const;
	void setPhysicsPoint(SimplePhysicsPoint* physicsPoint);
	float getMonstersRadius() const;
	void setMonstersRadius(float monstersRadius);
	int getMaxMonstersNumber() const;
	void setMaxMonstersNumber(int maxMonstersNumber);
private:
	Sprite *_home;
	SimplePhysicsPoint *_physicsPoint;
	float _monstersRadius;
	int _maxMonstersNumber;
};
