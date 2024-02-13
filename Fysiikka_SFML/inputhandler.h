#pragma once
#include "game.h"
#include <SFML/Graphics.hpp>

class InputHandler
{
public:

	InputHandler(Game* pg) {
		pGame = pg;
		event.type = sf::Event::Closed; // Not needed
	}

	void processInputs(sf::RenderWindow* prw);

private:

	Game* pGame;

	sf::Event event;

};

