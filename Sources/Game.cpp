#include "Game.h"

Game::Game(unsigned width, unsigned height, string title)
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), title);

	states.push_back(new MainMenuState(width, height, 3));
	states.push_back(new PlayState(width, height, 0));
	states.push_back(new PauseMenuState(width, height, 3));
	states.push_back(new GameEndState(width, height, 1));
}
 
Game::~Game()
{
	delete window;

	for (State* stat : states)
	{
		delete stat;
	}
}

void Game::Update(float deltaTime)
{
	sf::Event event_;

	while (window->pollEvent(event_))
	{
		if (event_.type == sf::Event::Closed)
		{
			window->close();
		}

		states.at(State::currentState)->Navigate(window, event_);
		
		if (State::load)
		{
			PlayState* temp = dynamic_cast<PlayState*>(states.at(1));
			
			temp->ResetLoadSavings();
			State::load = false;
		}
	}

	if (State::deadPlayer)
	{
		GameEndState* temp = dynamic_cast<GameEndState*>(states.at(3));
		temp->setString("You died");
	}

	if (State::currentState == 1)
	{
		PlayState* temp = dynamic_cast<PlayState*>(states.at(1));
		temp->Update(deltaTime);
	}
}

void Game::Draw()
{
	states.at(State::currentState)->Draw(window);
}

void Game::Run()
{
	sf::Clock clock;
	float deltaTime;

	while (window->isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		window->clear();
		Game::Update(deltaTime);
		Game::Draw();
		window->display();
	}
}