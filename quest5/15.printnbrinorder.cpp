#include <iostream>
#include <string>

/*
Write a function which prints the digits of an int passed in parameter in ascending order. All possible values of type int have to go through, excluding negative numbers. Conversion to int64 is not allowed.

Expected function
func PrintNbrInOrder(n int) {
}

Usage : 
piscine::PrintNbrInOrder(321)
piscine::PrintNbrInOrder(0)
piscine::PrintNbrInOrder(321)

Output:
1230123
*/

namespace piscine 
{
    std::string IntToString(const int n)
    {
      if (n == 0) return "0";

      std::string revNumStr {""};

      for (int quot {n}; quot != 0; quot /= 10)
      {
        int mod {quot % 10};
        revNumStr += '0' + mod;
      }

      std::string res {""};
      res.reserve(revNumStr.size());

      // Reverse the string
      for (auto it {revNumStr.rbegin()}; it != revNumStr.rend(); ++it)
        res += *it;

      return res;
    }

    void BubbleSortStr(std::string& s)
    {
        int n {static_cast<int>(s.size())};
        int end { n-1 };
        for (int i {0}; i < end; ++i)
        {
            for (int j {0}; j < end-i; ++j) // After every i pass, the (n-i)'th element is in the right place 
            {
                if (s[j] > s[j+1])
                {
                    char sJTemp {s[j]}, sJPlusTemp {s[j+1]};
                    s[j] = sJPlusTemp, s[j+1] = sJTemp; 
                }
            }
        }
    }

    void PrintNbrInOrder(int n)
    {
        std::string numStr {IntToString(n)};
        BubbleSortStr(numStr);
        std::cout << numStr;
    }
}

int main()
{
    piscine::PrintNbrInOrder(321);
    piscine::PrintNbrInOrder(0);
    piscine::PrintNbrInOrder(321);

    return EXIT_SUCCESS;
}