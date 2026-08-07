#include <iostream>
#include <string>
#include <vector>

/*
Write a function StringToIntSlice() that takes a string and returns the corresponding int slice.

Expected function
func StringToIntSlice(str string) []int {

}

Usage (Go) :
fmt.Println(piscine.StringToIntSlice("A quick brown fox jumps over the lazy dog"))
fmt.Println(piscine.StringToIntSlice("Converted this string into an int"))
fmt.Println(piscine.StringToIntSlice("hello THERE"))

Output :
[65 32 113 117 105 99 107 32 98 114 111 119 110 32 102 111 120 32 106 117 109 112 115 32 111 118 101 114 32 116 104 101 32 108 97 122 121 32 100 111 103]
[67 111 110 118 101 114 116 101 100 32 116 104 105 115 32 115 116 114 105 110 103 32 105 110 116 111 32 97 110 32 105 110 116]
[104 101 108 108 111 32 84 72 69 82 69]
*/

namespace piscine
{
    std::vector<int> StringToIntSlice(const std::string str)
    {
        int len {static_cast<int>(str.size())};
        std::vector<int> res {};
        res.reserve(len);

        for (int i {0}; i < len; ++i)
            res.push_back(static_cast<int>(str[i]));
        
        return res;
    }

    void PrintVector(const std::vector<int>& vec)
    {
        int len {static_cast<int>(vec.size())};
        std::cout << "[";
        for(int i {0}; i < len; ++i)
        {
            std::cout << vec.at(i);
            if (i != len-1)
                std::cout << " ";
        }
        std::cout << "]\n";
    }
} // namespace piscine


int main()
{
    piscine::PrintVector(piscine::StringToIntSlice("A quick brown fox jumps over the lazy dog"));
    piscine::PrintVector(piscine::StringToIntSlice("Converted this string into an int"));
    piscine::PrintVector(piscine::StringToIntSlice("hello THERE"));

    return EXIT_SUCCESS;
}