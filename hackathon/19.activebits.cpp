#include <iostream>

/*
Write a function ActiveBits that returns the number of active bits (bits with the value 1) in the binary representation of an integer.

Expected function
func ActiveBits(n int) int {

}

Usage (Go) :
fmt.Println(piscine.ActiveBits(7))

Output :
3
*/

namespace piscine
{
    int ActiveBits(int n)
    {
        int count {0};

        for (int quot {n}; quot != 0; quot /= 2)
        {
            int mod {quot % 2};
            if (mod == 1)
                ++count;
        }

        return count;
    }
} // namespace piscine


int main()
{
    std::cout << piscine::ActiveBits(7);

    return EXIT_SUCCESS;
}