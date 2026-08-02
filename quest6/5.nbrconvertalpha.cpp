#include <iostream>
#include <vector>

/*
Instructions
Write a program that prints the corresponding letter in the n position of the latin alphabet,
where n is each argument received.
For example 1 matches a, 2 matches b, etc. If n does not match a valid position of the alphabet 
or if the argument is not an integer, the program should print a space (" ").
A flag --upper should be implemented. When used, the program prints the result in upper case. 
The flag will always be the first argument.

Usage (Go) : 
$ go run .
$ go run . 8 5 12 12 15 | cat -e
hello$
$ go run . 12 5 7 5 14 56 4 1 18 25 | cat -e
legen dary$
$ go run . 32 86 h | cat -e
   $
$ go run . --upper 8 5 25
HEY$
$
*/

char ToUpper(char c)
{
    int gap {static_cast<int>('a' - 'A')};
    if (c >= 'a' && c <= 'z')
        return static_cast<char>(c - gap);

    return c;
}

int Square(int n, int power)
{
    if (power == 0) return 1;
    return n * Square(n,power-1);
}

int ConvStrToInt(std::string s)
{
    const int size {static_cast<int>(s.size())};
    int res {0};
    for (int i {0}; i < size; ++i)
    {
        // 325 
        // 3 * 100 = 3 * 10^2(3-0+1)
        int n {static_cast<int>(s[i] - '0')};
        int power {size - (i + 1)};
        res += n * Square(10,power);
    }
    return res;
}

int main(int argc, char* argv[])
{
    std::vector<std::string> osArgs (argv+1, argv+argc); // From index 1 to the end
    int len { static_cast<int>(osArgs.size())};

    if (len == 0)
        return EXIT_SUCCESS;

    bool ConvToUpper {osArgs[0] == "--upper"};

    if (len == 1 && ConvToUpper)
        return EXIT_SUCCESS;
    
    const std::vector<char> alphabet 
        {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    
    for (int i {ConvToUpper ? 1 : 0}; i < len; ++i)
    {
        int idx {ConvStrToInt(osArgs[i])-1};
        if (idx < 0 || idx >= alphabet.size())
        {
            std::cout << ' ';
            continue;
        }
        
        if (ConvToUpper)
            std::cout << ToUpper(alphabet[idx]);
        else
            std::cout << alphabet[idx];
    }

    return EXIT_SUCCESS;
}