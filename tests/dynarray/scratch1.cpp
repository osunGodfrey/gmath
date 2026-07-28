// scratch_step2_bug.cpp
#include "gmath/dynarray.hpp"
#include <iostream>

int main() {
    gmath::dynarray a(3);
    a[0] = 1.0f; a[1] = 2.0f; a[2] = 3.0f;

    gmath::dynarray b = a;   // compiler-generated copy: copies the pointer, not the data

    b[0] = 99.0f;
    std::cout << "a[0] = " << a[0] << "\n";
}   // both a and b destruct here -> delete[] on the same pointer, twice