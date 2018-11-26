#include "stdafx.h"
#include <SFML/Graphics.hpp>

#ifndef ENEMY_HEADER
#define ENEMY_HEADER

class Enemy
{
public:
	Enemy();
	~Enemy();

	void Draw(sf::RenderWindow *aWindow);

	sf::RectangleShape GetShape();

private:
	sf::RectangleShape myEnemyShape;
};

#endif // !ENEMY_HEADER

