#include "types.h"

#include <cmath>
#include <types.h>
#include <cassert>
#include <limits>

bool Vector2D::operator==(const Vector2D &rhs) const {
    auto equalZero = std::numeric_limits<double>::min();

    return fabs(x - rhs.x) <= equalZero &&
           fabs(y - rhs.y) <= equalZero;
}

bool Vector2D::operator!=(const Vector2D &rhs) const {
    return !(rhs == *this);
}

double Vector2D::length() const {
    return sqrt(x*x + y*y);
}

Vector2D& Vector2D::operator-=(const Vector2D& rhs) {
    *this = *this - rhs;
    return *this;
}

Vector2D& Vector2D::operator*=(const double& rhs) {
    *this = *this * rhs;
    return *this;
}

Vector2D& Vector2D::operator/=(const double& rhs) {
    *this = *this / rhs;
    return *this;
}

Vector2D &Vector2D::operator+=(const Vector2D &rhs) {
    *this = *this + rhs;
    return *this;
}

Vector2D operator-(const Vector2D &lhs, const Vector2D &rhs) {
    return { lhs.x - rhs.x,
             lhs.y - rhs.y };
}

Vector2D operator+(const Vector2D &lhs, const Vector2D &rhs) {
    return { lhs.x + rhs.x,
             lhs.y + rhs.y };
}

Vector2D operator*(const Vector2D &lhs, const double &rhs) {
    return { lhs.x * rhs,
             lhs.y * rhs };
}

Vector2D operator*(const double &lhs, const Vector2D &rhs) {
    return rhs * lhs;
}

Vector2D operator/(const Vector2D &lhs, const double &rhs) {
    assert(fabs(rhs) > 0);

    return { lhs.x / rhs,
             lhs.y / rhs };
}