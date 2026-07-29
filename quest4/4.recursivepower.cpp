#include <iostream>

/*
Instructions
Write a recursive function that returns the value of nb to the power of power.
Negative powers will return 0. Overflows do not have to be dealt with.
for is forbidden for this exercise.

Expected function
func RecursivePower(nb int, power int) int {

}
*/

namespace piscine
{
    int RecursivePower(int nb, int power)
    {
        if (power == 0) return 1;
        if (power == 1) return nb;

        return nb * RecursivePower(nb ,power-1);
    }
}

int main()
{
    std::cout << piscine::RecursivePower(10,2) << "\n";
    std::cout << piscine::RecursivePower(4,3) << "\n";

    return EXIT_SUCCESS;
}