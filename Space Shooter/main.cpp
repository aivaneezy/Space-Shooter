#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
constexpr int WIDTH = 720;
constexpr int HEIGHT = 720;
constexpr float BULLET_SPEED = 0.1f;


sf::Vector2f normalizeVector(sf::Vector2f vector)
{	
	// calculating the magnitude of the vector
	float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);

	// normalizzing the vector
	sf::Vector2f normalizeV;
	normalizeV.x = vector.x / magnitude;
	normalizeV.y = vector.y / magnitude;

	return normalizeV;
}

int main()
{
	// ---------------------- INIT --------------
	sf::ContextSettings settings;
	settings.antialiasingLevel = 0;
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "RPG", sf::Style::Default, settings);

	// PLAYERS
	//sf::RectangleShape spaceship(sf::Vector2f(150.f, 50.f)); // WIDTH AND HEIGHT
	//spaceship.setFillColor(sf::Color(0, 0, 255));
	// PLAYER SPIRTE
	sf::Texture playerTexture;
	sf::Sprite sprite;
	if (!playerTexture.loadFromFile("C:\\Users\\Golden\\Desktop\\ship1.png"));
	{
		std::cout << "Failed to load image" << std::endl;
	}
	
	sprite.setTexture(playerTexture);
	sprite.setScale(0.5f, 0.5f);


	// ENEMY
	sf::RectangleShape enemy(sf::Vector2f(100.f, 50.f)); // WIDTH AND HEIGHT
	enemy.setFillColor(sf::Color(255, 0, 0));

	// ----- SHOOTING BULLETS -----
	std::vector<sf::RectangleShape> bullets;


	//------------- MAIN GAME LOOP -----------------
	while (window.isOpen())
	{
		// -------------- EVENTS -------------------
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				std::cout << "Window is closed" << std::endl;
			}
		}



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

		// SHOOTING BULLETS
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			// pushing the bullets into the vector array
			bullets.push_back(sf::RectangleShape(sf::Vector2f(20.f, 20.f)));

			/*Setting the initial posiiton of the first bullet*/
			size_t lastElement = bullets.size() - 1;
			bullets[lastElement].setPosition(sprite.getPosition());
		}

		/*Calculating bullets direction*/
		for (int i = 0; i < bullets.size(); i++)
		{
			/*Calculating the bullet direction*/
			sf::Vector2f direction = enemy.getPosition() - bullets[i].getPosition();
			direction = normalizeVector(direction); // normalizzing the vector, converting to 1 unit
			bullets[i].setPosition(bullets[i].getPosition() + direction * BULLET_SPEED);
		}


		// ---- DRAW ------
		window.clear(sf::Color::Black);
		// ----------- UPDATE -------------
	
		window.draw(enemy);
		window.draw(sprite);
		
		for (int i = 0; i < bullets.size(); i++)
		{
			window.draw(bullets[i]);
		}
		window.display();
	}



	

	return 0;
}