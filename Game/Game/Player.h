#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	~Player();

	virtual void Init() override;
	virtual void Update(const float &aDeltaTimeValue) override;
	virtual void Draw(sf::RenderWindow *aWindow) override;

	virtual void Move() override;
	virtual void Attack() override;
private:
	bool mySpacePressedFlag;

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

