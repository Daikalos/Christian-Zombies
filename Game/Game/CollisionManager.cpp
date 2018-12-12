#include "CollisionManager.h"
#include "CollisionManager.h"

bool CollisionManager::CheckCollison(sf::IntRect aBox, sf::IntRect anotherBox)
{
	if (aBox.intersects(anotherBox) || anotherBox.intersects(aBox))
	{
		return true;
	}
	else
	{
		return false;
	}
}