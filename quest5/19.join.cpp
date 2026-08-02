#include <iostream>
#include <vector>
#include <string>

/*
Write a function that returns the concatenation of all the strings of a slice of strings separated by the separator passed as the argument sep.

Expected function
func Join(strs []string, sep string) string {

}

Usage (In GO) : 
toConcat := []string{"Hello!", " How", " are", " you?"}
fmt.Println(piscine.Join(toConcat, ":"))

Output : 
Hello!: How: are: you?
*/

namespace piscine
{
    std::string Join(const std::vector<std::string>& strs, std::string sep)
    {
        std::string res {""};
        int len {static_cast<int>(strs.size())};
        
        for (int i {0}; i < len; ++i)
        {
            res += strs.at(i);
            if (i != len-1)
                res += sep;
        }

        return res;
    }
} // namespace piscine

int main()
{
    std::vector<std::string> toConcat {"Hello!", " How", " are", " you?"};
    std::cout << piscine::Join(toConcat, ":") << "\n";

    return EXIT_SUCCESS;
}