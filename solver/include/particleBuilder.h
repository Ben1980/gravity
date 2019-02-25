#ifndef PARTICLEBUILDER_H
#define PARTICLEBUILDER_H

class Particle;

class ParticleBuilder {
public:
    ParticleBuilder * position();
    ParticleBuilder * velocity();
    ParticleBuilder * acceleration();
    ParticleBuilder * mass();
    Particle build();
};

#endif
