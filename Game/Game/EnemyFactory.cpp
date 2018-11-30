#include "stdafx.h"
#include "EnemyFactory.h"

EnemyFactory::EnemyFactory()
{

}

EnemyFactory::~EnemyFactory()
{

}

Enemy* EnemyFactory::CreateEnemy()
{
	return new Enemy();
}
