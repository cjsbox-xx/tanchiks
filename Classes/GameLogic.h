#pragma once

class GameWorld;

class GameLogic : public Node
{
public:
	virtual bool init();
	virtual void worldLoaded() = 0;
	virtual void update(float delta) = 0;

	void setWorld(GameWorld *world);
protected:
	GameWorld *_world;
};