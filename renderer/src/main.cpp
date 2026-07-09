#include <fstream>
#include <iostream>
#include <vector>
#include "gmath/vec3.hpp"

const int width = 256;
const int height = 256;
const float radius = 80.0f;
gmath::vec3 center{width / 2.0f, height / 2.0f, 0.0f};

int to_byte(float channel)
{
    return static_cast<int>(channel * 255.999f);
}

void write_pixel(std::ofstream& out, const gmath::vec3& color)
{
    out << to_byte(color.x) << " " << to_byte(color.y) << " " << to_byte(color.z) << " ";
}

float hits(int j, int i)
{
    int count = 0;
    std::vector<float> samples = {0.25f, -0.25f};
    for(auto s : samples)
    {
        for(auto t : samples)
        {
            gmath::vec3 dots{j + s, i + t, 0.0f};
            gmath::vec3 offset = dots - center;
            if(offset.length_squared() < radius * radius)
            {
                count++;
            }
        }
    }
    return count / 4.0f;
    
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
            float t = hits(j, i);
            gmath::vec3 background{r, g, 0.0f};
            gmath::vec3 circle_color{1.0f, 0.0f, 0.0f};
            gmath::vec3 color = background * (1.0f - t) + circle_color * t;
            write_pixel(out, color);
        }
        out << "\n";
    }

    std::cout << "wrote out/image.ppm\n";

}