#include <iostream>
#include <vector>
#include <string>

/*
Write a program named comcheck that examines the command-line arguments and 
prints Alert!!! followed by a newline ('\n') if at least one of the arguments 
matches any of the following strings: 01, galaxy, or galaxy 01. 
If none of the arguments match, the program should not output anything.

Usage (Go) :
$ go run . "I" "Will" "Enter" "the" "galaxy"
Alert!!!
$ go run . "galaxy 01" "do" "you" "hear" "me"
Alert!!!
*/

int main(int argc, char* argv[])
{
    if (argc == 1)
        return EXIT_SUCCESS;

    std::vector<std::string> args {argv+1, argv+argc};
    
    for (std::size_t i {0}; i < args.size(); ++i)
    {
        if (args[i] == "01" || args[i] == "galaxy" || args[i] == "galaxy 01")
        {
            std::cout << "Alert!!!";
            break;
        }
    }

    return EXIT_SUCCESS;
}