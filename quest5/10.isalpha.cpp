#include <iostream>
#include <string>

/*
Write a function that returns true if the string passed as the parameter only contains alphanumerical characters or is empty, and returns false otherwise.

Expected function
func IsAlpha(s string) bool {

}
*/

namespace piscine
{
    bool IsAlpha(std::string s)
    {
        for (const char& c : s)
        {
            // bool isLower { c >= 'a' && c <= 'z' };
            // bool isUpper { c >= 'A' && c <= 'Z' };
            // bool isNum { c >= '0' && c <= '9' };
            // If neither upper, lower nor number, return false
            if (!( (c >= 'a' && c <= 'z') ||  ( c >= 'A' && c <= 'Z') ||  c >= '0' && c <= '9'))
                return false;
        }

        return true;
    }
} // namespace piscine


int main()
{
    std::cout << std::boolalpha; // Show true/false instead of 1/0

    std::cout << piscine::IsAlpha("Hello! How are you?") << "\n" ;
    std::cout << piscine::IsAlpha("HelloHowareyou") << "\n" ;
    std::cout << piscine::IsAlpha("What's this 4?") << "\n" ;
    std::cout << piscine::IsAlpha("Whatsthis4") << "\n" ;

    return EXIT_SUCCESS;
}