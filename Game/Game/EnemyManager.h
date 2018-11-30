#ifndef ENEMYMANAGER_HEADER
#define ENEMYMANAGER_HEADER

#include "stdafx.h"
#include "Enemy.h"
#include <SFML/Graphics.hpp>

class EnemyManager
{
public:
	~EnemyManager();

	static void AddEnemy(Enemy* anEnemy);
	static void RemoveEnemy(int aPosition);

	static std::vector<Enemy*> GetEnemies();
	static Enemy * GetEnemy(int aPosition);

	static void SetEnemies(std::vector<Enemy*> someEnemies);
	static void SetEnemy(Enemy* anEnemy, int aPosition);

private:
	EnemyManager() {};
	static std::vector<Enemy*> myEnemies;
};

#endif // !ENEMYMANAGER_HEADER
