#include "stdafx.h"
#include "GameInfo.h"

sf::RenderWindow* GameInfo::myWindow;

GameInfo::~GameInfo()
{
}

sf::RenderWindow * GameInfo::GetWindow()
{
	return myWindow;
}

void GameInfo::SetWindowProperties(sf::VideoMode aVideoMode, std::string someToolbarText)
{
	myWindow = new sf::RenderWindow(aVideoMode, someToolbarText);
}
