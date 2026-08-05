#include <iostream>
#include <vector>

/*
Write a function IsSorted() that returns true, if the slice of int is sorted, otherwise returns false.
The function passed as an argument func(a, b int) returns a positive int if the first argument 
is greater than the second argument, it returns 0 if they are equal and it returns a negative int otherwise.
To do your testing you have to write your own f function.

Expected function
func IsSorted(f func(a, b int) int, a []int) bool {

}

Usage (Go) :
a1 := []int{0, 1, 2, 3, 4, 5}
a2 := []int{0, 2, 1, 3}
result1 := IsSorted(f, a1)
result2 := IsSorted(f, a2)
fmt.Println(result1)
fmt.Println(result2)

Output :
true
false
*/

namespace piscine
{
    // returns 0 if equal, 1 if a > b and -1 if a < b
    int f (int a, int b)
    {
        if (a > b)
            return 1;
        else if (a < b)
            return -1;
        else 
            return 0;
    } 
    
    bool IsSorted(int (*Compare)(int,int), std::vector<int> a)
    {
        int len {static_cast<int>(a.size())};

        for (int i {0}; i < len; ++i)
        {
            if ((i+1) < (len-1) && Compare(a[i],a[i+1]) == 1)
                return false;
        }
        return true;
    }
} // namespace piscine


int main()
{

    std::vector<int> a1 {0, 1, 2, 3, 4, 5};
    std::vector<int> a2 {0, 2, 1, 3};

    std::cout << std::boolalpha; // Enable printing of true/false instead of 0/1

    bool result1 {piscine::IsSorted(piscine::f, a1)};
    bool result2 {piscine::IsSorted(piscine::f, a2)};

    std::cout << result1 << "\n";
    std::cout << result2 << "\n";

    return EXIT_SUCCESS;
}