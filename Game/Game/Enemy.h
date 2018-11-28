#ifndef ENEMY_HEADER
#define ENEMY_HEADER

#include "Entity.h"

class Enemy : public Entity
{
public:
	Enemy();
	~Enemy();

	virtual void Init() override;
	virtual void Update(const float &aDeltaTimeValue) override;
	virtual void Draw(sf::RenderWindow *aWindow) override;

	virtual void Move() override;
	virtual void Attack() override;
private:
	sf::RectangleShape myEnemyShape;
};

#endif // !ENEMY_HEADER

