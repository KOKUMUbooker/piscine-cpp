#include <iostream>
#include <string>

/*
Write a function that returns true if the string passed as the parameter contains only lowercase characters, otherwise, returns false.

Expected function
func IsLower(s string) bool {

}
*/

namespace piscine
{
    bool IsLower(std::string s)
    {
        for(const char& c : s)
        {
            if (!(c >= 'a' && c <= 'z'))
                return false;
        }

        return true;
    }
} // namespace piscine


int main()
{
    std::cout << std::boolalpha; // Show true/false instead of 1/0

    std::cout << piscine::IsLower("hello") << "\n" ;
    std::cout << piscine::IsLower("hello!") << "\n" ;
    std::cout << piscine::IsLower("heLLo") << "\n" ;

    return EXIT_SUCCESS;
}