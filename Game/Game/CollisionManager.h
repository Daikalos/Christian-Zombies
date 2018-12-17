#ifndef COLLISIONMANAGER_HEADER
#define COLLISIONMANAGER_HEADER
#include "stdafx.h"
#include <SFML/Graphics.hpp>

class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();
	bool CheckCollison(sf::IntRect, sf::IntRect);

private:

};

CollisionManager::CollisionManager()
{

}

CollisionManager::~CollisionManager()
{

}

#endif