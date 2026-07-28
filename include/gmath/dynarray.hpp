#pragma once
#include <iostream>

namespace gmath
{

    class dynarray
    {
        private:
        float* data;
        size_t size_;

        public:
        // dynarray() = default;
        dynarray(size_t n) : data(new float[n]), size_(n) {}

        ~dynarray() {delete[] data;}

        float& operator[](size_t i)
        {
            return data[i];
        }

        const float& operator[](size_t i)
        const {
            return data[i];
        }

        size_t size()
        const {
            return size_;
        }
        
        dynarray(const dynarray& other) : data(new float[other.size_]), size_(other.size_) {
            for (size_t i = 0; i < size_; i++) data[i] = other.data[i];
        }

        dynarray& operator=(const dynarray& other) {
            if (this == &other) return *this;
            delete[] data;
            data = new float[other.size_];
            size_ = other.size_;
            for (size_t i = 0; i < size_; i++) data[i] = other.data[i];
            return *this;
        }


    };
}
