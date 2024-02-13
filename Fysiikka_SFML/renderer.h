#pragma once
#include "game_constants.h"
#include "game.h"
#include <SFML/Graphics.hpp>

class Renderer
{
public:
	// Constructor
	Renderer(Game* pg) {
		pGame = pg;
		shape.setFillColor(sf::Color::Red);
		shape.setRadius(RADIUS);
		line[0] = sf::Vector2f(ANCHOR_X, ANCHOR_Y);
	}

	// Render-function, draws into the given render window
	void render(sf::RenderWindow* prw);

private:
	// Pointer to the game-class object
	Game* pGame;

	// --------------------------------------------------
	// SHAPES FOR RENDERING:
	// --------------------------------------------------

	// For our particle (and planet)
	sf::CircleShape shape;

	// For our box
	sf::RectangleShape rect;

	// Two vertices to draw a line
	sf::Vertex line[2];

};

