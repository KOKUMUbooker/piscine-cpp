#include <iostream>
#include <string>

/*
Write a function that behaves like the Index function.

Expected function
func Index(s string, toFind string) int {

}
*/

namespace piscine
{
    int Index(std::string s, std::string toFind)
    {
        int sLen {static_cast<int>(s.size())};
        int tLen {static_cast<int>(toFind.size())};

        if (sLen == 0 && tLen == 0) return -1;
        if (tLen == 0) return -1;

        for (int i {0}; i < sLen; ++i )
        {
            if (s[i] == toFind[0])
                return i;
        }

        return -1;
    }
}

int main()
{
    std::cout << piscine::Index("Hello!", "l") << "\n";
    std::cout << piscine::Index("Salut!", "alu") << "\n";
    std::cout << piscine::Index("Ola!", "hOl") << "\n";

    return EXIT_SUCCESS;
}