#pragma once
#include <iostream>
#include <array>

namespace gmath{


struct vec3{
    float x = 0.0;
    float y = 0.0;
    float z = 0.0;


    vec3() = default;

    vec3(float x, float y, float z) : x(x), y(y), z(z) {};
    
    vec3(std::array<float, 3> input) : x(input[0]), y(input[1]), z(input[2]) {};

    void print()
    const {
        std:: cout << "vec("<< x << ", " << y << ", " << z << ")\n";
    }

    vec3 operator+(const vec3 b)
    const {
        return vec3(x + b.x ,y + b.y ,z + b.z);
    }

    vec3 operator-(const vec3 b)
    const {
        return vec3(x - b.x, y - b.y, z - b.z);
    }

    vec3 operator*(float b)
    const {
        return vec3(b * x, b * y, b * z);
    }

    vec3 operator/(float b)
    const {
        return vec3(x / b, y / b, z / b);
    }

};


}