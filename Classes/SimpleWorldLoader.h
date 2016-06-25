#pragma once
#include "WorldLoader.h"

class SimpleWorldLoader : public WorldLoader
{
public:
	virtual void load() override;
	virtual GameWorld* getWorld() override;
private:
	GameWorld *_world = nullptr;
};
