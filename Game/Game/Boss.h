#ifndef BOSS_HEADER
#define BOSS_HEADER

#include "stdafx.h"
#include "Subscriber.h"
#include "Entity.h"
#include "Animator.h"

enum BossStage
{
	Stage1, 
	Stage2,
	Stage3,
	Stage4
};

class Boss : public Entity, public Subscriber
{
public:
	Boss();
	~Boss();

	virtual void Init() override;
	virtual void Update(const float &aDeltaTimeValue, sf::Vector2f aPlayerPos);
	virtual void Draw(); 

	virtual void Move(sf::Vector2f aPlayerPos);
	virtual void Attack(sf::Vector2f aPlayerPos);
	virtual void RecieveMessage(const MessageType & aMessageType) override;
	sf::Texture myTexture;
	sf::IntRect mySourceRect;
	sf::Vector2f myPosition;
	Animator myAnimator;

	bool GetAliveStatus();
	sf::IntRect GetAttackBox();

private:
	BossStage myBossStage;
	int myAnimationState;
	bool 
		myDashFlag,
		myLapCompletedFlag,
		myIsAliveFlag,
		myJumpFlag;
	sf::RectangleShape 
		myDrawAttackBox,
		myUIHPBar,
		myUIHPBackground;
	sf::IntRect
		myBossHitbox,
		myAttackBox;
	float
		mySpeed,
		myMaxSpeed,
		myForce,
		myGravity,
		myJumpSpotY,
		myDashSpotX,
		myAnimationSpeed,
		myHPBarLength,
		myHPBackgroundLength,
		myAttackDelayTimer1,
		myAttackDelayTimer2,
		myAttackDelayTimer3,
		myAttackDelayTimer4,
		myAttackDelayTimerMax1,
		myAttackDelayTimerMax2,
		myAttackDelayTimerMax3,
		myAttackDelayTimerMax4;
};

#endif // !BOSS_HEADER