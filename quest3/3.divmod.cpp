#include <iostream>

/*
Write a function that will be formatted as below (GO version).
func DivMod(a int, b int, div *int, mod *int) {

}
This function will divide the int a and b.
The result of this division will be stored in the int pointed by div.
The remainder of this division will be stored in the int pointed by mod.

Sample call in GO : 
func main() {
	a := 13
	b := 2
	var div int
	var mod int
	piscine.DivMod(a, b, &div, &mod)
	fmt.Println(div)
	fmt.Println(mod)
}
Output : 
6
1
*/

namespace piscine 
{
    void DivMod(int a, int b, int* div, int* mod)
    {
        if (b == 0) return;
        *div = a / b;
        *mod = a % b;
    }
}

int main()
{
    int a {13};
    int b {2};

    int div {0};
    int mod {0};

    piscine::DivMod(a,b,&div,&mod);
    std::cout << div << "\n";
    std::cout << mod << "\n";

    return EXIT_SUCCESS;
}