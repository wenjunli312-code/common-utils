#pragma once

#include "vector3.h"
#include <array>
#include <cmath>
#include <stdexcept>

namespace common_utils {

// Row-major 4x4 matrix. m[row][col].
struct Matrix4x4 {
    std::array<std::array<double, 4>, 4> m;

    Matrix4x4() { for (auto& row : m) row.fill(0.0); }

    static Matrix4x4 identity();
    static Matrix4x4 translation(double tx, double ty, double tz);
    static Matrix4x4 rotationX(double radians);
    static Matrix4x4 rotationY(double radians);
    static Matrix4x4 rotationZ(double radians);
    static Matrix4x4 scale(double sx, double sy, double sz);

    Matrix4x4 operator*(const Matrix4x4& rhs) const;
    Vector3 transformPoint(const Vector3& v) const;
    Vector3 transformVector(const Vector3& v) const;

    Matrix4x4 inverse() const;
    Matrix4x4 transpose() const;

    bool operator==(const Matrix4x4& rhs) const { return m == rhs.m; }
    bool operator!=(const Matrix4x4& rhs) const { return !(*this == rhs); }
};

} // namespace common_utils
