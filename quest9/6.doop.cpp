#include <iostream>
#include <string>

/*
Write a program that is called doop.
The program has to be used with three arguments:
    A value
    An operator, one of : +, -, /, *, %
    Another value

In case of an invalid operator, value, number of arguments or an overflow, the programs prints nothing.
The program has to handle the modulo and division operations by 0 as shown on the output examples below.

Usage (Go) :
$ go run .
$ go run . 1 + 1 | cat -e
2
$
$ go run . hello + 1
$ go run . 1 p 1
$ go run . 1 / 0 | cat -e
No division by 0
$
$ go run . 1 % 0 | cat -e
No modulo by 0
$
$ go run . 9223372036854775807 + 1
$ go run . -9223372036854775809 - 3
$ go run . 9223372036854775807 "*" 3
$ go run . 1 "*" 1
1
$ go run . 1 "*" -1
-1
*/

inline bool IsValidOp(const std::string& op)
{
    return op == "+" || op == "-" || op == "/" || op == "*" || op == "%";
}

// TODO: Add overflow checks & string to int conversion failures
int main(int argc, char* argv[])
{
    if (argc != 4)
        return EXIT_SUCCESS;

    std::string op {argv[2]};
    if (!IsValidOp(op))
        return EXIT_SUCCESS;
    
    int operand1 {std::stoi(argv[1])};
    int operand2 {std::stoi(argv[3])};

    if (op == "+") 
        std::cout << operand1 + operand2 << "\n";

    if (op == "-")
        std::cout << operand1 - operand2 << "\n";
        
    if (op == "/")
    {
        if (operand2 == 0)
            std::cout << "No division by 0\n";
        else
            std::cout << operand1 / operand2 << "\n";
    }
    if (op == "*")
        std::cout << operand1 * operand2 << "\n";

    if (op == "%")
    {
        if (operand2 == 0)
            std::cout << "No modulo by 0\n";
        else
            std::cout << operand1 % operand2 << "\n";
    }

    return EXIT_SUCCESS;
}