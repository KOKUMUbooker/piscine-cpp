#include <string>
#include "include/utils.hpp"

std::string QuadA(int x, int y)
{
    std::string res;

    for (int row {1}; row <= y; ++row)
    {
        for (int col {1}; col <= x; ++col)
        {
            if (row == 1 && col == 1)
                res += "o";
            else if (row == 1 && col == x)
                res += "o";
            else if (row == y && col == 1)
                res += "o";
            else if (row == y && col == x)
                res += "o";
            else if (row == 1 || row == y)
                res += "-";
            else if (col == 1 || col == x)
                res += "|";
            else
                res += " ";
        }

        res += "\n";
    }

    return res;
}

std::string QuadB(int x, int y)
{
    std::string res;

    for (int row {1}; row <= y; ++row)
    {
        for (int col {1}; col <= x; ++col)
        {
            if (row == 1 && col == 1)
                res += "/";
            else if (row == 1 && col == x)
                res += "\\";
            else if (row == y && col == 1)
                res += "\\";
            else if (row == y && col == x)
                res += "/";
            else if (row == 1 || row == y)
                res += "*";
            else if (col == 1 || col == x)
                res += "*";
            else
                res += " ";
        }

        res += "\n";
    }

    return res;
}

std::string QuadC(int x, int y)
{
    std::string res;

    for (int row {1}; row <= y; ++row)
    {
        for (int col {1}; col <= x; ++col)
        {
            if (row == 1 && col == 1)
                res += "A";
            else if (row == 1 && col == x)
                res += "A";
            else if (row == y && col == 1)
                res += "C";
            else if (row == y && col == x)
                res += "C";
            else if (row == 1 || row == y)
                res += "B";
            else if (col == 1 || col == x)
                res += "B";
            else
                res += " ";
        }

        res += "\n";
    }

    return res;
}

std::string QuadD(int x, int y)
{
    std::string res;

    for (int row {1}; row <= y; ++row)
    {
        for (int col {1}; col <= x; ++col)
        {
            if (row == 1 && col == 1)
                res += "A";
            else if (row == 1 && col == x)
                res += "C";
            else if (row == y && col == 1)
                res += "A";
            else if (row == y && col == x)
                res += "C";
            else if (row == 1 || row == y)
                res += "B";
            else if (col == 1 || col == x)
                res += "B";
            else
                res += " ";
        }

        res += "\n";
    }

    return res;
}

std::string QuadE(int x, int y)
{
    std::string res;

    for (int row {1}; row <= y; ++row)
    {
        for (int col {1}; col <= x; ++col)
        {
            if (row == 1 && col == 1)
                res += "A";
            else if (row == 1 && col == x)
                res += "C";
            else if (row == y && col == 1)
                res += "C";
            else if (row == y && col == x)
                res += "A";
            else if (row == 1 || row == y)
                res += "B";
            else if (col == 1 || col == x)
                res += "B";
            else
                res += " ";
        }

        res += "\n";
    }

    return res;
}

bool compareQuad(const std::string& input, const std::string& quad)
{
    std::string trimmedInput {input};
    std::string trimmedQuad {quad};

    // Remove trailing '\n' characters
    while (!trimmedInput.empty() && trimmedInput.back() == '\n')
        trimmedInput.pop_back();

    while (!trimmedQuad.empty() && trimmedQuad.back() == '\n')
        trimmedQuad.pop_back();

    return trimmedInput == trimmedQuad;
}
