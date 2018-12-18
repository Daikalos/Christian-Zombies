#include "stdafx.h"
#include "Boss.h"
#include "GameInfo.h"

Boss::Boss()
{
	myHealthPoints = 200;
	myMaxHealth = 200;
	mySpeed = 0.55;
	myAnimationState = 1;
	myBossStage = BossStage::Stage1;

	sf::IntRect mySourceRect(0, 0, myTexture.getSize().x, myTexture.getSize().y);
	myTexture.loadFromFile("Textures/ZombieCycle3.png");

	if ((rand() % 100) + 1 > 50)
	{
		myPosition = sf::Vector2f(GameInfo::GetWindow()->getSize().x + (rand() % 100) + 100, (rand() % 200) + 500);
	}
	else
	{
		myPosition = sf::Vector2f(-((rand() % 100) + 200), (rand() % 200) + 500);
	}
}


Boss::~Boss()
{

}

void Boss::Init()
{

}
void Boss::Update(const float &aDeltaTime, sf::Vector2f aPlayerPos)
{
	myDeltaTime = aDeltaTime;
	Move(aPlayerPos);
	Attack();

	if (myHealthPoints <= 50)
	{
		myBossStage == BossStage::Stage3;
	}
	if (myHealthPoints > 50 && myHealthPoints <= 120)
	{
		myBossStage == BossStage::Stage2;
	}
}
void Boss::Draw()
{
	myAnimator.Animate(myTexture, mySourceRect, myPosition, 12, 2, 0.18, GameInfo::GetWindow(), myAnimationState);
}

void Boss::Move(sf::Vector2f aPlayerPos)
{
	int tempHorisontalStance = 10;
	if (myPosition.x + myTexture.getSize().x / 24 > aPlayerPos.x + tempHorisontalStance)
	{
		myPosition.x = myPosition.x - mySpeed * (myDeltaTime * 60);
		myAnimationState = 2;
	}
	else if (myPosition.x + myTexture.getSize().x / 24 < aPlayerPos.x - tempHorisontalStance)
	{
		myPosition.x = myPosition.x + mySpeed * (myDeltaTime * 60);
		myAnimationState = 1;
	}

	if (myPosition.y + (myTexture.getSize().y / 2) - 64 > aPlayerPos.y)
	{
		myPosition.y = myPosition.y - mySpeed * (myDeltaTime * 60);
	}
	else if (myPosition.y + (myTexture.getSize().y / 2) - 64 < aPlayerPos.y)
	{
		myPosition.y = myPosition.y + mySpeed * (myDeltaTime * 60);
	}
}
void Boss::Attack()
{
	switch (myBossStage)
	{
	case BossStage::Stage1:

		break;
	case BossStage::Stage2:

		break;
	case BossStage::Stage3:

		break;
	}
}

void Boss::RecieveMessage(const MessageType & aMessageType)
{
	
}
