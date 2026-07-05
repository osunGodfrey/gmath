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

    //          ---- reflection rule ----
    // negating:        -(a) == (-a)
    {
        gmath::vec3 a{1.0f, 2.0f, 3.0f};
        assert(approx_equal(-a, gmath::vec3(-1.0f, -2.0f, -3.0f)));
    }

    //          ---- dot rules ----

    // dot product        dot(a,a) == x^2 + y^2 + z^2
    {
        gmath::vec3 a{3.0f, 4.0f, 5.0f};
        assert(approx_equal(gmath::dot(a,a), 50.0f));
    }
    // dot with zero
    {
        gmath::vec3 a{0.0f, 0.0f, 0.0f};
        assert(approx_equal(gmath::dot(a,a), 0.0f));
    }
    // dot orthogonal axis      dot(a,b) == 0, dot(b,c) == 0, dot(a,c) == 0
    {
        gmath::vec3 a{1.0f, 0.0f, 0.0f};
        gmath::vec3 b{0.0f, 1.0f, 0.0f};
        gmath::vec3 c{0.0f, 0.0f, 1.0f};
        assert(approx_equal(gmath::dot(a,b), 0.0f));
        assert(approx_equal(gmath::dot(b,c), 0.0f));
        assert(approx_equal(gmath::dot(a,c), 0.0f));
    } 

    //          ---- cross rules ----

    // cross right hand rules       exp: cross({0,0,1},{0,1,0}) = {1,0,0}
    // cross right-hand rule — cyclic order is x→y→z→x
    {
        gmath::vec3 x{1.0f, 0.0f, 0.0f};
        gmath::vec3 y{0.0f, 1.0f, 0.0f};
        gmath::vec3 z{0.0f, 0.0f, 1.0f};

        // with the cycle: positive results
        assert(approx_equal(gmath::cross(x, y),  z));
        assert(approx_equal(gmath::cross(y, z),  x));
        assert(approx_equal(gmath::cross(z, x),  y));   // note: (z, x), not (x, z)

        // against the cycle: negated results
        assert(approx_equal(gmath::cross(y, x), -z));
        assert(approx_equal(gmath::cross(z, y), -x));
        assert(approx_equal(gmath::cross(x, z), -y));   // <-- the one your old test had backwards
    }
    // cross anticommutativity rule       cross(a,b) == -(cross(b,a))
    {
        gmath::vec3 a{2.0f, 3.0f, 4.0f};
        gmath::vec3 b{5.0f, 6.0f, 7.0f};
        assert(approx_equal(gmath::cross(a,b), - (gmath::cross(b,a))));
    }
    // cross orthogonal to both inputs      exp: dot(cross(a,b), a) == 0
    {
        gmath::vec3 a{2.0f, 3.0f, 4.0f};
        gmath::vec3 b{5.0f, 6.0f, 7.0f};
        assert(approx_equal(gmath::dot(gmath::cross(a,b), a), 0.0f));
        assert(approx_equal(gmath::dot(gmath::cross(a,b), b), 0.0f));
    }

    std::cout << "all tests passed\n";
    return 0;
}