#include <ostream>
#include <array>
#include "gmath/vec3.hpp"


int main(){

    gmath::vec3 v(1, 2, 3);
    // std::cout << "v = (" << v.get(0) << "," << v.get(1) << "," << v.get(2) << ")\n";
    v.print();

    std::array<float, 3> i = {4,5,6};
    gmath::vec3 u(i);
    u.print();

    gmath::vec3 a(2,4,8);
    gmath::vec3 b(2,4,8);
    gmath::vec3 c = a + b;
    c.print();
    gmath::vec3 d = (a + b) * 2.0f - a / 2.0f;
    d.print();

    gmath::vec3 a1{1.0f, 2.0f, 3.0f};
    gmath::vec3 b1{4.0f, 5.0f, 6.0f};
    gmath::vec3 c1 = a1 + b1 - a1;   // chaining two of your operators
    c1.print(); 

    return 0;
}

