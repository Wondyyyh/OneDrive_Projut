#include "game.h"
#include "game_constants.h"
#include <cstdlib>
#include <iostream>

Game::Game() {

    p.pos.x = 300.0;  // in meters
    p.pos.y = 200.0;
    p.pos.z = 0.0;

    p.vel.x = 10.0;  // meters per second
    p.vel.y = -50.0;
    p.vel.z = 0.0;

    p.acc.x = 0.0;  // in meters per second per second
    //p.acc.y = -9.81; // gravity on earth (approx)
    p.acc.y = 0.0; // gravity to zero to test collisions to upper "wall"
    p.acc.z = 0.0;
    p.setMass(2.0); // set mass to 10kg


    // Create some balls with RADIUS-radius
    for (int i = 0; i < 50; i++)
        gameobjects.push_back(new Ball(vector3(20.0 + (std::rand() / (float)RAND_MAX) * 1100.0, 20.0 + (std::rand() / (float)RAND_MAX) * 800.0, 0.0),
                                 vector3((std::rand() / (float)RAND_MAX) * 400.0, (std::rand() / (float)RAND_MAX) * 400.0, 0.0), 10.0, RADIUS));


    // Create our boxes
    for (int i=0;i<50;i++)
        gameobjects.push_back(new Box(vector3(20.0+(std::rand() / (float)RAND_MAX) * 1100.0, 20.0+ (std::rand() / (float)RAND_MAX) * 800.0, 0.0),
                                vector3((std::rand() / (float) RAND_MAX)*200.0, (std::rand() / (float)RAND_MAX)*200.0, 0.0), 10.0, 25.0, 25.0));

    pbox1 = new Box(vector3(100.0, 100.0, 0.0), vector3(0.0, 0.0, 0.0), 10.0, 20.0, 20.0);
    pbox2 = new Box(vector3(200.0, 200.0, 0.0), vector3(0.0, 0.0, 0.0), 10.0, 20.0, 20.0);
    pbox3 = new Box(vector3(300.0, 300.0, 0.0), vector3(0.0, 0.0, 0.0), 10.0, 20.0, 20.0);

    gameobjects.push_back(pbox1);
    gameobjects.push_back(pbox2);
    gameobjects.push_back(pbox3);

    // Forces
    //gf.setGravity(9.81);

    fr.add(&p, new GravityForce(9.81));   // add the particle and gravity force
    fr.add(&p, new AnchorSpringForce(vector3(ANCHOR_X, ANCHOR_Y, 0.0), .4)); // anchor spring force
}

void Game::update(double deltatime) {
    //
    // UPDATE PHYSICS:
    //

    // Update all forces that are registered
    fr.updateForces(deltatime);

    // Update all game objects (i.e. particles, etc.)
    p.update(deltatime);
  
    for (auto gobj : gameobjects) {
        gobj->update(deltatime);  // update the game object

        // check collisions against walls
        Ball* pball = dynamic_cast<Ball*>(gobj);
        if (pball) {
            checkBallCollisionsToWalls(&(pball->p));
        }
        Box* pbox = dynamic_cast<Box*>(gobj);
        if (pbox) {
            checkBoxCollisionsToWalls(pbox);
        }
    }

    // Check collisions of _gameobjects_ !!!
    for (auto gobj1 : gameobjects) {
        for (auto gobj2 : gameobjects) {
            if (gobj1 != gobj2) {
                // these are actually different game objects!
                Ball* pball1 = dynamic_cast<Ball*>(gobj1);
                Ball* pball2 = dynamic_cast<Ball*>(gobj2);
                if (pball1 && pball2) {
                    // They were ballssssss!!!
                    if (pball1->detectCollision(pball2)) {
                        pball1->resolveCollision(pball2);
                    }
                }
                Ball* Ballo = dynamic_cast<Ball*>(gobj1);
                Box* Boxi = dynamic_cast<Box*>(gobj2);
                if (Ballo && Boxi) {
                    // They were ballssssss!!!
                    if (Ballo->detectCollision(Boxi)) {
                        Ballo->resolveCollision(Boxi);
                    }
                }

                Box* pbox1 = dynamic_cast<Box*>(gobj1);
                Box* pbox2 = dynamic_cast<Box*>(gobj2);
                if (pbox1 && pbox2) {
                    // Boxen
                    if (pbox1->detectCollision(pbox2)) {
                        //std::cout << "collision!!!" << std::endl;
                        pbox1->resolveCollision(pbox2);
                    }
                }


            }
        }
    }



    /*
    // Update balls
    for (auto pball : balls) {
        pball->update(deltatime);
        checkBallCollisions(&(pball->p));
        pball->bColliding = false; // this needs to be cleared for all before collision check
    }

    // Ball collisions
    for (auto pball_this : balls)
        for (auto pball_other : balls)
            if (pball_this != pball_other) {
                if (pball_this->detectCollision(pball_other)) {
                    pball_this->resolveCollision(pball_other);
                    //std::cout << "OH BALLS!!!" << std::endl;
                }
            }


    // Update boxes
    for (auto pbox : boxes) {
        pbox->update(deltatime);
        checkBoxCollisionsToWalls(pbox);
        pbox->bColliding = false; // this needs to be cleared for all before collision check
    }

    // Check box collisions
    for (auto pbox_this : boxes)
        for (auto pbox_other : boxes)
            if (pbox_this != pbox_other) {
                //std::cout << "detect!" << std::endl;
                if (pbox_this->detectCollision(pbox_other)) {
                    //std::cout << "collision!!!" << std::endl;
                }
            }

    */


}

void Game::checkBallCollisionsToWalls(Particle* p) {
    // check y-collisions
    if (p->pos.y - RADIUS <= 0.0) {
        p->pos.y = RADIUS; // remove cross-over
        p->vel.y = -p->vel.y;  // reverse y-velocity
    }
    if (p->pos.y >= SCREEN_HEIGHT - RADIUS) {
        p->pos.y = SCREEN_HEIGHT - RADIUS; // remove cross-over
        p->vel.y = -p->vel.y;  // reverse y-velocity
    }

    // check x-collisions
    if (p->pos.x <= RADIUS) {
        p->pos.x = RADIUS;
        p->vel.x = -p->vel.x;
    }
    if (p->pos.x + RADIUS >= SCREEN_WIDTH) {
        p->pos.x = SCREEN_WIDTH - RADIUS;
        p->vel.x = -p->vel.x;
    }
}


void Game::checkBoxCollisionsToWalls(Box* pbox) {
    // check y-collisions
    if (pbox->p.pos.y - pbox->getHeight()/2.0 <= 0.0) {
        pbox->p.pos.y = pbox->getHeight() / 2.0; // remove cross-over
        pbox->p.vel.y = -pbox->p.vel.y;  // reverse y-velocity
    }
    if (pbox->p.pos.y + (pbox->getHeight() / 2.0) >= SCREEN_HEIGHT ) {
        pbox->p.pos.y = (double)SCREEN_HEIGHT - (pbox->getHeight() / 2.0); // remove cross-over
        pbox->p.vel.y = -pbox->p.vel.y;  // reverse y-velocity
    }

    // check x-collisions
    if (pbox->p.pos.x < pbox->getWidth() / 2.0) {
        pbox->p.pos.x = pbox->getWidth() / 2.0;
        pbox->p.vel.x = -pbox->p.vel.x;
    }
    if (pbox->p.pos.x + pbox->getWidth() / 2.0 > SCREEN_WIDTH) {
        pbox->p.pos.x = (double)SCREEN_WIDTH - pbox->getWidth() / 2.0;
        pbox->p.vel.x = -pbox->p.vel.x;
    }
}
