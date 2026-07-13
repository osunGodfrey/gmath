#pragma once
#include <iostream>
#include <array>
#include <cmath>

namespace gmath
{

    struct vec4
    {
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;
        float w = 0.0f;

    vec4() = default;

    vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {};

    vec4(std::array<float, 4> input) : x(input[0]), y(input[1]), z(input[2]), w(input[3]) {};

    void print()
    {
        std::cout << "(" << x << ", " << y << ", " << z << ", " << w << ") \n";
    }

    vec4 operator+(const vec4& b)
    const{
        return vec4(x + b.x, y + b.y, z + b.z, w + b.w);
    }

    vec4 operator-(const vec4& b)
    const{
        return vec4(x - b.x, y - b.y, z - b.z, w - b.w);
    }

    vec4 operator*(float b)
    const {
        return vec4(x * b, y * b, z * b, w * b);
    }

    vec4 operator/(float b)
    const {
        return vec4(x / b, y / b, z / b, w / b);
    }

    vec4 operator-()
    const {
        return vec4(-x, -y, -z, -w);
    }

    float length_squared()
    const {
        return x * x + y * y + z * z + w * w;
    }

    float length()
    const {
        return std::sqrt(length_squared());
    }

    vec4 normalized()
    const {
        if(length() == 0.0f)
        {
            return vec4(0.0f, 0.0f, 0.0f, 0.0f);
        }else
        {
            return (vec4(x, y, z, w) / length());
        }
    }

    };

    inline float dot(const vec4& a, const vec4& b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z + a.w * a.w;
    }
    
} // namespace gmath

