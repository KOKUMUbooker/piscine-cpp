#include <iostream>

/*
Write a program that prints the Latin alphabet in lowercase in reverse order (from 'z' to 'a') on a single line.
A line is a sequence of characters preceding the end of line character ('\n').
Please note that casting is not allowed for this exercise!
*/ 

int main()
{
    for (char i = 'z'; i >= 'a'; i--)
    {
        std::cout << i;
    }
    std::cout << '\n';

    return EXIT_SUCCESS;
}