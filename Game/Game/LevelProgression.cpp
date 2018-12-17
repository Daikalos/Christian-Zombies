#include "stdafx.h"
#include "LevelProgression.h"
#include "GameInfo.h"

LevelProgression::LevelProgression()
{
	myLevel = 0;
	myAlpha = 0;
	myGreenColor = 144;
	mySwitchAlphaValue = false;
	mySwitchGreenValue = false;
	myLoadNewLevel = false;

	myBlackScreen.setSize(sf::Vector2f(1280, 720));
	myBlackScreen.setOrigin(sf::Vector2f(0, 0));
	myBlackScreen.setFillColor(sf::Color::Black);

	myArrow.setPointCount(7);
	myArrow.setFillColor(sf::Color(34, myGreenColor, 45));

	myArrow.setPoint(0, sf::Vector2f(130, 180));
	myArrow.setPoint(1, sf::Vector2f(60, 150));
	myArrow.setPoint(2, sf::Vector2f(130, 115));

	myArrow.setPoint(3, sf::Vector2f(100, 135));
	myArrow.setPoint(4, sf::Vector2f(200, 135));
	myArrow.setPoint(5, sf::Vector2f(200, 165));
	myArrow.setPoint(6, sf::Vector2f(100, 165));

	mySecondArrow = myArrow;
	mySecondArrow.setPosition(sf::Vector2f(GameInfo::GetWindow()->getSize().x, 0));
	mySecondArrow.scale(sf::Vector2f(-1, 1));
}


LevelProgression::~LevelProgression()
{
}

void LevelProgression::DrawArrows(float const &aDeltaTime)
{
	if (!mySwitchGreenValue)
	{
		if (myGreenColor + aDeltaTime * 160 <= 220)
		{
			myGreenColor += aDeltaTime * 160;
		}
		else
		{
			mySwitchGreenValue = true;
			myGreenColor = 220;
		}
	}
	else
	{
		if (myGreenColor - aDeltaTime * 160 >= 144)
		{
			myGreenColor -= aDeltaTime * 160;
		}
		else
		{
			mySwitchGreenValue = false;
			myGreenColor = 144;
		}
	}
	myArrow.setFillColor(sf::Color(34, myGreenColor, 45));
	mySecondArrow.setFillColor(sf::Color(34, myGreenColor, 45));

	GameInfo::GetWindow()->draw(mySecondArrow);
	GameInfo::GetWindow()->draw(myArrow);
}

void LevelProgression::LoadNewLevel(Background &aBackground, Player &aPlayer, float const &aDeltaTime)
{
	if (myLoadNewLevel)
	{
		if (!mySwitchAlphaValue)
		{
			if (myAlpha + aDeltaTime * 170 <= 255)
			{
				myAlpha += aDeltaTime * 170;
			}
			else
			{
				mySwitchAlphaValue = true;
				myAlpha = 255;
				myLevel++; //Exempel...

				aBackground.RandomizeProps();
				if (aPlayer.GetPosition().x < (GameInfo::GetWindow()->getSize().x / 2))
				{
					aPlayer.RecieveMessage(MessageType::WestPlayerPos);
					aBackground.SetGroundSpritePos(sf::Vector2f(-520, 0));
					aBackground.SetBackgroundSpritePos(sf::Vector2f(-320, 0));
				}
				else
				{
					aPlayer.RecieveMessage(MessageType::EastPlayerPos);
					aBackground.SetGroundSpritePos(sf::Vector2f(0, 0));
					aBackground.SetBackgroundSpritePos(sf::Vector2f(0, 0));
				}
			}
		}
		else
		{
			if (myAlpha - aDeltaTime * 170 >= 0)
			{
				myAlpha -= aDeltaTime * 170;
			}
			else
			{
				mySwitchAlphaValue = false;
				myLoadNewLevel = false;
				myAlpha = 0;
			}
		}

		myBlackScreen.setFillColor(sf::Color(0, 0, 0, myAlpha));
		GameInfo::GetWindow()->draw(myBlackScreen);
	}
}

void LevelProgression::SetLoadNewLevel(bool aNewValue)
{
	this->myLoadNewLevel = aNewValue;
}
