#include <SFML/Graphics.hpp>
#include "Game.h"
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	sf::RenderWindow window(sf::VideoMode(900, 600), "Super Mario 2.0");
	Game game(&window);
	game.runGame();
	return 0;
}