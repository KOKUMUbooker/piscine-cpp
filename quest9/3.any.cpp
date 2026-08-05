#include <iostream>
#include <vector>
#include <string>

/*
Write a function Any that returns true if at least one element of a slice of strings satisfies a given function f.
The function f is applied to each element of the slice and returns a boolean value.

Expected function
func Any(f func(string) bool, a []string) bool {

}

Usage (Go) : 
a1 := []string{"Hello", "how", "are", "you"}
a2 := []string{"This", "is", "4", "you"}

result1 := piscine.Any(piscine.IsNumeric, a1)
result2 := piscine.Any(piscine.IsNumeric, a2)

fmt.Println(result1)
fmt.Println(result2)

Output :
false
true
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
    
    bool Any(bool (*f)(std::string), const std::vector<std::string>& a)
    {
        for (const std::string& s : a)
        {
            if (f(s)) 
                return true;
        }

        return false;
    }
} // namespace piscine


int main()
{
    std::vector<std::string> a1 {"Hello", "how", "are", "you"};
    std::vector<std::string> a2 {"This", "is", "4", "you"};

    std::cout << std::boolalpha; // Enable printing of true/false instead of 0/1

    bool result1 {piscine::Any(piscine::IsNumeric, a1)};
    bool result2 {piscine::Any(piscine::IsNumeric, a2)};

    std::cout << result1 << "\n";
    std::cout << result2 << "\n";

    return EXIT_SUCCESS;
}