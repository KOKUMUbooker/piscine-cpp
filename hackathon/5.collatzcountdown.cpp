#include <iostream>

/*
Write a function, CollatzCountdown, that returns the number of steps necessary to reach 1 using the collatz countdown.
It must return -1 if start is equal to 0 or negative.

Expected function
func CollatzCountdown(start int) int {

}

Usage : 
steps := piscine.CollatzCountdown(12)
fmt.Println(steps)

Output : 
9
*/

namespace piscine
{
    int CollatzCountdown(int start)
    {
        if (start <= 0)
            return -1;

        int count {0};
        while (start > 1)
        {
            if (start % 2 == 0)
                start = start / 2;
            else 
                start = (start * 3) + 1;

            ++count;
        }

        return count;
    }
} // namespace piscine


int main()
{
    std::cout << piscine::CollatzCountdown(12);

    return EXIT_SUCCESS;
}