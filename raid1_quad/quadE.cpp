#include <iostream>
#include "include/quadE.hpp"

/*
Write a function QuadE that prints a valid rectangle of width x and of height y.
The function must draw the rectangles as in the examples.
If x and y are positive numbers, the program should print the rectangles as seen in the examples, otherwise, the function should print nothing.

Expected function
func QuadE(x,y int) {

}

Usage : 
piscine::QuadE(5,3) : 
ABBBC
B   B
CBBBA

piscine::QuadE(5,1) :
ABBBC

piscine::QuadE(1,1) : 
A

piscine::QuadE(1,5) : 
A
B
B
B
C
*/

void QuadE(int x, int y)
{
    for (int i {1}; i <= y; ++i) // Rows
    {
        for (int j {1}; j <= x; ++j) // Columns
        {
            // Top Corners
            if(i == 1 && j == 1) 
                std::cout << "A";
            else if(i == 1 && j == x) 
                std::cout << "C";

            // Bottom Corners
            else if (i == y && j == 1)
                std::cout << "C";
            else if (i == y && j == x)
                std::cout << "A";
            
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
