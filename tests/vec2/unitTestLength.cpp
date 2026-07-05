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

    //      ----length----

    // length squared       {3.0f, 4.0f} == 25.0f
    {
        gmath::vec2 a{3.0f, 4.0f};
        assert(approx_equal(a.length_squared(), 25.0f));
    }
    // length       {3.0f, 4.0f} == 5.0f
    {
        gmath::vec2 a{3.0f, 4.0f};
        assert(approx_equal(a.length(), 5.0f));
    }
    // normalized       {3.0f, 4.0f} == {0.6f, 0.8f}
    {
        gmath::vec2 a{3.0f, 4.0f};
        assert(approx_equal(a.normalize(), gmath::vec2(0.6f, 0.8f)));
    }
    // normalized division by zero      {0.0f, 0.0f} == {0.0f, 0.0f}
    {
        gmath::vec2 a{0.0f, 0.0f};
        assert(approx_equal(a.normalize(), gmath::vec2(0.0f, 0.0f)));
    }




    std::cout << "all test passed\n";
    return 0;
}
