#pragma once

#include <iostream>
#include <fstream>
#include "State.h"

class MainMenuState : public State
{
public:
	MainMenuState(unsigned width, unsigned height, int buttonCount);

	void Navigate(sf::RenderWindow* window, sf::Event event) override;
	void Draw(sf::RenderWindow* window) override;
};

