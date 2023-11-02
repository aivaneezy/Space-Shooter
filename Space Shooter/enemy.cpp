#include "enemy.h"
#include <iostream>


void Enemy::Init()
{

}

void Enemy::LoadEnemyTexture()
{
	if (!EnemyTexture.loadFromFile("C:\\Users\\Golden\\Desktop\\Assets\\alien.png"))
	{
		std::cout << "Success Load image" << std::endl;
	}
	else
	{
		std::cout << "Failed to load enemy texture" << std::endl;
	}
	EnemySprite.setTexture(EnemyTexture);
	EnemySprite.setScale(0.5f, 0.5f);
}

void Enemy::Update()
{
	sf::Vector2f enemy_movement = EnemySprite.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		EnemySprite.setPosition(enemy_movement - sf::Vector2f(0, 1) * 0.1f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		EnemySprite.setPosition(enemy_movement + sf::Vector2f(0, 1) * 0.1f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		EnemySprite.setPosition(enemy_movement + sf::Vector2f(1, 0) * 0.1f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		EnemySprite.setPosition(enemy_movement - sf::Vector2f(1, 0) * 0.1f);
	}
}

void Enemy::Draw(sf::RenderWindow &window)
{
	window.draw(EnemySprite);
}