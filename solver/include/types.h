#ifndef TYPES_H
#define TYPES_H

struct Vector2D {
    double x;
    double y;

    Vector2D() : x(0), y(0) {}
    Vector2D(double x, double y) : x(x), y(y) {}
};

#endif
