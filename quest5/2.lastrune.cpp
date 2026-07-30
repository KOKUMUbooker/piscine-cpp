#include <iostream>
#include <string>

/*
Write a function that returns the last rune of a string.

Expected function
func LastRune(s string) rune {

}
*/

namespace piscine
{
    char LastRune(std::string s)
    {
        std::size_t sLen = s.size();
        if (sLen == 0) return '-';

        return s[sLen-1];
    }
}

int main()
{
    std::cout << piscine::LastRune("Hello!") << "\n" ;
    std::cout << piscine::LastRune("Salut!") << "\n" ;
    std::cout << piscine::LastRune("Ola!") << "\n" ;

    return EXIT_SUCCESS;
}