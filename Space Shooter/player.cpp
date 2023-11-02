#include "player.h"
#include <iostream>
#include "enemy.h"
#include "math.h"
#include <vector>
void Player::Init()
{
	
}

void Player::LoadTexturePlayer()
{
	if (playerTexture.loadFromFile("C:\\Users\\Golden\\Desktop\\Assets\\ship1.png"))
	{
		std::cout << "Success load Image" << std::endl;
	}
	else
	{
		std::cout << "Failed to load an image" << std::endl;
	}
	sprite.setTexture(playerTexture);
	sprite.setScale(0.5f, 0.5f);
}

void Player::Update(Enemy &enemy)
{
	// PLAYERS MOVEMENT
	sf::Vector2f players_movement = sprite.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		sprite.setPosition(players_movement - sf::Vector2f(0, 1) * 0.1f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		sprite.setPosition(players_movement + sf::Vector2f(0, 1) * 0.1f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		sprite.setPosition(players_movement + sf::Vector2f(1, 0) * 0.1f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		sprite.setPosition(players_movement - sf::Vector2f(1, 0) * 0.1f);
	}

	//// SHOOTING BULLETS
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		// pushing the bullets into the vector array
		bullets.push_back(sf::RectangleShape(sf::Vector2f(20.f, 20.f)));

		/*Setting the initial posiiton of the first bullet*/
		size_t lastElement = bullets.size() - 1;
		bullets[lastElement].setPosition(sprite.getPosition());
	}

	/*Calculating bullets direction*/
	for (size_t i = 0; i < bullets.size(); i++)
	{
		/*Calculating the bullet direction*/
		sf::Vector2f direction = enemy.EnemySprite.getPosition() - bullets[i].getPosition();
		direction = Math::normalizeVector(direction); // normalizzing the vector, converting to 1 unit
		bullets[i].setPosition(bullets[i].getPosition() + direction * BULLET_SPEED);
	}
	//}
}

void Player::Draw(sf::RenderWindow &window)
{
	window.draw(sprite);

	for (int i = 0; i < bullets.size(); i++)
	{
		window.draw(bullets[i]);
	}
}