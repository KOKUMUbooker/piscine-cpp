#include <iostream>
#include <vector>

/*
Write a function that takes two integers, min and max, as parameters and returns a 
slice of integers containing all values from min (inclusive) to max (exclusive).
If min is greater than or equal to max, the function must return a nil slice.
The use of make is not allowed for this exercise.

Expected function
func AppendRange(min, max int) []int {

}

Usage (Go) : 
fmt.Println(piscine.AppendRange(5, 10))
fmt.Println(piscine.AppendRange(10, 5))

Output : 
[5 6 7 8 9]
[]
*/

namespace piscine
{
    std::vector<int> AppendRange(int min, int max)
    {
        if (min > max || min == max)
            return std::vector<int> {};   
            
        std::vector<int> res {};
        res.reserve(max-min);

        for (int i {min}; i < max; ++i)
            res.push_back(i);
        
        return res;
    }

    void PrintVector(const std::vector<int>& vec)
    {
        int len {static_cast<int>(vec.size())};
        std::cout << "[";
        for(int i {0}; i < len; ++i)
        {
            std::cout << vec.at(i);
            if (i != len-1)
                std::cout << ", ";
        }
        std::cout << "]\n";
    }
} // namespace piscine


int main()
{
    std::vector<int> a {piscine::AppendRange(5, 10)};
    std::vector<int> b {piscine::AppendRange(10, 5)};

    piscine::PrintVector(a);
    piscine::PrintVector(b);

    return EXIT_SUCCESS;
}