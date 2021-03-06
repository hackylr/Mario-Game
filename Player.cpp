#include "Player.h"



Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight
	, float x, float y, float sizeX, float sizeY) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;
	this->sizeX = sizeX;
	this->sizeY = sizeY;

	body.setSize(sf::Vector2f(sizeX, sizeY));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(x, y);
	//body.setPosition(200.0f, 200.0f);
	body.setTexture(texture);
}


Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	//THis is to see if the player stops immediately or slows down
	velocity.x = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x -= speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x += speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump)
	{
		canJump = false;

		//Jump equation
		//100SFML units = 1 Meter
		velocity.y = -sqrt(2.0f * 981.0f * jumpHeight);
	}

	velocity.y += 981.0f * deltaTime;

	/*
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
	movement.y -= speed*deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
	movement.y += speed*deltaTime;
	}
	*/

	if (velocity.x == 0.0f)
	{
		row = 0;
	}
	else
	{
		row = 1;

		if (velocity.x > 0.0f)
		{
			faceRight = true;
		}
		else
		{
			faceRight = false;
		}
	}

	animation.update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Player::onCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		//Collision on the left
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		//Collision on the right
		velocity.x = 0.0f;
	}

	if (direction.y < 0.0f)
	{
		//Collision on the bottom
		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f)
	{
		//Collision on the top
		velocity.y = 0.0f;
	}

}