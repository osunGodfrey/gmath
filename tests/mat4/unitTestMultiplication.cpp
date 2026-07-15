#include <cassert>
#include <cmath>
#include <iostream>
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
    //          ---- multiplication ----
    // multiply matrix matrix       A * B = C
    {
        gmath::mat4 I;

        gmath::mat4 A;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                A[i][j] = float(4 * i + j);
            }
        }
        gmath::mat4 B;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                B[i][j] = float(4 * i + j);
            }
        }
        gmath::mat4 C;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                C[i][j] = 0.0f;
                for(int h = 0; h < 4; h++)
                {
                    C[i][j] += float(4 * i + h) * float(4 * h + j);
                }
            }
        }
        
        assert(approx_equal(I * I, I));
        assert(approx_equal(A * I, A));
        assert(approx_equal(I * A, A));
        assert(approx_equal(A * B, C));

        assert(approx_equal((A * B) * C, A * (B * C)));

    }
    {
        gmath::mat4 I;

        gmath::mat4 A{
            1.0f, 2.0f, 3.0f, 4.0f,
            5.0f, 6.0f, 7.0f, 8.0f,
            9.0f, 10.0f, 11.0f, 12.0f,
            13.0f, 14.0f, 15.0f, 16.0f
        };

        gmath::mat4 B{
            1.0f, 2.0f, 3.0f, 4.0f,
            5.0f, 6.0f, 7.0f, 8.0f,
            9.0f, 10.0f, 11.0f, 12.0f,
            13.0f, 14.0f, 15.0f, 16.0f
        };

        gmath::mat4 C{
            90.0f, 100.0f, 110.0f, 120.0f,
            202.0f, 228.0f, 254.0f, 280.0f,
            314.0f, 356.0f, 398.0f, 440.0f,
            426.0f, 484.0f, 542.0f, 600.0f
        };

        assert(approx_equal(I * I, I));
        assert(approx_equal(A * I, A));
        assert(approx_equal(I * A, A));
        assert(approx_equal(A * B, C));

        assert(approx_equal((A * B) * C, A * (B * C)));
    }
    // multiply matrix vector       A * v = u
    {
        gmath::mat4 I;

        gmath::mat4 A;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                A[i][j] = float(4 * i + j);
            }
        }

        gmath::vec4 v{1.0f, 2.0f, 3.0f, 4.0f};

        gmath::vec4 u{20.0f, 60.0f, 100.0f, 140.0f};

        assert(approx_equal(I * v, v));
        assert(approx_equal(A * v, u));
    }
    {
        gmath::mat4 I;

        gmath::mat4 A{
            1.0f, 2.0f, 3.0f, 4.0f,
            5.0f, 6.0f, 7.0f, 8.0f,
            9.0f, 10.0f, 11.0f, 12.0f,
            13.0f, 14.0f, 15.0f, 16.0f
        };

        gmath::vec4 v{1.0f, 2.0f, 3.0f, 4.0f};

        gmath::vec4 u{30.0f, 70.0f, 110.0f, 150.0f};

        assert(approx_equal(I * v, v));
        assert(approx_equal(A * v, u));
    }

    //          ---- transpose ----
    {
        gmath::mat4 I;

        gmath::mat4 M{
            1.0f, 2.0f, 3.0f, 4.0f,
            2.0f, 1.0f, 2.0f, 3.0f,
            3.0f, 2.0f, 1.0f, 2.0f,
            4.0f, 3.0f, 2.0f, 1.0f
        };

        gmath::mat4 A{
            1.0f, 2.0f, 3.0f, 4.0f,
            5.0f, 6.0f, 7.0f, 8.0f,
            9.0f, 10.0f, 11.0f, 12.0f,
            13.0f, 14.0f, 15.0f, 16.0f
        };

        assert(approx_equal(I.transpose(), I));
        assert(approx_equal(M.transpose(), M));
        assert(!approx_equal(A.transpose(), A));
    }
    std::cout << "all test passed\n";
    return 0;

}