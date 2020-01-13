#pragma once

#include <fstream>
#include <string>
#include <exception>
#include <SFML/Graphics.hpp>

using namespace std;

class ExceptionManager 
{
public:
	void load(sf::Texture& texture, string path);
};