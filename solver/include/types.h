#ifndef TYPES_H
#define TYPES_H

struct Vector2D {
    double x;
    double y;

    Vector2D() : x(0), y(0) {}
    Vector2D(double x, double y) : x(x), y(y) {}

    friend bool operator==(const Vector2D &lhs, const Vector2D &rhs);

    double length() const;

    Vector2D& operator-=(const Vector2D& rhs);

    Vector2D& operator+=(const Vector2D& rhs);

    Vector2D& operator*=(double rhs);

    Vector2D& operator/=(double rhs);
};

bool operator==(const Vector2D &lhs, const Vector2D &rhs);

bool operator!=(const Vector2D &lhs, const Vector2D &rhs);

Vector2D operator-(const Vector2D &lhs, const Vector2D &rhs);

Vector2D operator+(const Vector2D &lhs, const Vector2D &rhs);

Vector2D operator*(const Vector2D &lhs, double rhs);

Vector2D operator*(double lhs, const Vector2D &rhs);

Vector2D operator/(const Vector2D &lhs, double rhs);

#endif
