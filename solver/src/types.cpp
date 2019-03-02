#include "types.h"

#include <cmath>
#include <types.h>
#include <assert.h>

bool Vector2D::operator==(const Vector2D &rhs) const {
    if(fabs(x) > 0 && fabs(rhs.x) <= std::numeric_limits<double>::min()) return false;
    if(fabs(y) > 0 && fabs(rhs.y) <= std::numeric_limits<double>::min()) return false;

    return fabs((x / rhs.x) - 1) <= std::numeric_limits<double>::min() &&
           fabs((y / rhs.y) - 1) <= std::numeric_limits<double>::min();
}

bool Vector2D::operator!=(const Vector2D &rhs) const {
    return !(rhs == *this);
}

double Vector2D::length() const {
    const double sumOfSquares = x*x +y*y;

    assert(sumOfSquares >= 0);

    return sqrt(sumOfSquares);
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