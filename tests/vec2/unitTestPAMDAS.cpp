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
    //          ----constructor----
    {
        gmath::vec2 v;
        assert(approx_equal(v, gmath::vec2(0.0f, 0.0f)));
    }
    {
        gmath::vec2 v{1.0f, 3.0f};
        assert(approx_equal(v, gmath::vec2(1.0f, 3.0f)));
    }

    //          ----PAMDAS----
    // addition     
    {
        gmath::vec2 a{1.0f, 2.0f};
        gmath::vec2 b{3.0f, 4.0f};
        assert(approx_equal(a + b, gmath::vec2(4.0f, 6.0f)));
    }
    // subtraction
    {
        gmath::vec2 a{3.0f, 4.0f};
        gmath::vec2 b{1.0f, 2.0f};
        assert(approx_equal(a - b, gmath::vec2(2.0f, 2.0f)));
    }
    // multiply
    {
        gmath::vec2 a{1.0f, 3.0f};
        assert(approx_equal(a * 2.0f, gmath::vec2(2.0f, 6.0f)));
    }
    // divide
    {
        gmath::vec2 a{1.0f, 3.0f};
        assert(approx_equal(a / 2, gmath::vec2(0.5f, 1.5f)));
    }
    // negate
    {
        gmath::vec2 a{1.0f, 3.0f};
        assert(approx_equal(-a, gmath::vec2(-1.0f, -3.0f)));
    }
    // chaining
    {
        gmath::vec2 a{1.0f, 2.0f};
        gmath::vec2 b{3.0f, 4.0f};
        assert(approx_equal((a + b) - b, gmath::vec2(1.0f, 2.0f)));
    }

    std::cout << "all test passed\n";
    return 0;
}
