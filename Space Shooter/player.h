#pragma once
#include <SFML/Graphics.hpp>
#include "enemy.h"

class Player
{
public:
	void Init();
	void LoadTexturePlayer();
	void Update(float delaTime, Enemy& enemy, sf::RenderWindow& window, sf::Clock c);
	void Draw(sf::RenderWindow& window);
private:

public:
	sf::Sprite sprite;
	// ----- SHOOTING BULLETS -----
	std::vector<sf::RectangleShape> bullets;
	float BULLET_SPEED = 0.001f;
	float playerSpeed = 1.0f;
	std::vector<float> angle; // calculating the angle

	// counter
	int counter = 0;
	
	
private:
	sf::Texture playerTexture;

};

