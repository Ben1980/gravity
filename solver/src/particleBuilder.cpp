#include "particleBuilder.h"
#include "particle.h"
#include <random>
#include <functional>

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

std::vector<Particle> ParticleBuilder::build(size_t numberOfParticles)
{
    std::vector<Particle> particle(numberOfParticles);

    std::mt19937 mt(std::random_device{}());
    std::uniform_real_distribution real_dist(1.0, static_cast<double>(numberOfParticles));
    auto gen = std::bind(std::ref(real_dist), std::ref(mt));

    for(Particle &p : particle) {
        p = mass(gen())
                .acceleration({ gen(), gen() })
                .velocity({ gen(), gen() })
                .position({ gen(), gen() })
                .build();
    }

    return particle;
}
