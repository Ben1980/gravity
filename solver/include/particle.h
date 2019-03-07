#ifndef PARTICLE_H
#define PARTICLE_H

#include "types.h"
#include <cstdlib>

class Particle {
public:
    Particle(double mass = 0, const Vector2D &acceleration = { 0, 0 }, const Vector2D &velocity = { 0, 0 }, const Vector2D &position = { 0, 0 });

    friend bool operator==(const Particle &lhs, const Particle &rhs);

    size_t getID() const {
        return id;
    }

    double getMass() const;

    const Vector2D &getAcceleration() const;

    void setAcceleration(const Vector2D &acceleration);

    const Vector2D &getVelocity() const;

    void setVelocity(const Vector2D &velocity);

    const Vector2D &getPosition() const;

    void setPosition(const Vector2D &position);

private:
    static size_t IDCounter;

    size_t id;
    double mass;
    Vector2D acceleration;
    Vector2D velocity;
    Vector2D position;
};

inline bool operator==(const Particle &lhs, const Particle &rhs) {
    return lhs.getID() == rhs.getID();
}

inline bool operator!=(const Particle &lhs, const Particle &rhs) {
    return !(lhs == rhs);
}


#endif
