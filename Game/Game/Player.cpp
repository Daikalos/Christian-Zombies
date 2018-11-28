#include "stdafx.h"
#include "Player.h"
#include "GameInfo.h"

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
	myPlayerShape.setPosition(sf::Vector2f(	(GameInfo::GetWindow()->getSize().x / 2) - (myPlayerShape.getSize().x / 2), 
											(GameInfo::GetWindow()->getSize().y / 2) - (myPlayerShape.getSize().y / 2)));
	myPlayerShape.setFillColor(sf::Color::Blue);
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && myXMovementSpeed > -myMaxXMovementSpeed)
	{
		myXMovementSpeed -= (float)(0.70 * myDeltaTime * 60);
		myPlayerDirection = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && myXMovementSpeed < myMaxXMovementSpeed)
	{
		myXMovementSpeed += (float)(0.70 * myDeltaTime * 60);
		myPlayerDirection = 1;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		myXMovementSpeed = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && myYMovementSpeed > -myMaxYMovementSpeed)
	{
		myYMovementSpeed -= (float)(0.70 * myDeltaTime * 60);
		myPlayerDirection = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && myYMovementSpeed < myMaxYMovementSpeed)
	{
		myYMovementSpeed += (float)(0.70 * myDeltaTime * 60);
		myPlayerDirection = 3;
	}
	if ((!sf::Keyboard::isKeyPressed(sf::Keyboard::W) ^ myPlayerShape.getPosition().y < GameInfo::GetWindow()->getSize().y / 4) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::S) ^ myPlayerShape.getPosition().y > GameInfo::GetWindow()->getSize().y * 2 / 3))
	{
		myYMovementSpeed = 0;
	}

	myPlayerShape.move(myXMovementSpeed * myDeltaTime * 60, myYMovementSpeed * myDeltaTime * 60);
}
void Player::Attack() 
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !mySpacePressedFlag)
	{
		//ATTACK HERE
		mySpacePressedFlag = true;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		mySpacePressedFlag = false;
	}
}