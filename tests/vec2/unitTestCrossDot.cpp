#include <cassert>
#include <cmath>
#include <iostream>
#include <gmath/vec2.hpp>

// Float comparison helper — the one non-obvious piece.
// Never use == on floats: 0.1f + 0.2f != 0.3f due to rounding.
bool approx_equal(float a, float b, float eps = 1e-6f) {
    return std::fabs(a - b) < eps;
}

bool approx_equal(const gmath::vec2& a, const gmath::vec2& b, float eps = 1e-6f) {
    return approx_equal(a.x, b.x, eps)
        && approx_equal(a.y, b.y, eps);
}

int main()
{
    //      ----negate----
    // negate       - {1.0f, 2.0f} == {-1.0f, 2.0f}
    {
        gmath::vec2 a{1.0f, 2.0f};
        assert(approx_equal(-a, gmath::vec2(-1.0f, -2.0f)));
    }

    //      ----dot----
    // dot product      dot(a,a) == x^2 + y^2
    {
        gmath::vec2 a{3.0f, 4.0f};
        // assert(approx_equal())
    }
    // dot with zero
    {
        gmath::vec2 a{1.0f, 2.0f};
        gmath::vec2 b{0.0f, 0.0f};
        assert(approx_equal(gmath::dot(a,b), 0.0f));
    }
    // dot orthogonal axis      dot(a,b) == 0, dot(b,a) == 0
    {
        gmath::vec2 a{1.0f, 2.0f};
        gmath::vec2 b{2.0f, -1.0f};
        assert(approx_equal(gmath::dot(a,b), 0.0f));
        assert(approx_equal(gmath::dot(b,a), 0.0f));
    }

    //      ----cross product---- to continue



    std::cout << "all test passed\n";
    return 0;
}
