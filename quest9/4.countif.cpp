#include <iostream>
#include <string>
#include <vector>

/*
Write a function CountIf that counts how many elements in a slice of strings satisfy a given condition.
The function must apply f to each element of the slice and return the number of elements for 
which f returns true. If the slice is empty, the function must return 0.

Expected function
func CountIf(f func(string) bool, tab []string) int {

}

Usage (Go) :
tab1 := []string{"Hello", "how", "are", "you"}
tab2 := []string{"This","1", "is", "4", "you"}
answer1 := piscine.CountIf(piscine.IsNumeric, tab1)
answer2 := piscine.CountIf(piscine.IsNumeric, tab2)
fmt.Println(answer1)
fmt.Println(answer2)

Output :
0
2
*/

namespace piscine
{
    bool IsNumeric(std::string s)
    {
        for (const char& c : s)
        {
            if(!( c >= '0' && c <= '9' ))
                return false;
        }

        return true;
    }

    int CountIf(bool (*f)(std::string), const std::vector<std::string>& tab)
    {
        int count {0};

        for (const std::string& s : tab)
            if(f(s)) count++;

        return count;
    }
} // namespace piscine


int main()
{
    std::vector<std::string> tab1 {"Hello", "how", "are", "you"};
    std::vector<std::string> tab2 {"This","1", "is", "4", "you"};

    int answer1 {piscine::CountIf(piscine::IsNumeric, tab1)};
    int answers {piscine::CountIf(piscine::IsNumeric, tab2)};

    std::cout << answer1 << "\n";
    std::cout << answers << "\n";

    return EXIT_SUCCESS;
}