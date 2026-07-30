#include <iostream>
#include <string>

/*
Write a function that behaves like the Compare function in Go

Expected function
func Compare(a, b string) int {

}
*/

/*
1. The strings.Compare() FunctionThe strings.Compare(a, b) function evaluates two strings in lexicographical (alphabetical) order. 
    It is rarely used for simple equality checks because standard operators like == and < are faster and more readable. 
    However, it is highly useful when you need a custom sorting three-way result.
    
    Return Values:
        0 : If a == b
       -1 : If a < b
        1 : If a > b
*/

namespace piscine
{
    int Compare(std::string a, std::string b)
    {
        int aLen {static_cast<int>(a.size())};
        int bLen {static_cast<int>(b.size())};
        
        bool same {true};
        int least {aLen > bLen ? bLen : aLen};

        for (int i {0}; i < least; ++i)
        {
            char aChar {a[i]}, bChar {b[i]};

            if (aChar != bChar) 
                same = false;
            
            if (aChar > bChar)
                return 1;
            else if (bChar > aChar)
                return -1;
        }

        if (aLen > bLen)
            return 1;
        else if (bLen > aLen)
            return -1;
        else  // strings are equal
            return 0;
    }
} 

int main()
{
    std::cout << piscine::Compare("Hello!", "Hello!") << "\n";
    std::cout << piscine::Compare("Salut!", "lut!") << "\n";
    std::cout << piscine::Compare("Ola!", "Ol") << "\n";

    return EXIT_SUCCESS;
}