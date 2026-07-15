#include <cassert>
#include <cmath>
#include <iostream>
#include "gmath/mat4.hpp"

// Float comparison helper — the one non-obvious piece.
// Never use == on floats: 0.1f + 0.2f != 0.3f due to rounding.
bool approx_equal(float a, float b, float esp = 1e-6f)
{
    return std::fabs(a - b) < esp;
}

bool approx_equal(const gmath::mat4 a, const gmath::mat4 b, float esp = 1e-6f)
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
    //          ---- constructor ----
    //  identity matrix
    {
        gmath::mat4 v;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                if(i == j)
                {
                    assert(approx_equal(v[i][j], 1.0f));
                }else{
                    assert(approx_equal(v[i][j], 0.0f));
                }
            }
        }
    }

    //          ----- accessor ----
    // parenthesis accessor         m(i, j) == 
    {
        // init via parenthesis
        gmath::mat4 v;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                v(i, j) = float(i * j);
            }
        }
        // access via parenthesis
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                assert(approx_equal(v(i, j), float(i * j)));
            }
        }
    }

    // index accessor
    {
        // init via index
        gmath::mat4 v;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                v[i][j] = float(i * j);
            }
        }
        // access via index
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                assert(approx_equal(v[i][j], float(i * j)));
            }
        }
    }

    std::cout << "all test passed\n";
    return 0;


}

