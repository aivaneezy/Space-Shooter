#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
#include "player.h"
#include "enemy.h"
#include "math.h"
constexpr int WIDTH = 720;
constexpr int HEIGHT = 720;





int main()
{
	// ---------------------- INIT --------------
	sf::ContextSettings settings;
	settings.antialiasingLevel = 0;
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "RPG", sf::Style::Default, settings);
	window.setFramerateLimit(240);

	/*Player class object*/
	Player player;
	player.Init();
	player.LoadTexturePlayer(); // player texture

	/*Enemy class object*/
	Enemy enemy;
	enemy.Init();
	//enemy.LoadEnemyTexture();

	



	

	sf::Clock clock;
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
		sf::Time delaTimeTimer = clock.restart();
		float deltaTime = delaTimeTimer.asMilliseconds();
	
		player.Update(deltaTime, enemy, window, clock);
		enemy.Update(window);
		

	
		// ---- DRAW ------
		window.clear(sf::Color::Black);
		// ----------- UPDATE -------------

		player.Draw(window); // rendering player sprite
		enemy.Draw(window); // rendering enemy sprite
		
		window.display();


	}
	return 0;
}
