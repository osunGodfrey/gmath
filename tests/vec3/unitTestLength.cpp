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
    //          ----length----

    // length squared       {3,4,5} == 50.0
    {
        gmath::vec3 a{3,4,5};
        assert(approx_equal(a.length_squared(), 50.0));
    }

    // length       exp: a{0, 3, 4} === 5.0
    {
        gmath::vec3 a{0,3,4};
        gmath::vec3 b{3,4,0};
        assert(approx_equal(a.length(), 5.0f));
        assert(approx_equal(b.length(), 5.0f));
    }
    // normalized       exp: a{0,3,4} == {0.0, 0.3, 0.8}
    {
        gmath::vec3 a{0,3,4};
        gmath::vec3 b{3,4,0};
        assert(approx_equal(a.normalized(), gmath::vec3(0.0f, 0.6f, 0.8f)));
        assert(approx_equal(b.normalized(), gmath::vec3(0.6f, 0.8f, 0.0f)));
    }
    // normalized division by zero       exp: a{0,0,0} == 
    {
        gmath::vec3 a{0,0,0};
        assert(approx_equal(a.normalized(), gmath::vec3(0.0f, 0.0f, 0.0f)));
    }

    std::cout << "all tests passed\n";
    return 0;
}