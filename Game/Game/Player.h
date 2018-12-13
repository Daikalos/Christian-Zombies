#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "Entity.h"
#include <string>
#include "Animator.h"

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
	sf::Texture myTexture;
	sf::IntRect mySourceRect;
	sf::Vector2f myPosition;
	Animator myAnimator;

	virtual void Init() override;
	virtual void Update(const float &aDeltaTimeValue) override;
	virtual void Draw(sf::RenderWindow *aWindow);

	virtual void Move() override;
	virtual void Attack() override;

	sf::Vector2f GetPosition();
	void SetPosition(sf::Vector2f aNewPosition);

	float GetPlayerXVirtualSpeed();

private:
	bool mySpacePressedFlag;
	float
		myXMovementSpeed,
		myXVirtualSpeed,
		myYMovementSpeed,
		mySpeed,
		myCastTime;
	 int 
		myPlayerDirection,
	    myAnimationState,
	    myPreviousState;
	bool
		myAttackingFlag = false,
		myAttack1Flag = false,
		myAttack2Flag = false;
	PlayerCLAP myCLAP;
};

#endif // !PLAYER_HEADER

