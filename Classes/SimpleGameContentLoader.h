#pragma once
#include "GameContentLoader.h"
class GameContent;
class SimpleGameContentLoader : public GameContentLoader
{
public:
	virtual void load() override;
	virtual GameContent* getGameContent() override;
private:
	GameContent *_gameContent;
};
