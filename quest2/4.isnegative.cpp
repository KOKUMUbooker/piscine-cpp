#include <iostream>

/*
Write a function that prints 'T' (true) on a single line if the int passed as parameter is negative, otherwise it prints 'F' (false).
*/

namespace piscine 
{
    void IsNegative(int nb)
    {
        if (nb < 0) std::cout << "T\n" ;
        else std::cout << "F\n";
    }
}

int main()
{
    piscine::IsNegative(1);
	piscine::IsNegative(0);
	piscine::IsNegative(-1);

    return EXIT_SUCCESS;
}

