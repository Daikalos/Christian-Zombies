#ifndef LEVELPROGRESSION_HEADER
#define LEVELPROGRESSION_HEADER

#include "Background.h"
#include "Player.h"

class LevelProgression
{
public:
	LevelProgression();
	~LevelProgression();

	void DrawArrows(float const &aDeltaTime);
	void LoadNewLevel(Background &aBackground, Player &aPlayer, float const &aDeltaTime);
	void SetLoadNewLevel(bool aNewValue);

private:
	int myLevel;
	float 
		myAlpha,
		myGreenColor;
	bool 
		mySwitchAlphaValue,
		mySwitchGreenValue,
		myLoadNewLevel;
	sf::RectangleShape myBlackScreen;
	sf::ConvexShape myArrow;
	sf::ConvexShape mySecondArrow;
};

#endif // !LEVELPROGRESSION_HEADER