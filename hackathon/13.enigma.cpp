#include <iostream>

/*
Write a function called Enigma that receives pointers as arguments and move its values around to hide them.

This function will put :
a into c.
c into d.
d into b.
b into a.

Expected function
func Enigma(a ***int, b *int, c *******int, d ****int) {

}

Usage (Go) :
x := 5
y := &x
z := &y
a := &z

w := 2
b := &w

u := 7
e := &u
f := &e
g := &f
h := &g
i := &h
j := &i
c := &j

k := 6
l := &k
m := &l
n := &m
d := &n

fmt.Println(***a)
fmt.Println(*b)
fmt.Println(*******c)
fmt.Println(****d)

piscine.Enigma(a, b, c, d)

fmt.Println("After using Enigma")
fmt.Println(***a)
fmt.Println(*b)
fmt.Println(*******c)
fmt.Println(****d)

Output :
5
2
7
6
After using Enigma
2
6
5
7
*/

namespace piscine
{
    // (a ***int, b *int, c *******int, d ****int)
    void Enigma(int*** a, int* b, int******* c, int**** d)
    {
        /*
        a into c.
        c into d.
        d into b.
        b into a.
        */
       int aTemp {***a};
       int bTemp {*b};
       int cTemp {*******c};
       int dTemp {****d};
       ***a = bTemp;
       *b = dTemp;
       *******c = aTemp;
       ****d = cTemp;
    }
} // namespace piscine


int main()
{
    int x { 5 };
 	int* y { &x  };
	int** z { &y  };
	int*** a { &z  };

	int w { 2 };
 	int* b { &w  };

	int u { 7 };
 	int* e { &u  };
	int** f { &e  };
	int*** g { &f  };
	int**** h { &g  };
	int***** i { &h  };
	int****** j { &i  };
	int******* c { &j  };

	int k { 6 };
 	int* l { &k  };
	int** m { &l  };
	int*** n { &m  };
	int**** d { &n  };

    std::cout << ***a << "\n";
    std::cout << *b << "\n";
    std::cout << *******c << "\n";
    std::cout << ****d << "\n";

    piscine::Enigma(a, b, c, d);

    std::cout << "After using Enigma" << "\n";
    std::cout << ***a << "\n";
    std::cout << *b << "\n";
    std::cout << *******c << "\n";
    std::cout << ****d << "\n";

    return EXIT_SUCCESS;
}