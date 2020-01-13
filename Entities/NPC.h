#pragma once

#include "Entity.h"

class NPC : public Entity
{
private:
	float totalPath;
	sf::Vector2f velocity;
	sf::Vector2f boundaries;
	unsigned row;
	float direction;

public:
	NPC(sf::Vector2f size, sf::Vector2f position, string path, bool right = true);
	virtual ~NPC();

	void Update(float deltaTime) override;
};

