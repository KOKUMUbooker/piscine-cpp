#include <iostream>

/*
Create the following function.
func UltimateDivMod(a *int, b *int) {

}
UltimateDivMod should divide the dereferenced value of a by the dereferenced value of b.
Store the result of the division in the int which a points to.
Store the remainder of the division in the int which b points to.

Sample call in GO : 
func main() {
	a := 13
	b := 2
	piscine.UltimateDivMod(&a, &b)
	fmt.Println(a)
	fmt.Println(b)
}

Output : 
6
1
*/

namespace piscine 
{
    void UltimateDivMod(int* a, int* b)
    {
        int aTemp {*a}, bTemp {*b};
        *a = aTemp / bTemp;
        *b = aTemp % bTemp;
    }
}

int main()
{
    int a {13}, b {2};
    piscine::UltimateDivMod(&a,&b); 
    
    std::cout << a << "\n";
    std::cout << b << "\n";

    return EXIT_SUCCESS;
}