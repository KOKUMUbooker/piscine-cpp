#include <iostream>

/*
Write a function that returns the first prime number that is equal or superior to the int passed as parameter.
The function must be optimized in order to avoid time-outs with the tester.
(We consider that only positive numbers can be prime numbers)

Expected function
func FindNextPrime(nb int) int {

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

        for (int i {2}; i*i <= nb; ++i)
        {
            // If a number excluding 1 and the number itself divides the number, its not a prime
            if (nb % i == 0) 
                return false; 
        }

        return true;
    }

    int FindNextPrime(int nb)
    {
        if(IsPrime(nb)) return nb;

        for (int i {nb+1} ; ; ++i)
        {
            if(IsPrime(i)) return i;
        }
    }
}

int main()
{
    std::cout << piscine::FindNextPrime(5) << "\n"; 
    std::cout << piscine::FindNextPrime(6) << "\n"; 

    return EXIT_SUCCESS;
}