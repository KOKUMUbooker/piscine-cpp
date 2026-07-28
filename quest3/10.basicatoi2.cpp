#include <iostream>
#include <string>
#include <vector>

/*
Write a function that simulates a simplified version of Go's strconv.Atoi function.
The function must convert a number represented as a string into an int.
    If the string is not a valid numeric representation, the function must return 0.
    The string may contain non-digit characters; such strings are considered invalid.
    Handling of the + or - signs is not required.
    The function must return only the integer value; error handling is not required.

Expected function
func BasicAtoi2(s string) int {

}
*/

namespace piscine
{
    std::string RemoveFrontZeroes(const std::string& s)
    {
        std::size_t start {0}, sLen {s.size()};

        while (start < sLen)
        {
            if (s[start] >= '1' && s[start] <= '9') break;
            ++start;
        }

        return s.substr(start);
    }

    int square(int base, int exp)
    {
        if (exp == 0) return 1;
        if (exp == 1) return base;
        return base * square(base,exp-1);
    }

    bool AreAllNumbers(const std::string& s)
    {
        for (const char& charV : s)
        {
            if (!(charV >= '0' && charV <= '9')) 
                return false;
        }
        return true;
    }

    int BasicAtoi2(std::string s)
    {
        if (!AreAllNumbers(s)) return 0;

        s = RemoveFrontZeroes(s);
        if (s == "0") return 0;

        std::vector<int> nums {};
        for (const char& numChar : s)
        {
            int num { numChar - '0'}; // Convert char to int
            nums.push_back(num);
        }

        int num {0};
        int sLen {static_cast<int>(s.size())};
        for (int i {0}; i < sLen; ++i)
        {
            int exp {sLen - (i+1)}; // eg if 325, 3 will be -> 3 * 100 -> 3 * 10^2
            num += nums[i] * square(10,exp);
        }

        return num;
    }
}


int main()
{
    std::cout << piscine::BasicAtoi2("12345") << "\n";
    std::cout << piscine::BasicAtoi2("0000000012345") << "\n";
    std::cout << piscine::BasicAtoi2("012 345") << "\n";
    std::cout << piscine::BasicAtoi2("Hello World!") << "\n";

    return EXIT_SUCCESS;
}