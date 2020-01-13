#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "ExceptionManager.h"
#include "FileException.h"
#include "State.h"

using namespace std;

class Map
{
private:
	sf::Sprite background[4];
	sf::Texture backgroundTexture[2];
	sf::Texture foregroundTexture[2];
	sf::Texture tileTexture;
	vector<Tile> mudTiles;
	vector<Tile> grassTiles;
	vector<Tile> spikeTiles;
	ExceptionManager exceptionManager;

public:
	Map(unsigned width, unsigned height, string path, unsigned groundCoord);

	void InitTiles(unsigned height, unsigned groundCoord, string path);

	void Draw(sf::RenderWindow* window);

	vector<Tile> getGrassTiles() const { return grassTiles; }
	vector<Tile> getMudTiles() const { return mudTiles; }
	vector<Tile> getSpikeTiles() const { return spikeTiles; }
};

