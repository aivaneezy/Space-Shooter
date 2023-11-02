#pragma once
#include <SFML/Graphics.hpp>


class Enemy
{
public:
	void Init();
	void LoadEnemyTexture();
	void Update();
	void Draw(sf::RenderWindow& window);
	

public:
	sf::Sprite EnemySprite;
private:
	sf::Texture EnemyTexture;
};