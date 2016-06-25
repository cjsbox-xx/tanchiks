#pragma once
#include "BaseGameObject.h"

class SimpleObject : public BaseGameObject
{
public:
	virtual void init() override;
	virtual void attachToWorld() override;
	virtual GameObjectType getType() const override;
private:
	Sprite *_sprite;
};
