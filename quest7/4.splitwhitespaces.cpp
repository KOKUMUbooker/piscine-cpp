#include <iostream>
#include <string>
#include <vector>

/*
Write a function that separates the words of a string and puts them in a string slice.
The separators are spaces, tabs and newlines.

Expected function
func SplitWhiteSpaces(s string) []string {

}
*/

namespace piscine
{
    //"Hello how are you?"
    std::vector<std::string> SplitWhiteSpaces(const std::string& s)
    {
        std::string tempStr {""};
        std::vector<std::string> res {};
        for (const char& c : s)
        {
            if(c == ' ' || c == '\t' || c == '\n')
            {
                if (tempStr != "")
                {
                    res.push_back(tempStr);
                    tempStr = "";
                }
                continue;
            }

            tempStr += c;
        }

        // Additional check for once looping is done but no newline,tab or empty char was found to push the last bit to res
        if (tempStr != "")
            res.push_back(tempStr);

        return res;
    }

    void PrintVector(const std::vector<std::string>& vec)
    {
        std::cout <<vec.size() << "\n";
        int len {static_cast<int>(vec.size())};
        std::cout << "[";
        for(int i {0}; i < len; ++i)
        {
            std::cout << vec.at(i);
            if (i != len-1)
                std::cout << ", ";
        }
        std::cout << "]\n";
    }
} // namespace piscine


int main()
{
    std::string str {"Hello how are you?"};
    piscine::PrintVector(piscine::SplitWhiteSpaces(str));

    return EXIT_SUCCESS;
}