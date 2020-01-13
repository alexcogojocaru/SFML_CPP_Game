#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
#include "NPC.h"
#include "Map.h"

using namespace std;

class Level
{
private:
	sf::Texture npcTexture;
	Player* player;
	vector<NPC*> npcs; 
	Map* map;
	unsigned height;

public:
	Level(Player* player, unsigned width, unsigned height, string mapPath, unsigned level, unsigned groundCoord);
	virtual ~Level();

	void InitLevel(unsigned level);
	bool allNPCSKilled();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
	bool isPlayerDead() const { return (player->getHealth() < 0.0f) ? true : false; }
};

