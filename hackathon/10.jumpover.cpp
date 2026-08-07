#include <iostream>
#include <string>

/*
Write a function JumpOver() that takes a string and returns another string with every third character.
Prints the output followed by newline \n.
If the string is empty, return newline \n.
If there is no third character, return newline \n.

Expected function
func JumpOver(str string) string {

}

Usage (Go) :
fmt.Print(piscine.JumpOver("1010101010"))
fmt.Print(piscine.JumpOver(""))
fmt.Print(piscine.JumpOver("t w e l v e"))
fmt.Print(piscine.JumpOver("12"))

Output :
101

w v

*/

namespace piscine
{
    std::string JumpOver(const std::string str)
    {
        int len {static_cast<int>(str.size())};
        if (len < 3)
            return "\n";

        std::string res {""};
        for (int i {0}; i < len; ++i)
        {
            if ((i+1) % 3 == 0)
                res += str[i];
        }

        return res + "\n";
    }
} // namespace piscine

int main()
{
    std::cout << piscine::JumpOver("1010101010");   
    std::cout << piscine::JumpOver(""); 
    std::cout << piscine::JumpOver("t w e l v e");  
    std::cout << piscine::JumpOver("12");   

    return EXIT_SUCCESS;
}