#include "stdafx.h"
#include "CollisionManager.h"

bool CollisionManager::CheckCollison(sf::IntRect aBox, sf::IntRect anotherBox)
{
	//printf("manager");
	if (aBox.intersects(anotherBox) || anotherBox.intersects(aBox))
	{
		//printf("true");
		return true;
	}
	else
	{
		//printf("false");
		return false;
	}
}
CollisionManager::CollisionManager()
{

}

CollisionManager::~CollisionManager()
{

}