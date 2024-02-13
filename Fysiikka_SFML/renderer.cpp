#include "renderer.h"

void Renderer::render(sf::RenderWindow* prw)
{
    prw->clear();

    // update shape object according to physics, flip y-coord
    shape.setPosition(pGame->p.pos.x - RADIUS, SCREEN_HEIGHT - pGame->p.pos.y - RADIUS);
    // render the particle
    prw->draw(shape);
    // update the particle end of the line
    line[1] = sf::Vector2f(pGame->p.pos.x, SCREEN_HEIGHT - pGame->p.pos.y);

    // draw the line
    prw->draw(line, 2, sf::Lines);

    // draw the gameobjects
    for (auto gobj : pGame->gameobjects) {
        
        // try to cast the game object into a ball
        Ball* pball = dynamic_cast<Ball*>(gobj);
        if (pball) {
            // this actually was a ball
            if (pball->bColliding)
                shape.setFillColor(sf::Color::White);
            else
                shape.setFillColor(sf::Color::Magenta);
            shape.setPosition(pball->p.pos.x - pball->getRadius(),
                SCREEN_HEIGHT - (pball->p.pos.y + pball->getRadius()));
            shape.setRadius(pball->getRadius());
            prw->draw(shape);
            continue;  // continue the loop, since this one was a ball
        }
        // try to cast the game object into a box
        Box* pbox = dynamic_cast<Box*>(gobj);
        if (pbox) {
            // this actually was a box
            if (pbox->bColliding)
                rect.setFillColor(sf::Color::Cyan);
            else
                rect.setFillColor(sf::Color::Blue);
            rect.setPosition(pbox->p.pos.x - pbox->getWidth() / 2.0,
                SCREEN_HEIGHT - (pbox->p.pos.y + pbox->getHeight() / 2.0));
            rect.setSize(sf::Vector2f(pbox->getWidth(), pbox->getHeight()));
            prw->draw(rect);
        }

    }

    // draw the box
    // get the position of the box, use width/2 and height/2...
    /*
    for (auto pbox : pGame->boxes) {

        if (pbox->isColliding())
            rect.setFillColor(sf::Color::Red);
        else
            rect.setFillColor(sf::Color::Green);

        rect.setPosition(pbox->p.pos.x - pbox->getWidth() / 2.0,
            SCREEN_HEIGHT - (pbox->p.pos.y + pbox->getHeight() / 2.0));
        rect.setSize(sf::Vector2f(pbox->getWidth(), pbox->getHeight()));
        prw->draw(rect);
    }
    // Draw the balls
    for (auto pball : pGame->balls) {

        if (pball->bColliding)
            shape.setFillColor(sf::Color::Red);
        else
            shape.setFillColor(sf::Color::Yellow);

        shape.setPosition(pball->p.pos.x - pball->getRadius(),
            SCREEN_HEIGHT - (pball->p.pos.y + pball->getRadius()));
        shape.setRadius(pball->getRadius());
        prw->draw(shape);
    }
    */

    prw->display();
}
