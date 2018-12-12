#include "stdafx.h"
#include "CollisionBox.h"
#include <SFML\Graphics.hpp>

CollisionBox::CollisionBox()
{

}
CollisionBox::~CollisionBox()
{

}
sf::IntRect CollisionBox::DrawBox(sf::IntRect aBox, sf::Vector2f aPosition)
{
	aBox.top = aPosition.y + (aBox.height / 2);
	aBox.left = aPosition.x + (aBox.width / 2);
	return aBox;
}