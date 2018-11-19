#include "stdafx.h"
#include "Animator.h"
#include <SFML\Graphics.hpp>

Animator::Animator()
{
	sf::Clock myClock;
	myClock.restart();
}

Animator::~Animator()
{

}

sf::Sprite Animator::Animate(sf::Texture aTexture, int aStartX, int aStartY, int aSpriteWidth, int aSpriteHeight, int someColumns, int someRows, float anAninmationSpeed)
{
	sf::IntRect tempSourceRect(aStartX, aStartY, aSpriteWidth, aSpriteHeight);
	sf::Sprite tempSprite(aTexture, tempSourceRect);

	if (myClock.getElapsedTime().asSeconds() > anAninmationSpeed)
	{
		if (tempSourceRect.left == aSpriteWidth * someColumns)
			tempSourceRect.left = 0;
		else
			tempSourceRect.left += aSpriteWidth;

		tempSprite.setTextureRect(tempSourceRect);
		myClock.restart();
		return tempSprite;
	}
}