#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "ExceptionManager.h"
#include "FileException.h"

using namespace std;

class State
{
protected:
	sf::Sprite background[4];
	sf::Texture backgroundTexture[2];
	sf::Texture foregroundTexture[2];
	ExceptionManager exceptionManager;
	vector<Button*> buttons;
	sf::Text text;
	sf::Font font;
	int currentButton;
	int buttonCount;

public:
	static unsigned currentState;
	static unsigned level;
	static bool load;
	static bool deadPlayer;
	static bool textureError;

public:
	State(unsigned width, unsigned height, int buttonCount);
	virtual ~State();

	virtual void Navigate(sf::RenderWindow* window, sf::Event event);
	virtual void Draw(sf::RenderWindow* window);
};

