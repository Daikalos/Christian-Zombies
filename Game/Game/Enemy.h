#ifndef ENEMY_HEADER
#define ENEMY_HEADER

#include "Entity.h"
#include "Subscriber.h"
#include "Postmaster.h"

class Enemy : public Entity, public Subscriber
{
public:
	Enemy();
	~Enemy();

	virtual void Init() override;
	virtual void Update(const float &aDeltaTimeValue) override;
	virtual void Draw(sf::RenderWindow *aWindow) override;

	virtual void Move() override;
	virtual void Attack() override;
	virtual void RecieveMessage(const MessageType & aMessageType) override;

private:
	sf::RectangleShape myEnemyShape;
};

#endif // !ENEMY_HEADER

