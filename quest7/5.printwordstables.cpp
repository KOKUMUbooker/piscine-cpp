#include <iostream>
#include <vector>
#include <string>

/*
Write a function that receives a string slice and prints each element of the slice in a seperate line.

Expected function
func PrintWordsTables(a []string) {

}
*/

namespace piscine
{   
    void PrintWordsTables(const std::vector<std::string>& a)
    {
        for (const std::string s : a)
            std::cout << s << "\n";
    }

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
    auto vec { piscine::SplitWhiteSpaces("Hello how are you?") };
    piscine::PrintVector(vec);

    return EXIT_SUCCESS;
}