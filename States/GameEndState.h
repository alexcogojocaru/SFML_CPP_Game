#pragma once

#include "State.h"

class GameEndState : public State
{
private:
	sf::Text endText;

public:
	GameEndState(unsigned width, unsigned height, int buttonCount);

	void Navigate(sf::RenderWindow *window, sf::Event event) override;
	void Draw(sf::RenderWindow* window) override;

	void setString(string text) { endText.setString(text); };
};

