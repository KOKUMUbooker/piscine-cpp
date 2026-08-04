#include <string>
#include <vector>
#include "include/solve.hpp"

bool Solve(std::vector<std::string>& grid)
{

}

void FindUnassignedLocation(const std::vector<std::string>& grid, int& row, int& col)
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
            }
        }
    }
}