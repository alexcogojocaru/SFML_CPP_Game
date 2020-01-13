#include "Tile.h"

Tile::Tile(sf::Vector2f coords, sf::Texture* texture, sf::Vector2i texCoords, sf::Vector2f size)
	: Component(size, coords, texture)
{
	sprite.setTextureRect(sf::IntRect(texCoords.x, texCoords.y, tileSize, tileSize));
}

void Tile::Draw(sf::RenderWindow* window)
{
	window->draw(sprite);
}
