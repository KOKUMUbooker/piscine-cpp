#include <iostream>
#include <vector>

/*
Write a function that generates a slice of integers in descending order.
The function takes two integers as parameters: max and min. It returns a slice of integers 
containing all the values from max down to min, in decreasing order.
    The max value must be included in the result.
    The min value must not be included.
    If max is less than or equal to min, the function must return an empty slice.

Expected function
func DescendAppendRange(max, min int) []int {

}

Usage (Go) :
fmt.Println(piscine.DescendAppendRange(10, 5))
fmt.Println(piscine.DescendAppendRange(5, 10))

Output : 
[10 9 8 7 6]
[]
*/

namespace piscine
{
    std::vector<int> DescendAppendRange(int max, int min)
    {
        std::vector<int> res {};
        if (max <= min)
            return res;
        
        for (int i {max}; i > min; --i)
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
                std::cout << " ";
        }
        std::cout << "]\n";
    }
} // namespace piscine

int main()
{
    piscine::PrintVector(piscine::DescendAppendRange(10, 5));
    piscine::PrintVector(piscine::DescendAppendRange(5, 10));

    return EXIT_SUCCESS;
}