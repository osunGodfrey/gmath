#include <cassert>
#include <cmath>
#include <iostream>
#include "gmath/vec4.hpp"

// Float comparison helper — the one non-obvious piece.
// Never use == on floats: 0.1f + 0.2f != 0.3f due to rounding.
bool approx_equal(float a, float b, float eps = 1e-6f) {
    return std::fabs(a - b) < eps;
}

bool approx_equal(const gmath::vec4& a, const gmath::vec4& b, float eps = 1e-6f) {
    return approx_equal(a.x, b.x, eps)
        && approx_equal(a.y, b.y, eps)
        && approx_equal(a.z, b.z, eps)
        && approx_equal(a.w, b.w, eps);
}

int main() {
    // --- constructors ---
    {
        gmath::vec4 v;
        assert(approx_equal(v, gmath::vec4(0.0f, 0.0f, 0.0f, 0.0f)));
    }
    {
        gmath::vec4 v{1.0f, 2.0f, 3.0f, 4.0f};
        assert(v.x == 1.0f && v.y == 2.0f && v.z == 3.0f && v.w == 4.0f);
    }

    // --- addition ---
    // addition:        a + b = (6.0f, 8.0f, 10.0f, 12.0f)
    {
        gmath::vec4 a{1.0f, 2.0f, 3.0f, 4.0f};
        gmath::vec4 b{5.0f, 6.0f, 7.0f, 8.0f};
        assert(approx_equal(a + b, gmath::vec4(6.0f, 8.0f, 10.0f, 12.0f)));
    }

    // --- your turn: same pattern, one block each ---
    // subtraction:      a - b == (-4, -4, -4, -4)
    {
        gmath::vec4 a{1.0f, 2.0f, 3.0f, 4.0f};
        gmath::vec4 b{5.0f, 6.0f, 7.0f, 8.0f};
        assert(approx_equal(a - b, gmath::vec4(-4.0f, -4.0f, -4.0f, -4.0f)));
    }
    // scalar multiply:  a * 2.0f == (2, 4, 6, 8)
    {
        gmath::vec4 a{1.0f, 2.0f, 3.0f, 4.0f};
        assert(approx_equal(a * 2.0f, gmath::vec4(2.0f, 4.0f, 6.0f, 8.0f)));
    }
    // scalar divide:    a / 2.0f == (0.5, 1, 1.5, 2.0)
    {
        gmath::vec4 a{1.0f, 2.0f, 3.0f, 4.0f};
        assert(approx_equal( a / 2.0f, gmath::vec4(0.5f, 1.0f, 1.5f, 2.0f)));
    }
    // chaining:         (a + b) - b == a          <-- algebraic identity, the best kind of test
    {
        gmath::vec4 a{1.0f, 2.0f, 3.0f, 4.0f};
        gmath::vec4 b{5.0f, 6.0f, 7.0f, 8.0f};
        assert(approx_equal((a + b) - b, a));
    }
    // negating:        -(a) == (-a)
    {
        gmath::vec4 a{1.0f, 2.0f, 3.0f, 4.0f};
        assert(approx_equal(-a, gmath::vec4(-1.0f, -2.0f, -3.0f, -4.0f)));
    }

    std::cout << "all tests passed\n";
    return 0;
}