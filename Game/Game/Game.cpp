#include "stdafx.h"
#include "Player.h"
#include "Boss.h"
#include "EnemyFactory.h"
#include "EnemyManager.h"
#include "EnemySpawner.h"
#include "LevelProgression.h"
#include "GameInfo.h"
#include "Background.h"
#include <SFML/Graphics.hpp>

int main()
{
	GameInfo::SetWindowProperties(sf::VideoMode(1280, 720), "Hrethric's Crusade");
	GameInfo::GetWindow()->setFramerateLimit(60);

	srand(static_cast<unsigned int>(time(0)));

	Boss myBoss;
	Player myPlayer;
	Background myBackground;
	LevelProgression myLevelProgression;

	sf::Clock tempClock;
	bool tempSpacePressed = false;
	float tempRespawnTime = 1;

	float tempSpawnTimer = 500;
	float tempFixedSpawnTimer = 300;
	int tempNbrOfEnemies = 5;
	bool tempSwitchLevel = true; //Ska egentligen vara false 

	while (GameInfo::GetWindow()->isOpen())
	{
		float tempDeltaTime = tempClock.restart().asSeconds();
		tempRespawnTime -= tempDeltaTime;

		sf::Event tempEvent;
		while (GameInfo::GetWindow()->pollEvent(tempEvent))
		{
			if (tempEvent.type == sf::Event::Closed)
			{
				GameInfo::GetWindow()->close();
			}
		}

		myPlayer.Update(tempDeltaTime);
		myBackground.Update(myPlayer.GetPosition(), myPlayer.GetPlayerXVirtualSpeed(), tempDeltaTime);

		Enemy* tempEnemy = EnemySpawner::SpawnEnemy(tempSpawnTimer, tempFixedSpawnTimer, tempNbrOfEnemies, tempDeltaTime);
		if (tempEnemy)
		{
			tempEnemy->Init(); 
		}
		//Om du vill spawna fiender igen behöver du enbart ändra tempNbrOfEnemies
		//Ändra tempFixedSpawnTimer om du vill ändra hur ofta dem spawnar i millisekunder
		//Se till att ändra de värden en gång och inte så de ändras till samma värde konstant

		GameInfo::GetWindow()->clear();

		myBackground.DrawBackground();
		myPlayer.Draw(GameInfo::GetWindow());
		myBackground.DrawProps();

		myBoss.Draw();

		for (size_t i = EnemyManager::GetEnemies().size(); i > 0; i--)
		{
			sf::IntRect &tempRectPtr = EnemyManager::GetEnemies()[i - 1]->mySourceRect;
			EnemyManager::GetEnemies()[i - 1]->Draw(EnemyManager::GetEnemies()[i - 1]->myTexture,
				tempRectPtr, EnemyManager::GetEnemies()[i - 1]->myPosition, 12, 1, 0.1, GameInfo::GetWindow());

			if (EnemyManager::GetEnemies().size() > 2) //Exempel
			{
				delete EnemyManager::GetEnemy(i - 2);
				Postmaster::Unsubscribe(EnemyManager::GetEnemy(i - 2));

				EnemyManager::SetEnemy(NULL, (i - 2));
				EnemyManager::RemoveEnemy((i - 2));
			}
		}

		if (tempSwitchLevel)
		{
			if (myBackground.GetGroundSprite().getPosition().x - myPlayer.GetPlayerXVirtualSpeed() >= 0 || myBackground.GetGroundSprite().getPosition().x + myBackground.GetGroundSprite().getGlobalBounds().width - myPlayer.GetPlayerXVirtualSpeed() <= GameInfo::GetWindow()->getSize().x)
			{
				if (myPlayer.GetPosition().x <= 100 || myPlayer.GetPosition().x >= GameInfo::GetWindow()->getSize().x - 100)
				{
					myLevelProgression.SetLoadNewLevel(true);
					tempSwitchLevel = false;
				}
			}
			myLevelProgression.DrawArrows(tempDeltaTime);
		}
		myLevelProgression.LoadNewLevel(myBackground, myPlayer, tempDeltaTime);

		GameInfo::GetWindow()->display();
	}

	return 0;
}

