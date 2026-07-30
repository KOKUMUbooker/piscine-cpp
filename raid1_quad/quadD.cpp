#include <iostream>
#include "include/quadD.hpp"

/*
Write a function QuadD that prints a valid rectangle of width x and of height y.
The function must draw the rectangles as in the examples.
If x and y are positive numbers, the program should print the rectangles as seen in the examples, otherwise, the function should print nothing.

Expected function
func QuadD(x,y int) {

}

Usage : 
piscine::QuadD(5,3) : 
ABBBC
B   B
ABBBC

piscine::QuadD(5,1) :
ABBBC

piscine::QuadD(1,1) :
A

piscine::QuadD(1,5) :
A
B
B
B
A
*/

namespace piscine
{
    
    void QuadD(int x, int y)
    {
        for (int i {1}; i <= y; ++i) // Rows
        {
            for (int j {1}; j <= x; ++j) // Columns
            {
                // 1st column Corners
                if(j == 1 && (i == 1 || i == y)) 
                    std::cout << "A";
    
                // last colum Corners
                else if (j == x && (i == 1 || i == y))
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
