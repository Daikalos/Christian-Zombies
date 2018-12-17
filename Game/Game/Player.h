#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "Entity.h"
#include <string>
#include "Animator.h"
#include "Subscriber.h"

enum PlayerClass {
	CLASS_BARBARIAN, CLASS_ARCHER, CLASS_ROGUE
};

struct PlayerCLAP {
	PlayerClass myClass = CLASS_BARBARIAN;
	int myLevel = 1;
	std::vector<std::string> myAchievements;
	std::vector<std::string> myPerks;
};

class Player : public Entity, public Subscriber
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
	virtual void RecieveMessage(const MessageType & aMessageType) override;

	virtual void Move() override;
	virtual void Attack() override;

	void AddExperiencePoints(float anExperienceValue);
	void SetExperiencePoints(float anExperienceValue);

	sf::Vector2f GetPosition();
	float GetPlayerXVirtualSpeed();

private:
	bool mySpacePressedFlag;
	float
		myXMovementSpeed,
		myXVirtualSpeed,
		myYMovementSpeed,
		mySpeed,
		myCastTime,
		myExperiencePoints = 0;
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

