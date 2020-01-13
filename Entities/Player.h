#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.h"

using namespace std;

constexpr float jumpHeight = 200.0f;

class Player : public Entity
{
private:
	float time;
	bool isAttacking;
	bool canJump;
	sf::Vector2f velocity;

public:
	Player(sf::Vector2f size, sf::Vector2f position, string path);
	virtual ~Player();

	void Update(float deltaTime);

	void setJump() { canJump = true; }
	bool getIsAttacking() const { return isAttacking; }
};
