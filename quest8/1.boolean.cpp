#include <string>
#include <iostream>

/*
Copy the provided code into a file named main.go inside the boolean directory, then apply the necessary changes so that the program compiles and runs correctly.

Code to be copied
func printStr(s string) {
	for _, r := range s {
		z01.PrintRune(r)
	}
	z01.PrintRune('\n')
}

func isEven(nbr int) boolean {
	if even(nbr) == 1 {
		return yes
	} else {
		return no
	}
}

func main() {
	if isEven(lengthOfArg) == 1 {
		printStr(EvenMsg)
	} else {
		printStr(OddMsg)
	}
}

Usage
$ go run . "not" "odd"
I have an even number of arguments
$ go run . "not even"
I have an odd number of arguments
*/
const std::string EvenMsg {"I have an even number of arguments"};
const std::string OddMsg {"I have an odd number of arguments"};
void printStr(const std::string s)
{
    for (const char& c : s)
        std::cout << c;
    std::cout << '\n';
}

inline int even(int nbr)
{
    return nbr % 2 == 0 ? 1 : 0;
}

bool isEven(int nbr)
{
    if (even(nbr) == 1)
        return true;
    else    
        return false;
}

int main(int argc, char* argv[])
{
    argc = argc - 1; // Remove count of the program name
    if (isEven(argc))
        printStr(EvenMsg);
    else 
        printStr(OddMsg);

    return EXIT_SUCCESS;
}