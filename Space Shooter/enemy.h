#pragma once
#include <SFML/Graphics.hpp>


class Enemy
{
public:
	void Init();
	void LoadEnemyTexture();
	void Update(sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);
	

public:
	sf::Sprite EnemySprite;
	std::vector<sf::RectangleShape> enemies;
	std::vector<sf::Vector2f> enemyPositions;
private:
	sf::Texture EnemyTexture;
};