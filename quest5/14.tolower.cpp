#include <iostream>
#include <string>

/*
Write a function that lower cases for each letter in a string.

Expected function
func ToLower(s string) string {

}
*/

// Uppercase Letters (65–90) A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
// Lowercase Letters (97–122) a b c d e f g h i j k l m n o p q r s t u v w x y z
namespace piscine
{
    std::string ToLower(std::string s)
    {
        std::string capitalizedStr {};
        capitalizedStr.reserve(s.size());

        int gap { 'a' - 'A' }; // gap from any lower case letter to its upper case value

        for (char& c : s)
        {
            if (c >= 'A' && c <= 'Z')
                capitalizedStr += static_cast<char>(c + gap); 
            else 
                capitalizedStr += c;
        }

        return capitalizedStr;
    }
}

int main()
{
    std::cout << piscine::ToLower("Hello! How are you?") << "\n";

    return EXIT_SUCCESS;
}