#include <iostream>

/*
Write a function that returns the square root of the int passed as parameter, if that square root is a whole number. 
Otherwise it returns 0.

Expected function
func Sqrt(nb int) int {

}
*/

namespace piscine
{
    int Sqrt(int nb)
    {
        int n {1};

        while (true)
        {
            if(n*n == nb) break; // perfect square
            if(n*n > nb) return 0; // Square root will end up not being a whole number
            ++n;
        }

        return n;
    }
}

int main()
{
    std::cout << piscine::Sqrt(4) << "\n";
    std::cout << piscine::Sqrt(3) << "\n";

    return EXIT_SUCCESS;
}