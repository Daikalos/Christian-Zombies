#ifndef ENEMY_HEADER
#define ENEMY_HEADER

#include "Entity.h"
#include "Subscriber.h"
#include "Postmaster.h"
#include "Animator.h"

class Enemy : public Entity, public Subscriber
{
public:
	Enemy();
	~Enemy();

	virtual void Init() override;
	virtual void Update(const float &aDeltaTimeValue) override;
	virtual void Draw(sf::Texture aTexture, sf::IntRect &aSourceRect, sf::Vector2f aPosition, int someColumns, int someRows, float anAninmationSpeed, sf::RenderWindow *aWindow);

	virtual void Move() override;
	virtual void Attack() override;
	virtual void RecieveMessage(const MessageType & aMessageType) override;
	sf::Texture myTexture;
	sf::IntRect mySourceRect;
	sf::Vector2f myPosition;
	Animator myAnimator;

private:
	sf::RectangleShape myEnemyShape;
};

#endif // !ENEMY_HEADER

