#include <iostream>
#include <string>

/*
Write a function that returns true if the string passed as a parameter contains only printable characters, otherwise, returns false.

Expected function
func IsPrintable(s string) bool {

}
*/

// 0–31 & 127: Characters outside the 32–126 range are non-printing control characters (like Newline \n, Tab \t, and Backspace).
// 127: This is the DEL (Delete) control character. 
namespace piscine
{
    bool IsPrintable(std::string s) // Are values from 32(' ') to 126('~')
    {
        for (const char& c : s)
        {
            // if (!(c >= ' ' && c <= '~')) // Cna be written like this
            if (!(c >= 32 && c <= 126))
                return false;
        }

        return true;
    }
} // namespace piscine


int main()
{
    std::cout << std::boolalpha; // Show true/false instead of 1/0

    // char x {126};
    // std::cout << x;

    std::cout << piscine::IsPrintable("Hello") << "\n" ;
    std::cout << piscine::IsPrintable("Hello\n") << "\n" ;

    return EXIT_SUCCESS;
}