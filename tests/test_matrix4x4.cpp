#include "common_utils/matrix4x4.h"
#include <cassert>
#include <cmath>

using common_utils::Matrix4x4;
using common_utils::Vector3;

static bool approxEq(double a, double b, double eps = 1e-9) {
    return std::abs(a - b) < eps;
}

int main() {
    // Identity * Identity = Identity
    auto I = Matrix4x4::identity();
    auto II = I * I;
    assert(II == I);

    // Translation moves a point
    auto T = Matrix4x4::translation(1, 2, 3);
    Vector3 p(0, 0, 0);
    Vector3 tp = T.transformPoint(p);
    assert(approxEq(tp.x, 1) && approxEq(tp.y, 2) && approxEq(tp.z, 3));

    // Translation does NOT move a vector (direction)
    Vector3 v(1, 0, 0);
    Vector3 tv = T.transformVector(v);
    assert(approxEq(tv.x, 1) && approxEq(tv.y, 0) && approxEq(tv.z, 0));

    // Inverse of identity is identity
    auto Iinv = I.inverse();
    assert(Iinv == I);

    // M * M^-1 ≈ Identity
    auto T_inv = T.inverse();
    auto prod = T * T_inv;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            assert(approxEq(prod.m[i][j], (i == j) ? 1.0 : 0.0));

    // Rotation by 90 degrees around Z
    auto Rz = Matrix4x4::rotationZ(M_PI / 2.0);
    Vector3 xAxis(1, 0, 0);
    Vector3 rotated = Rz.transformVector(xAxis);
    assert(approxEq(rotated.x, 0.0, 1e-9));
    assert(approxEq(rotated.y, 1.0, 1e-9));
    assert(approxEq(rotated.z, 0.0, 1e-9));

    return 0;
}
