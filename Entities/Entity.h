#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Component.h"
#include "Animation.h"

using namespace std;

constexpr float speed = 100.0f;

class Entity : public Component
{
protected:
	Animation* animation;
	double health;
	double attackDamage;
	bool right;

public:
	Entity(sf::Vector2f size, sf::Vector2f position, string path);
	virtual ~Entity();

	virtual void Draw(sf::RenderWindow* window);
	virtual void Update(float deltaTime) = 0;

	bool checkCollision(Component* component);
	void takeDamage() { health -= 0.1f; }
	double getHealth() const { return health; }
};

