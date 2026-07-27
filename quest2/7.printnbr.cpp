#include <iostream>
#include <vector>
#include <algorithm>

/*
Write a function that prints an int passed in parameter. All possible values of type int have to go through. You cannot convert to int64.

Try and do it as though the only way to display items is via individual char items. 
- Weird way to do it as You could just do std::cout << number;
- Try to mimick the zones piscine restriction ie z01.PrintRune('\n')
eg
	piscine::PrintNbr(-123)
	piscine::PrintNbr(0)
	piscine::PrintNbr(123)

    returns
    -1230123
*/

namespace piscine 
{
    char ConvertIntToChar(int n)
    {
        return static_cast<char>('0' + n );
    }

    void PrintNbr(int n)
    {
        if (n == 0)
        {
            std::cout << ConvertIntToChar(n); 
            return;
        }

        bool isNegative = n < 0;
        std::vector<int> splitNums {};

        for (int quot = n; quot != 0; quot = quot / 10)
        {
            int mod = quot % 10;
            splitNums.push_back(isNegative ? -mod : mod);
        }

        if (isNegative) std::cout << "-";

        // Loop in reverse
        std::for_each(splitNums.rbegin(), splitNums.rend(), [](int item){
            std::cout << ConvertIntToChar(item);
        });
    }

    void PrintChar(char r)
    {
        std::cout << r;
    }
}

int main()
{
	piscine::PrintNbr(-123);
	piscine::PrintNbr(0);
	piscine::PrintNbr(123);
	piscine::PrintNbr(500);
	piscine::PrintNbr(-299);
    piscine::PrintChar('\n');

    return EXIT_SUCCESS;
}

// 125 / 10 = 12.5
// 12  / 10 = 1.2
// 1   / 10 = 0.1

// 125 % 10 = 5
// 12  % 10 = 2
// 1   % 10 = 1