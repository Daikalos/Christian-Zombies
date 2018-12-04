#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "Entity.h"
#include <string>

enum PlayerClass {
	CLASS_BARBARIAN, CLASS_ARCHER, CLASS_ROGUE
};

struct PlayerCLAP {
	PlayerClass myClass;
	int myLevel;
	std::vector<std::string> myAchievements;
	std::vector<std::string> myPerks;
};

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
	float
		myXMovementSpeed,
		myMaxXMovementSpeed,
		myYMovementSpeed,
		myMaxYMovementSpeed,
		mySpeed,
		myCastTime;
	int myPlayerDirection;
	bool
		myAttackingFlag = false,
		myAttack1Flag = false,
		myAttack2Flag = false;

	sf::RectangleShape myPlayerShape;
	PlayerCLAP myCLAP;
};

#endif // !PLAYER_HEADER

