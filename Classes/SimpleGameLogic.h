#pragma once
#include "GameLogic.h"

class SimpleGameLogic : public GameLogic
{
public:
	virtual void worldLoaded() override;
	virtual void update(float delta) override;
private:

};
