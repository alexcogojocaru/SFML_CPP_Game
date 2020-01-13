#include "State.h"

unsigned State::currentState = 0;

unsigned State::level = 0;

bool State::load = false;

bool State::deadPlayer = false;

bool State::textureError = false;

State::State(unsigned width, unsigned height, int buttonCount)
{
	this->buttonCount = buttonCount;
	currentButton = 0;

	try {
		exceptionManager.load(backgroundTexture[0], "Textures/FinalTiles/Background/CloudsBack.png");
		exceptionManager.load(backgroundTexture[1], "Textures/FinalTiles/Background/CloudsFront.png");
		exceptionManager.load(foregroundTexture[0], "Textures/FinalTiles/Background/BGBack.png");
		exceptionManager.load(foregroundTexture[1], "Textures/FinalTiles/Background/BGFront.png"); 
	}
	catch (const exception & ex) {
		textureError = true;
	}

	font.loadFromFile("Fonts/BLKCHCRY.ttf");
	text = sf::Text("Could not load the texture", font, 30);
	text.setFillColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold);
	text.setPosition({ 10.0f, 0.0f });

	background[0].setTexture(backgroundTexture[0]);
	background[1].setTexture(backgroundTexture[1]);
	background[2].setTexture(foregroundTexture[0]);
	background[3].setTexture(foregroundTexture[1]);

	for (int i = 0; i < 4; i++)
	{
		background[i].setScale((float)width / backgroundTexture[0].getSize().x, (float)height / backgroundTexture[0].getSize().y);
	}
}

State::~State()
{
	for (Button* but : buttons)
		delete but;
}

void State::Navigate(sf::RenderWindow* window, sf::Event event)
{
	buttons.at(currentButton)->setColor(sf::Color::White);

	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::W)
			--currentButton;

		if (event.key.code == sf::Keyboard::S)
			++currentButton;
	}

	if (currentButton < 0)
		currentButton = 0;

	if (currentButton > buttonCount - 1)
		currentButton = buttonCount - 1;

	buttons.at(currentButton)->setColor(sf::Color::Red);
}

void State::Draw(sf::RenderWindow* window)
{
	for (Button* but : buttons)
	{
		but->Draw(window);
	}
}