#include <iostream>

/*
Write a program that prints the arguments received in the command line in reverse order.
*/

int main(int argc, char* argv[])
{
    for (int i {argc-1}; i > 0; --i) // Exclude index 0 - the program name
        std::cout << argv[i] << "\n";

    return EXIT_SUCCESS;
}