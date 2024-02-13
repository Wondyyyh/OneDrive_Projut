
#include <SFML/Graphics.hpp>
#include "vector3.h"
#include <iostream>
#include <vector>
#include "game_constants.h"
#include "game.h"
#include "renderer.h"
#include "inputhandler.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML works!");

    // Let's create a game object from the Game-class
    // Beware, this is NOT a singleton-class...
    Game myGame;
    // Also create the renderer and pass the game-object's physical address
    Renderer myRenderer(&myGame);
    // Finally, create the input handler
    InputHandler myInputHandler(&myGame);

    // Limit the frame rate    
    window.setFramerateLimit(60);
    // Delta time
    double dt = 17.0 / 1000.0;

    // ---------------------------------------------------
    // GAME LOOP STARTS HERE:
    //----------------------------------------------------
    while (window.isOpen()){
        //
        // PROCESS INPUTS:
        // 
        myInputHandler.processInputs(&window);
        // 
        // GAME UPDATE:
        //
        myGame.update(dt);
        // -----------------------------------------------
        // RENDERING STARTS HERE:
        // -----------------------------------------------
        myRenderer.render(&window);
    }

	return 0;
}