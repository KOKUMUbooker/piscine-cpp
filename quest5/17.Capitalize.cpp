#include <iostream>
#include <string>

/*
Write a function that capitalizes the first letter of each word and converts the rest of the letters to lowercase.
A word is a sequence of alphanumeric characters.

Expected function
func Capitalize(s string) string {

}

Usage :
piscine::Capitalize("Hello! How are you? How+are+things+4you?");

Output : 
Hello! How Are You? How+Are+Things+4you?
*/

// Uppercase Letters (65–90)
// Lowercase Letters (97–122)
namespace piscine
{
    inline bool IsAlphanum(char c)
    {
        return (c >= 'a' && c <= 'z') ||
               (c >= 'A' && c <= 'Z') ||
               (c >= '0' && c <= '9');
    }

    char ToUpper(char c)
    {
        if (c >= 'a' && c <= 'z')
        {
            int gap {'a' - 'A'};
            return static_cast<char>(c - gap);
        } 
        return c;
    }

    char ToLower(char c)
    {
        if (c >= 'A' && c <= 'Z')
        {
            int gap {'a' - 'A'};
            return static_cast<char>(c + gap);
        } 
        return c;
    }

    std::string Capitalize(std::string s)
    {
        std::string res {""};
        res.reserve(s.size());

        bool firstLetter {false};
        for (char& c : s)
        {
            if (!IsAlphanum(c))
            {
                firstLetter = false; // Reset flag
                res += c;
                continue;
            }

            if (!firstLetter) // Means we're on the first letter of word
            {
                res += ToUpper(c);
                firstLetter = true; // Specify that we've already passed first word
            }
            else
            {
                res += ToLower(c);
            }
        }

        return res;
    }
} // namespace piscine

int main()
{
    std::cout << piscine::Capitalize("Hello! How are you? How+are+things+4you?") << "\n";

    return EXIT_SUCCESS;
}