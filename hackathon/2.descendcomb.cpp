#include <iostream>

/*
Write a function that prints in descending order and on a single line all possible combinations of two different two-digit numbers.
These combinations are separated by a comma and a space.

Expected function
func DescendComb() {

}

Usage (Go) :
piscine.DescendComb()

Output : 
99 98, 99 97, 99 96, 99 95, 99 94, ..., 03 01, 03 00, 02 01, 02 00, 01 00
*/

namespace piscine
{
    void DescendComb()
    {
        for (int i {99}; i > 0; --i)
        {
            for (int j {i-1}; j >= 0; --j)
            {
                if (i < 10)
                    std::cout << "0" << i;
                else
                    std::cout << i;
                
                std::cout << " ";

                if (j < 10 && j != 0)
                    std::cout << "0" << j;
                else if (j == 0)
                    std::cout << "00";
                else
                    std::cout << j;

                if (i > 1)
                    std::cout << ", ";
            }
        }
    }
} // namespace piscine


int main()
{
    piscine::DescendComb();

    return EXIT_SUCCESS;
}