#include <iostream>
#include <vector>
#include <string>

/*
The restaurant employees are having a really tough day and are delivering the customers' food in the wrong order. 
You need to fix the problem so that they can deliver it correctly.

Write a function ReverseMenuIndex() that takes a slice of strings as an argument and returns 
another slice of strings with the menu in the correct order.

append() is not allowed for this exercise.
Expected function
func ReverseMenuIndex(menu []string) []string {

}

Usage (Go) :
fmt.Println(piscine.ReverseMenuIndex([]string{"desserts", "mains", "drinks", "starters"}))

Output :
[starters drinks mains desserts]
*/

namespace piscine
{
    std::vector<std::string> ReverseMenuIndex(const std::vector<std::string>& menu)
    {
        int len {static_cast<int>(menu.size())};
        std::vector<std::string> res (len);
        for(int i {len-1}; i >= 0; --i)
            res[(len-1)-i] = menu[i];

        return res;
    }

    void PrintVector(const std::vector<std::string>& vec)
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
    std::vector<std::string> a {"desserts", "mains", "drinks", "starters"};
    piscine::PrintVector(piscine::ReverseMenuIndex(a));

    return EXIT_SUCCESS;
}