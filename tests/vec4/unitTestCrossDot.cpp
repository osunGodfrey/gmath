#include <cassert>
#include <cmath>
#include <iostream>
#include "gmath/vec4.hpp"

// Float comparison helper — the one non-obvious piece.
// Never use == on floats: 0.1f + 0.2f != 0.3f due to rounding.
bool approx_equal(float a, float b, float eps = 1e-6f) {
    return std::fabs(a - b) < eps;
}

bool approx_equal(const gmath::vec4& a, const gmath::vec4 b, float eps = 1e-6f) {
    return approx_equal(a.x, b.x, eps)
        && approx_equal(a.y, b.y, eps)
        && approx_equal(a.z, b.z, eps)
        && approx_equal(a.w, b.w, eps);
}

int main() {

    //          ---- reflection rule ----
    // negating:        -(a) == (-a)
    {
        gmath::vec4 a{1.0f, 2.0f, 3.0f, 4.0f};
        assert(approx_equal(-a, gmath::vec4(-1.0f, -2.0f, -3.0f, -4.0f)));
    }

    //          ---- dot rules ----
    // dot product        dot(a,a) == x^2 + y^2 + z^2
    {
        gmath::vec4 a{3.0f, 4.0f, 5.0f, 6.0f};
        assert(approx_equal(gmath::dot(a,a), 86.0f));
    }
    // dot with zero
    {
        gmath::vec4 a{0.0f, 0.0f, 0.0f, 0.0f};
        assert(approx_equal(gmath::dot(a,a), 0.0f));
    }
    // dot orthogonal axis      dot(a,b) == 0, dot(b,c) == 0, dot(a,c) == 0
    {
        gmath::vec4 a{1.0f, 0.0f, 0.0f, 0.0f};
        gmath::vec4 b{0.0f, 1.0f, 0.0f, 0.0f};
        gmath::vec4 c{0.0f, 0.0f, 1.0f, 0.0f};
        gmath::vec4 d{0.0f, 0.0f, 0.0f, 1.0f};
        assert(approx_equal(gmath::dot(a,b), 0.0f));
        assert(approx_equal(gmath::dot(a,c), 0.0f));
        assert(approx_equal(gmath::dot(a,d), 0.0f));
        assert(approx_equal(gmath::dot(b,c), 0.0f));
        assert(approx_equal(gmath::dot(b,d), 0.0f));
        assert(approx_equal(gmath::dot(c,d), 0.0f));
    }

    std::cout << "all tests passed\n";
    return 0;
}