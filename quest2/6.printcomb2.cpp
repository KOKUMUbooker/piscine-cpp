#include <iostream>

/*
Write a function that prints in ascending order and on a single line: all possible combinations of two different two-digit numbers.
These combinations are separated by a comma and a space.

Sample output : 
00 01, 00 02, 00 03, ..., 00 98, 00 99, 01 02, 01 03, ..., 97 98, 97 99, 98 99$
*/

namespace piscine
{
    void PrintComb2()
    {
        for (int i = 0; i <= 99; i++)
        {
            for (int j = i+1; j <= 99; j++)
            {
                if (i < 10) std::cout << 0;
                std::cout << i << " ";

                if (j < 10) std::cout << 0;
                std::cout << j ;

                if (!( i == 98 && j == 99)) std::cout << ", ";
            }
        }
    }
}

int main()
{
    piscine::PrintComb2();

    return EXIT_SUCCESS;
}