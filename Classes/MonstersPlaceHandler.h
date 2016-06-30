#pragma once 
#include "MonstersPlace.h"
#include "Monster.h"

class MonstersPlaceHandler
{
public:
	MonstersPlaceHandler(GameWorld *world, MonstersPlace* monstersPlace);
	virtual void update(float dt);
	void createMonster();
private:
	GameWorld *_world;
	MonstersPlace *_monstersPlace;
	std::vector<Monster*> _monsters;
	std::vector<Monster*> _monsterToRemove;
};
