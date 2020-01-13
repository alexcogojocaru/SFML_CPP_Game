#pragma once

#include <stack>
#include "State.h"
#include "Level.h"
#include "Player.h"

class PlayState : public State
{
private:
	sf::Texture playerTexture;
	Player* player;
	stack<Level*> levels;

public:
	PlayState(unsigned width, unsigned height, int buttonCount);
	virtual ~PlayState();

	void ResetLoadSavings();
	void Navigate(sf::RenderWindow* window, sf::Event event) override;
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window) override;

	Player* getPlayer() const { return player; }
};

