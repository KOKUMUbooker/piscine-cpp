#include <iostream>
#include <vector>
#include <string>

/*
Write a function SortWordArr that sorts by ascii (in ascending order) a string slice.

Expected function
func SortWordArr(a []string) {

}

Usage (Go) :
result := []string{"a", "A", "1", "b", "B", "2", "c", "C", "3"}
piscine.SortWordArr(result)
fmt.Println(result)

Output : 
[1 2 3 A B C a b c]
*/

namespace piscine
{
    void SortWordArr(std::vector<std::string>& a)
    {
        int len {static_cast<int>(a.size())};
        for(int i {0}; i < len-1; ++i)
        {
            for(int j {0}; j < len-i-1; ++j)
            {
                if (a[j] > a[j+1])
                {
                    std::string temp {a[j]};
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }
    }

    void PrintVector(const std::vector<std::string>& vec)
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
    std::vector<std::string> result {"a", "A", "1", "b", "B", "2", "c", "C", "3"};
    piscine::SortWordArr(result);
    piscine::PrintVector(result);

    return EXIT_SUCCESS;
}