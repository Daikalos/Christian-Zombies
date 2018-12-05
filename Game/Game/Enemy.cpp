#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy()
{
	myTexture.loadFromFile("Textures/ZombieCycle1.png");
	myPosition = sf::Vector2f(rand() % 1000, rand() % 500);

	sf::IntRect mySourceRect(0, 0, myTexture.getSize().x / 12, myTexture.getSize().y);
}

Enemy::~Enemy()
{

}

void Enemy::Init() { }
void Enemy::Update(const float & aDeltaTimeValue) { }
void Enemy::Draw(sf::Texture aTexture, sf::IntRect &aSourceRect, sf::Vector2f aPosition, int someColumns, int someRows, float anAninmationSpeed, sf::RenderWindow *aWindow)
{
	myAnimator.Animate(aTexture, aSourceRect, aPosition, someColumns, someRows, anAninmationSpeed, aWindow, 1);
}

void Enemy::Move() { }
void Enemy::Attack() { }

void Enemy::RecieveMessage(const MessageType &aMessageType)
{

}