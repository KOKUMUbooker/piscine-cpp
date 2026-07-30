#include <iostream>
#include <string>

/*
Write a function that returns the concatenation of two strings passed in arguments.

Expected function
func Concat(str1 string, str2 string) string {

}
*/

namespace piscine
{
    std::string Concat(std::string str1, std::string str2)
    {
        return str1 + str2;
    }
}

int main()
{
    std::cout << piscine::Concat("Hello!", " How are you?") << "\n";

    return EXIT_SUCCESS;
}