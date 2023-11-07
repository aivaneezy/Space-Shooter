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

void Player::Update(float deltaTime, Enemy &enemy, sf::RenderWindow &window, sf::Clock c)
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
		size_t lastElement = bullets.size() - 1;
		bullets[lastElement].setPosition(sprite.getPosition().x + 55, sprite.getPosition().y - 20);
		// calculating the bullets direction relative to the mouse position
		angle.push_back(Math::calculateAngle(sf::Mouse::getPosition(window).y - sprite.getPosition().y,
			                                  sf::Mouse::getPosition(window).x - sprite.getPosition().x));

		
		counter++;
		// shotting bullets just once every 0.5 seconds
		std::cout << counter << std::endl;
	}
	
	
	
}

void Player::Draw(sf::RenderWindow &window)
{
	window.draw(sprite);

	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].setFillColor(sf::Color(0, 255, 0));
		if (counter > 500)
		{
			bullets[i].setFillColor(sf::Color(255, 0, 0));
		}
		if (counter > 1000)
		{
			bullets[i].setFillColor(sf::Color(0, 0, 255));
		}
		window.draw(bullets[i]);
		bullets[i].move(5 * cos(angle[i]), 5 * sin(angle[i]));

		
	
	}
}