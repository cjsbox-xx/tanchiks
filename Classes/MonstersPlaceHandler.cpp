#include "MonstersPlaceHandler.h"
#include "GameWorld.h"

MonstersPlaceHandler::MonstersPlaceHandler(GameWorld *world, MonstersPlace* monstersPlace) : 
_world(world), _monstersPlace(monstersPlace)
{

}

void MonstersPlaceHandler::update(float dt)
{
	for (auto monster : _monsterToRemove)
	{
		monster->detachFromWorld();
		_monsters.erase(std::find(_monsters.begin(), _monsters.end(), monster));
		delete monster;
	}
	_monsterToRemove.clear();
	int maxMonstersNumber = _monstersPlace->getMaxMonstersNumber();
	if (_monsters.size() < maxMonstersNumber)
	{
		int monstersCount = maxMonstersNumber - _monsters.size();
		for (int i = 0; i < monstersCount; i++)
		{
			createMonster();
		}
	}
}

void MonstersPlaceHandler::createMonster()
{
	Monster *monster = nullptr;

	//ToDo Разделить это всё на фабрики.
	int monsterType = rand() % 3;
	switch (monsterType)
	{
	case 0:
		monster = new Monster1();
		break;
	case 1:
		monster = new Monster2();
		break;
	case 2:
		monster = new Monster3();
		break;
	}
	int angle = rand() % 360;
	Vec2 position(_monstersPlace->getPhysicsPoint()->getPosition().x + cosf(angle) * _monstersPlace->getMonstersRadius(),
		_monstersPlace->getPhysicsPoint()->getPosition().y + sinf(angle) * _monstersPlace->getMonstersRadius());

	monster->setPhysicsPoint(_world->getGameContent()->getPhysicsWorld()->createPoint(position, 0.0f, 10.0f));

	monster->initWithWorld(_world);
	_monsters.push_back(monster);
	monster->onDeathEvent = [&](Monster *deadMonster)
	{
		_monsterToRemove.push_back(deadMonster);
	};

}
