#include "stdafx.h"
#include "Player.h"
#include "EnemyFactory.h"
#include "EnemyManager.h"
#include "GameInfo.h"

#include <SFML/Graphics.hpp>

int main()
{
	GameInfo::SetWindowProperties(sf::VideoMode(1280, 720), "Hrethric's Crusade");
	GameInfo::GetWindow()->setFramerateLimit(60);

	Player myPlayer;

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

		if (tempRespawnTime <= 0)
		{
			Enemy* tempEnemy = EnemyFactory::CreateEnemy();
			EnemyManager::AddEnemy(tempEnemy);
			Postmaster::Subscribe(tempEnemy);

			tempRespawnTime = 1;
		}

		GameInfo::GetWindow()->clear();

		myPlayer.Draw(GameInfo::GetWindow());

		for (size_t i = EnemyManager::GetEnemies().size(); i > 0; i--)
		{
			sf::IntRect &tempRectPtr = EnemyManager::GetEnemies()[i - 1]->mySourceRect;
			EnemyManager::GetEnemies()[i - 1]->Draw(EnemyManager::GetEnemies()[i - 1]->myTexture, 
				tempRectPtr, EnemyManager::GetEnemies()[i - 1]->myPosition, 12, 1, 0.1, GameInfo::GetWindow());
			//EnemyManager::GetEnemies()[i - 1]->SendMessage(MessageType::Type1);

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

