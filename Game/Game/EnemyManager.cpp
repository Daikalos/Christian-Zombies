#include "stdafx.h"
#include "EnemyManager.h"

std::vector<Enemy*> EnemyManager::myEnemies;

EnemyManager::~EnemyManager()
{
}

void EnemyManager::AddEnemy(Enemy* anEnemy)
{
	myEnemies.push_back(anEnemy);
}
void EnemyManager::RemoveEnemy(int aPosition)
{
	myEnemies.erase(myEnemies.begin() + aPosition);
}

std::vector<Enemy*> EnemyManager::GetEnemies()
{
	return myEnemies;
}
Enemy * EnemyManager::GetEnemy(int aPosition)
{
	return myEnemies[aPosition];
}

void EnemyManager::SetEnemies(std::vector<Enemy*> someEnemies)
{
	myEnemies = someEnemies;
}
void EnemyManager::SetEnemy(Enemy* anEnemy, int aPosition)
{
	myEnemies[aPosition] = anEnemy;
}
