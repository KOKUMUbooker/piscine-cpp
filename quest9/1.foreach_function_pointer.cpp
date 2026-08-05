#include <iostream>
#include <vector>

/*
Write a function ForEach that, for an int slice, applies a function on each element of that slice.

Expected function
func ForEach(f func(int), a []int) {

}

Usage (Go) :
a := []int{1, 2, 3, 4, 5, 6}
piscine.ForEach(piscine.PrintNbr, a)

Ooutput:
123456
*/

namespace piscine
{
    void ForEach(void (*func)(int), const std::vector<int>& nums)
    {
        for (const int& n : nums)
            func(n);
    }

    void PrintNbr(int n)
    {
        std::cout << n ;
    }
    
} // namespace piscine


int main()
{
    // Declare function pointer named PrintFunc to store the PrintNbr func
    void (*PrintFunc)(int) = piscine::PrintNbr;
    std::vector<int> a = {1, 2, 3, 4, 5, 6};

    piscine::ForEach(PrintFunc,a);

    return EXIT_SUCCESS;
}