#include "stdafx.h"
#include "Player.h"
#include "GameInfo.h"

#include <iostream>

Player::Player()
{
	myPlayerDirection = 0;
	mySpeed = 5;

	myXMovementSpeed = 0;
	myYMovementSpeed = 0;
	myMaxXMovementSpeed = mySpeed;
	myMaxYMovementSpeed = mySpeed;

	SetMaxHealth(20.0f);
	SetHealthPoints(20.0f);
	SetDamageValue(5.0f);

	myPlayerShape.setSize(sf::Vector2f(50, 100));
	myPlayerShape.setPosition(sf::Vector2f((GameInfo::GetWindow()->getSize().x / 2) - (myPlayerShape.getSize().x / 2),
		(GameInfo::GetWindow()->getSize().y / 2) - (myPlayerShape.getSize().y / 2)));
	myPlayerShape.setFillColor(sf::Color::Blue);

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
}
void Player::Draw(sf::RenderWindow *aWindow)
{
	aWindow->draw(myPlayerShape);
}

void Player::Move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && myXMovementSpeed > -myMaxXMovementSpeed)
	{
		myXMovementSpeed -= (float)(0.70 * myDeltaTime * 60);
		myPlayerDirection = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && myXMovementSpeed < myMaxXMovementSpeed)
	{
		myXMovementSpeed += (float)(0.70 * myDeltaTime * 60);
		myPlayerDirection = 1;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		myXMovementSpeed = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && myYMovementSpeed > -myMaxYMovementSpeed)
	{
		myYMovementSpeed -= (float)(0.70 * myDeltaTime * 60);
		myPlayerDirection = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && myYMovementSpeed < myMaxYMovementSpeed)
	{
		myYMovementSpeed += (float)(0.70 * myDeltaTime * 60);
		myPlayerDirection = 3;
	}
	if ((!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ^ myPlayerShape.getPosition().y < GameInfo::GetWindow()->getSize().y / 4) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ^ myPlayerShape.getPosition().y > GameInfo::GetWindow()->getSize().y * 2 / 3))
	{
		myYMovementSpeed = 0;
	}

	myPlayerShape.move(myXMovementSpeed * myDeltaTime * 60, myYMovementSpeed * myDeltaTime * 60);
}

void Player::Attack()
{
	switch (myCLAP.myClass) {
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