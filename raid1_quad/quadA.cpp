#include <iostream>
#include "include/quadA.hpp"

/*
Write a function QuadA that prints a valid rectangle with a given width of x and height of y.
The function must draw the rectangles as in the examples.
If x and y are positive numbers, the program should print the rectangles as seen in the examples,
otherwise, the function should print nothing.

Expected function
func QuadA(x,y int) {

}

Usage : 
piscine::QuadA(5,3) : 
o---o
|   |
o---o

piscine::QuadA(5,1) :
o---o

piscine::QuadA(1,1) :
o

piscine::QuadA(1,5) : 
o
|
|
|
o
*/
namespace piscine
{
    void QuadA(int x, int y)
    {
        for (int i {1}; i <= y; ++i) // Rows
        {
            for (int j {1}; j <= x; ++j) // Columns
            {
                // Top Corners
                if(i == 1 && (j == 1 || j == x)) 
                    std::cout << "o";

                // Bottom Corners
                else if (i == y && (j == 1 || j == x))
                    std::cout << "o";
                
                // Top middle horizontal section
                else if (i == 1 && j > 1 && j < x) 
                    std::cout << "-";
                
                // Bottom middle horizontal section
                else if (i == y && j > 1 && j < x)
                    std::cout << "-";

                // Right middle vertical section
                else if (j == 1 && i > 1 && i < y)
                    std::cout << "|";

                // Left middle vertical section
                else if (j == x && i > 1 && i < y)
                    std::cout << "|";

                else 
                    std::cout << " ";
                
            }

            std::cout << "\n";
        } 
    }
}
