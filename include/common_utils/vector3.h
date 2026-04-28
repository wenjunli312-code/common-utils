#pragma once

#include <cmath>
#include <stdexcept>

namespace common_utils {

struct Vector3 {
    double x, y, z;

    Vector3() : x(0), y(0), z(0) {}
    Vector3(double x, double y, double z) : x(x), y(y), z(z) {}

    Vector3 operator+(const Vector3& rhs) const { return {x + rhs.x, y + rhs.y, z + rhs.z}; }
    Vector3 operator-(const Vector3& rhs) const { return {x - rhs.x, y - rhs.y, z - rhs.z}; }
    Vector3 operator*(double s) const { return {x * s, y * s, z * s}; }
    Vector3 operator/(double s) const { return {x / s, y / s, z / s}; }

    Vector3& operator+=(const Vector3& rhs) { x += rhs.x; y += rhs.y; z += rhs.z; return *this; }
    Vector3& operator-=(const Vector3& rhs) { x -= rhs.x; y -= rhs.y; z -= rhs.z; return *this; }
    Vector3& operator*=(double s) { x *= s; y *= s; z *= s; return *this; }
    Vector3& operator/=(double s) { x /= s; y /= s; z /= s; return *this; }

    bool operator==(const Vector3& rhs) const { return x == rhs.x && y == rhs.y && z == rhs.z; }
    bool operator!=(const Vector3& rhs) const { return !(*this == rhs); }

    double dot(const Vector3& rhs) const { return x * rhs.x + y * rhs.y + z * rhs.z; }

    Vector3 cross(const Vector3& rhs) const {
        return {
            y * rhs.z - z * rhs.y,
            z * rhs.x - x * rhs.z,
            x * rhs.y - y * rhs.x
        };
    }

    double magnitude() const { return std::sqrt(x * x + y * y + z * z); }

    Vector3 normalize() const {
        double mag = magnitude();
        if (mag == 0.0) throw std::runtime_error("Cannot normalize zero vector");
        return *this / mag;
    }
};

inline Vector3 operator*(double s, const Vector3& v) { return v * s; }

} // namespace common_utils
