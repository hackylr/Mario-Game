// From here: https://www.sfml-dev.org/tutorials/2.4/window-events.php
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
#include "Player.h"
#include "Platform.h"
#include <conio.h>

static const float VIEW_HEIGHT = 512.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "Tux the Hero");

	sf::Texture playerTexture;
	sf::Texture enemyTexture;
	playerTexture.loadFromFile("tux_from_linux.png");
	enemyTexture.loadFromFile("pacman_from_philippines.png");


	//VIEW******************************
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

	//ANIMATION************************
	Player player(&playerTexture, sf::Vector2u(3, 9), 0.3f, 150.0f, 200.0f, 200.0f, 200.0f, 100.0f, 150.0f);
	Player enemy(&enemyTexture, sf::Vector2u(3, 9), 0.3f, 0.0f, 0.0f, 400.0f, 200.0f, 40.0f, 65.0f);
	Player enemy2(&enemyTexture, sf::Vector2u(3, 9), 0.3f, 0.0f, 0.0f, 2700.0f, -100.0f, 40.0f, 65.0f);
	float deltaTime = 0.0f;
	sf::Clock clock;

	std::vector<Platform> platforms1;

	// 1. From start zone to long and high block
	platforms1.push_back(Platform(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(500.0f, 500.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(700.0f, 350.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(900.0f, 200.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(800.0f, 200.0f), sf::Vector2f(1450.0f, 50.0f)));

	std::vector<Platform> platforms2;

	// 1. From start zone to long and high block
	platforms2.push_back(Platform(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(500.0f, 500.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(1000.0f, 300.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(800.0f, 150.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(150.0f, 150.0f), sf::Vector2f(600.0f, 50.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(350.0f, -150.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(600.0f, -300.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(750.0f, -400.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(800.0f, 200.0f), sf::Vector2f(1450.0f, 0.0f)));

	// 2. from high block to even higher block
	platforms2.push_back(Platform(nullptr, sf::Vector2f(200.0f, 200.0f), sf::Vector2f(2100.0f, -150.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(100.0f, 500.0f), sf::Vector2f(2450.0f, -300.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(2250.0f, 300.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(500.0f, 100.0f), sf::Vector2f(2700.0f, 200.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(3100.0f, 25.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(300.0f, 100.0f), sf::Vector2f(3300.0f, -150.0f)));

	// cool structure within this part
	platforms2.push_back(Platform(nullptr, sf::Vector2f(150.0f, 500.0f), sf::Vector2f(3300.0f, -700.0f)));

	//There is something wrong with this one, changed to be lower. Original was -350
	platforms2.push_back(Platform(nullptr, sf::Vector2f(200.0f, 100.0f), sf::Vector2f(3700.0f, -345.0f)));

	platforms2.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(3550.0f, -150.0f)));

	//Changed from -550
	platforms2.push_back(Platform(nullptr, sf::Vector2f(200.0f, 100.0f), sf::Vector2f(3900.0f, -540.0f)));

	platforms2.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(4200.0f, -675.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(150.0f, 100.0f), sf::Vector2f(3900.0f, -800.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(150.0f, 500.0f), sf::Vector2f(4300.0f, -700.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(1100.0f, 100.0f), sf::Vector2f(3800.0f, -1200.0f)));

	// 3. from even higher block to highest of all blocks (or is it?)
	platforms2.push_back(Platform(nullptr, sf::Vector2f(500.0f, 100.0f), sf::Vector2f(4750.0f, -1050.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(5200.0f, -1200.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(5400.0f, -1300.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(5600.0f, -1400.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(5800.0f, -1500.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(6000.0f, -1600.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(6200.0f, -1700.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(6400.0f, -1800.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(6600.0f, -1900.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(6800.0f, -2000.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(7000.0f, -2170.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(400.0f, 100.0f), sf::Vector2f(7300.0f, -1800.0f)));

	// final stretch to the top (and end of the course)
	platforms2.push_back(Platform(nullptr, sf::Vector2f(25.0f, 25.0f), sf::Vector2f(7700.0f, -1900.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(25.0f, 25.0f), sf::Vector2f(7900.0f, -2050.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(25.0f, 25.0f), sf::Vector2f(8100.0f, -2225.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(300.0f, 200.0f), sf::Vector2f(8600.0f, -2426.0f)));
	// and then we end at the bottom
	platforms2.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(8300.0f, 0.0f)));

	// run the program as long as the window is open
	std::cout << "Welcome to the Game!!!" << std::endl;
	std::cout << std::endl;
	std::cout << "Controls:" << std::endl;
	std::cout << "W - Jump, A - Left, D - Right, Escape - Exit" << std::endl;
	std::cout << std::endl;
	std::cout << "Menu for the courses!" << std::endl;
	std::cout << "Enter 1 for Easy, 2 for Medium, 3 for Hard" << std::endl;
	int val = 0;
	sf::Vector2f pos;
	sf::Vector2f enemyPos;
	sf::Vector2f enemy2Pos;

	bool printVictoryMsg = false;
	bool printDeathMsg = false;

	bool playerKilled = false;
	bool enemyKilled = false;
	bool enemy2Killed = false;


	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 20.0f)
		{
			deltaTime = 1.0f / 20.0f;
		}

		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Num1)
				{
					std::cout << "You have selected the Easy Course!" << std::endl;
					val = 1;
				}

				else if (event.key.code == sf::Keyboard::Num2)
				{
					std::cout << "You have selected the Medium Course!" << std::endl;
					std::cout << "Be careful! If you touch the enemy in the wrong way, you die!" << std::endl;
					val = 2;
				}

				else if (event.key.code == sf::Keyboard::Num3)
				{
					std::cout << "You have selected the Hard Course!" << std::endl;
					std::cout << "But you need to pay for this! Support us please!" << std::endl;
					val = 3;
				}

				else if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
				break;

			case sf::Event::Resized:

				ResizeView(window, view);
				break;

			default:
				break;
			}
		}

		sf::Vector2f direction;
		view.setCenter(player.GetPosition());
		window.clear(sf::Color(150, 150, 150));
		window.setView(view);

		switch (val)
		{
		case 1:
			player.Update(deltaTime);
			for (Platform& platform : platforms1)
			{
				if (platform.GetCollider().CheckCollider(player.GetCollider(), direction, 1.0f))
					player.onCollision(direction);

				if (platform.GetCollider().CheckCollider(enemy.GetCollider(), direction, 1.0f))
					enemy.onCollision(direction);
			}

			player.Draw(window);

			for (Platform& platform : platforms1)
			{
				platform.Draw(window);
			}
			pos = player.GetPosition();

			if (1650.0f <= pos.x && pos.x <= 1850.0f && !printVictoryMsg)
			{
				printVictoryMsg = true;
				std::cout << "Congratualations! You finished the course!" << std::endl;
			}

			if (pos.y > 500.0f && !printDeathMsg) 
			{
				printDeathMsg = true;
				std::cout << "Unfortunately, you have died! Please exit and restart to try again!" << std::endl;
			}
			break;

		case 2:
			player.Update(deltaTime);
			enemy.Update(deltaTime);
			enemy2.Update(deltaTime);

			pos = player.GetPosition();
			enemyPos = enemy.GetPosition();
			enemy2Pos = enemy2.GetPosition();

			for (Platform& platform : platforms2)
			{
				if (platform.GetCollider().CheckCollider(player.GetCollider(), direction, 1.0f))
					player.onCollision(direction);

				if (platform.GetCollider().CheckCollider(enemy.GetCollider(), direction, 1.0f))
					enemy.onCollision(direction);

				if (platform.GetCollider().CheckCollider(enemy2.GetCollider(), direction, 1.0f))
					enemy2.onCollision(direction);

				if (!enemyKilled && !playerKilled) 
				{
					if (abs(pos.x - enemyPos.x) < 15.0f && abs(pos.y - enemyPos.y) <= 150.0f) 
					{
						std::cout << "You killed the enemy!" << std::endl;
						enemyKilled = true;
					}

					//This is just for regular collision
					else if (player.GetCollider().CheckCollider(enemy.GetCollider(), direction, 1.0f))
					{
						std::cout << "You died!" << std::endl;
						std::cout << "To start over, press escape!" << std::endl;
						playerKilled = true;
					}

					//This is to prevent death after landing from the jump
					else if (player.GetCollider().CheckCollider(enemy.GetCollider(), direction, 1.0f) && (pos.y) < (enemyPos.y)) 
					{
						std::cout << "You died!" << std::endl;
						std::cout << "To start over, press escape!" << std::endl;
						playerKilled = true;
					}
				}

				if (!enemy2Killed && !playerKilled)
				{
					if (abs(pos.x - enemy2Pos.x) < 15.0f && abs(pos.y - enemy2Pos.y) <= 150.0f)
					{
						std::cout << "You killed the enemy!" << std::endl;
						enemy2Killed = true;
					}

					//This is just for regular collision
					else if (player.GetCollider().CheckCollider(enemy2.GetCollider(), direction, 1.0f))
					{
						std::cout << "You died!" << std::endl;
						std::cout << "To start over, press escape!" << std::endl;
						playerKilled = true;
					}

					//This is to prevent death after landing from the jump
					else if (player.GetCollider().CheckCollider(enemy2.GetCollider(), direction, 1.0f) && (pos.y) < (enemy2Pos.y))
					{
						std::cout << "You died!" << std::endl;
						std::cout << "To start over, press escape!" << std::endl;
						playerKilled = true;
					}
				}
			}

			if (!playerKilled) {
				player.Draw(window);
			}

			if (!enemyKilled) {
				enemy.Draw(window);
			}

			if (!enemy2Killed) {
				enemy2.Draw(window);
			}

			for (Platform& platform : platforms2)
			{
				platform.Draw(window);
			}

			if (8100.0f <= pos.x && pos.x <= 8500.0f && pos.y > -200.0f && !printVictoryMsg)
			{
				printVictoryMsg = true;
				std::cout << "Congratualations! You finished the course!" << std::endl;
			}

			if (pos.y > 500.0f && !printDeathMsg) 
			{
				printDeathMsg = true;
				std::cout << "Unfortunately, you have died! Please exit and restart to try again!" << std::endl;
			}
			break;
		

		case 3:
			break;
							
		}

		window.display();
	}
	return 0;
}
