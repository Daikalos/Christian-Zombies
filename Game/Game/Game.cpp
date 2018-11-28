#include "stdafx.h"
#include "Player.h"
#include "Enemy.h"
#include "Postmaster.h"
#include <SFML/Graphics.hpp>

Player myPlayer;
std::vector<Enemy*> myEnemies;

int main()
{
	sf::RenderWindow tempWindow(sf::VideoMode(1280, 720), "Medieval Zombie Slayer");
	tempWindow.setFramerateLimit(60);

	sf::Clock tempClock;
	bool tempSpacePressed = false;
	float tempRespawnTime = 1;

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

		myPlayer.Update(tempDeltaTime);

		if (tempRespawnTime <= 0)
		{
			Enemy *tempEnemy = new Enemy();
			myEnemies.push_back(tempEnemy);
			Postmaster::Subscribe(tempEnemy);

			tempRespawnTime = 1;
		}

		tempWindow.clear();

		myPlayer.Draw(&tempWindow);

		for (size_t i = myEnemies.size(); i > 0; i--)
		{
			myEnemies[i - 1]->Draw(&tempWindow);
			myEnemies[i - 1]->SendMessage(MessageType::Type1);

			if (myEnemies.size() > 2) //Exempel
			{
				delete myEnemies[i - 1];
				Postmaster::Unsubscribe(myEnemies[i - 1]);

				myEnemies[i - 1] = NULL;
				myEnemies.erase(myEnemies.begin() + (i - 1));
			}
		}

		tempWindow.display();
	}

	return 0;
}

