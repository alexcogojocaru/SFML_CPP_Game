#include "MainMenuState.h"

MainMenuState::MainMenuState(unsigned width, unsigned height, int buttonCount)
	: State(width, height, buttonCount)
{
	buttons.push_back(new Button("PLAY", { (float)width / 2 - 60, 200}));
	buttons.at(0)->setColor(sf::Color::Red);
	buttons.push_back(new Button("LOAD", { (float)width / 2 - 60, 300}));
	buttons.push_back(new Button("EXIT", { (float)width / 2 - 60, 400}));
}

void MainMenuState::Navigate(sf::RenderWindow* window, sf::Event event)
{
	State::Navigate(window, event);

	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Enter)
		{
			if (buttons.at(currentButton)->getString() == "PLAY")
			{
				currentState = 1;
			}

			if (buttons.at(currentButton)->getString() == "LOAD")
			{
				FileException<ifstream> fileException;
				ifstream loadFile;

				try {
					fileException.load(loadFile, "saveFile.txt");
					loadFile >> State::level;
					loadFile.close();
					State::load = true;
				}
				catch (const ifstream::failure & ex) {

				}
			}

			if (buttons.at(currentButton)->getString() == "EXIT")
			{
				window->close();
			}
		}
	}
}

void MainMenuState::Draw(sf::RenderWindow* window)
{
	for (sf::Sprite x : background)
	{
		window->draw(x);
	}

	State::Draw(window);
}
