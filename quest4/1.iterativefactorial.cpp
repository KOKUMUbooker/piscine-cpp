#include <iostream>

/*
Write an iterative function that returns the factorial of the int passed as parameter.
Errors (non possible values or overflows) will return 0.

Expected function
func IterativeFactorial(nb int) int {

}
*/

namespace piscine
{
    /* eg 4! = 4 * 2 * 3 * 2 * 1 = 24*/
    /* Factorial of 1: (1! = 1) */
    /* Factorial of 0: (0! = 1) */
    int IterativeFactorial(const int nb)
    {
        if ( nb < 0 ) return 0;
        if ( nb == 0 ) return 0;
        if ( nb == 1 ) return 1;

        int res {1};
        for (int i {nb}; i >= 1; --i)
            res *= i;

        return res;
    }
}

int main()
{
    std::cout << piscine::IterativeFactorial(4) << "\n";

    return EXIT_SUCCESS;
}