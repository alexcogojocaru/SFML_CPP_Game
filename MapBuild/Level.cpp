#include "Level.h"

Level::Level(Player* player, unsigned width, unsigned height, string mapPath, unsigned level, unsigned groundCoord)
	: player(player)
{
	this->height = height;

	map = new Map(width, height, mapPath, groundCoord);

	Level::InitLevel(level);
}

Level::~Level()
{
	for (NPC* npc : npcs)
	{
		delete npc;
	}
	
	delete player;
	delete map;
}

void Level::InitLevel(unsigned level)
{
	if (level == 0)
	{
		npcs.push_back(new NPC({ 40, 40 }, { 1500.0f, 100.0f }, "Textures/Knight2/spritesheet.png", false));
	}							 
	else if (level == 1)		 
	{							 
		npcs.push_back(new NPC({ 40, 40 }, { 100.0f, 200.0f }, "Textures/Knight2/spritesheet.png"));
		npcs.push_back(new NPC({ 40, 40 }, { 1500.0f, 100.0f }, "Textures/Knight2/spritesheet.png", false));
	}							 
	else if (level == 2)		 
	{							 
		npcs.push_back(new NPC({ 40, 40 }, { 50.0f, 100.0f }, "Textures/Knight2/spritesheet.png"));
		npcs.push_back(new NPC({ 40, 40 }, { 1300.0f, 100.0f }, "Textures/Knight2/spritesheet.png", false));
		npcs.push_back(new NPC({ 40, 40 }, { 1000.0f, 400.0f }, "Textures/Knight2/spritesheet.png", false));
	}
}

bool Level::allNPCSKilled()
{
	for (NPC* npc : npcs)
	{
		if (npc->getHealth() >= 0.0f)
			return false;
	}

	return true;
}

void Level::Update(float deltaTime)
{
	player->Update(deltaTime);

	if (player->getPosition().y > height)
		player->takeDamage();

	for (NPC* npc : npcs)
	{
		if (npc->getPosition().y > height)
			npc->takeDamage();

		npc->Update(deltaTime);
	}

	for (Tile tile : map->getSpikeTiles())
	{
		if (player->checkCollision(&tile))
		{
			player->Move({ 0.0f, -3.0f });
			player->takeDamage();
			player->setJump();
		}

		for (NPC* npc : npcs)
		{
			if (npc->checkCollision(&tile))
			{
				npc->Move({ 0.0f, -3.0f });
				npc->takeDamage();
			}
		}
	}

	for (Tile tile : map->getGrassTiles())
	{
		if (player->checkCollision(&tile)) 
		{
			player->Move({ 0.0f, -3.0f });
			player->setJump();
		}

		for (NPC* npc : npcs)
		{
			if (npc->checkCollision(&tile))
			{
				npc->Move({ 0.0f, -3.0f });
			}
		}
	}

	for (NPC* npc : npcs)
	{
		if (player->getIsAttacking() && player->checkCollision(&*npc))
		{
			npc->takeDamage();
		}
	}
}

void Level::Draw(sf::RenderWindow* window)
{
	map->Draw(window);
	player->Draw(window);

	for (NPC* npc : npcs)
	{
		npc->Draw(window);
	}
}
