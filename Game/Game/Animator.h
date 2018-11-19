#ifndef ANIMATOR_HEADER
#define ANIMATOR_HEADER

#include "stdafx.h"
#include <SFML/Graphics.hpp>

class Animator
{
public:
	Animator();
	~Animator();
	sf::Sprite Animate(sf::Texture aTexture, int aStartX, int aStartY, int aSpriteWidth, int aSpriteHeight, int someColumns, int someRows, float anAnimationSpeed);

private:
	sf::Clock myClock;
};

#endif