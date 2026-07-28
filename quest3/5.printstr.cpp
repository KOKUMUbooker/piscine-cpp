#include <iostream>
#include <string>

/*
Write a function that prints one by one the characters of a string on the screen.

Expected func in GO : 
func PrintStr(s string) {

}
*/

namespace piscine
{
    void PrintStr(const std::string& s)
    {
        // Index based looping
        // const auto sLen = s.size();
        // for (std::size_t i = 0; i < sLen; ++i) {
        //     std::cout << s[i];
        // }

        for (const char& charV : s) { // Use char& instead of char to avoid makinv charV copies on every iteration
            std::cout << charV;
        }
    }
}

int main()
{
    piscine::PrintStr("Hello World!");
    
    return EXIT_SUCCESS;
}