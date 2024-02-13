#include "inputhandler.h"

void InputHandler::processInputs(sf::RenderWindow* prw)
{
    // 
    // GET INPUTS FROM USER:
    //
    while (prw->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            prw->close();

        // If it was a key pressed-event
        if (event.type == sf::Event::KeyPressed) {

            if (event.key.code == sf::Keyboard::W) {
                // Particle velocity upwards?!??!
                //pGame->p.vel.y += 20.0;
                pGame->pbox1->p.pos.y += 5.0;
            }
            if (event.key.code == sf::Keyboard::A) {
                // Particle velocity left?!??!
                //pGame->p.vel.x -= 20.0;
                pGame->pbox1->p.pos.x -= 5.0;
            }
            if (event.key.code == sf::Keyboard::S) {
                // Particle velocity down?!??!
                //pGame->p.vel.y -= 20.0;
                pGame->pbox1->p.pos.y -= 5.0;
            }
            if (event.key.code == sf::Keyboard::D) {
                // Particle velocity right?!??!
                //pGame->p.vel.x += 20.0;
                pGame->pbox1->p.pos.x += 5.0;
            }

            if (event.key.code == sf::Keyboard::Escape) {
                prw->close();
            }

        }
    }
}
