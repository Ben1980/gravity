#include "types.h"

#include <cmath>
#include <types.h>
#include <cassert>
#include <limits>

double Vector2D::length() const {
    return sqrt(x*x + y*y);
}

Vector2D& Vector2D::operator-=(const Vector2D& rhs) {
    *this = *this - rhs;
    return *this;
}

Vector2D& Vector2D::operator*=(double rhs) {
    *this = *this * rhs;
    return *this;
}

Vector2D& Vector2D::operator/=(double rhs) {
    *this = *this / rhs;
    return *this;
}

Vector2D &Vector2D::operator+=(const Vector2D &rhs) {
    *this = *this + rhs;
    return *this;
}


bool operator==(const Vector2D &lhs, const Vector2D &rhs) {
    auto equalZero = std::numeric_limits<double>::min();

    return fabs(lhs.x - rhs.x) <= equalZero &&
           fabs(lhs.y - rhs.y) <= equalZero;
}

bool operator!=(const Vector2D &lhs, const Vector2D &rhs) {
    return !(lhs == rhs);
}

Vector2D operator-(const Vector2D &lhs, const Vector2D &rhs) {
    return { lhs.x - rhs.x,
             lhs.y - rhs.y };
}

Vector2D operator+(const Vector2D &lhs, const Vector2D &rhs) {
    return { lhs.x + rhs.x,
             lhs.y + rhs.y };
}

Vector2D operator*(const Vector2D &lhs, double rhs) {
    return { lhs.x * rhs,
             lhs.y * rhs };
}

Vector2D operator*(double lhs, const Vector2D &rhs) {
    return rhs * lhs;
}

Vector2D operator/(const Vector2D &lhs, double rhs) {
    assert(fabs(rhs) > 0);

    return { lhs.x / rhs,
             lhs.y / rhs };
}