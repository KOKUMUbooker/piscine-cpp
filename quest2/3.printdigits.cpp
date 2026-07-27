#include <iostream>

/*
Write a program that prints the decimal digits in ascending order (from 0 to 9) on a single line.
A line is a sequence of characters preceding the end of line character ('\n').
*/

int main()
{
    for (short i = 0; i <= 9; i++)
    {
        std::cout << i;
    }
    std:: cout << "\n";

    return EXIT_SUCCESS;
}