#include "PlayState.h"

PlayState::PlayState(unsigned width, unsigned height, int buttonCount)
	: State(width, height, buttonCount)
{
	player = new Player({ 40, 40 }, { 100.0f, 100.0f }, "Textures/Knight2/spritesheet.png");

	levels.push(new Level(player, width, height, "map_coordinates2.txt", 2, 100));
	levels.push(new Level(player, width, height, "map_coordinates1.txt", 1, 200));
	levels.push(new Level(player, width, height, "map_coordinates0.txt", 0, 300));
}

PlayState::~PlayState()
{
	delete player;
}

void PlayState::ResetLoadSavings()
{
	unsigned x = 0;

	while (!levels.empty() && (x++ < State::level))
		levels.pop();
}

void PlayState::Navigate(sf::RenderWindow* window, sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Escape)
		{
			currentState = 2;
		}
	}
}

void PlayState::Update(float deltaTime)
{
	if (!levels.empty())
	{
		if (levels.top()->isPlayerDead())
		{
			currentState = 3;
			State::deadPlayer = true;
		}

		if (levels.top()->allNPCSKilled())
		{
			levels.pop();
			player->setPosition({ 1320.0f, 100.0f });
			++State::level;
		}
		else
		{
			levels.top()->Update(deltaTime);
		}
	}
	else
	{
		currentState = 3;
	}
}

void PlayState::Draw(sf::RenderWindow* window)
{
	if (!levels.empty())
	{
		levels.top()->Draw(window);
	}
	
	if (textureError)
	{
		window->draw(text);
	}
}