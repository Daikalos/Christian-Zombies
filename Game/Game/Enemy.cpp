#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy()
{
	myEnemyShape.setPosition(sf::Vector2f(rand() % 1000, rand() % 500));
	myEnemyShape.setSize(sf::Vector2f(30, 70));
	myEnemyShape.setFillColor(sf::Color::Red);
}

Enemy::~Enemy()
{

}

void Enemy::Init() { }
void Enemy::Update(const float & aDeltaTimeValue) { }
void Enemy::Draw(sf::RenderWindow *aWindow) 
{
	aWindow->draw(myEnemyShape);
}

void Enemy::Move() { }
void Enemy::Attack() { }