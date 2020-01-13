#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "ExceptionManager.h"
#include "State.h"

using namespace std;

class Component
{
private:
	sf::Texture texture;
	ExceptionManager exceptionManager;

protected:
	sf::RectangleShape sprite;

public:
	Component(sf::Vector2f size, sf::Vector2f position, sf::Texture *texture);
	Component(sf::Vector2f size, sf::Vector2f position, string path);
	virtual ~Component();

	sf::RectangleShape getEntity() const { return sprite; }
	sf::Vector2f getPosition() const { return sprite.getPosition(); }
	void setPosition(sf::Vector2f pos) { sprite.setPosition(pos); }
	void Move(sf::Vector2f pos) { sprite.move(pos); }
	
	virtual void Draw(sf::RenderWindow* window) = 0;
};