#include "Player.h"

Player::Player(sf::Vector2f size, sf::Vector2f position, string path)
	: Entity(size, position, path), canJump(true), isAttacking(false)
{
	time = 0.0f;
}

Player::~Player()
{	
}

void Player::Update(float deltaTime)
{
	unsigned row;

	velocity.x = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		velocity.x += speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		velocity.x -= speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump)
	{
		velocity.y = -sqrtf(2.0f * 800.0f * jumpHeight);
		canJump = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		isAttacking = true;

	velocity.y += 800.0f * deltaTime;

	if (!isAttacking)
	{
		if (velocity.x == 0.0f)
		{
			row = 0;
		}
		else
		{
			row = 1;

			if (velocity.x > 0.0f)
				right = true;
			else
				right = false;
		}
	}
	else
	{
		row = 2;

		time += deltaTime;

		if (time >= 1.5f)
		{
			isAttacking = false;
			time = 0.0f;
		}
	}

	animation->Update(row, deltaTime, right);
	sprite.setTextureRect(animation->shapeRect);
	sprite.move(velocity * deltaTime);
}