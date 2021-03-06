#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight
	, float x, float y, float sizeX, float sizeY);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void onCollision(sf::Vector2f direction);

	sf::Vector2f GetPosition()
	{
		return body.getPosition();
	}

	float getSizeX() {
		return sizeX;
	}

	float getSizeY() {
		return sizeY;
	}

	sf::Vector2f SetPosition(float x, float y)
	{
		body.setPosition(x, y);
		return body.getPosition();
	}

	Collider GetCollider()
	{
		return Collider(body);
	}

private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;

	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;

	float sizeX;
	float sizeY;
};