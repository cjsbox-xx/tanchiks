#include "SimplePhysicsWorld.h"

SimplePhysicsWorld::~SimplePhysicsWorld()
{
	for (auto point : _physicsPoints)
	{
		delete point;
	}
}

SimplePhysicsWorld::SimplePhysicsWorld(const Rect& worldBounds) : _worldBounds(worldBounds)
{

}

void SimplePhysicsWorld::update(float dt)
{
	for (auto point : _physicsPoints)
	{
		Vec2 position = point->getPosition();
		Vec2 velocity = point->getVelocity();
		Vec2 newPosition = position + velocity * dt;
		if (_worldBounds.containsPoint(newPosition))
		{
			point->setPosition(newPosition);
		}
		float angle = point->getAngle();
		float angularVelocity = point->getAngularVelocity();
		float newAngle = angle + angularVelocity * dt;
		point->setAngle(newAngle);
	}

	for (int i = 0; i < _physicsPoints.size() - 1; i++)
	{
		for (int j = i + 1; j < _physicsPoints.size(); j++)
		{
			SimplePhysicsPoint *pointA = _physicsPoints[i];
			SimplePhysicsPoint *pointB = _physicsPoints[j];
			if (pointA->getPosition().distance(pointB->getPosition()) <= pointA->getRadius() + pointB->getRadius())
			{
				if (_collisionCallback)
				{
					_collisionCallback->onPointsBeginContact(pointA, pointB);
				}
			}
		}
	}
}

SimplePhysicsPoint * SimplePhysicsWorld::createPoint(Vec2 position, float angle, float radius)
{
	SimplePhysicsPoint *physicsPoint = new SimplePhysicsPoint();
	physicsPoint->setPhysicsWorld(this);
	physicsPoint->setAngle(angle);
	physicsPoint->setAngularVelocity(0.0f);
	physicsPoint->setPosition(position);
	physicsPoint->setRadius(radius);
	physicsPoint->setVelocity(Vec2(0.0f, 0.0f));
	_physicsPoints.push_back(physicsPoint);
	return physicsPoint;
}

void SimplePhysicsWorld::destroyPoint(SimplePhysicsPoint *point)
{
	_physicsPoints.erase(std::find(_physicsPoints.begin(), _physicsPoints.end(), point));
}

void SimplePhysicsWorld::setCollisionCallback(SimplePhysicsWorldCollisionCallback *callback)
{
	_collisionCallback = callback;
}
