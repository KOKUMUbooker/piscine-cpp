#include <iostream>
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

void PrintGrid(const std::vector<std::string>& args)
{
    int argLen {static_cast<int>(args.size())};
    
    for (int i {0}; i < argLen; ++i)
    {
        int rowLen {static_cast<int>(args[i].size())};

        for (int j {0}; j < rowLen; ++j)
        {
            std::cout << args[i][j];

            if (j != rowLen - 1)
                std::cout << ' ';
        }
        std::cout << "\n";
    }
}