#include "stdafx.h"
#include "Boss.h"
#include "GameInfo.h"
#include "CollisionManager.h"
#include "EnemyManager.h"
#include "EnemyFactory.h"

Boss::Boss()
{
	sf::IntRect mySourceRect(0, 0, myTexture.getSize().x, myTexture.getSize().y);
	myTexture.loadFromFile("Textures/ZombieCycle3.png");
}

Boss::~Boss()
{

}

void Boss::Init()
{
	myHealthPoints = 200;
	myMaxHealth = 200;
	mySpeed = 0.55f;
	myAnimationState = 1;
	myForce = 0;
	myGravity = 0.5f;
	myBossStage = BossStage::Stage1;
	myIsAliveFlag = true;
	myJumpFlag = false;
	myDashFlag = false;
	myLapCompletedFlag = false;
	myMaxSpeed = mySpeed;
	myAnimationSpeed = 0.18f;

	myDrawAttackBox.setFillColor(sf::Color(255, 0, 0, 80));

	myAttackDelayTimer1 = 2000;
	myAttackDelayTimerMax1 = myAttackDelayTimer1;
	myAttackDelayTimer2 = 8000;
	myAttackDelayTimerMax2 = myAttackDelayTimer2;
	myAttackDelayTimer3 = 30000;
	myAttackDelayTimerMax3 = myAttackDelayTimer3;
	myAttackDelayTimer4 = 40000;
	myAttackDelayTimerMax4 = myAttackDelayTimer4;

	if ((rand() % 100) + 1 > 50)
	{
		myPosition = sf::Vector2f(GameInfo::GetWindow()->getSize().x + (rand() % 100) + 100, (rand() % 200) + 500);
	}
	else
	{
		myPosition = sf::Vector2f(-((rand() % 100) + 200), (rand() % 200) + 500);
	}
}
void Boss::Update(const float &aDeltaTime, sf::Vector2f aPlayerPos)
{
	if (myIsAliveFlag)
	{
		myDeltaTime = aDeltaTime;
		Move(aPlayerPos);
		Attack(aPlayerPos);

		if (myHealthPoints <= 50)
		{
			myBossStage = BossStage::Stage4;
		}
		if (myHealthPoints > 50 && myHealthPoints <= 120)
		{
			myBossStage = BossStage::Stage3;
		}
		if (myHealthPoints > 120 && myHealthPoints <= 170)
		{
			myBossStage = BossStage::Stage2;
			myMaxSpeed = 0.65f;
		}
		if (myHealthPoints <= 0)
		{
			myIsAliveFlag = false;
		}

		myHPBarLength = myHealthPoints;
		myHPBackgroundLength = myMaxHealth;

		myUIHPBackground.setPosition(myPosition.x, myPosition.y - 30);
		myUIHPBackground.setFillColor(sf::Color::Color(40, 40, 40, 255));
		myUIHPBackground.setSize(sf::Vector2f(myHPBackgroundLength, 20));

		myUIHPBar.setPosition(myPosition.x, myPosition.y - 30);
		myUIHPBar.setFillColor(sf::Color::Color(175, 0, 0, 255));
		myUIHPBar.setSize(sf::Vector2f(myHPBarLength, 20));

		myDrawAttackBox.setSize(sf::Vector2f(myAttackBox.width, myAttackBox.height));
		myDrawAttackBox.setPosition(sf::Vector2f(myAttackBox.left, myAttackBox.top));

		myAttackDelayTimer1 -= (aDeltaTime * 1000);
		myAttackDelayTimer2 -= (aDeltaTime * 1000);
		myAttackDelayTimer3 -= (aDeltaTime * 1000);
		myAttackDelayTimer4 -= (aDeltaTime * 1000);
	}
}
void Boss::Draw()
{
	if (myIsAliveFlag)
	{
		GameInfo::GetWindow()->draw(myDrawAttackBox);
		GameInfo::GetWindow()->draw(myUIHPBackground);
		GameInfo::GetWindow()->draw(myUIHPBar);
		myAnimator.Animate(myTexture, mySourceRect, myPosition, 12, 2, myAnimationSpeed, GameInfo::GetWindow(), myAnimationState);
	}
}

void Boss::Move(sf::Vector2f aPlayerPos)
{
	int tempHorisontalStance = 20;
	if (!myDashFlag)
	{
		if (myPosition.x + (myTexture.getSize().x / 40) - tempHorisontalStance > aPlayerPos.x)
		{
			myPosition.x -= mySpeed * (myDeltaTime * 60);
			myAnimationState = 2;
		}
		else if (myPosition.x + (myTexture.getSize().x / 24) + tempHorisontalStance < aPlayerPos.x)
		{
			myPosition.x += mySpeed * (myDeltaTime * 60);
			myAnimationState = 1;
		}
	}
	else
	{
		switch (myAnimationState)
		{
		case 1:
			myPosition.x += mySpeed * (myDeltaTime * 60);
			if (myPosition.x > GameInfo::GetWindow()->getSize().x)
			{
				myPosition.x = -192;
				myLapCompletedFlag = true;
			}
			if (myLapCompletedFlag && myPosition.x >= myDashSpotX)
			{
				myDashFlag = false;
			}
			break;
		case 2:
			myPosition.x -= mySpeed * (myDeltaTime * 60);
			if (myPosition.x + myTexture.getSize().x / 12 < 0)
			{
				myPosition.x = GameInfo::GetWindow()->getSize().x;
				myLapCompletedFlag = true;
			}
			if (myLapCompletedFlag && myPosition.x <= myDashSpotX)
			{
				myDashFlag = false;
			}
			break;
		}
	}

	if (!myJumpFlag && !myDashFlag)
	{
		if (myPosition.y + (myTexture.getSize().y / 2) - 64 > aPlayerPos.y + 1)
		{
			myPosition.y = myPosition.y - mySpeed * (myDeltaTime * 60);
		}
		else if (myPosition.y + (myTexture.getSize().y / 2) - 64 < aPlayerPos.y - 1)
		{
			myPosition.y = myPosition.y + mySpeed * (myDeltaTime * 60);
		}
	}

	if (!myJumpFlag && !myDashFlag)
	{
		mySpeed = myMaxSpeed;
		myAnimationSpeed = 0.18f;
	}
	else if (!myDashFlag)
	{
		mySpeed = myMaxSpeed * 4;
		myAnimationSpeed = 0.5f;
	}
	else
	{
		mySpeed = myMaxSpeed * 8;
		myAnimationSpeed = 0.05f;
	}

	if (myPosition.y <= myJumpSpotY && myJumpFlag)
	{
		myForce += myGravity * myDeltaTime * 20;
	}
	else
	{
		myForce = 0;
		myJumpFlag = false;
	}
	myPosition.y += myForce;

	if (!myJumpFlag && !myDashFlag)
	{
		myAttackBox = sf::IntRect(0, 0, 0, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
	{
		myHealthPoints--;
	}
}
void Boss::Attack(sf::Vector2f aPlayerPos)
{
	if (myBossStage >= BossStage::Stage1)
	{
		if (myAttackDelayTimer1 <= 0 && !myJumpFlag && !myDashFlag)
		{
			int tempDistanceToPlayer = std::sqrt(std::pow(myPosition.x - aPlayerPos.x, 2) + std::pow(myPosition.y - aPlayerPos.y, 2));
			if (tempDistanceToPlayer < 200)
			{
				myAttackBox = sf::IntRect(myPosition.x + (myTexture.getSize().x / 24) - 40, myPosition.y, (myTexture.getSize().x / 14), myTexture.getSize().y / 2);
				if (myAnimationState != 1)
				{
					myAttackBox = sf::IntRect(myPosition.x + (myTexture.getSize().x / 24) + 40, myPosition.y, -1 * (myTexture.getSize().x / 14), myTexture.getSize().y / 2);
				}

				myAttackDelayTimer1 = myAttackDelayTimerMax1;
			}
		}
	}
	if (myBossStage >= BossStage::Stage2)
	{
		if (myJumpFlag && myForce > -1)
		{
			myAttackBox = sf::IntRect(myPosition.x, myPosition.y, myTexture.getSize().x / 12, myTexture.getSize().y / 2);
		}
		if (myAttackDelayTimer2 <= 0)
		{
			myJumpFlag = true;
			myJumpSpotY = myPosition.y;
			myForce = -7;

			myAttackDelayTimer2 = myAttackDelayTimerMax2;
		}
	}
	if (myBossStage >= BossStage::Stage3)
	{
		if (myDashFlag)
		{
			myAttackBox = sf::IntRect(myPosition.x, myPosition.y, myTexture.getSize().x / 12, myTexture.getSize().y / 2);
		}
		if (myAttackDelayTimer3 <= 0)
		{
			myDashFlag = true;
			myLapCompletedFlag = false;
			myDashSpotX = myPosition.x;

			myAttackDelayTimer3 = myAttackDelayTimerMax3;
		}
	}
	if (myBossStage >= BossStage::Stage4)
	{
		if (myAttackDelayTimer4 <= 0)
		{
			for (int i = 0; i < 2 + (rand() % 2); i++)
			{
				EnemyManager::AddEnemy(EnemyFactory::CreateEnemy());
				EnemyManager::GetEnemies()[i]->Init();
			}

			myAttackDelayTimer4 = myAttackDelayTimerMax4;
		}
	}
}

void Boss::RecieveMessage(const MessageType & aMessageType)
{
	if (aMessageType == MessageType::IsDead)
	{
		myIsAliveFlag = false;
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

bool Boss::GetAliveStatus()
{
	return myIsAliveFlag;
}

sf::IntRect Boss::GetAttackBox()
{
	return myAttackBox;
}
