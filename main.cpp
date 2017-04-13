// From here: https://www.sfml-dev.org/tutorials/2.4/window-events.php
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
#include "Player.h"
#include "Platform.h"

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
	Player player(&playerTexture, sf::Vector2u(3, 9), 0.3f, 100.0f, 200.0f);
	float deltaTime = 0.0f;
	sf::Clock clock;

	std::vector<Platform> platforms;
	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(500.0f, 500.0f)));


	/*
	sf::Vector2u textureSize = shapeTexture.getSize();
	textureSize.x /= 3;
	textureSize.y /= 9;
	shape.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y * 8, textureSize.x, textureSize.y));
	*/

	// run the program as long as the window is open
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

		sf::Vector2f direction;

		for (Platform& platform : platforms)
		{
			if (platform.GetCollider().CheckCollider(player.GetCollider(), direction, 1.0f))
				player.onCollision(direction);
		}

		/*
		platform1.GetCollider().CheckCollider(player.GetCollider(), 0.0f);
		platform2.GetCollider().CheckCollider(player.GetCollider(), 1.0f);
		*/

		view.setCenter(player.GetPosition());

		window.clear(sf::Color(150, 150, 150));
		window.setView(view);
		player.Draw(window);
		
		for (Platform& platform : platforms)
		{
			platform.Draw(window);
		}

		window.display();
	}

	return 0;
}
