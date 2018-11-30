#ifndef ENTITY_HEADER
#define ENTITY_HEADER

#include "stdafx.h"
#include <SFML/Graphics.hpp>

class Entity 
{
public:
	float GetHealthPoints() const;
	void SetHealthPoints(float someHealthPoints);

	float GetMaxHealth() const;

	float GetDamageValue() const;
	void SetDamageValue(float aDamageValue);

	virtual void Init();
	virtual void Update(const float &aDeltaTimeValue);
	virtual void Draw(sf::RenderWindow *aWindow);

	virtual void Move();
	virtual void Attack();
protected:
	float myDeltaTime;

	float myHealthPoints;
	float myMaxHealth;

	float myDamageValue;

	void SetMaxHealth(float aMaxHealthValue);
};
#endif
