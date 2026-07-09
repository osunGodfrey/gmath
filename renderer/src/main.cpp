#include <fstream>
#include <iostream>
#include "gmath/vec3.hpp"

const int width = 256;
const int height = 256;

int to_byte(float channel)
{
    return static_cast<int>(channel * 255.999f);
}

void write_pixel(std::ofstream& out, const gmath::vec3& color)
{
    out << to_byte(color.x) << " " << to_byte(color.y) << " " << to_byte(color.z) << " ";
}

int main()
{
    std::ofstream out("out/image.ppm");
    out << "P3\n";
    out << "256 256\n";
    out << "255\n";

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            float r = float(j) / float(width - 1);
            float g = float(i) / float(height - 1);
            gmath::vec3 color(r, g, 0.0f);
            write_pixel(out, color);
        }
        out << "\n";
    }

    std::cout << "wrote out/image.ppm\n";

}