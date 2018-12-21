#include "Director.h"

Director::Director()
{
	myLevel = 0;
}


Director::~Director()
{
}

void Director::InitializeLevel(int &aNbrOfEnemies, Boss &aBoss)
{
	myLevel++;
	if (myLevel % 5 == 0)
	{
		aBoss.Init();
	}
	else
	{
		aNbrOfEnemies = myLevel + (rand() % (myLevel + 2));
	}
}
