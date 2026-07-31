#include <iostream>
#include <string>

/*
Write a function that returns true if the string passed as parameter contains only uppercase characters, otherwise, returns false.

Expected function
func IsUpper(s string) bool {

}
*/

namespace piscine
{   
    bool IsUpper(std::string s)
    {
        for(char& c : s)
        {
            if (!(c >= 'A' && c <= 'Z'))
                return false;
        }

        return true;
    }
} // namespace piscine


int main()
{
    std::cout << std::boolalpha; // Show true/false instead of 1/0

    std::cout << piscine::IsUpper("HELLO") << "\n" ;
    std::cout << piscine::IsUpper("HELLO!") << "\n" ;
    std::cout << piscine::IsUpper("Hello") << "\n" ;

    return EXIT_SUCCESS;
}