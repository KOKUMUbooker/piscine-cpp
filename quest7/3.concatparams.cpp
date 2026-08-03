#include <iostream>
#include <string>
#include <vector>

/*
Write a function ConcatParams that takes a slice of strings as input and returns a single string made by concatenating all elements of the slice separated by a newline (\n).

Expected function
func ConcatParams(args []string) string {

*/

namespace piscine
{
    std::string ConcatParams(const std::vector<std::string>& args)
    {
        std::string res {""};
        int size {static_cast<int>(args.size())};
        for (int i {0}; i < size; ++i)
        {
            res += args[i];
            if (i != (size-1))
                res += '\n';
        }
        return res;
    }
} // namespace piscine

int main()
{
    std::vector<std::string> test {"Hello", "how", "are", "you?"};
    std::cout << piscine::ConcatParams(test) << "\n";

    return EXIT_SUCCESS;
}