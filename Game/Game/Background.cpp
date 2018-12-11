#include "stdafx.h"
#include "Background.h"
#include "GameInfo.h"


Background::Background()
{
	myBackgroundTexture.loadFromFile("Textures/VillageTexture.png");
	myGroundTexture.loadFromFile("Textures/GroundTexture.png");

	myBackgroundSprite.setTexture(myBackgroundTexture);
	myBackgroundSprite.setTextureRect(sf::IntRect(0, 0, myBackgroundTexture.getSize().x, myBackgroundTexture.getSize().y));
	myBackgroundSprite.setPosition(sf::Vector2f(-160, 0));

	myGroundSprite.setTexture(myGroundTexture);
	myGroundSprite.setTextureRect(sf::IntRect(0, 0, myGroundTexture.getSize().x, myGroundTexture.getSize().y));
	myGroundSprite.setPosition(sf::Vector2f(-260, 0));

	for (size_t i = 0; i < 3 + (rand() % 8); i++)
	{
		sf::Texture tempProp;
		std::string tempPathString = "Textures/BackgroundProp";
		tempPathString += std::to_string(rand() % 5);
		tempPathString += ".png";
		tempProp.loadFromFile(tempPathString);
		myPropTextures.push_back(tempProp);

		sf::Sprite tempSprite;
		myPropSprites.push_back(tempSprite);
	}
	
	for (size_t i = myPropTextures.size(); i > 0; i--)
	{
		myPropSprites[i - 1].setTexture(myPropTextures[i - 1]);
		myPropSprites[i - 1].setTextureRect(sf::IntRect(0, 0, myPropTextures[i - 1].getSize().x, myPropTextures[i - 1].getSize().y));
		myPropSprites[i - 1].setPosition(sf::Vector2f(-260 + (rand() % ((GameInfo::GetWindow()->getSize().x + 260))), GameInfo::GetWindow()->getSize().y - 80));
	}
}


Background::~Background()
{

}

void Background::Update(sf::Vector2f aPlayerPosition, float aPlayerSpeed, const float &aDeltaTimeValue)
{
	if (myGroundSprite.getPosition().x - aPlayerSpeed < 0 && myGroundSprite.getPosition().x + myGroundSprite.getGlobalBounds().width - aPlayerSpeed > GameInfo::GetWindow()->getSize().x)
	{
		if (aPlayerPosition.x < 100 - aPlayerSpeed || aPlayerPosition.x > GameInfo::GetWindow()->getSize().x - 100 - aPlayerSpeed)
		{
			myBackgroundSprite.setPosition(myBackgroundSprite.getPosition().x - (aPlayerSpeed * 0.25 * aDeltaTimeValue * 60),
				myBackgroundSprite.getPosition().y);
			myGroundSprite.setPosition(myGroundSprite.getPosition().x - (aPlayerSpeed * aDeltaTimeValue * 60), 
				myGroundSprite.getPosition().y);
			for (size_t i = myPropSprites.size(); i > 0; i--)
			{
				myPropSprites[i - 1].setPosition(myPropSprites[i - 1].getPosition().x - (aPlayerSpeed * 1.5 * aDeltaTimeValue * 60), 
					myPropSprites[i - 1].getPosition().y);
			}
		}
	}
}

void Background::DrawBackground()
{
	GameInfo::GetWindow()->draw(myBackgroundSprite);
	GameInfo::GetWindow()->draw(myGroundSprite);
}

void Background::DrawProps()
{
	for (size_t i = myPropSprites.size(); i > 0; i--)
	{
		GameInfo::GetWindow()->draw(myPropSprites[i - 1]);
	}
}
