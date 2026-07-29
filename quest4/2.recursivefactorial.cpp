#include <iostream>

/*
Write a recursive function that returns the factorial of the int passed as parameter.
Errors (non possible values or overflows) will return 0.
for is forbidden for this exercise.

Expected function
func RecursiveFactorial(nb int) int {

}
*/

namespace piscine
{
    /* eg 4! = 4 * 2 * 3 * 2 * 1 = 24*/
    /* Factorial of 1: (1! = 1) */
    /* Factorial of 0: (0! = 1) */
    int RecursiveFactorial(int nb)
    {
        if (nb == 1 || nb == 0) return 1;

        return nb * RecursiveFactorial(nb-1);
    }
}

int main()
{
    std::cout << piscine::RecursiveFactorial(4) << "\n";

    return EXIT_SUCCESS;
}