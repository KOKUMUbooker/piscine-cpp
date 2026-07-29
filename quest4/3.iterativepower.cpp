#include <iostream>

/*
Write an iterative function that returns the value of nb to the power of power.
Negative powers will return 0. Overflows do not have to be dealt with.

Expected function
func IterativePower(nb int, power int) int {

}
*/

namespace piscine 
{
    int IterativePower(int nb, int power)
    {
        if (power < 0) return 0;
        if (power == 0) return 1;

        int res {1};
        for (int i {power}; i >= 1; --i)
        {
            res *= nb;
        }

        return res;
    }
}

int main()
{
    std::cout << piscine::IterativePower(10,2) << "\n";
    std::cout << piscine::IterativePower(4,3) << "\n";

    return EXIT_SUCCESS;
}