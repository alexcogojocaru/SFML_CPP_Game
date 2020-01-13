#pragma once

#include <SFML/Graphics.hpp>

using namespace std;

class Button
{
private:
	sf::Text* button;
	sf::Font font;

public:
	Button(string text, sf::Vector2f position);
	~Button();

	void Draw(sf::RenderWindow* window);
	void setColor(sf::Color color) { button->setFillColor(color); }
	string getString() const { return button->getString(); }
};

