#include <string>
#include <iostream>
#include <vector>
#include "include/solve.hpp"

bool Solve(std::vector<std::string>& grid)
{
    int row {0}, col {0};

    bool openSlotFound { FindUnassignedLocation(grid, row, col) };
    if (!openSlotFound)
        return true;

    for (char num {'0'}; num <= '9'; ++num)
    {
        // Check for validity of i in openslot
        if (NoConFlicts(grid, row, col, num))
        {
            // Place num
            grid[row][col] = num;

            // If No violations found recursively call Solve
            if (Solve(grid))
                return true;
                
            // If the next recursive call failed, undo the current row and col values in grid & proceed to next iteration
            grid[row][col] = '.'; // Backtrack
        }
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

bool NoConFlicts(const std::vector<std::string>& grid, int row, int col, char num)
{
    // Check if no. exists in the x axis
    for (int i {0}; i < grid[row].size(); ++i)
    {
        if (grid[row][i] == num)
            return false;
    }

    // Check if no. exists in the y axis
    for (int i {0}; i < grid.size(); ++i)
    {
        if (grid[i][col] == num)
            return false;
    }

    // Check if no. exists in the cells 3*3 mini grid
    int boxRowStart { (row/3) * 3 };
    int boxColStart { (col/3) * 3 };
    for (int r {boxRowStart}; r < boxRowStart+3; ++r)
    {
        for (int c {boxColStart}; c < boxColStart+3; ++c)
        {
            if (grid[r][c] == num)
                return false;
        }
    }

    return true;
}