#include "stdafx.h"
#include "EnemySpawner.h"


EnemySpawner::EnemySpawner()
{

}


EnemySpawner::~EnemySpawner()
{
}

Enemy * EnemySpawner::SpawnEnemy(float &aSpawnTime, int aFixedSpawnTime, int &aNbrOfEnemies, const float &aDeltaTimeValue)
{
	aSpawnTime -= aDeltaTimeValue * 1000;
	if (aSpawnTime <= 0 && aNbrOfEnemies > 0)
	{
		Enemy* tempEnemy = EnemyFactory::CreateEnemy();

		EnemyManager::AddEnemy(tempEnemy);
		Postmaster::Subscribe(tempEnemy);

		aNbrOfEnemies--;
		aSpawnTime = aFixedSpawnTime;

		return tempEnemy;
	}
	return nullptr;
}
