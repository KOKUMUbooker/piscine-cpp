#include <iostream>
#include <string>

/*
Write a function that counts the runes of a string and that returns that count.
Expected function in Go : 
func StrLen(s string) int {

}
*/

namespace piscine
{
    int StrLen(const std::string s)
    {
        if (s.size() == 0) return 0;
        int count {0};

        for (const char& c : s) 
            ++count;
            
        return count;
    }
}

int main()
{
    int len = piscine::StrLen("Hello World!");
    std::cout << len;

    return EXIT_SUCCESS;
}