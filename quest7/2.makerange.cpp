#include <iostream>
#include <vector>

/*
Write a function that takes an int min and an int max as parameters. The function must return a slice of ints with all the values between min and max.
Min is included, and max is excluded.
If min is greater than or equal to max, a nil slice is returned.
append is not allowed for this exercise.

Expected function
func MakeRange(min, max int) []int {

}
*/


namespace piscine
{
    std::vector<int> MakeRange(int min, int max)
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
    std::vector<int> a {piscine::MakeRange(5, 10)};
    std::vector<int> b {piscine::MakeRange(10, 5)};

    piscine::PrintVector(a);
    piscine::PrintVector(b);

    return EXIT_SUCCESS;
}