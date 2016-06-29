#pragma once
#include "BasePhysicsWorld.h"

class SimplePhysicsWorld;

class SimplePhysicsPoint
{
public:

	SimplePhysicsWorld* getPhysicsWorld() const
	{
		return _physicsWorld;
	}

	void setPhysicsWorld(SimplePhysicsWorld* physicsWorld)
	{
		_physicsWorld = physicsWorld;
	}

	Vec2 getPosition() const
	{
		return _position;
	}

	void setPosition(const Vec2& position)
	{
		_position = position;
	}

	float getAngle() const
	{
		return _angle;
	}

	void setAngle(float angle)
	{
		_angle = angle;
	}

	Vec2 getVelocity() const
	{
		return _velocity;
	}

	void setVelocity(const Vec2& velocity)
	{
		_velocity = velocity;
	}

	float getAngularVelocity() const
	{
		return _angularVelocity;
	}

	void setAngularVelocity(float angularVelocity)
	{
		_angularVelocity = angularVelocity;
	}

	float getRadius() const
	{
		return _radius;
	}

	void setRadius(float radius)
	{
		_radius = radius;
	}

	void* getUserData() const
	{
		return _userData;
	}

	void setUserData(void* userData)
	{
		_userData = userData;
	}

private:
	SimplePhysicsWorld *_physicsWorld;
	Vec2 _position = Vec2(0.0f, 0.0f);
	float _angle = 0.0f;
	Vec2 _velocity = Vec2(0.0f, 0.0f);
	float _angularVelocity = 0.0f;
	float _radius = 1.0f;
	void *_userData = nullptr;
};

class SimplePhysicsWorldCollisionCallback
{
public:
	virtual void onPointsBeginContact(SimplePhysicsPoint *pointA, SimplePhysicsPoint *pointB) = 0;
	virtual void onPointReachedBorder(SimplePhysicsPoint *point) = 0;
};

class SimplePhysicsWorld : public BasePhysicsWorld
{
public:
	~SimplePhysicsWorld();
	SimplePhysicsWorld(const Rect& worldBounds);
	virtual void update(float dt) override;
	SimplePhysicsPoint *createPoint(Vec2 position, float angle, float radius);
	void destroyPoint(SimplePhysicsPoint *point);
	void setCollisionCallback(SimplePhysicsWorldCollisionCallback *callback);
private:
	Rect _worldBounds;
	std::vector<SimplePhysicsPoint*> _physicsPoints;
	SimplePhysicsWorldCollisionCallback *_collisionCallback = nullptr;
};
