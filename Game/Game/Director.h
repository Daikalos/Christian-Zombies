#ifndef DIRECTOR_HEADER
#define DIRECTOR_HEADER

#include "Boss.h"

class Director
{
public:
	Director();
	~Director();

	void InitializeLevel(int &aNbrOfEnemies, Boss &aBoss);

private:
	int myLevel;
};

#endif // !DIRECTOR_HEADER

