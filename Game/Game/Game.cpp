#include "stdafx.h"
#include "Player.h"
#include "EnemyFactory.h"
#include "EnemyManager.h"
#include "GameInfo.h"
#include "Background.h"
#include <SFML/Graphics.hpp>

int main()
{
	GameInfo::SetWindowProperties(sf::VideoMode(1280, 720), "Hrethric's Crusade");
	GameInfo::GetWindow()->setFramerateLimit(60);

	srand(static_cast<unsigned int>(time(0)));

	Player myPlayer;
	Background myBackground;

	sf::Clock tempClock;
	bool tempSpacePressed = false;
	float tempRespawnTime = 1;

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

		if (tempRespawnTime <= 0)
		{
			Enemy* tempEnemy = EnemyFactory::CreateEnemy();
			EnemyManager::AddEnemy(tempEnemy);
			Postmaster::Subscribe(tempEnemy);

			tempRespawnTime = 1;
		}

		GameInfo::GetWindow()->clear();
		
		myBackground.DrawBackground();
		myPlayer.Draw(GameInfo::GetWindow());
		myBackground.DrawProps();

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

		GameInfo::GetWindow()->display();
	}

	return 0;
}

