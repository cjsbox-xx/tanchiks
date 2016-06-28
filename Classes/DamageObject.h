#pragma once

enum class DamageType
{
	SIMPLE_DAMAGE
};

class DamageInfo
{
public:
	virtual float getDamageValue() = 0;
	virtual DamageType getDamageType() = 0;
};

class DamageableObject; 

class DamageObject
{
public:
	virtual DamageInfo *getDamageInfo() = 0;
	virtual void onAfterDamage(DamageableObject *damageableObject)
	{
		
	}
protected:
};

class DamageableObject
{
public:
	virtual void damage(DamageInfo *damageInfo) = 0;
};

class SimpleDamageInfo : public DamageInfo
{
public:
	SimpleDamageInfo(float damageValue);
	virtual float getDamageValue() override;
	virtual DamageType getDamageType() override;
private:
	float _damageValue;
};

class SimpleDamageObject : public DamageObject
{
public:
	virtual DamageInfo* getDamageInfo() override;
	virtual float getDamageValue() = 0;
};

class SimpleDamageableObject : public DamageableObject
{
public:
	virtual void damage(DamageInfo* damageInfo) override;
	
	virtual void onDeath() = 0;

	virtual void setLifeValue(float lifeValue);
	virtual void setArmourValue(float armourValue);

	virtual float getLifeValue();
	virtual float getArmourValue();
protected:
	float _lifeValue;
	float _armourValue;
};