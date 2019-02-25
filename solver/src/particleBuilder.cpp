#include "particleBuilder.h"
#include "particle.h"

ParticleBuilder * ParticleBuilder::position()
{
    return this;
}

ParticleBuilder * ParticleBuilder::velocity()
{
    return this;
}

ParticleBuilder * ParticleBuilder::acceleration()
{
    return this;
}

ParticleBuilder * ParticleBuilder::mass()
{
    return this;
}

Particle ParticleBuilder::build()
{
    return {};
}

