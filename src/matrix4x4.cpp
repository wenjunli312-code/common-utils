#include "common_utils/matrix4x4.h"

#include <cmath>
#include <stdexcept>

namespace common_utils {

Matrix4x4 Matrix4x4::identity() {
    Matrix4x4 mat;
    mat.m[0][0] = mat.m[1][1] = mat.m[2][2] = mat.m[3][3] = 1.0;
    return mat;
}

Matrix4x4 Matrix4x4::translation(double tx, double ty, double tz) {
    Matrix4x4 mat = identity();
    mat.m[0][3] = tx;
    mat.m[1][3] = ty;
    mat.m[2][3] = tz;
    return mat;
}

Matrix4x4 Matrix4x4::rotationX(double radians) {
    Matrix4x4 mat = identity();
    double c = std::cos(radians);
    double s = std::sin(radians);
    mat.m[1][1] =  c;  mat.m[1][2] = -s;
    mat.m[2][1] =  s;  mat.m[2][2] =  c;
    return mat;
}

Matrix4x4 Matrix4x4::rotationY(double radians) {
    Matrix4x4 mat = identity();
    double c = std::cos(radians);
    double s = std::sin(radians);
    mat.m[0][0] =  c;  mat.m[0][2] =  s;
    mat.m[2][0] = -s;  mat.m[2][2] =  c;
    return mat;
}

Matrix4x4 Matrix4x4::rotationZ(double radians) {
    Matrix4x4 mat = identity();
    double c = std::cos(radians);
    double s = std::sin(radians);
    mat.m[0][0] =  c;  mat.m[0][1] = -s;
    mat.m[1][0] =  s;  mat.m[1][1] =  c;
    return mat;
}

Matrix4x4 Matrix4x4::scale(double sx, double sy, double sz) {
    Matrix4x4 mat = identity();
    mat.m[0][0] = sx;
    mat.m[1][1] = sy;
    mat.m[2][2] = sz;
    return mat;
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& rhs) const {
    Matrix4x4 result;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 4; ++k)
                result.m[i][j] += m[i][k] * rhs.m[k][j];
    return result;
}

Vector3 Matrix4x4::transformPoint(const Vector3& v) const {
    double x = m[0][0]*v.x + m[0][1]*v.y + m[0][2]*v.z + m[0][3];
    double y = m[1][0]*v.x + m[1][1]*v.y + m[1][2]*v.z + m[1][3];
    double z = m[2][0]*v.x + m[2][1]*v.y + m[2][2]*v.z + m[2][3];
    double w = m[3][0]*v.x + m[3][1]*v.y + m[3][2]*v.z + m[3][3];
    if (w != 1.0 && w != 0.0) return {x/w, y/w, z/w};
    return {x, y, z};
}

Vector3 Matrix4x4::transformVector(const Vector3& v) const {
    return {
        m[0][0]*v.x + m[0][1]*v.y + m[0][2]*v.z,
        m[1][0]*v.x + m[1][1]*v.y + m[1][2]*v.z,
        m[2][0]*v.x + m[2][1]*v.y + m[2][2]*v.z
    };
}

Matrix4x4 Matrix4x4::transpose() const {
    Matrix4x4 result;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            result.m[i][j] = m[j][i];
    return result;
}

// Gauss-Jordan elimination for 4x4 inverse.
Matrix4x4 Matrix4x4::inverse() const {
    double a[4][8];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) a[i][j] = m[i][j];
        for (int j = 0; j < 4; ++j) a[i][4+j] = (i == j) ? 1.0 : 0.0;
    }
    for (int col = 0; col < 4; ++col) {
        int pivot = -1;
        double maxVal = 0.0;
        for (int row = col; row < 4; ++row) {
            if (std::abs(a[row][col]) > maxVal) {
                maxVal = std::abs(a[row][col]);
                pivot = row;
            }
        }
        if (pivot == -1 || maxVal < 1e-12)
            throw std::runtime_error("Matrix is singular and cannot be inverted");
        std::swap(a[col], a[pivot]);
        double div = a[col][col];
        for (int j = 0; j < 8; ++j) a[col][j] /= div;
        for (int row = 0; row < 4; ++row) {
            if (row == col) continue;
            double factor = a[row][col];
            for (int j = 0; j < 8; ++j)
                a[row][j] -= factor * a[col][j];
        }
    }
    Matrix4x4 result;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            result.m[i][j] = a[i][4+j];
    return result;
}

} // namespace common_utils
