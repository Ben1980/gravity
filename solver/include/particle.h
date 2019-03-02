#ifndef PARTICLE_H
#define PARTICLE_H

#include "types.h"

struct Particle {
    double mass;
    Vector2D acceleration;
    Vector2D velocity;
    Vector2D position;

    Particle() : mass(0) {}
    Particle(double mass, const Vector2D &acceleration, const Vector2D &velocity, const Vector2D &position)
        : mass(mass), acceleration(acceleration), velocity(velocity), position(position) {}

    bool operator==(const Particle &rhs) const {
        return mass == rhs.mass &&
               acceleration == rhs.acceleration &&
               velocity == rhs.velocity &&
               position == rhs.position;
    }

    bool operator!=(const Particle &rhs) const {
        return !(rhs == *this);
    }
};

#endif
