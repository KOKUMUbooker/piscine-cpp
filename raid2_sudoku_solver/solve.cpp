#include <string>
#include <vector>
#include "include/solve.hpp"

bool Solve(std::vector<std::string>& grid)
{
    int row {0}, col {0};

    bool openSlotFound { FindUnassignedLocation(grid, row, col) };
    if (!openSlotFound)
        return true;

    for (char i {'0'}; i <= '9'; ++i)
    {
        // Check for validity of i in openslot

        // If No violations found recursively call Solve

        // If the next recursivecall failed, undo the current row and col values in grid & try next value in next iteration
    }

    return false; // Means values(0-9) failed to be placed at the current row & col 
}

bool FindUnassignedLocation(const std::vector<std::string>& grid, int& row, int& col)
{
    int rowLen {static_cast<int>(grid.size())};
    for (int i {0}; i < rowLen; ++i)
    {
        int colLen {static_cast<int>(grid[i].size())};
        for (int j {0}; j < colLen; ++j)
        {
            if (grid[i][j] == '.')
            {
                row = i;
                col = j;
                return true;
            }
        }
    }

    return false;
}