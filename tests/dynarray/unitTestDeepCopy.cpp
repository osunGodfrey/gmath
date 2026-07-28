#include "gmath/dynarray.hpp"
#include <cassert>
#include <iostream>

int main() {
    // --- construction + access ---
    {
        gmath::dynarray a(5);
        for (size_t i = 0; i < a.size(); i++) a[i] = float(i) * 2.0f;
        for (size_t i = 0; i < a.size(); i++) assert(a[i] == float(i) * 2.0f);
        assert(a.size() == 5);
    }

    // --- copy independence: the double-free / aliasing bug, now as a permanent check ---
    {
        gmath::dynarray a(3);
        a[0] = 1.0f; a[1] = 2.0f; a[2] = 3.0f;

        gmath::dynarray b = a;   // copy constructor
        b[0] = 99.0f;

        assert(a[0] == 1.0f);   // a must be untouched
        assert(b[0] == 99.0f);
        assert(a.size() == 3 && b.size() == 3);
    }

    // --- copy assignment independence ---
    {
        gmath::dynarray a(3);
        a[0] = 1.0f; a[1] = 2.0f; a[2] = 3.0f;

        gmath::dynarray c(1);   // different size on purpose, exercises the delete+realloc path
        c = a;                  // copy assignment
        c[0] = 42.0f;

        assert(a[0] == 1.0f);   // a must be untouched
        assert(c[0] == 42.0f);
        assert(c.size() == 3);  // c should now match a's size
    }

    // --- self-assignment must not crash or corrupt ---
    {
        gmath::dynarray a(3);
        a[0] = 1.0f; a[1] = 2.0f; a[2] = 3.0f;

        a = a;   // self-assignment

        assert(a[0] == 1.0f && a[1] == 2.0f && a[2] == 3.0f);
        assert(a.size() == 3);
    }

    std::cout << "all tests passed\n";
    return 0;
}