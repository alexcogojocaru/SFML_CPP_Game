#include "NPC.h"

NPC::NPC(sf::Vector2f size, sf::Vector2f position, string path, bool right)
	: Entity(size, position, path), row(1)
{
	direction = (right) ? 1.0f : -1.0f;
	totalPath = 0.0f;
	velocity = { direction * (speed - 20.0f), 0.0f };
	boundaries = { 100, 300 };
	this->right = right;
}


NPC::~NPC()
{

}

void NPC::Update(float deltaTime)
{
	//float direction = (right) ? -1.0f : 1.0f;
	totalPath += 20.0f;

	if (health > 0.0f)
	{
		if (totalPath * deltaTime >= 500.0f)
		{
			totalPath = 0.0f;
			right = !right;
			velocity.x *= -1.0f;
		}
	}
	else
	{
		row = 3;
	}

	velocity.y += 200.0f * deltaTime;

	animation->Update(row, deltaTime, right);
	sprite.setTextureRect(animation->shapeRect);
	sprite.move(velocity * deltaTime);
}