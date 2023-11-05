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

void Player::Update(float deltaTime, Enemy &enemy, sf::RenderWindow &window)
{
	// PLAYERS MOVEMENT
	sf::Vector2f players_movement = sprite.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		sprite.setPosition(players_movement - sf::Vector2f(0, 1) *playerSpeed * deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		sprite.setPosition(players_movement + sf::Vector2f(0, 1) *playerSpeed * deltaTime);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		sprite.setPosition(players_movement + sf::Vector2f(1, 0) *playerSpeed * deltaTime );
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		sprite.setPosition(players_movement - sf::Vector2f(1, 0) *playerSpeed * deltaTime);
	}

	// SHOOTING BULLETS
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		// pushing the bullets into the vector array
		bullets.push_back(sf::RectangleShape(sf::Vector2f(20.f, 20.f)));
		/*Setting the initial posiiton of the first bullet*/
		bullets.back().setPosition(sprite.getPosition());

		// calculating the bullets direction relative to the mouse position
		angle.push_back(atan2(sf::Mouse::getPosition(window).y - sprite.getPosition().y,
			                                  sf::Mouse::getPosition(window).x - sprite.getPosition().x));
	}

	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].move(5 * cos(angle[i]), 5 * sin(angle[i]));
	}
}

void Player::Draw(sf::RenderWindow &window)
{
	window.draw(sprite);

	for (int i = 0; i < bullets.size(); i++)
	{
		window.draw(bullets[i]);
	
	}
}