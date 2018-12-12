#ifndef COLLISION_HEADER
#define COLLISION_HEADER
#include "stdafx.h"
#include <SFML/Graphics.hpp>

class CollisionBox
{
public:
	CollisionBox();
	~CollisionBox();
	sf::IntRect DrawBox(sf::IntRect, sf::Vector2f);
};

#endif
