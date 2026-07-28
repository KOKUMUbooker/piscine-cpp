#include <iostream>
#include <string>

/*
Write a function that reverses a string.
This function will return the reversed string.

Expected function
func StrRev(s string) string {

}
*/

namespace piscine
{
    std::string StrRev(const std::string& str)
    {
       std::string res {""};
      
       for (auto it {str.rbegin()}; it != str.rend(); ++it)
            res += *it;
       
        return res;
    }
}

int main()
{
    std::string str {"Hello World!"};
    std::cout << piscine::StrRev(str);

    return EXIT_SUCCESS;
}