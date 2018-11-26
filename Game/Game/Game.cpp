#include "stdafx.h"
#include "Player.h"
#include "Enemy.h"
#include "GameInfo.h"

#include <SFML/Graphics.hpp>

int main()
{
	GameInfo::SetWindowProperties(sf::VideoMode(1280, 720), "Medieval Zombie Slayer");
	GameInfo::GetWindow()->setFramerateLimit(60);

	Player myPlayer;
	std::vector<Enemy> myEnemies;

	sf::Clock tempClock;
	bool tempSpacePressed = false;
	float tempRespawnTime = 4;

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
			Enemy anEnemy;
			myEnemies.push_back(anEnemy);
			tempRespawnTime = 4;
		}

		GameInfo::GetWindow()->clear();

		myPlayer.Draw(GameInfo::GetWindow());

		for (size_t i = myEnemies.size(); i > 0; i--)
		{
			myEnemies[i - 1].Draw(GameInfo::GetWindow());
		}

		GameInfo::GetWindow()->display();
	}

	return 0;
}

