#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Component.h"

using namespace std;

constexpr float tileOffset = 60;
constexpr int tileSize = 16;

class Tile : public Component
{
public:
	Tile(sf::Vector2f coords, sf::Texture* texture, sf::Vector2i texCoords, sf::Vector2f size = { tileOffset, tileOffset });

	void Draw(sf::RenderWindow* window);
};

