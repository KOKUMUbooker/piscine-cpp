#include <iostream>
#include <string>
#include <vector>

/*
Write a program that prints the arguments received in the command line in ASCII order.

Usage : 
./out 1 a 2 A 3 b 4 C

Output : 
1
2
3
4
A
C
a
b
*/

void bubbleSort(std::vector<std::string>& args)
{
    for (std::size_t i = 0; i < args.size() - 1; ++i)
    {
        for (std::size_t j = 0; j < args.size() - i - 1; ++j)
        {
            if (args[j] > args[j + 1])
            {
                std::swap(args[j], args[j + 1]);
            }
        }
    }
}

int main(int argc, char* argv[])
{
    // slice argv from index 1(argv + 1) to the last element (argv + argc)
    std::vector<std::string> args(argv + 1, argv + argc);

    bubbleSort(args);

    for (const auto& arg : args)
        std::cout << arg << '\n';
}