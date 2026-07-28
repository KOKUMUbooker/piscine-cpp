#include <iostream>

/*
Write a function that takes two pointers to an int (*int) and swaps their contents.
Expected function in Go :
func Swap(a *int, b *int) {

}
*/

namespace piscine
{
    void Swap(int* a, int* b)
    {
        int aTemp {*a}, bTemp {*b};
        *a = bTemp, *b = aTemp;
    }
}

int main()
{
    int a {3}, b {5};
    std::cout << "Before a : " << a << ", b : " << b << "\n"; 
    piscine::Swap(&a,&b);
    std::cout << "After a : " << a << ", b : " << b << "\n"; 
    return EXIT_SUCCESS;
}