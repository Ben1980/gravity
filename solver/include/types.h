#ifndef TYPES_H
#define TYPES_H

#include <cmath>

struct Vector2D {
    double x;
    double y;

    Vector2D() : x(0), y(0) {}
    Vector2D(double x, double y) : x(x), y(y) {}

    bool operator==(const Vector2D &rhs) const;

    bool operator!=(const Vector2D &rhs) const;

    double length() const;

    Vector2D& operator-=(const Vector2D& rhs);

    Vector2D& operator+=(const Vector2D& rhs);

    Vector2D& operator*=(const double& rhs);

    Vector2D& operator/=(const double& rhs);
};

Vector2D operator-(const Vector2D &lhs, const Vector2D &rhs);

Vector2D operator+(const Vector2D &lhs, const Vector2D &rhs);

Vector2D operator*(const Vector2D &lhs, const double &rhs);

Vector2D operator*(const double &lhs, const Vector2D &rhs);

Vector2D operator/(const Vector2D &lhs, const double &rhs);

#endif
