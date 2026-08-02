#include <iostream>
#include <vector>
#include <string>

/*
Write a function that concatenates all strings in a slice and returns the resulting string.
The strings must be joined in the order they appear in the slice.

Expected function
func BasicJoin(elems []string) string {

}

Usage (in GO) : 
elems := []string{"Hello!", " How", " are", " you?"}
fmt.Println(piscine.BasicJoin(elems))

Output : 
Hello! How are you?
*/

namespace piscine
{
    std::string BasicJoin(const std::vector<std::string>& elems)
    {
        std::string res {""};
        for (std::string str : elems)
            res += str;
        
        return  res;
    }
} // namespace piscine

int main()
{
    std::vector<std::string> elems {"Hello!", " How", " are", " you?"};
    std::cout << piscine::BasicJoin(elems) << "\n" ; 

    return EXIT_SUCCESS;
}