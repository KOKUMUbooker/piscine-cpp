#include <iostream>
#include "include/quadB.hpp"

/*
Write a function QuadB that prints a valid rectangle of width x and of height y.
The function must draw the rectangles as in the examples.
If x and y are positive numbers, the program should print the rectangles as seen in the examples, otherwise, the function should print nothing.

Expected function
func QuadB(x,y int) {

}
*/
// Usage
// piscine::QuadB(5,3) :
// /***\
// *   *
// \***/

// piscine::QuadB(5,1) :
// /***\

// piscine::QuadB(1,1) :
// /

// piscine.QuadB(1,5) :
// /
// *
// *
// *
// \

namespace piscine
{
    void QuadB(int x, int y)
    {
        for (int i {1}; i <= y; ++i) // Rows
        {
            for (int j {1}; j <= x; ++j) // Columns
            {
                // Top Corners
                if(i == 1 && j == 1) 
                    std::cout << "/";
                else if(i == 1 && j == x) 
                    std::cout << "\\";
    
                // Bottom Corners
                else if (i == y && j == 1)
                    std::cout << "\\";
                else if (i == y && j == x)
                    std::cout << "/";
                
                // Top middle horizontal section
                else if (i == 1 && j > 1 && j < x) 
                    std::cout << "*";
                
                // Bottom middle horizontal section
                else if (i == y && j > 1 && j < x)
                    std::cout << "*";
    
                // Right middle vertical section
                else if (j == 1 && i > 1 && i < y)
                    std::cout << "*";
    
                // Left middle vertical section
                else if (j == x && i > 1 && i < y)
                    std::cout << "*";
    
                else 
                    std::cout << " ";
                
            }
    
            std::cout << "\n";
        } 
    }
}
