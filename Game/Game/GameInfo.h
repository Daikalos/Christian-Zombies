#ifndef GAMEINFO_HEADER
#define GAMEINFO_HEADER

#include <SFML/Graphics.hpp>

class GameInfo {
public:
	~GameInfo();
	static sf::RenderWindow* GetWindow();
	static void SetWindowProperties(sf::VideoMode aVideoMode, std::string someToolbarText);
private:
	GameInfo() 
	{

	};
	static sf::RenderWindow* myWindow;
};
#endif