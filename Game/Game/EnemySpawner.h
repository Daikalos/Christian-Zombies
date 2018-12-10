#ifndef ENEMYSPAWNER_HEADER
#define ENEMYSPAWNER_HEADER

#include <SFML/Graphics.hpp>
#include "EnemyFactory.h"
#include "EnemyManager.h"
#include "Postmaster.h"
#include "Enemy.h"

class EnemySpawner
{
public:
	EnemySpawner();
	~EnemySpawner();

	static Enemy * SpawnEnemy(float &aSpawnTime, int aFixedSpawnTime, int &aNbrOfEnemies, const float &aDeltaTimeValue);
};


#endif // !ENEMYSPAWNER_HEADER
