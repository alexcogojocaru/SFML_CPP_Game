#include "Game.h"

int main()
{
	Game* game = new Game(1600, 800, "SFML WINDOW");

	game->Run();

	return 0;
}