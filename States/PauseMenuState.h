#pragma once

#include "State.h"

class PauseMenuState : public State
{
public:
	PauseMenuState(unsigned width, unsigned height, int buttonCount);

	void Navigate(sf::RenderWindow* window, sf::Event event) override;
	void Draw(sf::RenderWindow* window) override;
};

