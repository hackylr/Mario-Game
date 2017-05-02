// From here: https://www.sfml-dev.org/tutorials/2.4/window-events.php
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
#include "Player.h"
#include "Platform.h"
#include <conio.h>

/*
int main() {
sf::Window window(sf::VideoMode(800, 600), "Window", sf::Style::Default);
//window.setVerticalSyncEnabled(true); // call it once, after creating the window

//window.setPosition(sf::Vector2i(100, 100));
//sf::Vector2u size = window.getSize();
//unsigned int width = size.x;
//unsigned int height = size.y;
//std::cout << width << std::endl;
//std::cout << height << std::endl;
//std::cin.get();
sf::Event event;
// while there are pending events...
std::cout << "Poll event" << std::endl;
while (window.pollEvent(event)) {
//std::cout << "Poll event" << std::endl;
// check the type of the event...
switch (event.type) {
// key pressed
case sf::Event::KeyPressed:
std::cout << "Key Pressed" << std::endl;
if (event.key.code == sf::Keyboard::Escape) {
std::cout << "the escape key was pressed" << std::endl;
//std::cout << "control:" << event.key.control << std::endl;
}
break;
default:
//std::cout << "Other" << std::endl;
break;
}
}
std::cout << "Quit menu" << std::endl;
std::cin.get();
}
*/

static const float VIEW_HEIGHT = 512.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "My window");
	//sf::RectangleShape shape(sf::Vector2f(100.0f, 150.0f));
	//shape.setFillColor(sf::Color::Yellow);
	//shape.setOrigin(50.0f, 50.0f);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("tux_from_linux.png");
	//shape.setTexture(&shapeTexture);

	//VIEW******************************
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

	//ANIMATION************************
	// For testing the ending
	//Player player(&playerTexture, sf::Vector2u(3, 9), 0.3f, 150.0f, 200.0f, 7300.0f, -2100.0f);
	Player player(&playerTexture, sf::Vector2u(3, 9), 0.3f, 150.0f, 200.0f, 200.0f, 200.0f);
	Player player2(&playerTexture, sf::Vector2u(3, 9), 0.3f, 150.0f, 200.0f, 300.0f, 300.0f);
	float deltaTime = 0.0f;
	sf::Clock clock;

	std::vector<Platform> platforms1;
	/*
	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(500.0f, 500.0f)));
	*/

	// 1. From start zone to long and high block
	platforms1.push_back(Platform(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(500.0f, 500.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(1000.0f, 300.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(800.0f, 150.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(150.0f, 150.0f), sf::Vector2f(600.0f, 50.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(350.0f, -150.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(600.0f, -300.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(750.0f, -400.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(800.0f, 200.0f), sf::Vector2f(1450.0f, 0.0f)));

	//remove when done testing (cheat block to skip part 1s)
	//platforms.push_back(Platform(nullptr, sf::Vector2f(225.0f, 100.0f), sf::Vector2f(1100.0f, 25.0f)));

	// 2. from high block to even higher block
	platforms1.push_back(Platform(nullptr, sf::Vector2f(200.0f, 200.0f), sf::Vector2f(2100.0f, -150.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(100.0f, 500.0f), sf::Vector2f(2450.0f, -300.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(2250.0f, 300.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(500.0f, 100.0f), sf::Vector2f(2700.0f, 200.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(3100.0f, 25.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(300.0f, 100.0f), sf::Vector2f(3300.0f, -150.0f)));

	// cool structure within this part
	platforms1.push_back(Platform(nullptr, sf::Vector2f(150.0f, 500.0f), sf::Vector2f(3300.0f, -700.0f)));

	//There is something wrong with this one, changed to be lower. Original was -350
	platforms1.push_back(Platform(nullptr, sf::Vector2f(200.0f, 100.0f), sf::Vector2f(3700.0f, -345.0f)));

	platforms1.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(3550.0f, -150.0f)));

	//Changed from -550
	platforms1.push_back(Platform(nullptr, sf::Vector2f(200.0f, 100.0f), sf::Vector2f(3900.0f, -540.0f)));

	platforms1.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(4200.0f, -675.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(150.0f, 100.0f), sf::Vector2f(3900.0f, -800.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(150.0f, 500.0f), sf::Vector2f(4300.0f, -700.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(1100.0f, 100.0f), sf::Vector2f(3800.0f, -1200.0f)));

	// 3. from even higher block to highest of all blocks (or is it?)
	platforms1.push_back(Platform(nullptr, sf::Vector2f(500.0f, 100.0f), sf::Vector2f(4750.0f, -1050.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(5200.0f, -1200.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(5400.0f, -1300.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(5600.0f, -1400.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(5800.0f, -1500.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(6000.0f, -1600.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(6200.0f, -1700.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(6400.0f, -1800.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(6600.0f, -1900.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(6800.0f, -2000.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(7000.0f, -2170.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(400.0f, 100.0f), sf::Vector2f(7300.0f, -1800.0f)));

	// final stretch to the top (and end of the course)
	platforms1.push_back(Platform(nullptr, sf::Vector2f(25.0f, 25.0f), sf::Vector2f(7700.0f, -1900.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(25.0f, 25.0f), sf::Vector2f(7900.0f, -2050.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(25.0f, 25.0f), sf::Vector2f(8100.0f, -2225.0f)));
	platforms1.push_back(Platform(nullptr, sf::Vector2f(300.0f, 200.0f), sf::Vector2f(8600.0f, -2426.0f)));
	// and then we end at the bottom
	platforms1.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(8300.0f, 0.0f)));


	/*
	sf::Vector2u textureSize = shapeTexture.getSize();
	textureSize.x /= 3;
	textureSize.y /= 9;
	shape.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y * 8, textureSize.x, textureSize.y));
	*/

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
	bool printVictoryMsg = false;
	bool printDeathMsg = false;

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
				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
				break;


				/*
				case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
				{
				std::cout << "the escape key was pressed" << std::endl;
				}
				else
				{
				std::cout << "Another key was pressed" << std::endl;
				}



				case sf::Event::TextEntered:
				if (event.text.unicode < 128)
				{
				printf("%c", event.text.unicode);
				}
				*/
			case sf::Event::Resized:
				//printf("New Window width: %i, New window height: %i\n", event.size.width, event.size.height);
				ResizeView(window, view);
				break;

			default:
				break;
			}

			//Moving with the keyboard
			/*
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			{
			shape.move(-2.0f, 0.0f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			{
			shape.move(2.0f, 0.0f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			{
			shape.move(0.0f, -2.0f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			{
			shape.move(0.0f, 2.0f);
			}
			*/

			/*
			//Moving with the mouse
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			//(float) is faster, but not as safe as static_cast
			shape.setPosition((float)(mousePos.x), (float)(mousePos.y));
			//shape.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
			}
			*/


		}
		player.Update(deltaTime);
		player2.Update(deltaTime);

		sf::Vector2f direction;

		for (Platform& platform : platforms1)
		{
			if (platform.GetCollider().CheckCollider(player.GetCollider(), direction, 1.0f))
				player.onCollision(direction);

			if (platform.GetCollider().CheckCollider(player2.GetCollider(), direction, 1.0f))
				player2.onCollision(direction);
		}

		/*
		platform1.GetCollider().CheckCollider(player.GetCollider(), 0.0f);
		platform2.GetCollider().CheckCollider(player.GetCollider(), 1.0f);
		*/

		view.setCenter(player.GetPosition());

		window.clear(sf::Color(150, 150, 150));
		window.setView(view);
		
		switch (val)
		{
		case 1:
			player.Draw(window);
			player2.Draw(window);

			for (Platform& platform : platforms1)
			{
				platform.Draw(window);
			}
			pos = player.GetPosition();
			//std::cout << pos.x;
			//std::cout << pos.y << std::endl;
			//This will repeatedly show the message....I guess it's ok. It's kind of funny haha

			if (8100.0f <= pos.x && pos.x <= 8500.0f && pos.y == -175.0f && !printVictoryMsg)
			{
				printVictoryMsg = true;
				std::cout << "Congratualations! You finished the course!" << std::endl;
				//std::cout << "Press Escape to escape!" << std::endl;
				//getch();
			}

			if (pos.y > 500.0f && !printDeathMsg) {
				printDeathMsg = true;
				std::cout << "Unfortunately, you have died! Please exit and restart to try again!" << std::endl;
			}


			break;
		}

		window.display();
	}
	/*
	I could put the message here, but it does not show up until I close out the window.
	So it will show up briefly for like half a second...


	if (8000.0f < pos.x && pos.x <= 8300.0f && pos.y == -175.0f)
	{
	std::cout << "Congratualations! You finished the course!" << std::endl;
	//std::cout << "Press Escape to escape!" << std::endl;
	_getch();
	}
	*/

	return 0;
}