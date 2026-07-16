#pragma once
#include <iostream>
#include <array>
#include <cmath>
#include "gmath/vec3.hpp"
#include "gmath/vec4.hpp"

namespace gmath
{

    struct mat4
    {
        std::array<float, 16> mat =
        {
            1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f,
        };

        mat4() = default;

        mat4(
            float m00, float m01, float m02, float m03,
            float m10, float m11, float m12, float m13,
            float m20, float m21, float m22, float m23,
            float m30, float m31, float m32, float m33
        )   :
            mat{
                m00, m01, m02, m03,
                m10, m11, m12, m13,
                m20, m21, m22, m23,
                m30, m31, m32, m33
            } {}

        void print()
        {
            for(int i = 0; i < 4; i++)
            {
                std::cout << "|"    << (*this)(i, 0) << ", "
                                    << (*this)(i, 1) << ", "
                                    << (*this)(i, 2) << ", "
                                    << (*this)(i, 3) << "|\n";
            }
        }

        // Row-major storage: mat[row*4 + col].
        // Chosen to match NumPy's default C-order layout for Differential-Sim interop.
        // If/when this feeds OpenGL: use glUniformMatrix4fv(loc, 1, GL_TRUE, ...) — GL_TRUE transposes on upload.

        // 1. READ-ONLY ACCESS (Your current working implementation)
        // Used when inspecting the matrix or inside const workflows
        float operator()(size_t row, size_t col)
        const {
            return mat[4 * row + col];
        }

        // 2. NEW: WRITEABLE ACCESS (Returns a mutable reference)
        // Add this to allow changing data, like: myMatrix(2, 3) = 15.0f;
        float& operator()(size_t row, size_t col)
        {
            return mat[4 * row + col];
        }
        
        // 1. MUTABLE BRACKETS: Returns a read/write pointer to a row
        // Allows: matrix[row][col] = value;
        float* operator[](size_t row)
        {
            return &mat[4 * row];
        }

        // 2. CONST BRACKETS: Returns a read-only pointer to a row
        // Used when passing the matrix into read-only functions
        const float* operator[](size_t row)
        const {
            return &mat[4 * row];
        }

        mat4 operator*(const mat4& B)
        const {
            mat4 results;
            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j < 4; j++)
                {
                    results[i][j] = 0.0f;
                    for(int h = 0; h < 4; h++)
                    {
                        results[i][j] += (*this)[i][h] * B[h][j];
                    }
                }
            }
            return results;
        }

        vec4 operator*(const vec4& v)
        const {
            return vec4(
                v.x * (*this)[0][0] + v.y * (*this)[0][1] + v.z * (*this)[0][2] + v.w * (*this)[0][3],
                v.x * (*this)[1][0] + v.y * (*this)[1][1] + v.z * (*this)[1][2] + v.w * (*this)[1][3],
                v.x * (*this)[2][0] + v.y * (*this)[2][1] + v.z * (*this)[2][2] + v.w * (*this)[2][3],
                v.x * (*this)[3][0] + v.y * (*this)[3][1] + v.z * (*this)[3][2] + v.w * (*this)[3][3]
            );
        }

        mat4 transpose()
        const {
            mat4 result;
            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j < 4; j++)
                {
                    result[i][j] = (*this)[j][i];
                }
            }
            return result;
        }

    };

    inline mat4 translate(const vec3& v)
    {
        gmath::mat4 t;
        t(0, 3) = v.x;
        t(1, 3) = v.y;
        t(2, 3) = v.z;
        return t;
    }

    inline mat4 scale(const vec3& v)
    {
        gmath::mat4 s;
        s(0, 0) = v.x;
        s(1, 1) = v.y;
        s(2, 2) = v.z;
        return s;
    }

    inline mat4 rotate_z(float z)
    {
        gmath::mat4 rz;
        rz(0, 0) = std::cos(z);
        rz(0, 1) = -std::sin(z);
        rz(1, 0) = std::sin(z);
        rz(1, 1) = std::cos(z);
        return rz;
    }

    inline mat4 rotate_x(float x)
    {
        gmath::mat4 rx;
        rx(1, 1) = std::cos(x);
        rx(1, 2) = -std::sin(x);
        rx(2, 1) = std::sin(x);
        rx(2, 2) = std::cos(x);
        return rx;
    }

    inline mat4 rotate_y(float y)
    {
        gmath::mat4 ry;
        ry(0, 0) = std::cos(y);
        ry(0, 2) = std::sin(y);
        ry(2, 0) = -std::sin(y);
        ry(2, 2) = std::cos(y);
        return ry;
    }
}