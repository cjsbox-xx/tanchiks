#include "SimpleGameContentLoader.h"
#include "GameContent.h"
#include "SimpleObject.h"
#include "Tank.h"
#include "MonstersPlace.h"

void SimpleGameContentLoader::load()
{
	_gameContent = new GameContent();
	BaseGameObject *gameObject = new SimpleObject();

	SimplePhysicsWorld *physicsWorld = new SimplePhysicsWorld(Rect(0.0f, 0.0f, 1000.0f, 1000.0f));
	_gameContent->setPhysicsWorld(physicsWorld);
	_gameContent->addGameObject(gameObject);
	
	Tank *tank = new Tank();
	tank->setName("Player");
	tank->setPhysicsPoint(physicsWorld->createPoint(Vec2(250.0f, 250.0f), 0.0f, 50.0f));
	_gameContent->addGameObject(tank);

	MonstersPlace *monstersPlace = new MonstersPlace();
	monstersPlace->setPhysicsPoint(physicsWorld->createPoint(Vec2(650.0f, 450.0f), 0.0f, 10.0f));
	monstersPlace->setMaxMonstersNumber(5);
	monstersPlace->setMonstersRadius(50.0f);
	_gameContent->addGameObject(monstersPlace);
}

GameContent* SimpleGameContentLoader::getGameContent()
{
	return _gameContent;
}
