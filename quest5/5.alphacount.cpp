#include <iostream>
#include <string>

/*
Write a function that counts the number of letters in a string and returns the count.
Only letters from the Latin alphabet (a–z and A–Z) must be counted. 
All other characters (digits, symbols, spaces, etc.) must be ignored.

Expected function
func AlphaCount(s string) int {

}
*/

namespace piscine
{
    int AlphaCount(std::string s)
    {
        int count {0};
        for (const char& sChar : s)
        {
            if ((sChar >= 'a' && sChar <= 'z') || (sChar >= 'A' && sChar <= 'Z'))
                ++count;
        }

        return count;
    }
}  


int main()
{
    std::string s {"Hello 78 World!    4455 /"};
    std::cout << piscine::AlphaCount(s) << "\n";

    return EXIT_SUCCESS;
}