#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "include/utils.hpp"

int main()
{
    std::vector<std::string> lines;

    int width {-1};
    int height {0};

    std::string line;

    // Read input and validate row widths
    while (std::getline(std::cin, line))
    {
        if (width == -1)
        {
            width = static_cast<int>(line.length());
        }
        else if (static_cast<int>(line.length()) != width)
        {
            std::cout << "Not a quad function\n";
            return 0;
        }

        lines.push_back(line);
        ++height;
    }

    // Reject if no rows or no columns
    if (width <= 0 || height <= 0)
    {
        std::cout << "Not a quad function\n";
        return 0;
    }

    // Join lines with '\n'
    std::string input;

    for (int i {0}; i < static_cast<int>(lines.size()); ++i)
    {
        if (i > 0)
            input += "\n";

        input += lines[i];
    }

    std::vector<std::string> matches;

    if (compareQuad(input, QuadA(width, height)))
    {
        matches.push_back(
            "[quadA] [" + std::to_string(width) + "] [" +
            std::to_string(height) + "]"
        );
    }

    if (compareQuad(input, QuadB(width, height)))
    {
        matches.push_back(
            "[quadB] [" + std::to_string(width) + "] [" +
            std::to_string(height) + "]"
        );
    }

    if (compareQuad(input, QuadC(width, height)))
    {
        matches.push_back(
            "[quadC] [" + std::to_string(width) + "] [" +
            std::to_string(height) + "]"
        );
    }

    if (compareQuad(input, QuadD(width, height)))
    {
        matches.push_back(
            "[quadD] [" + std::to_string(width) + "] [" +
            std::to_string(height) + "]"
        );
    }

    if (compareQuad(input, QuadE(width, height)))
    {
        matches.push_back(
            "[quadE] [" + std::to_string(width) + "] [" +
            std::to_string(height) + "]"
        );
    }

    if (matches.empty())
    {
        std::cout << "Not a quad function\n";
        return 0;
    }

    // Join matches with " || "
    for (std::size_t i {0}; i < matches.size(); ++i)
    {
        if (i > 0)
            std::cout << " || ";

        std::cout << matches[i];
    }

    std::cout << "\n";

    return 0;
}