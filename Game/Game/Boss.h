#ifndef BOSS_HEADER
#define BOSS_HEADER

#include "Subscriber.h"
#include "Entity.h"
#include "Animator.h"

enum BossStage
{

};

class Boss : public Entity, public Subscriber
{
public:
	Boss();
	~Boss();

	virtual void Init() override;
	virtual void Update(const float &aDeltaTimeValue) override;
	virtual void Draw();

	virtual void Move() override;
	virtual void Attack() override;
	virtual void RecieveMessage(const MessageType & aMessageType) override;
	sf::Texture myTexture;
	sf::IntRect mySourceRect;
	sf::Vector2f myPosition;
	Animator myAnimator;

private:

};

#endif // !BOSS_HEADER