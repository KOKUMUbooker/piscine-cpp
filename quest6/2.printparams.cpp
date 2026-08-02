#include <iostream>

/*
Write a program that prints the arguments received in the command line.
*/

int main(int argc, char* argv[])
{
    for(int i {1}; i < argc; ++i)
        std::cout << argv[i] << "\n";

    return EXIT_SUCCESS;
}