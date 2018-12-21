#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy()
{
	myTexture.loadFromFile("Textures/ZombieCycle2.png");
	if ((rand() % 100) + 1 > 50)
	{ myPosition = sf::Vector2f(1500, (rand() % 200) + 500); }
	else
	{ myPosition = sf::Vector2f(-700, (rand() % 200) + 500); }
	myAnimationState = 1;
	sf::IntRect mySourceRect(0, 0, myTexture.getSize().x, myTexture.getSize().y);
}

Enemy::~Enemy()
{

}

void Enemy::Init() { }
void Enemy::Update(const float & aDeltaTimeValue, sf::Vector2f aPlayerPos) 
{
	myDestRect.width = 50;
	myDestRect.height = 50;
	myDestRect.top = myPosition.y;
	myDestRect.left = myPosition.x;
	myDeltaTime = aDeltaTimeValue;
	Move(aPlayerPos);
}
void Enemy::Draw(sf::Texture aTexture, sf::IntRect &aSourceRect, sf::Vector2f aPosition, int someColumns, int someRows, float anAninmationSpeed, sf::RenderWindow *aWindow)
{
	myAnimator.Animate(aTexture, aSourceRect, aPosition, someColumns, someRows, anAninmationSpeed, aWindow, myAnimationState);
}

void Enemy::Move(sf::Vector2f aPlayerPos) 
{
	int tempHorisontalStance = 60;
	int tempVerticalStance = 5;
	int tempSpeed = 2;
	if (myPosition.x > aPlayerPos.x + tempHorisontalStance)
	{
		myPosition.x = myPosition.x - tempSpeed * (myDeltaTime * 60);
		myAnimationState = 2;
	}
	else if (myPosition.x < aPlayerPos.x - tempHorisontalStance)
	{
		myPosition.x = myPosition.x + tempSpeed * (myDeltaTime * 60);
		myAnimationState = 1;
	}

	if (myPosition.y > aPlayerPos.y + tempVerticalStance)
	{
		myPosition.y = myPosition.y - tempSpeed * (myDeltaTime * 60);
	}
	else if (myPosition.y < aPlayerPos.y - tempVerticalStance)
	{
		myPosition.y = myPosition.y + tempSpeed * (myDeltaTime * 60);
	}
}
void Enemy::Attack() { }

void Enemy::RecieveMessage(const MessageType &aMessageType)
{
	if (aMessageType == MessageType::IsDead)
	{
		
	}
	if (aMessageType == MessageType::MoveEnemiesLeft)
	{
		myPosition.x -= 5;
	}
	if (aMessageType == MessageType::MoveEnemiesRight)
	{
		myPosition.x += 5;
	}
	if (aMessageType == MessageType::PauseEnemies)
	{

	}
}