#include "stdafx.h"
#include "Player.h"
#include "Boss.h"
#include "Director.h"
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

	Player tempPlayer;
	Background tempBackground;
	Director tempDirector;
	LevelProgression tempLevelProgression;
	
	Boss* tempBoss = new Boss();
	Postmaster::Subscribe(tempBoss);

	sf::Clock tempClock;
	bool tempSpacePressed = false;
	float tempRespawnTime = 1;

	float tempSpawnTimer = 500;
	float tempFixedSpawnTimer = 300;
	int tempNbrOfEnemies = 0;
	bool tempSwitchLevel = false;

	tempDirector.InitializeLevel(tempNbrOfEnemies, *tempBoss);

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

		tempPlayer.Update(tempDeltaTime);
		tempBackground.Update(tempPlayer.GetPosition(), tempPlayer.GetPlayerXVirtualSpeed(), tempDeltaTime);

		Enemy* tempEnemy = EnemySpawner::SpawnEnemy(tempSpawnTimer, tempFixedSpawnTimer, tempNbrOfEnemies, tempDeltaTime);
		if (tempEnemy)
		{
			tempEnemy->Init(); 
		}
		//Om du vill spawna fiender igen behöver du enbart ändra tempNbrOfEnemies
		//Ändra tempFixedSpawnTimer om du vill ändra hur ofta dem spawnar i millisekunder
		//Se till att ändra de värden en gång och inte så de ändras till samma värde konstant

		GameInfo::GetWindow()->clear();

		tempBackground.DrawBackground();
		tempPlayer.Draw(GameInfo::GetWindow());

		tempBoss->Draw();
		tempBoss->Update(tempDeltaTime, tempPlayer.GetPosition());

		for (size_t i = EnemyManager::GetEnemies().size(); i > 0; i--)
		{
			sf::IntRect &tempRectPtr = EnemyManager::GetEnemies()[i - 1]->mySourceRect;
			EnemyManager::GetEnemies()[i - 1]->Draw(EnemyManager::GetEnemies()[i - 1]->myTexture,
				tempRectPtr, EnemyManager::GetEnemies()[i - 1]->myPosition, 12, 2, 0.1, GameInfo::GetWindow());

			EnemyManager::GetEnemies()[i - 1]->Update(tempDeltaTime, tempPlayer.myPosition);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5)) //Detta är för testing
		{
			for (size_t i = EnemyManager::GetEnemies().size(); i > 0; i--)
			{
				delete EnemyManager::GetEnemy(i - 1);
				Postmaster::Unsubscribe(EnemyManager::GetEnemy(i - 1));

				EnemyManager::SetEnemy(NULL, (i - 1));
				EnemyManager::RemoveEnemy((i - 1));
			}
		}

		tempBackground.DrawProps();

		if (tempSwitchLevel)
		{
			if (tempBackground.GetGroundSprite().getPosition().x - tempPlayer.GetPlayerXVirtualSpeed() >= 0 || tempBackground.GetGroundSprite().getPosition().x + tempBackground.GetGroundSprite().getGlobalBounds().width - tempPlayer.GetPlayerXVirtualSpeed() <= GameInfo::GetWindow()->getSize().x)
			{
				if (tempPlayer.GetPosition().x <= 100 || tempPlayer.GetPosition().x >= GameInfo::GetWindow()->getSize().x - 100)
				{
					tempLevelProgression.SetLoadNewLevel(true);
					tempSwitchLevel = false;
				}
			}
			tempLevelProgression.DrawArrows(tempDeltaTime);
		}
		tempLevelProgression.LoadNewLevel(tempBackground, tempPlayer, tempDirector, *tempBoss, tempNbrOfEnemies, tempDeltaTime);

		if (tempNbrOfEnemies == 0 && EnemyManager::GetEnemies().size() == 0 && !tempBoss->GetAliveStatus())
		{
			tempSwitchLevel = true;
		}

		GameInfo::GetWindow()->display();
	}

	return 0;
}

