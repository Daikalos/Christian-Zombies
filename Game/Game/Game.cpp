#include "stdafx.h"
#include "Player.h"
#include "Enemy.h"
#include <SFML/Graphics.hpp>

Player myPlayer;
std::vector<Enemy> myEnemies;

int main()
{
	sf::RenderWindow tempWindow(sf::VideoMode(1280, 720), "Medieval Zombie Slayer");
	tempWindow.setFramerateLimit(60);

	sf::Clock tempClock;
	bool tempSpacePressed = false;
	float tempRespawnTime = 4;

	while (tempWindow.isOpen())
	{
		float tempDeltaTime = tempClock.restart().asSeconds();
		tempRespawnTime -= tempDeltaTime;

		sf::Event tempEvent;
		while (tempWindow.pollEvent(tempEvent))
		{
			if (tempEvent.type == sf::Event::Closed)
			{
				tempWindow.close();
			}
		}

		myPlayer.Update(tempDeltaTime, tempSpacePressed);

		if (tempRespawnTime <= 0)
		{
			Enemy anEnemy;
			myEnemies.push_back(anEnemy);
			tempRespawnTime = 4;
		}

		tempWindow.clear();

		myPlayer.Draw(&tempWindow);

		for (size_t i = myEnemies.size(); i > 0; i--)
		{
			myEnemies[i - 1].Draw(&tempWindow);
		}

		tempWindow.display();
	}

	return 0;
}

