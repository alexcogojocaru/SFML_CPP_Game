#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "MainMenuState.h"
#include "PlayState.h"
#include "PauseMenuState.h"
#include "GameEndState.h"

using namespace std;

class Game
{
private:
	sf::RenderWindow* window;
	vector<State*> states;

private:
	void Update(float deltaTime);
	void Draw();

public:
	Game(unsigned width, unsigned height, string title);
	~Game();

	Game(const Game& game) = delete;
	Game& operator = (const Game& game) = delete;

	void Run();
};

