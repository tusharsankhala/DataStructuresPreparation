// This is a implementaion of Bresenham Line Drawing Algorithm
//
 
#include <iostream>

void Set_Pixel(int x, int y)
{
    std::cout << "(" << x << "," << y << ")"<<std::endl;
}

void DrawBresenham(int x0, int y0, int x1, int y1) 
{
    auto m = 2 * (y1 - y0);
    auto slope_error = m - (x1 - x0);

    for(int x = x0, y = y0; x <= x1; ++x)
    {
        Set_Pixel(x, y);

        // Add slope to increment formed.
        slope_error += m;

        // If slope error reached limit
        // time to increment y and update 
        // slope error.
        if (slope_error >= 0)
        {
            y += 1;
            slope_error -= m - (x1 - x0);
        }

        Set_Pixel(x, y);
    }
}

int main()
{
    DrawBresenham(3, 2, 15, 5);
    
}