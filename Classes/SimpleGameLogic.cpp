#include "SimpleGameLogic.h"
#include "GameWorld.h"
#include "MonstersPlace.h"

void SimpleGameLogic::worldLoaded()
{
	_physicsWorld = _world->getGameContent()->getPhysicsWorld();
	_physicsWorld->setCollisionCallback(this);

	_tank = static_cast<Tank*>(_world->getGameContent()->getObjectByName("Player"));

	ControllerManager::getInstance()->registerListener(this);

	std::vector<MonstersPlace*> monstersPlaces = _world->getGameContent()->getObjectsByTypeName<MonstersPlace>(GameObjectType::MONSTERS_PLACE);
	for (auto monstersPlace : monstersPlaces)
	{
		MonstersPlaceHandler *handler = new MonstersPlaceHandler(_world, monstersPlace);
		_handlers.push_back(handler);
	}
}

void SimpleGameLogic::update(float delta)
{
	_physicsWorld->update(delta);
	for (auto handler : _handlers)
	{
		handler->update(delta);
	}
}

void SimpleGameLogic::onKeyDown(EventKeyboard::KeyCode keyCode)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		_tank->moveLeft();
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		_tank->moveRight();
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		_tank->moveForward();
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
	{
		_tank->moveBackward();
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_X)
	{
		_tank->fire();
	}
}

void SimpleGameLogic::onKeyPress(EventKeyboard::KeyCode keyCode)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_Q)
	{
		_tank->prevWeapon();
	} else if (keyCode == EventKeyboard::KeyCode::KEY_W)
	{
		_tank->nextWeapon();
	}
}

void SimpleGameLogic::onKeyUp(EventKeyboard::KeyCode keyCode)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		_tank->stopMoveLeft();
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		_tank->stopMoveRight();
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		_tank->stopMoveBackward();
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
	{
		_tank->stopMoveBackward();
	}
}

void SimpleGameLogic::onPointsBeginContact(SimplePhysicsPoint* pointA, SimplePhysicsPoint* pointB)
{
	BaseGameObject *gameObjectA = static_cast<BaseGameObject*>(pointA->getUserData());
	BaseGameObject *gameObjectB = static_cast<BaseGameObject*>(pointB->getUserData());

	//ToDo как-то надо обойти эту проверку
	if (gameObjectA->getType() == GameObjectType::TANK && gameObjectB->getType() == GameObjectType::TANK_BULLET
		|| gameObjectB->getType() == GameObjectType::TANK && gameObjectA->getType() == GameObjectType::TANK_BULLET)
	{
		return;
	}

	if (isMonster(gameObjectA) && isMonster(gameObjectB))
	{
		return;
	}

	DamageableObject *damageableObjectA = dynamic_cast<DamageableObject*>(gameObjectA);
	DamageObject *damageObjectB = dynamic_cast<DamageObject*>(gameObjectB);

	if (damageableObjectA && damageObjectB)
	{
		DamageInfo *damageInfo = damageObjectB->getDamageInfo();
		damageableObjectA->damage(damageInfo);
		delete damageInfo;
	}
	DamageableObject *damageableObjectB = dynamic_cast<DamageableObject*>(gameObjectB);
	DamageObject *damageObjectA = dynamic_cast<DamageObject*>(gameObjectA);
	if (damageableObjectB && damageObjectA)
	{
		DamageInfo *damageInfo = damageObjectA->getDamageInfo();
		damageableObjectB->damage(damageInfo);
		delete damageInfo;
	}
}

void SimpleGameLogic::onPointReachedBorder(SimplePhysicsPoint* point)
{
	BaseGameObject *gameObject = static_cast<BaseGameObject*>(point->getUserData());
	if (gameObject)
	{
		if (gameObject->getType() == GameObjectType::TANK_BULLET)
		{
			scheduleOnce([=](float dt){
				gameObject->detachFromWorld();
				delete gameObject;
			}, 0.0f, "DestroyGameObject");
		}
	}
}

bool SimpleGameLogic::isMonster(BaseGameObject *gameObject)
{
	return gameObject->getType() == GameObjectType::MONSTER1 
		|| gameObject->getType() == GameObjectType::MONSTER2
		|| gameObject->getType() == GameObjectType::MONSTER3;
}
