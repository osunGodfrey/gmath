#pragma once
#include <iostream>
#include <array>
#include <cmath>

namespace gmath{


struct vec2
{
    float x = 0.0f;
    float y = 0.0f;

    vec2() = default;
    vec2(float x, float y) : x(x), y(y) {}
    vec2(std::array<float, 2> input) : x(input[0]), y(input[1]) {}

    void print()
    const {
        std::cout << "vec2(" << x << ", " << y << ")\n";
    }

    vec2 operator+(const vec2& a)
    const {
        return gmath::vec2(x + a.x, y + a.y);
    }

    vec2 operator-(const vec2& a)
    const {
        return gmath::vec2(x - a.x, y - a.y);
    }

    vec2 operator*(const float a)
    const {
        return gmath::vec2(a * x, a * y);
    }

    vec2 operator/(const float a)
    const {
        return gmath::vec2( x / a, y / a);
    }

    vec2 operator-()
    const {
        return gmath::vec2(-x, -y);
    }

    float length_squared()
    const {
        return x * x + y * y;
    }

    float length()
    const {
        return std::sqrt(x * x + y * y);
    }

    vec2 normalize()
    const {
        float len = length();
        if(len == 0)
        {
            return vec2(0.0f, 0.0f);
        }
        return vec2(x, y) / len;
    }




};

inline float dot(const vec2& a, const vec2& b)
{
    return a.x * b.x + a.y * b.y;
}

// inline vec2 cross(const vec2& a)
// {
//     return vec2(-a.y, a.x);
// }



}

