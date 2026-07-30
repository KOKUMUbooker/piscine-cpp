#include <iostream>
#include "include/quadC.hpp"

/*
Write a function QuadC that prints a valid rectangle of width x and of height y.
The function must draw the rectangles as in the examples.
If x and y are positive numbers, the program should print the rectangles as seen in the examples, otherwise, the function should print nothing.

Expected function
func QuadC(x,y int) {

}

Usage : 
piscine::QuadC(5,3) :
ABBBA
B   B
CBBBC

piscine::QuadC(5,1) :
ABBBA

piscine::QuadC(1,1) : 
A

piscine::QuadC(1,5) :
A
B
B
B
C
*/

namespace piscine 
{
    void QuadC(int x, int y)
    {
        for (int i {1}; i <= y; ++i) // Rows
        {
            for (int j {1}; j <= x; ++j) // Columns
            {
                // Top Corners
                if(i == 1 && (j == 1 || j == x)) 
                    std::cout << "A";
    
                // Bottom Corners
                else if (i == y && (j == 1 || j == x))
                    std::cout << "C";
                
                // Top middle horizontal section
                else if (i == 1 && j > 1 && j < x) 
                    std::cout << "B";
                
                // Bottom middle horizontal section
                else if (i == y && j > 1 && j < x)
                    std::cout << "B";
    
                // Right middle vertical section
                else if (j == 1 && i > 1 && i < y)
                    std::cout << "B";
    
                // Left middle vertical section
                else if (j == x && i > 1 && i < y)
                    std::cout << "B";
    
                else 
                    std::cout << " ";
                
            }
    
            std::cout << "\n";
        } 
    }
}