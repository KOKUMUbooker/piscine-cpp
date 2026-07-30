#include <iostream>
#include <string>

/*
Write a function that returns the nth rune of a string. If not possible, it returns 0.

Expected function
func NRune(s string, n int) rune {

}

Usage : 
func main() {
	z01.PrintRune(piscine.NRune("Hello!", 3))
	z01.PrintRune(piscine.NRune("Salut!", 2))
	z01.PrintRune(piscine.NRune("Bye!", -1))
	z01.PrintRune(piscine.NRune("Bye!", 5))
	z01.PrintRune(piscine.NRune("Ola!", 4))
	z01.PrintRune('\n')
}
And its output :

$ go run .
la!

*/

namespace piscine
{
   // n = 1 means give 1st char in string
   char NRune(std::string s, int n)
   {
       std::size_t sLen {s.size()};
       if (sLen < 1 || n > sLen) return '\0'; // Print nothing
       
       return s[n-1];
   }    
}


int main()
{
    std::cout << piscine::NRune("Hello!", 3);
    std::cout << piscine::NRune("Salut!", 2);
    std::cout << piscine::NRune("Bye!", -1);
    std::cout << piscine::NRune("Bye!", 5);
    std::cout << piscine::NRune("Ola!", 4);

    std::cout << "\n";

    return EXIT_SUCCESS;
}