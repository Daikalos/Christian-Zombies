#include "stdafx.h"
#include "Player.h"
#include "GameInfo.h"

#include <cmath>
#include <iostream>

Player::Player()
{
	myPlayerDirection = 0;
	myAnimationState = 0;
	myPreviousState = 1;

	mySpeed = 5;
	myXMovementSpeed = 0;
	myYMovementSpeed = 0;

	SetMaxHealth(20.0f);
	SetHealthPoints(20.0f);
	SetDamageValue(5.0f);

	myTexture.loadFromFile("Textures/MainWalkCycle.png");
	myPosition = sf::Vector2f(GameInfo::GetWindow()->getSize().x / 2, GameInfo::GetWindow()->getSize().y - 100);
	myCLAP.myClass = PlayerClass::CLASS_BARBARIAN;
}

Player::~Player()
{

}

void Player::Init() { }
void Player::Update(const float &aDeltaTimeValue)
{
	myDeltaTime = aDeltaTimeValue;
	Move();
	Attack();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)) AddExperiencePoints(1);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) SetExperiencePoints(0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3)) SetLevel(1);

	if (myExperiencePoints > std::pow(10, 1 + (0.1f * myCLAP.myLevel))) 
	{
		myExperiencePoints -= std::pow(10, 1 + (0.1f * myCLAP.myLevel));
		myCLAP.myLevel++;
		std::cout << "Level Up!" << std::endl;
	}

	float tempExpProgress = myExperiencePoints / std::pow(10, 1 + (0.1f * myCLAP.myLevel));
	int tempBarLength = 500;

	sf::Font tempFont;

	myUIExpBackground.setPosition(10, 10);
	myUIExpBackground.setFillColor(sf::Color::Color(40, 40, 40, 255));
	myUIExpBackground.setSize(sf::Vector2f(tempBarLength, 20));

	myUIHPBackground.setPosition(GameInfo::GetWindow()->getSize().x - 10 - tempBarLength, 10);
	myUIHPBackground.setFillColor(sf::Color::Color(40, 40, 40, 255));
	myUIHPBackground.setSize(sf::Vector2f(tempBarLength, 20));

	myUIExpBar.setPosition(10, 10);
	myUIExpBar.setFillColor(sf::Color::Color(0, 175, 0, 255));
	myUIExpBar.setSize(sf::Vector2f(tempExpProgress * tempBarLength, 20));

	myUIHPBar.setPosition(GameInfo::GetWindow()->getSize().x - 10 - tempBarLength, 10);
	myUIHPBar.setFillColor(sf::Color::Color(175, 0, 0, 255));
	myUIHPBar.setSize(sf::Vector2f(myHealthPoints / myMaxHealth * tempBarLength, 20));

	myUILevel.setString(std::to_string(myCLAP.myLevel));
	myUILevel.setPosition(GameInfo::GetWindow()->getSize().x / 2, 10);
	myUILevel.setFillColor(sf::Color::Color(0, 0, 175, 255));
}
void Player::Draw(sf::RenderWindow *aWindow)
{
	if (myAnimationState == 0)
	{
		sf::IntRect tempRect;
		tempRect.height = myTexture.getSize().y / 2; tempRect.width = myTexture.getSize().x / 9; tempRect.left = 0; tempRect.top = 0;
		myAnimator.Animate(myTexture, tempRect, myPosition, 9, 2, 99999, aWindow, myPreviousState);
	}
	else
	{
		myAnimator.Animate(myTexture, mySourceRect, myPosition, 9, 2, 0.05, aWindow, myAnimationState);
	}

	aWindow->draw(myUIExpBackground);
	aWindow->draw(myUIHPBackground);
	aWindow->draw(myUIExpBar);
	aWindow->draw(myUIHPBar);
	aWindow->draw(myUILevel);
}

void Player::Move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		myAnimationState = 1; 
		myPreviousState = myAnimationState;
		myXMovementSpeed = -mySpeed;
		myPlayerDirection = 0;

		myXVirtualSpeed = -mySpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		myAnimationState = 2;
		myPreviousState = myAnimationState;
		myXMovementSpeed = mySpeed;
		myPlayerDirection = 1;

		myXVirtualSpeed = mySpeed;
	}
	if ((!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ^ myPosition.x < 100) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ^ myPosition.x > GameInfo::GetWindow()->getSize().x - 100))
	{
		myXMovementSpeed = 0;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		myXVirtualSpeed = 0;
		myXMovementSpeed = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		myXMovementSpeed = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		myAnimationState = myPreviousState;
		myYMovementSpeed = -mySpeed;
		myPlayerDirection = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		myAnimationState = myPreviousState;
		myYMovementSpeed = mySpeed;
		myPlayerDirection = 3;
	}
	if ((!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ^ myPosition.y - myYMovementSpeed < GameInfo::GetWindow()->getSize().y - 155) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ^ myPosition.y + myYMovementSpeed > GameInfo::GetWindow()->getSize().y - 65))
	{
		myYMovementSpeed = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		myYMovementSpeed = 0;
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		myAnimationState = 0;
	}

	//myPosition.move(myXMovementSpeed * myDeltaTime * 60, myYMovementSpeed * myDeltaTime * 60);
	myPosition.x = myPosition.x + myXMovementSpeed * myDeltaTime * 60;
	myPosition.y = myPosition.y + myYMovementSpeed * myDeltaTime * 60;
}

void Player::Attack()
{
	switch (myCLAP.myClass) 
	{
	case PlayerClass::CLASS_BARBARIAN:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !myAttackingFlag) //Attack 1
		{
			std::cout << "Started to Kick!" << std::endl;
			myCastTime = 0.5f; //In seconds
			myAttack1Flag = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !myAttackingFlag) //Attack 2
		{
			std::cout << "Started to Punch!" << std::endl;
			myCastTime = 1.0f;
			myAttack2Flag = true;
		}

		if (myAttack1Flag && myCastTime <= 0)
		{
			/*Attack enemy*/
			std::cout << "Kicked!" << std::endl;
			myAttack1Flag = false;
		}

		if (myAttack2Flag && myCastTime <= 0)
		{
			/*Attack enemy*/
			std::cout << "Punched!" << std::endl;
			myAttack2Flag = false;
		}
		break;
	case PlayerClass::CLASS_ARCHER:
		break;
	case PlayerClass::CLASS_ROGUE:
		break;
	}

	if (myAttack1Flag || myAttack2Flag)
	{
		myAttackingFlag = true;
	}
	else if (!myAttack1Flag && !myAttack2Flag)
	{
		myAttackingFlag = false;
	}

	if (myCastTime > 0)
	{
		myCastTime -= myDeltaTime;
	}

	/*
	Attack 1: Kick
	1. Start the attack cast time
	2. At the animation apex, check if an enemy is in the area
	3a. If an enemy is in the area, damage that enemy
	3b. If an enemy is not in in the area, finish the animation
	3c. If multiple enemies are in the area, damage the closest enemy

	Barbarian Attack 2: Punch
	1. Start the attack cast time
	2. At the animation apex, check if an enemy is in the area
	3a. If an enemy is in the area, damage that enemy
	3b. If an enemy is not in in the area, finish the animation
	3c. If multiple enemies are in the area, damage all of those enemies

	Archer Attack 2: Bow & Arrow
	1. Start the attack cast time
	2. When the cast time reaches 0, instantiate an arrow with a velocity in the direction the player faces
	3. If an enemy is hit by the arrow, damage that enemy

	Rogue Attack 2: Dagger
	1. Start the attack cast time
	2. If an enemy is within the area during the cast time, the player enters a 'stabbing' state
	3. Spamming 'Attack 2' will deal multiple blows within a set amount of time
	*/
}

void Player::AddExperiencePoints(float anExperienceValue)
{
	myExperiencePoints += anExperienceValue;
	std::cout << "Exp Add | " + std::to_string(myExperiencePoints) + " | " + std::to_string(std::pow(10, 1 + (0.1f * myCLAP.myLevel))) + " | " + std::to_string(myCLAP.myLevel) << std::endl;
}

void Player::SetExperiencePoints(float anExperienceValue)
{
	myExperiencePoints = anExperienceValue;
	std::cout << "Exp Set | " + std::to_string(myExperiencePoints) + " | " + std::to_string(std::pow(10, 1 + (0.1f * myCLAP.myLevel))) + " | " + std::to_string(myCLAP.myLevel) << std::endl;
}

void Player::SetLevel(float aLevel)
{
	myCLAP.myLevel = aLevel;
	myExperiencePoints = 0;
	std::cout << "Level Set | " + std::to_string(myExperiencePoints) + " | " + std::to_string(std::pow(10, 1 + (0.1f * myCLAP.myLevel))) + " | " + std::to_string(myCLAP.myLevel) << std::endl;
}

sf::Vector2f Player::GetPosition()
{
	return myPosition;
}

float Player::GetPlayerXVirtualSpeed()
{
	return myXVirtualSpeed;
}