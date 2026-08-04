#include <iostream>
#include <fstream>
#include <string>

/*
Write a program that displays, on the standard output, the content of a file given as argument.

Usage :
$ go run .
File name missing
$ echo 'Almost there!!' > quest8.txt
$ go run . quest8.txt main.go
Too many arguments
$ go run . quest8.txt
Almost there!!
*/

int main(int argc, char* argv[])
{
    if (argc == 1)
        std::cout << "File name missing\n";
        
    if (argc != 2)
        std::cout << "Too many arguments\n";

    // Declare file stream
    std::fstream fileStream {}; 

    // Open file in read mode
    fileStream.open(argv[1], std::ios::in);

    if (!fileStream.is_open())
    {
        std::cerr << "Invalid file path : " << argv[1] << "\n";
        return EXIT_FAILURE;
    }

    std::string line {};
    while(std::getline(fileStream, line)) // Read line by line till the end of the file
    {
        std::cout << line << "\n";
    }

    // Close file stream
    fileStream.close();

    return EXIT_SUCCESS;
}