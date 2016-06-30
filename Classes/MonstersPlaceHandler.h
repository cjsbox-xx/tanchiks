#pragma once 
#include "MonstersPlace.h"
#include "Monster.h"
#include "Tank.h"
class MonstersPlaceHandler
{
public:
	MonstersPlaceHandler(GameWorld *world, MonstersPlace* monstersPlace, Tank *tank);
	virtual void update(float dt);
	void createMonster();
private:
	GameWorld *_world;
	MonstersPlace *_monstersPlace;
	Tank *_tank;
	std::vector<Monster*> _monsters;
	std::vector<Monster*> _monsterToRemove;
};
