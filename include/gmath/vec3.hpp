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

    vec3 operator-()
    const {
        return vec3(-x, -y, -z);
    }

};

inline float dot(const vec3 a, const vec3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline vec3 cross(const vec3 a, const vec3 b)
{
    return vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}


}