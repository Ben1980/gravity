#include "particleBuilder.h"
#include "particle.h"

ParticleBuilder & ParticleBuilder::position(const Vector2D &position)
{
    mPosition = position;
    return *this;
}

ParticleBuilder & ParticleBuilder::velocity(const Vector2D &velocity)
{
    mVelocity = velocity;
    return *this;
}

ParticleBuilder & ParticleBuilder::acceleration(const Vector2D &acceleration)
{
    mAcceleration = acceleration;
    return *this;
}

ParticleBuilder & ParticleBuilder::mass(double mass)
{
    mMass = mass;
    return *this;
}

Particle ParticleBuilder::build() const
{
    return {mMass, mAcceleration, mVelocity, mPosition};
}
