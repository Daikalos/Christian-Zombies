#include "stdafx.h"
#include "Entity.h"

#pragma region Get/Set
float Entity::GetHealthPoints() const
{
	return myHealthPoints;
}
void Entity::SetHealthPoints(float someHealthPoints)
{
	this->myHealthPoints = GetMaxHealth() < someHealthPoints ? GetMaxHealth() : someHealthPoints;
}

float Entity::GetMaxHealth() const
{
	return myMaxHealth;
}
void Entity::SetMaxHealth(float aMaxHealthValue)
{
	this->myMaxHealth = aMaxHealthValue;
}

float Entity::GetDamageValue() const
{
	return myDamageValue;
}
void Entity::SetDamageValue(float aDamageValue)
{
	this->myDamageValue = aDamageValue;
}
#pragma endregion

void Entity::Init()
{
	SetMaxHealth(20.0f);
	SetHealthPoints(20.0f);
	SetDamageValue(5.0f);
}

void Entity::Update()
{
}

void Entity::Draw()
{
}


void Entity::Move()
{
}

void Entity::Attack()
{
}

