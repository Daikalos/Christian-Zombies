#ifndef BACKGROUND_HEADER
#define BACKGROUND_HEADER

#include "stdafx.h"
#include <SFML/Graphics.hpp>

class Background
{
public:
	Background();
	~Background();

	void Update(sf::Vector2f aPlayerPosition, float aPlayerSpeed);
	void DrawBackground();
	void DrawProps();

private:
	sf::Texture myBackgroundTexture;
	sf::Texture myGroundTexture;
	sf::Sprite myBackgroundSprite;
	sf::Sprite myGroundSprite;
	std::vector<sf::Texture> myPropTextures;
	std::vector<sf::Sprite> myPropSprites;
};

#endif // !BACKGROUND_HEADER