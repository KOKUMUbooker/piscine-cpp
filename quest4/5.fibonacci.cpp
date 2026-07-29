#include <iostream>

/*
Instructions
Write a recursive function that returns the value at the position index in the fibonacci sequence.
The first value is at index 0.
The sequence starts this way: 0, 1, 1, 2, 3 etc...
A negative index will return -1.
for is forbidden for this exercise.

Expected function
package piscine

func Fibonacci(index int) int {

}
*/

namespace piscine
{
    /* F(n) = F(n-1)+F(n-2) */
    /* eg 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ... */
    // F(0) = 0
    // F(1) = 1
    // F(2) = F(1) + F(0)
    // F(3) = F(2) + F(1)
    int Fibonacci(int index)
    {
        if (index == 0) return 0;
        if (index == 1) return 1;

        return Fibonacci(index-1) + Fibonacci(index-2);
    }
}

int main()
{
    std::cout << piscine::Fibonacci(4) << "\n";

    return EXIT_SUCCESS;
}