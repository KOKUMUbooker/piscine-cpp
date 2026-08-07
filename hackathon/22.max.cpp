#include <iostream>
#include <vector>

/*
Write a function Max that will return the maximum value in a slice of integers. If the slice is empty it will return 0.

Expected function
func Max(a []int) int {

}

Usage (Go) :
a := []int{23, 123, 1, 11, 55, 93}
max := piscine.Max(a)
fmt.Println(max)

Output :
123
*/

namespace piscine
{
    int Max(const std::vector<int>& a)
    {
        int len {static_cast<int>(a.size())};
        if (len == 0)
            return -1;

        int max {a[0]};
        for (const int& n : a)
        {
            if (n > max)
                max = n;
        }

        return max;
    }
} // namespace piscine


int main()
{
    std::vector<int> a {23, 123, 1, 11, 55, 93};
    int max {piscine::Max(a)};
    std::cout << max << "\n";

    return EXIT_SUCCESS;
}