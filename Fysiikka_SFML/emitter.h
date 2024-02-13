#pragma once
#include <SFML/Graphics.hpp>
#include "vector3.h"
#include <vector>
#include "effect_particle.h"

class Emitter : public sf::Drawable {
public:
	int n_particles; // number of particles
	int startRGB;
	int endRGB;
	vector3 position; // position of this emitter
	vector3 direction;  // the main direction where the emitter emits particles
	double spread_angle; // the spread of the particles
	double speed;  // the speed of the particles
	double lifetime;  // how many seconds the particles will live
	double spread_time; // how many seconds the particles are spread across
	bool looping;  // will the emitter loop?

	double size = 10.f;  // constant size? maybe start_size & end_size?

	// Container for the particles
	std::vector<EffectParticle*> vec_particles;

	void createParticles();
	void update(double deltatime);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	bool is_alive = false;
	//bool is_paused = false;
};

