#ifndef ENEMY_HEADER
#define ENEMY_HEADER

#include "Entity.h"
#include "Subscriber.h"
#include "Postmaster.h"
#include "Animator.h"
#include "CollisionBox.h"

class Enemy : public Entity, public Subscriber
{
public:
	Enemy();
	~Enemy();

	virtual void Init() override;
	virtual void Update(const float &aDeltaTimeValue, sf::Vector2f aPlayerPos);
	virtual void Draw(sf::Texture aTexture, sf::IntRect &aSourceRect, sf::Vector2f aPosition, int someColumns, int someRows, float anAninmationSpeed, sf::RenderWindow *aWindow);

	virtual void Move(sf::Vector2f aPlayerPos);
	virtual void Attack() override;
	virtual void RecieveMessage(const MessageType & aMessageType) override;
	sf::Texture myTexture;
	sf::IntRect mySourceRect;
	sf::IntRect myDestRect;
	sf::Vector2f myPosition;
	Animator myAnimator;
	CollisionBox myBox;

private:
	sf::RectangleShape myEnemyShape;
	int myAnimationState;

};

#endif // !ENEMY_HEADER

