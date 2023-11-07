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

void Enemy::Update(sf::RenderWindow &window)
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

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		enemies.push_back(sf::RectangleShape(sf::Vector2f(50.f, 50.f)));
		enemyPositions.push_back(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
	}
}

void Enemy::Draw(sf::RenderWindow &window)
{
	window.draw(EnemySprite);

	for (size_t i = 0; i < enemies.size(); i++)
	{
		enemies[i].setPosition(enemyPositions[i]);
		window.draw(enemies[i]);
	}
}