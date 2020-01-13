#include "Component.h"

Component::Component(sf::Vector2f size, sf::Vector2f position, sf::Texture* texture)
{
	sprite.setPosition(position);
	sprite.setSize(size);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 170, 96));
}

Component::Component(sf::Vector2f size, sf::Vector2f position, string path)
{
	try {
		exceptionManager.load(texture, path);
	}
	catch (const exception & ex) {
		State::textureError = true;
	}

	sprite.setPosition(position);
	sprite.setSize(size);
	sprite.setTexture(&texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 170, 96));
}

Component::~Component()
{

}