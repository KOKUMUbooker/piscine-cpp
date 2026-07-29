#include <iostream>

/*
Write a function that returns true if the int passed as parameter is a prime number. Otherwise it returns false.
The function must be optimized in order to avoid time-outs with the tester.
(We consider that only positive numbers can be prime numbers)
(We also consider that 1 is not a prime number)

Expected function
func IsPrime(nb int) bool {

}
*/

namespace piscine
{
    /* A prime number is a whole number greater than 1 that can only be divided evenly by 1 and itself */
    bool IsPrime(int nb)
    {
        if (nb < 2) return false; // 1 and below not prime
        if (nb == 2) return true; // 2 is the only prime
        if (nb % 2 == 0) return false; // Even numbers excluding 2 - not prime

        for (int i {2}; i <= nb-1; ++i) // More optimized : for (int i {2}; i*i <= nb; ++i)
        {
            // If a number excluding 1 and the number itself divides the number, its not a prime
            if (nb % i == 0) 
                return false; 
        }

        return true;
    }
}

int main()
{
    // Enable text output for booleans
    std::cout << std::boolalpha; 

    std::cout << piscine::IsPrime(5) << "\n";
    std::cout << piscine::IsPrime(4) << "\n";
    std::cout << piscine::IsPrime(2) << "\n";
    std::cout << piscine::IsPrime(3) << "\n";

    return EXIT_SUCCESS;
}