#pragma once
class GameContent;

class GameContentLoader
{
public:
	virtual void load() = 0;
	virtual GameContent *getGameContent() = 0;
};
