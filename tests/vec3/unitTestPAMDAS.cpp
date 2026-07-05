#include <cassert>
#include <cmath>
#include <iostream>
#include "gmath/vec3.hpp"

// Float comparison helper — the one non-obvious piece.
// Never use == on floats: 0.1f + 0.2f != 0.3f due to rounding.
bool approx_equal(float a, float b, float eps = 1e-6f) {
    return std::fabs(a - b) < eps;
}

bool approx_equal(const gmath::vec3& a, const gmath::vec3& b, float eps = 1e-6f) {
    return approx_equal(a.x, b.x, eps)
        && approx_equal(a.y, b.y, eps)
        && approx_equal(a.z, b.z, eps);
}

int main() {
    // --- constructors ---
    {
        gmath::vec3 v;
        assert(approx_equal(v, gmath::vec3(0.0f, 0.0f, 0.0f)));
    }
    {
        gmath::vec3 v{1.0f, 2.0f, 3.0f};
        assert(v.x == 1.0f && v.y == 2.0f && v.z == 3.0f);  // exact literals, == is OK here
    }
    {
        gmath::vec3 v{std::array<float, 3>{1.0f, 2.0f, 3.0f}};
        assert(v.z == 3.0f);   // <-- this one would have caught tonight's bug
    }

    // --- addition ---
    {
        gmath::vec3 a{1.0f, 2.0f, 3.0f};
        gmath::vec3 b{4.0f, 5.0f, 6.0f};
        assert(approx_equal(a + b, gmath::vec3(5.0f, 7.0f, 9.0f)));
    }

    // --- your turn: same pattern, one block each ---
    // subtraction:      a - b == (-3, -3, -3)
    {
        gmath::vec3 a{1.0f, 2.0f, 3.0f};
        gmath::vec3 b{4.0f, 5.0f, 6.0f};
        assert(approx_equal(a - b, gmath::vec3(-3.0f, -3.0f, -3.0)));
    }
    // scalar multiply:  a * 2.0f == (2, 4, 6)
    {
        gmath::vec3 a{1.0f, 2.0f, 3.0f};
        assert(approx_equal(a * 2.0f, gmath::vec3(2, 4, 6)));
    }
    // scalar divide:    a / 2.0f == (0.5, 1, 1.5)
    {
        gmath::vec3 a{1.0f, 2.0f, 3.0f};
        assert(approx_equal(a / 2.0f, gmath::vec3(0.5f, 1.0f, 1.5f)));
    }
    // chaining:         (a + b) - b == a          <-- algebraic identity, the best kind of test
    {
        gmath::vec3 a{1.0f, 2.0f, 3.0f};
        gmath::vec3 b{4.0f, 5.0f, 6.0f};
        assert(approx_equal((a + b) - b, a));
    }
    // negating:        -(a) == (-a)
    {
        gmath::vec3 a{1.0f, 2.0f, 3.0f};
        assert(approx_equal(-a, gmath::vec3(-1.0f, -2.0f, -3.0f)));
    }

    std::cout << "all tests passed\n";
    return 0;
}