#include "Button.h"

Button::Button(string text, sf::Vector2f position)
{
	font.loadFromFile("Fonts/BLKCHCRY.ttf");
	
	button = new sf::Text(text, font, 30);

	button->setPosition(position);
	button->setFillColor(sf::Color::White);
	button->setStyle(sf::Text::Bold);
}

Button::~Button()
{
	delete button;
}

void Button::Draw(sf::RenderWindow* window)
{
	window->draw(*button);
}
