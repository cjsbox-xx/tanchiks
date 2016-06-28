#include "DamageObject.h"

SimpleDamageInfo::SimpleDamageInfo(float damageValue) : _damageValue(damageValue)
{

}

float SimpleDamageInfo::getDamageValue()
{
	return _damageValue;
}

DamageType SimpleDamageInfo::getDamageType()
{
	return DamageType::SIMPLE_DAMAGE;
}

DamageInfo* SimpleDamageObject::getDamageInfo()
{
	return new SimpleDamageInfo(getDamageValue());
}

void SimpleDamageableObject::damage(DamageInfo* damageInfo)
{
	if (_lifeValue > 0)
	{
		_lifeValue = _lifeValue - damageInfo->getDamageValue() * (1.0f - _armourValue);
		if (_lifeValue < 0)
		{
			onDeath();
		}
	} 
}

void SimpleDamageableObject::setLifeValue(float lifeValue)
{
	_lifeValue = lifeValue;
}

void SimpleDamageableObject::setArmourValue(float armourValue)
{
	_armourValue = armourValue;
}

float SimpleDamageableObject::getLifeValue()
{
	return _lifeValue;
}

float SimpleDamageableObject::getArmourValue()
{
	return _armourValue;
}
