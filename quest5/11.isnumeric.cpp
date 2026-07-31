#include <iostream>
#include <string>

/*
Write a function that returns true if the string passed as a parameter contains only numerical characters, otherwise, returns false.

Expected function
func IsNumeric(s string) bool {

}
*/

namespace piscine
{
    bool IsNumeric(std::string s)
    {
        for (const char& c : s)
        {
            if(!( c >= '0' && c <= '9' ))
                return false;
        }

        return true;
    }
} // namespace piscine


int main()
{
    std::cout << std::boolalpha; // Show true/false instead of 1/0

    std::cout << piscine::IsNumeric("010203") << "\n" ;
    std::cout << piscine::IsNumeric("01,02,03") << "\n" ;

    return EXIT_SUCCESS;
}