#include <string>
#include <vector>
#include "include/utils.hpp"

// Returns true if arguments are valid sudoku grid
bool ValidateArgs(const std::vector<std::string>& args)
{
    if (args.size() < 9)
        return false;

    for (const std::string& s : args)
    {
        if (s.size() != 9)
            return false;
    }

    return true;
}