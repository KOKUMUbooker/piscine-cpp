#include <iostream>
#include <string>
#include <set>

/*
Write a function that prints an int in a string base passed as parameters.
If the base is not valid, the function prints NV (Not Valid):
Validity rules for a base :
    A base must contain at least 2 characters.
    Each character of a base must be unique.
    A base should not contain + or - characters.
    The function has to manage negative numbers. (as shown in the example)

Expected function
func PrintNbrBase(nbr int, base string) {

}

Usage (In GO) :
piscine.PrintNbrBase(125, "0123456789")
z01.PrintRune('\n')
piscine.PrintNbrBase(-125, "01")
z01.PrintRune('\n')
piscine.PrintNbrBase(125, "0123456789ABCDEF")
z01.PrintRune('\n')
piscine.PrintNbrBase(-125, "choumi")
z01.PrintRune('\n')
piscine.PrintNbrBase(125, "aa")
z01.PrintRune('\n')

Output : 
125
-1111101
7D
-uoi
NV
*/

namespace piscine
{
    bool AreUnique(std::string& base)
    {
        std::set<char> unique {};
        for (char& c : base)
            unique.emplace(c);
        
        return unique.size() == base.size();
    }

    bool ContainsSigns(std::string& base)
    {
        for (char& c : base)
        {
            if (c == '-' || c == '+')
                return true;
        }

        return false;
    }

    void ReversStr(std::string& str)
    {
        std::string res;
        for (auto it {str.rbegin()}; it != str.rend(); ++it)
            res += *it;
        str = res;
    }

    // string base are the individual character found in that number system
    void PrintNbrBase(int nbr, std::string base)
    {
        int bLen {static_cast<int>(base.size())}; // eg len of 2 means we should convert to binary

        if (bLen < 2 || !AreUnique(base) || ContainsSigns(base))
        {
            std::cout << "NV";
            return;
        }

        bool IsNegative {nbr < 0};
        std::string res {""};

        for (int quot {nbr}; quot != 0; quot /= bLen)
        {
            int mod {quot % bLen}; // Mod is the index we can use to index the actual number from the base string
            if (IsNegative) mod = -mod; // Make it positive
            res += base.at(mod);
        }

        ReversStr(res);
        res = IsNegative ? '-' + res : res;

        std::cout << res;
    }
} // namespace piscine

int main()
{
    // std::string a {"aa"};
    // std::string b {"abc"};
    // std::cout << piscine::AreUnique(a) << "\n";
    // std::cout << piscine::AreUnique(b) << "\n";

    piscine::PrintNbrBase(125, "0123456789");
    std::cout << '\n';
    piscine::PrintNbrBase(-125, "01");
    std::cout << '\n';
    piscine::PrintNbrBase(125, "0123456789ABCDEF");
    std::cout << '\n';
    piscine::PrintNbrBase(-125, "choumi");
    std::cout << '\n';
    piscine::PrintNbrBase(125, "aa");
    std::cout << '\n';

    return EXIT_SUCCESS;
}