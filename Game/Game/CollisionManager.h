#ifndef COLLISIONMANAGER_HEADER
#define COLLISIONMANAGER_HEADER
#include "stdafx.h"
#include <SFML/Graphics.hpp>

class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();
	static bool CheckCollison(sf::IntRect, sf::IntRect);

};
#endif