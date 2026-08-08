#ifndef _INCLUDE_SOLVE_
#define _INCLUDE_SOLVE_

#include <string>
#include <vector>

bool Solve(std::vector<std::string>& grid);
bool FindUnassignedLocation(const std::vector<std::string>& grid, int& row, int& col);
bool NoConFlicts(const std::vector<std::string>& grid, int row, int col, char num);

#endif