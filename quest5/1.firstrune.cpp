#include <iostream>
#include <string>

/*
Write a function that returns the first rune of a string.

Expected function
func FirstRune(s string) rune {

}
*/

namespace piscine
{
    char FirstRune(const std::string& s)
    {
        if (s == "") return '0';
        return s[0];
    }
} 

int main()
{
    std::cout << piscine::FirstRune("Hello!") << "\n" ;
    std::cout << piscine::FirstRune("Salut!") << "\n" ;
    std::cout << piscine::FirstRune("Ola!") << "\n" ;

    return EXIT_SUCCESS;
}