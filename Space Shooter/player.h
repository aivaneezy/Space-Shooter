#pragma once
#include <SFML/Graphics.hpp>
#include "enemy.h"

class Player
{
public:
	void Init();
	void LoadTexturePlayer();
	void Update(Enemy& enemy);
	void Draw(sf::RenderWindow& window);

public:
	sf::Sprite sprite;
	// ----- SHOOTING BULLETS -----
	std::vector<sf::RectangleShape> bullets;
	float BULLET_SPEED = 0.1f;
private:
	sf::Texture playerTexture;

};

