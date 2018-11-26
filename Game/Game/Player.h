#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "stdafx.h"
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	~Player();

	void Update(const float &aDeltaTime, bool &tempSpacePressed);
	void Draw(sf::RenderWindow *aWindow);

	void PlayerMovement(const float &aDeltaTime);
	void PlayerAttack(const float &aDeltaTime, bool &tempSpacePressed);

private:
	float 
		myXMovementSpeed,
		myMaxXMovementSpeed,
		myYMovementSpeed,
		myMaxYMovementSpeed,
		mySpeed;
	int myPlayerDirection;
	sf::RectangleShape myPlayerShape;
};

#endif // !PLAYER_HEADER

