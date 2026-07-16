#include <cassert>
#include <cmath>
#include <iostream>
#include "gmath/vec3.hpp"
#include "gmath/vec4.hpp"
#include "gmath/mat4.hpp"


bool approx_equal(float a, float b, float esp = 1e-6f)
{
    return std::fabs(a - b) < esp;
}

bool approx_equal(const gmath::vec4& a, const gmath::vec4& b, float eps = 1e-6f) {
    return approx_equal(a.x, b.x, eps)
        && approx_equal(a.y, b.y, eps)
        && approx_equal(a.z, b.z, eps)
        && approx_equal(a.w, b.w, eps);
}

bool approx_equal(const gmath::mat4& a, const gmath::mat4& b, float esp = 1e-6f)
{
    bool test_equal = true;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            test_equal = test_equal && approx_equal(a[i][j], b[i][j], esp);
        }
    }
    return test_equal;
}

int main()
{
    //      ---- TSR ----
    // translate
    {
        gmath::mat4 T = gmath::translate(gmath::vec3(3.0f, 8.0f, 15.0f));
        gmath::vec4 v1{1.0f, 0.0f, 0.0f, 1.0f};
        gmath::vec4 u1{4.0f, 8.0f, 15.0f, 1.0f};
        assert(approx_equal(T * v1, u1));
        gmath::vec4 v2{0.0f, 2.0f, 0.0f, 1.0f};
        gmath::vec4 u2{3.0f, 10.0f, 15.0f, 1.0f};
        assert(approx_equal(T * v2, u2));
        gmath::vec4 v3{0.0f, 2.0f, 5.0f, 1.0f};
        gmath::vec4 u3{3.0f, 10.0f, 20.0f, 1.0f};
        assert(approx_equal(T * v3, u3));

        gmath::vec4 dir{1.0f, 0.0f, 0.0f, 0.0f};
        assert(approx_equal(T * dir, dir));   // translate must not move directions
    }
    // scale
    {
        gmath::mat4 S = gmath::scale(gmath::vec3(2.0f, 5.0f, 12.0f));
        gmath::vec4 v1{1.0f, 4.0f, 5.0f, 1.0f};
        gmath::vec4 u1{2.0f, 20.0f, 60.0f, 1.0f};
        assert(approx_equal(S * v1, u1));
        gmath::vec4 v2{4.0f, 1.0f, 5.0f, 1.0f};
        gmath::vec4 u2{8.0f, 5.0f, 60.0f, 1.0f};
        assert(approx_equal(S * v2, u2));
        gmath::vec4 v3{4.0f, 5.0f, 1.0f, 1.0f};
        gmath::vec4 u3{8.0f, 25.0f, 12.0f, 1.0f};
        assert(approx_equal(S * v3, u3));
    }
    // rotation z
    {
        constexpr double pi = 3.14159265358979323846;
        float sqrt2 = static_cast<float>(std::sqrt(2));
        gmath::mat4 RZ = gmath::rotate_z(pi / 4);
        gmath::vec4 v1{1.0f, 0.0f, 0.0f, 1.0f};
        gmath::vec4 u1{sqrt2 / 2, sqrt2 / 2, 0.0f, 1.0f};
        assert(approx_equal( RZ * v1, u1));
        gmath::vec4 v2{0.0f, -1.0f, 0.0f, 1.0f};
        gmath::vec4 u2{sqrt2 / 2, -sqrt2 / 2, 0.0f, 1.0f};
        assert(approx_equal( RZ * v2, u2));
    }
    // rotation x
    {
        constexpr double pi = 3.14159265358979323846;
        float sqrt2 = static_cast<float>(std::sqrt(2));
        gmath::mat4 RX = gmath::rotate_x(pi / 4);
        gmath::vec4 v1{0.0f, 1.0f, 0.0f, 1.0f};
        gmath::vec4 u1{0.0f, sqrt2 / 2, sqrt2 / 2, 1.0f};
        assert(approx_equal(RX * v1, u1));
        gmath::vec4 v2{0.0f, 0.0f, -1.0f, 1.0f};
        gmath::vec4 u2{0.0f, sqrt2 / 2, -sqrt2 / 2, 1.0f};
        assert(approx_equal(RX * v2, u2));
    }
    // rotation y
    {
        constexpr double pi = 3.14159265358979323846;
        float sqrt2 = static_cast<float>(std::sqrt(2));
        gmath::mat4 RY = gmath::rotate_y(pi / 4);
        gmath::vec4 v1{0.0f, 0.0f, 1.0f, 1.0f};
        gmath::vec4 u1{sqrt2 / 2, 0.0f, sqrt2 / 2, 1.0f};
        assert(approx_equal(RY * v1, u1));
        gmath::vec4 v2{-1.0f, 0.0f, 0.0f, 1.0f};
        gmath::vec4 u2{-sqrt2 / 2, 0.0f, sqrt2 / 2, 1.0f};
        assert(approx_equal(RY * v2, u2));
    }

    std::cout << "all test passed\n";
    return 0;
}

