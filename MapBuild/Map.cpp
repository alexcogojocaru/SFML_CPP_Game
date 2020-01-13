#include "Map.h"

Map::Map(unsigned width, unsigned height, string path, unsigned groundCoord)
{
	try {
		exceptionManager.load(backgroundTexture[0], "Textures/FinalTiles/Background/CloudsBack.png");
		exceptionManager.load(backgroundTexture[1], "Textures/FinalTiles/Background/CloudsFront.png");
		exceptionManager.load(foregroundTexture[0], "Textures/FinalTiles/Background/BGBack.png");
		exceptionManager.load(foregroundTexture[1], "Textures/FinalTiles/Background/BGFront.png");
		
		exceptionManager.load(tileTexture, "Textures/FinalTiles/Foreground/Tileset.png");
	}
	catch (const exception & ex) {
		State::textureError = true;
	}

	background[0].setTexture(backgroundTexture[0]);
	background[1].setTexture(backgroundTexture[1]);
	background[2].setTexture(foregroundTexture[0]);
	background[3].setTexture(foregroundTexture[1]);

	for (int i = 0; i < 4; i++)
	{
		background[i].setScale((float)width / backgroundTexture[0].getSize().x, (float)height / backgroundTexture[0].getSize().y);
	}

	Map::InitTiles(height, groundCoord, path);
}

void Map::InitTiles(unsigned height, unsigned groundCoord, string path)
{
	ifstream openFile;
	FileException<ifstream> fileException;
	sf::Vector2f coords = { 0.0f, (float)groundCoord };
	sf::Vector2i mudTexCoords, grassTexCoords, spikeTexCoords;

	try {
		fileException.load(openFile, path);
	
		while (!openFile.eof())
		{
			bool existsGrass = false;
			bool existsSpike = false;
			bool existsMud = true;
			bool addToVector = true;
			char x;

			openFile >> x;

			if (x == '0')
			{
				mudTexCoords = { 16, 0 };
				grassTexCoords = { 7 * 16, 32 };
				existsGrass = true;
			}
			else if (x == '1')
			{
				mudTexCoords = { 0, 0 };
				grassTexCoords = { 6 * 16, 32 };
				existsGrass = true;
			}
			else if (x == '2')
			{
				mudTexCoords = { 32, 0 };
				grassTexCoords = { 9 * 16, 32 };
				existsGrass = true;
			}
			else if (x == '3')
			{
				mudTexCoords = { 0, 16 };
			}
			else if (x == '4')
			{
				mudTexCoords = { 16, 16 };
			}
			else if (x == '5')
			{
				mudTexCoords = { 32, 16 };
			}
			else if (x == '6')
			{
				mudTexCoords = { 0, 32 };
			}
			else if (x == '7')
			{
				mudTexCoords = { 16, 32 };
			}
			else if (x == '8')
			{
				mudTexCoords = { 32, 32 };
			}
			else if (x == '9')
			{
				spikeTexCoords = { 9 * 16, 4 * 16 };
				existsSpike = true;
				existsMud = false;
			}
			else if (x == '#')
			{
				mudTexCoords = { 16, 0 };
			}
			else if (x == '%')
			{
				mudTexCoords = { 48, 16 };
			}
			else
			{
				addToVector = false;
			}

			if (addToVector && existsMud)
			{
				mudTiles.push_back(Tile(coords, &tileTexture, mudTexCoords));
			}

			if (existsGrass)
			{
				grassTiles.push_back(Tile(coords, &tileTexture, grassTexCoords));
			}

			if (existsSpike)
			{
				spikeTiles.push_back(Tile(coords, &tileTexture, spikeTexCoords));
			}

			coords.x += tileOffset;

			if (openFile.peek() == '\n')
			{
				coords.x = 0;
				coords.y += tileOffset;
			}
		}
	}
	catch (const ifstream::failure & ex) {
		State::textureError = true;
	}
}

void Map::Draw(sf::RenderWindow* window)
{
	for (sf::Sprite x : background)
	{
		window->draw(x);
	}

	for (Tile x : mudTiles)
	{
		x.Draw(window);
	}

	for (Tile x : grassTiles)
	{
		x.Draw(window);
	}

	for (Tile x : spikeTiles)
		x.Draw(window);
}

