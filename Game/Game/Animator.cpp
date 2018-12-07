#include "stdafx.h"
#include "Animator.h"
#include <SFML\Graphics.hpp>
#include "GameInfo.h"

Animator::Animator()
{
	sf::Clock myClock;
	myClock.restart();
}

Animator::~Animator()
{

}

void Animator::Animate(sf::Texture aTexture, sf::IntRect &aSourceRect, sf::Vector2f aPosition, int someColumns, int someRows, float anAninmationSpeed, sf::RenderWindow *aWindow, int RowToAnimate)
{
	int tempSpriteWidth = aTexture.getSize().x / someColumns;
	int tempSpriteHeight = aTexture.getSize().y / someRows;

	sf::Sprite tempSprite(aTexture, aSourceRect);

	if (myClock.getElapsedTime().asSeconds() > anAninmationSpeed)
	{
		if (aSourceRect.left == (tempSpriteWidth * someColumns) - tempSpriteWidth)
			aSourceRect.left = 0;
		else
			aSourceRect.left += tempSpriteWidth;

		myClock.restart();
	}
	tempSprite.setPosition(aPosition);
	aSourceRect.height = tempSpriteHeight * RowToAnimate;
	aSourceRect.top = tempSpriteHeight * (RowToAnimate - 1);
	tempSprite.setTextureRect(aSourceRect);
	aSourceRect.width = tempSpriteWidth;
	GameInfo::GetWindow()->draw(tempSprite);
}