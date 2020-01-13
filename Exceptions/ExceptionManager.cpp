#include "ExceptionManager.h"

void ExceptionManager::load(sf::Texture& texture, string path)
{
	if (!texture.loadFromFile(path))
		throw exception{};
}
