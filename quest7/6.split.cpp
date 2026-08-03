#include <iostream>
#include <vector>
#include <string>

/*
Write a function that receives a string and a separator and returns a slice of strings that results of splitting the string s by the separator sep.

Expected function
func Split(s, sep string) []string {

}

Usage (Go) : 
s := "HelloHAhowHAareHAyou?"
fmt.Printf("%#v\n", piscine.Split(s, "HA"))

Output :
[]string{"Hello", "how", "are", "you?"}
*/

namespace piscine
{
    bool NextCharsMatchSep(int n, const std::string& s, std::string sep)
    {
        int sepLen {static_cast<int>(sep.size())};

        if ((n + sepLen) > s.size())
            return false;

        for (int i {n}; i < sepLen; ++i)
        {
            if (s[i] != sep[i])
                return false;
        }

        return true;
    }

    std::vector<std::string> Split(const std::string& s, std::string sep)
    {
        int sLen {static_cast<int>(s.size())};
        int sepLen {static_cast<int>(sep.size())};
        std::vector<std::string> res {};
        std::string tempStr {};

        int i {0};
        while (i < sLen)
        {
            if (s[i] == sep[0] && NextCharsMatchSep(i, s, sep))
            {
                if (tempStr != "")
                {
                    res.push_back(tempStr);
                    tempStr = "";
                }
                i = i+sepLen;
                continue;
            }

            tempStr += s[i];
            ++i;
        }
        // HeHAhas
        // 0123456

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
    std::string s {"HelloHAhowHAareHAyou?"};
    std::vector<std::string> vec {piscine::Split(s,"HA")};
    piscine::PrintVector(vec);

    return EXIT_SUCCESS;
}