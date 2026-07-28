#include <iostream>

/*
Write a function that takes a pointer to an int as argument and gives to this int the value of 1.
*/

namespace piscine
{
    void PointOne(int* n)
    {
        *n = 1;
    }
}

int main()
{
    int n {0};
    piscine::PointOne(&n);

    std::cout << n;

    return EXIT_SUCCESS;
}