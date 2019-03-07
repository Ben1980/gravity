#ifndef TYPES_H
#define TYPES_H

#include <cassert>
#include <limits>
#include <cmath>

enum class Coordinate {
    X,
    Y
};

class Vector2D {
public:
    Vector2D(double x = 0.0, double y = 0.0) : mData{x, y} {}

    double length() const {
        const double &x = mData[(std::size_t)Coordinate::X];
        const double &y = mData[(std::size_t)Coordinate::Y];

        return sqrt(x*x + y*y);
    }

    double& operator[](Coordinate c) {
        return mData[(std::size_t)c];
    }

    const double& operator[](Coordinate c) const {
        return mData[(std::size_t)c];
    }

    Vector2D& operator-=(const Vector2D& rhs) {
        mData[(std::size_t)Coordinate::X] -= rhs[Coordinate::X];
        mData[(std::size_t)Coordinate::Y] -= rhs[Coordinate::Y];

        return *this;
    }

    Vector2D& operator+=(const Vector2D& rhs) {
        mData[(std::size_t)Coordinate::X] += rhs[Coordinate::X];
        mData[(std::size_t)Coordinate::Y] += rhs[Coordinate::Y];

        return *this;
    }

    Vector2D& operator*=(double rhs) {
        mData[(std::size_t)Coordinate::X] *= rhs;
        mData[(std::size_t)Coordinate::Y] *= rhs;

        return *this;
    }

    Vector2D& operator/=(double rhs) {
        assert(fabs(rhs) > 0);

        mData[(std::size_t)Coordinate::X] /= rhs;
        mData[(std::size_t)Coordinate::Y] /= rhs;

        return *this;
    }

private:
    double mData[2];
};

inline bool operator==(const Vector2D &lhs, const Vector2D &rhs) {
    auto equalZero = std::numeric_limits<double>::min();

    return fabs(lhs[Coordinate::X] - rhs[Coordinate::X]) <= equalZero &&
           fabs(lhs[Coordinate::Y] - rhs[Coordinate::Y]) <= equalZero;
}

inline bool operator!=(const Vector2D &lhs, const Vector2D &rhs) {
    return !(lhs == rhs);
}

inline Vector2D operator-(Vector2D lhs, const Vector2D &rhs) {
    return lhs -= rhs;
}

inline Vector2D operator+(Vector2D lhs, const Vector2D &rhs) {
    return lhs += rhs;
}

inline Vector2D operator*(Vector2D lhs, double rhs) {
    return lhs *= rhs;
}

inline Vector2D operator*(double lhs, const Vector2D &rhs) {
    return rhs * lhs;
}

inline Vector2D operator/(Vector2D lhs, double rhs) {
    return lhs /= rhs;
}

#endif