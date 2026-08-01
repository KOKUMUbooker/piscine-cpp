#include <iostream>
#include <string>

/*
Write a function that transforms numbers within a string, into an int.
If the - sign is encountered before any number it should determine the sign of the returned int.
This function should only return an int. In the case of an invalid input, the function should return 0.

Note: There will never be more than one sign in a string in the tests.
Expected function
func TrimAtoi(s string) int {

}

Usage : 
piscine::TrimAtoi("12345");
piscine::TrimAtoi("str123ing45");
piscine::TrimAtoi("012 345");
piscine::TrimAtoi("Hello World!");
piscine::TrimAtoi("sd+x1fa2W3s4");
piscine::TrimAtoi("sd-x1fa2W3s4");
piscine::TrimAtoi("sdx1-fa2W3s4");
piscine::TrimAtoi("sdx1+fa2W3s4");

Output :
12345
12345
12345
0
1234
-1234
1234
1234
*/

namespace piscine
{
    std::string ExtractNumbersAndSign(const std::string& s)
    {
        std::string res {""};
        for (const char& c : s)
        {
            if ((c >= '0' && c <= '9') || c == '-' || c == '+' )
                res += c;
        }

        return res;
    }

    void TrimStartingZeroes(std::string& s)
    {
        int start {-1}, size {static_cast<int>(s.size())};
        for (int i {0}; i < size; ++i)
        {
            if (start == -1 && (s[i] >= '1' && s[i] <= '9'))
                start = i;
        }
        if(start == -1)
            return;

        s = s.substr(start);
    }

    int Square(int n, int power)
    {
        if (power == 0) return 1;
        return n * Square(n, power-1);
    }

    int TrimAtoi(std::string s)
    {
        if(s == "" || s == " ") 
            return 0;
        
        s = ExtractNumbersAndSign(s);

        bool isNegative {s[0] == '-'};
        if (isNegative || s[0] == '+')
            s = s.substr(1);

        TrimStartingZeroes(s);
        
        int size {static_cast<int>(s.size())};
        if (size == 0)
            return 0;

        // "325"
        // 3 * 100 = 3 * 10 ^ 2(3-i+1) 
        // 2 * 10  = 2 * 10 ^ 1(3-i+1) 
        // 5 * 1   = 5 * 10 ^ 0(3-i+1) 

        int res {0};
        for (int i {0}; i < size; ++i)
        {
            int n { static_cast<int>(s[i] - '0') };
            int power {size - (i+1)};
            res += n * Square(10,power);
        }

        return isNegative ? -res : res;
    }
} // namespace piscine


int main()
{
    std::cout << piscine::TrimAtoi("12345") << "\n";
    std::cout << piscine::TrimAtoi("str123ing45") << "\n";
    std::cout << piscine::TrimAtoi("012 345") << "\n";
    std::cout << piscine::TrimAtoi("Hello World!") << "\n";
    std::cout << piscine::TrimAtoi("sd+x1fa2W3s4") << "\n";
    std::cout << piscine::TrimAtoi("sd-x1fa2W3s4") << "\n";
    std::cout << piscine::TrimAtoi("sdx1-fa2W3s4") << "\n";
    std::cout << piscine::TrimAtoi("sdx1+fa2W3s4") << "\n";

    return EXIT_SUCCESS;
}