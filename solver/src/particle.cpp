#include "particle.h"
#include <random>
#include <functional>
#include <chrono>
#include <cassert>

size_t Particle::IDCounter = 0;

Particle::Particle()
    : mass(0) {
    id = IDCounter++;
}

Particle::Particle(double mass, const Vector2D &acceleration, const Vector2D &velocity, const Vector2D &position)
        : mass(mass), acceleration(acceleration), velocity(velocity), position(position) {
    assert(mass > 0);
    id = IDCounter++;
}

const Vector2D &Particle::getAcceleration() const {
    return acceleration;
}

void Particle::setAcceleration(const Vector2D &acceleration) {
    Particle::acceleration = acceleration;
}

const Vector2D &Particle::getVelocity() const {
    return velocity;
}

void Particle::setVelocity(const Vector2D &velocity) {
    Particle::velocity = velocity;
}

const Vector2D &Particle::getPosition() const {
    return position;
}

void Particle::setPosition(const Vector2D &position) {
    Particle::position = position;
}

double Particle::getMass() const {
    return mass;
}

bool operator==(const Particle &lhs, const Particle &rhs) {
    return lhs.id == rhs.id;
}

bool operator!=(const Particle &lhs, const Particle &rhs) {
    return !(lhs == rhs);
}