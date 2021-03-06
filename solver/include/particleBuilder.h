#ifndef PARTICLEBUILDER_H
#define PARTICLEBUILDER_H

#include "types.h"
#include <vector>

class Particle;

class ParticleBuilder {
public:
    ParticleBuilder() : mMass(0) {}

    ParticleBuilder & position(const Vector2D &position);
    ParticleBuilder & velocity(const Vector2D &velocity);
    ParticleBuilder & acceleration(const Vector2D &acceleration);
    ParticleBuilder & mass(double mass);
    Particle build() const;
    std::vector<Particle> build(size_t numberOfParticles);

private:
    double mMass;
    Vector2D mAcceleration;
    Vector2D mVelocity;
    Vector2D mPosition;
};

#endif
