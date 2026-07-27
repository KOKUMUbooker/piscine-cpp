#include <iostream>

int main()
{
    for (char i = 'z'; i >= 'a'; i--)
    {
        std::cout << i;
    }
    std::cout << '\n';

    return EXIT_SUCCESS;
}