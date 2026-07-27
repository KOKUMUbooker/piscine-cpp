#include <iostream>
/*
    Write a program that prints the Latin alphabet in lowercase on a single line.
    A line is a sequence of characters preceding the end of line character ('\n').
*/

int main()
{
    for (char i = 'a'; i <= 'z'; i++) 
    {
        std::cout << i ;
    }

    std::cout << '\n' ;

    return EXIT_SUCCESS;
}
