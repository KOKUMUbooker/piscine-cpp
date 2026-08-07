#include <iostream>
#include <string>

/*
Write a function called RockAndRoll() that takes an int and returns a string.
    If the number is divisible by 2, print rock followed by a newline \n.
    If the number is divisible by 3, print roll followed by a newline \n.
    If the number is divisible by 2 and 3, print rock and roll followed by a newline \n.
    If the number is negative return error: number is negative followed by a newline \n.
    If the number is non divisible return error: non divisible followed by a newline \n.

Expected function
func RockAndRoll(n int) string {

}

Usage (Go) :
fmt.Println(piscine.RockAndRoll(4))
fmt.Println(piscine.RockAndRoll(9))
fmt.Println(piscine.RockAndRoll(6))

Output :
rock$
$
roll$
$
rock and roll$
$
*/

namespace piscine
{
    std::string RockAndRoll(int n)
    {
        if (n < 0)
            return "error: number is negative\n";
        else if (n % 2 == 0 && n % 3 == 0)
            return "rock and roll\n";
        else if (n % 2 == 0 )
            return "rock\n";
        else if (n % 3 == 0)
            return "roll\n";
        else return "error: non divisible";
    }
} // namespace piscine


int main()
{
    std::cout << piscine::RockAndRoll(4);
    std::cout << piscine::RockAndRoll(9);
    std::cout << piscine::RockAndRoll(6);
    
    return EXIT_SUCCESS;
}