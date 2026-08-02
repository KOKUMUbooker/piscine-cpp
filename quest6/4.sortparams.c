#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Write a program that prints the arguments received in the command line in ASCII order.

Usage : 
./out 1 a 2 A 3 b 4 C

Output : 
1
2
3
4
A
C
a
b
*/

void bubbleSortOSParams(int argc, char* argv[])
{
     if (argc <= 2)
        return;

    for(int i = 1; i < argc - 1; ++i) // Start from index 1 to avoid sorting program name
    {
        for (int j = 1; j < argc - i; ++j)
        {
            if (strcmp(argv[j],argv[j+1]) > 0)
            {
                char* temp = argv[j];
                argv[j] = argv[j + 1];
                argv[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    bubbleSortOSParams(argc,argv);

    for (int i = 1; i < argc; ++i)
        printf("%s\n",argv[i]);

    return EXIT_SUCCESS;
}