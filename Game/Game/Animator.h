#ifndef ANIMATOR_HEADER
#define ANIMATOR_HEADER

#include "stdafx.h"
#include <SFML/Graphics.hpp>

class Animator
{
public:
	Animator();
	~Animator();
	void Animate(sf::Texture aTexture, sf::IntRect &aSourceRect, sf::Vector2f aPosition, int someColumns, int someRows, float anAninmationSpeed, sf::RenderWindow *aWindow);

private:
	sf::Clock myClock;
};

#endif