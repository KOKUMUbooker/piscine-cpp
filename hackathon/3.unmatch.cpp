#include <iostream>
#include <vector>
#include <map>

/*
Write a function, Unmatch, that returns the element of the slice that does not have a correspondent pair.
If all the number have a correspondent pair, it should return -1.

Expected function
func Unmatch(a []int) int {

}

Usage (Go) :
a := []int{1, 2, 3, 1, 2, 3, 4}
unmatch := piscine.Unmatch(a)
fmt.Println(unmatch)

Output : 
4
*/

namespace piscine
{
    int Unmatch(const std::vector<int>& a)
    {
        std::map<int,int> freq {};
        for (const int& n : a)
        {
            auto val = freq.extract(n);
            if (val.empty())
                freq[n] = 1;
            else 
                freq[n] = ++freq[n];
        }

        for (std::pair<int,int> x : freq)
        {
            if (x.second == 1)
                return x.first;
        }

        return -1;
    }
} // namespace piscine


int main()
{
    std::vector<int> a {1, 2, 3, 1, 2, 3, 4};
    int unmatch {piscine::Unmatch(a)};
    std::cout << unmatch ;

    return EXIT_SUCCESS;
}