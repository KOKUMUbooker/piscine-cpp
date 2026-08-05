#include <iostream>
#include <vector>
#include <functional>

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

/*
, a single std::function variable can uniformly hold:Regular functionsLambda expressionsFunctors (classes overloading operator())Pointers to member functions
*/

namespace piscine
{
    void ForEach(std::function<void(int)> func, const std::vector<int>& nums)
    {
        for (const int& n : nums)
            func(n);
    }
} // namespace piscine


int main()
{
    // // Declare function pointer named PrintFunc to store the PrintNbr func
    // void (*PrintFunc)(int) = piscine::PrintNbr;
    
    // Syntax: std::function<Return_Type(Parameter_Types...)> name;
    std::function<void(int)> PrintFunc = [](int n){ std::cout << n; }; // lambda

    std::vector<int> a = { 1, 2, 3, 4, 5, 6 };

    piscine::ForEach(PrintFunc, a);

    return EXIT_SUCCESS;
}