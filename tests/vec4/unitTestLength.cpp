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
        && approx_equal(a.y, a.y, eps)
        && approx_equal(a.z, b.z, eps)
        && approx_equal(a.w, a.w, eps);
}

int main() {
    //          ----length----

    // length squared       {3,4,5} == 50.0
    {
        gmath::vec4 a{3, 4, 5, 6};
        assert(approx_equal(a.length_squared(), 86.0f));
    }

    // length       exp: a{0, 3, 4} === 5.0
    {
        gmath::vec4 a{3,4,0,0};
        gmath::vec4 b{0,3,4,0};
        gmath::vec4 c{0,0,3,4};
        assert(approx_equal(a.length(), 5.0f));
        assert(approx_equal(b.length(), 5.0f));
        assert(approx_equal(c.length(), 5.0f));
    }
    // normalized       exp: a{0,3,4} == {0.0, 0.3, 0.8}
    {
        gmath::vec4 a{3,4,0,0};
        gmath::vec4 b{0,3,4,0};
        gmath::vec4 c{0,0,3,4};
        assert(approx_equal(a.normalized(), gmath::vec4(0.6f, 0.8f, 0.0f, 0.0f)));
        assert(approx_equal(b.normalized(), gmath::vec4(0.0f, 0.6f, 0.8f, 0.0f)));
        assert(approx_equal(c.normalized(), gmath::vec4(0.0f, 0.0f, 0.6f, 0.8f)));
        assert(approx_equal(c.normalized(), gmath::vec4(0.0f, 0.0f, 0.6f, 0.8f)));
    }
    // normalized division by zero       exp: a{0,0,0} == 
    {
        gmath::vec4 a{0,0,0,0};
        assert(approx_equal(a.normalized(), gmath::vec4(0.0f, 0.0f, 0.0f, 0.0f)));
    }

    std::cout << "all tests passed\n";
    return 0;
}