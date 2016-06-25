#pragma once

class GameWorld;

class WorldLoader
{
public:
	virtual void load() = 0;
	virtual GameWorld *getWorld() = 0;
};
