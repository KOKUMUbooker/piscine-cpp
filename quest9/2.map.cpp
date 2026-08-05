#include <iostream>
#include <vector>
// #include <functional>

/*
Write a function Map that, for an int slice, applies a function of this type 
func(int) bool on each element of that slice and returns a slice of all the return values.

Expected function
func Map(f func(int) bool, a []int) []bool {
}

Usage (Go) : 
a := []int{1, 2, 3, 4, 5, 6}
result := piscine.Map(piscine.IsPrime, a)
fmt.Println(result)

Output : 
[false true true false true false]
*/

namespace piscine
{
    void PrintVector(const std::vector<bool>& vec)
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

    /* A prime number is a whole number greater than 1 that can only be divided evenly by 1 and itself */
    bool IsPrime(int nb)
    {
        if (nb < 2) return false; // 1 and below not prime
        if (nb == 2) return true; // 2 is the only prime
        if (nb % 2 == 0) return false; // Even numbers excluding 2 - not prime

        for (int i {2}; i <= nb-1; ++i) // More optimized : for (int i {2}; i*i <= nb; ++i)
        {
            // If a number excluding 1 and the number itself divides the number, its not a prime
            if (nb % i == 0) 
                return false; 
        }

        return true;
    }

    //std::vector<bool> Map(std::function<bool(int)> f, const std::vector<int>& a) // This also works
    std::vector<bool> Map(bool (*f)(int), const std::vector<int>& a)
    {
        std::vector<bool> res {};
        res.reserve(a.size());

        for (const int num : a)
            res.push_back(f(num));
        
        return res;
    }
}

int main()
{
    std::vector<int> a {1, 2, 3, 4, 5, 6};
    auto result {piscine::Map(piscine::IsPrime, a)};

    std::cout << std::boolalpha; // Enable printing of true/false instead of 0/1

    piscine::PrintVector(result);

    return EXIT_SUCCESS;
}