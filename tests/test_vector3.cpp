#include "common_utils/vector3.h"
#include <cassert>
#include <cmath>

using common_utils::Vector3;

int main() {
    Vector3 a(1, 2, 3);
    Vector3 b(4, 5, 6);

    Vector3 sum = a + b;
    assert(sum.x == 5 && sum.y == 7 && sum.z == 9);

    Vector3 diff = b - a;
    assert(diff.x == 3 && diff.y == 3 && diff.z == 3);

    Vector3 scaled = a * 2.0;
    assert(scaled.x == 2 && scaled.y == 4 && scaled.z == 6);

    assert(a.dot(b) == 32.0);

    Vector3 cross = a.cross(b);
    assert(cross.x == -3 && cross.y == 6 && cross.z == -3);

    Vector3 unit(3, 0, 0);
    Vector3 norm = unit.normalize();
    assert(norm.x == 1.0 && norm.y == 0.0 && norm.z == 0.0);

    assert(std::abs(a.magnitude() - std::sqrt(14.0)) < 1e-10);

    return 0;
}
