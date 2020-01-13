#include "PauseMenuState.h"

PauseMenuState::PauseMenuState(unsigned width, unsigned height, int buttonCount)
	: State(width, height, buttonCount)
{
	buttons.push_back(new Button("RESUME", { (float)width / 2 - 90, 300 }));
	buttons.at(0)->setColor(sf::Color::Red);
	buttons.push_back(new Button("SAVE", { (float)width / 2 - 60, 400 }));
	buttons.push_back(new Button("MAIN MENU", { (float)width / 2 - 120, 500 }));
}

void PauseMenuState::Navigate(sf::RenderWindow* window, sf::Event event)
{
	State::Navigate(window, event);

	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Enter)
		{
			if (buttons.at(currentButton)->getString() == "RESUME")
			{
				currentState = 1;
			}

			if (buttons.at(currentButton)->getString() == "SAVE")
			{
				FileException<ofstream> fileException;
				ofstream saveFile;

				try {
					fileException.load(saveFile, "saveFile.txt");
					saveFile << State::level;
					saveFile.close();
				}
				catch (const ofstream::failure & ex)
				{
					
				}
			}

			if (buttons.at(currentButton)->getString() == "MAIN MENU")
			{
				currentState = 0;
			}
		}
	}
}

void PauseMenuState::Draw(sf::RenderWindow* window)
{
	for (sf::Sprite x : background)
	{
		window->draw(x);
	}

	State::Draw(window);
}
