#ifndef BOSS_HEADER
#define BOSS_HEADER

#include "Subscriber.h"
#include "Entity.h"
#include "Animator.h"

enum BossStage
{
	Stage1, 
	Stage2,
	Stage3
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
	virtual void Attack() override;
	virtual void RecieveMessage(const MessageType & aMessageType) override;
	sf::Texture myTexture;
	sf::IntRect mySourceRect;
	sf::Vector2f myPosition;
	Animator myAnimator;

private:
	sf::RectangleShape myUIHPBar;
	sf::RectangleShape myUIHPBackground;
	BossStage myBossStage;
	int myAnimationState;
	float mySpeed;
};

#endif // !BOSS_HEADER