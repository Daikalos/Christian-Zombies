#include "stdafx.h"
#include "Boss.h"
#include "GameInfo.h"

Boss::Boss()
{
	myHealthPoints = 200;
	myMaxHealth = 200;

	myTexture.loadFromFile("Textures/ZombieCycle1.png");
	myPosition = sf::Vector2f(rand() % 1000, rand() % 500);

	sf::IntRect mySourceRect(0, 0, myTexture.getSize().x / 12, myTexture.getSize().y);
}


Boss::~Boss()
{

}

void Boss::Init()
{

}
void Boss::Update(const float &aDeltaTime)
{
	Move();
	Attack();
}
void Boss::Draw()
{
	myAnimator.Animate(myTexture, mySourceRect, myPosition, 12, 1, 0.1, GameInfo::GetWindow(), 1);
}

void Boss::Move()
{

}
void Boss::Attack()
{

}

void Boss::RecieveMessage(const MessageType & aMessageType)
{

}
