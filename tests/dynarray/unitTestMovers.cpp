#include "gmath/dynarray.hpp"
#include <cassert>
#include <iostream>
#include <utility>   // std::move

int main() {
    // --- move constructor: steals the pointer, doesn't copy ---
    {
        gmath::dynarray a(1000);
        a[0] = 42.0f;
        float* original_address = &a[0];   // capture the address BEFORE moving

        gmath::dynarray b(std::move(a));   // move constructor

        assert(&b[0] == original_address);   // same address = stolen, not copied
        assert(b[0] == 42.0f);
        assert(b.size() == 1000);
    }

    // --- move assignment: steals, and frees whatever the destination owned first ---
    {
        gmath::dynarray a(500);
        a[0] = 7.0f;
        float* original_address = &a[0];

        gmath::dynarray c(10);
        c = std::move(a);

        assert(&c[0] == original_address);
        assert(c[0] == 7.0f);
        assert(c.size() == 500);
    }

    // --- self-move-assignment must not crash or corrupt ---
    {
        gmath::dynarray a(3);
        a[0] = 1.0f; a[1] = 2.0f; a[2] = 3.0f;
        a = std::move(a);
        assert(a.size() == 3);
        assert(a[0] == 1.0f && a[1] == 2.0f && a[2] == 3.0f);
    }

    std::cout << "all move tests passed\n";
    return 0;
}