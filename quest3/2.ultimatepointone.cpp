#include <iostream>

/*
Write a function that takes a pointer to a pointer to a pointer to an int as argument and gives to this int the value of 1.
In go the func would look like this : 

func UltimatePointOne(n ***int) {

}

which gets called like this : 

func main() {
	a := 0
	b := &a
	n := &b
	piscine.UltimatePointOne(&n)
	fmt.Println(a)
}
*/

namespace piscine
{
    void UltimatePointOne(int*** n)
    {
        ***n = 1;
    }
}

int main()
{
    int a {0};
    int* b {&a};
    int** c {&b};

    piscine::UltimatePointOne(&c);
    std::cout << **c;

    return EXIT_SUCCESS;
}