// From here: https://www.sfml-dev.org/tutorials/2.4/window-events.php
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
	sf::Window window(sf::VideoMode(800, 600), "Window", sf::Style::Default);
	window.setVerticalSyncEnabled(true); // call it once, after creating the window

	//window.setPosition(sf::Vector2i(100, 100));
	/*sf::Vector2u size = window.getSize();
	unsigned int width = size.x;
	unsigned int height = size.y;
	std::cout << width << std::endl;
	std::cout << height << std::endl;
	std::cin.get();*/
	
	sf::Event event;

	// while there are pending events...
	while (window.pollEvent(event)) {
		std::cout << "Poll event" << std::endl;
		// check the type of the event...
		switch (event.type) {
		  // key pressed
		  case sf::Event::KeyPressed:
		    std::cout << "Key Pressed" << std::endl;
		    if (event.key.code == sf::Keyboard::Escape) {
			  std::cout << "the escape key was pressed" << std::endl;
			  std::cout << "control:" << event.key.control << std::endl;
			}
			break;
		  default:
			std::cout << "Other" << std::endl;
			break;
		}
	}
	std::cout << "Quit menu" << std::endl;
	std::cin.get();
}

/*int main() {
	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Application");
	sf::CircleShape shape;
	shape.setRadius(40.f);
	shape.setPosition(100.f, 100.f);
	shape.setFillColor(sf::Color::Cyan);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(shape);
		window.display();
	}
}*/
