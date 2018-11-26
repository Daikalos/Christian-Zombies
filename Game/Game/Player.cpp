#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	myPlayerDirection = 0;
	mySpeed = 5;

	myXMovementSpeed = 0;
	myYMovementSpeed = 0;
	myMaxXMovementSpeed = mySpeed;
	myMaxYMovementSpeed = mySpeed;

	myPlayerShape.setPosition(sf::Vector2f(100, 100));
	myPlayerShape.setSize(sf::Vector2f(50, 100));
	myPlayerShape.setFillColor(sf::Color::Blue);
}

Player::~Player()
{

}

void Player::Update(const float &aDeltaTime, bool &tempSpacePressed)
{
	PlayerMovement(aDeltaTime);
	PlayerAttack(aDeltaTime, tempSpacePressed);
}

void Player::Draw(sf::RenderWindow *aWindow)
{
	aWindow->draw(myPlayerShape);
}

void Player::PlayerMovement(const float &aDeltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && myXMovementSpeed > -myMaxXMovementSpeed)
	{
		myXMovementSpeed -= (float)(0.70 * aDeltaTime * 60);
		myPlayerDirection = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && myXMovementSpeed < myMaxXMovementSpeed)
	{
		myXMovementSpeed += (float)(0.70 * aDeltaTime * 60);
		myPlayerDirection = 1;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		myXMovementSpeed = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && myYMovementSpeed > -myMaxYMovementSpeed)
	{
		myYMovementSpeed -= (float)(0.70 * aDeltaTime * 60);
		myPlayerDirection = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && myYMovementSpeed < myMaxYMovementSpeed)
	{
		myYMovementSpeed += (float)(0.70 * aDeltaTime * 60);
		myPlayerDirection = 3;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{ 
		myYMovementSpeed = 0; 
	}

	myPlayerShape.move(myXMovementSpeed * aDeltaTime * 60, myYMovementSpeed * aDeltaTime * 60);
}

void Player::PlayerAttack(const float &aDeltaTime, bool &tempSpacePressed)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !tempSpacePressed)
	{
		//ATTACK HERE
		tempSpacePressed = true;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		tempSpacePressed = false;
	}
}
