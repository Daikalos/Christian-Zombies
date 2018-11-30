#ifndef ENEMYFACTORY_HEADER
#define ENEMYFACTORY_HEADER

#include "stdafx.h"
#include "Enemy.h"
#include <SFML/Graphics.hpp>

class EnemyFactory
{
public:
	EnemyFactory();
	~EnemyFactory();

	static Enemy * CreateEnemy();

};

#endif // ! ENEMYFACTORY_HEADER

