#pragma once
#include "particle.h"
#include "force.h"
#include "box.h"
#include "ball.h"
#include "gameobject.h"

class Game
{

public:

    // Constructs our game
    Game();

	void update(double deltatime);

    // -------------------------------------------------
    // PARTICLE(S):
    // -------------------------------------------------
    // Create a particle
    // TODO: Move this to private-section!!!
    Particle p;

    std::vector<GameObject*> gameobjects;

    /*
    std::vector<Ball*> balls;
    std::vector<Box*> boxes;
    */

    Box* pbox1;
    Box* pbox2;
    Box* pbox3;

private:

    // Checks ball collisions against walls
    void checkBallCollisionsToWalls(Particle* p);

    void checkBoxCollisionsToWalls(Box* pbox);
 
    // -------------------------------------------------
    // FORCES:
    // -------------------------------------------------
    // gravity force of 255.0 m/s^2
    //GravityForce gf;
    // planetary force at 500.0, 500.0
    double planet_x = 600.0;
    double planet_y = 400.0;
    //PlanetaryForce pf(vector3(planet_x, planet_y, 0.0), 3000000000000000000.0);
    //AirblowerForce abf(vector3(100.0, 100.0, 0.0), 200.0, 600.0, 40.0);
    //AirblowerForce abf2(vector3(500.0, 100.0, 0.0), 200.0, 800.0, 80.0);
    //AnchorSpringForce asf(vector3(500.0, 400.0, 0.0), .4);

    // -------------------------------------------------
    // FORCE REGISTTRY STUFF:
    // -------------------------------------------------
    ForceRegistry fr;  // make a registry of forces
 
};

