#include "GameEndState.h"

GameEndState::GameEndState(unsigned width, unsigned height, int buttonCount)
	: State(width, height, buttonCount)
{
	endText = sf::Text("Well done", font, 30);
	endText.setPosition({ (float)width / 2 - 100, 300 });
	endText.setFillColor(sf::Color::Red);
	endText.setStyle(sf::Text::Bold);

	buttons.push_back(new Button("MAIN MENU", { (float)width / 2 - 120, 500 }));
	buttons.at(0)->setColor(sf::Color::Red);
}

void GameEndState::Navigate(sf::RenderWindow* window, sf::Event event)
{
	State::Navigate(window, event);

	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Enter)
		{
			currentState = 0;
		}
	}
}

void GameEndState::Draw(sf::RenderWindow* window) 
{
	for (sf::Sprite x : background)
	{
		window->draw(x);
	}

	window->draw(endText);
	State::Draw(window);
}