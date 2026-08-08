#include <iostream>
#include <string>

/*
Write a function LoafOfBread() that takes a string and returns another one with words of 5 characters 
and skips the next character followed by newline \n.
If there is a space in the middle of a string it should ignore it and get the next character until getting to a length of 5.
If the string is less than 5 characters return "Invalid Output\n".

Expected function
func LoafOfBread(str string) string {

}

Usage (Go) :
fmt.Print(piscine.LoafOfBread("deliciousbread"))
fmt.Print(piscine.LoafOfBread("This is a loaf of bread"))
fmt.Print(piscine.LoafOfBread("loaf"))

Output :
delic ousbr ad
Thisi aloaf ofbre d
Invalid Output
*/

namespace piscine
{
    std::string LoafOfBread(const std::string str)
    {
        int len {static_cast<int>(str.size())};
        if (len < 5)
            return "Invalid Output\n";

        std::string res {""};
        res.reserve(len);
        int count {1};
        for (int i {0}; i < len; ++i)
        {
            if (count == 6)
            {
                res += ' ';
                count = 1; // Reset count
                continue;
            }

            if (str[i] != ' ')
            {
                res += str[i];
                ++count;
            }
        }

        return res + "\n";
    }
} // namespace piscine


int main()
{
    std::cout << piscine::LoafOfBread("deliciousbread");
    std::cout << piscine::LoafOfBread("This is a loaf of bread");
    std::cout << piscine::LoafOfBread("loaf");

    return EXIT_SUCCESS;
}