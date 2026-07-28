#include <iostream>
#include "gmath/dynarray.hpp"

int main()
{
    gmath::dynarray a(5);
    for (size_t i = 0; i < a.size(); i++) a[i] = float(i) * 2.0f;
    for (size_t i = 0; i < a.size(); i++) std::cout << a[i] << " ";
}