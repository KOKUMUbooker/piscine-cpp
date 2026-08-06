#include <iostream>
#include <string>

/*
Write a function rot14 that returns the string within the parameter transformed into a rot14 string. 
Each letter will be replaced by the letter 14 spots ahead in the alphabetical order.
'z' becomes 'n' and 'Z' becomes 'N'. The case of the letter stays the same.
Expected function
func Rot14(s string) string {

}

Usage (Go) :
result := piscine.Rot14("Hello! How are You?")

for _, r := range result {
    z01.PrintRune(r)
}
z01.PrintRune('\n')

Output : 
Vszzc! Vck ofs Mci?
*/

namespace piscine
{
    inline bool IsAlpha(char c)
    {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    char GetRotChar(const char c)
    {
        if (!IsAlpha(c))
            return c;

        int count {0};
        char res {c};
        bool islower {c >= 'a' && c <= 'z'};
        while (count < 14)
        {   
            ++res;
            ++count;
            if (islower && res == ('z'+1))
                res = 'a';
            else if (!islower && res == ('Z'+1))
                res = 'A';
        }

        return res;
    }

    std::string Rot14(const std::string s)
    {
        std::string res {""};
        for (const char c : s)
            res += GetRotChar(c);
        
        return res;
    }
    
} // namespace piscine


int main()
{
    std::string result { piscine::Rot14("Hello! How are You?") };
    std::cout << result << "\n";

    return EXIT_SUCCESS;
}