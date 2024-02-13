#include "emitter.h"
#include <cmath>
#include <iostream>
#include "game_constants.h"

void Emitter::createParticles()
{
    for (int i = 0; i < n_particles; i++) {
        // create a new particle
        EffectParticle* pParticle = new EffectParticle();
        // Position for the particle
        pParticle->pos = position;

        // Velocity for the particle (random: 0...speed)

        // angle of direction
        double angle = atan2(direction.y, direction.x) * 180.0 / PI;
        //std::cout << angle << std::endl;
        // random angle + angle spread
        angle = angle + (spread_angle * (rand() / (float)RAND_MAX) - spread_angle / 2.0);
        //std::cout << angle << std::endl;

        vector3 dir;
        dir.x = cos(PI*angle / 180.0);
        dir.y = sin(PI*angle / 180.0);

//        pParticle->vel = direction * speed * (rand() / (float)RAND_MAX);
        pParticle->vel = dir * speed;

        // Acceleration for the particle
        pParticle->acc.y = 0;

        // Effect Particle properties
        pParticle->R = startRGB & 255;  // R-bits are on the right
        pParticle->G = (startRGB >> 8) & 255;  // G-bits are 8-bits to the left
        pParticle->B = (startRGB >> 16) & 255; // B-bits are 16-bits to the left

        // Lifetime
        pParticle->lifetime = lifetime;  // in seconds
        pParticle->lifetime_left = lifetime;  // in seconds

        // Start time????
        pParticle->start_time = spread_time * (rand() / (float)RAND_MAX);
        pParticle->age = 0.0;
        pParticle->isAlive = false;

        // Push the particle into the back of the container
        vec_particles.push_back(pParticle);
    }
    this->is_alive = true;
}

void Emitter::update(double deltatime){
    // loop the vector of particles
    this->is_alive = false;
    for (auto it = vec_particles.begin(); it != vec_particles.end(); it++) {
        (*it)->update(deltatime);  // update the particles
        if ((*it)->isAlive) {
            this->is_alive = true;
        }
    }

    // looping? and we are dead?
    if (looping && !is_alive) {
        // delete all particles
        for (auto it = vec_particles.begin(); it != vec_particles.end(); it++) {
            delete* it;
        }
        vec_particles.clear();
        // create particles
        this->createParticles();
    }

}

void Emitter::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::CircleShape shape;
    shape.setRadius(this->size);
    // draw all the particles
    for (auto it = vec_particles.begin(); it != vec_particles.end(); it++) {
        shape.setPosition((*it)->pos.x-size, SCREEN_HEIGHT - (*it)->pos.y - size);
        shape.setFillColor(sf::Color((*it)->R, (*it)->G, (*it)->B, (*it)->A));
        target.draw(shape, states);
    }
}
