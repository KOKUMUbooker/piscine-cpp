#include <iostream>

/*
The code below must be copied into a file called main.go inside the point directory.
The necessary changes must be applied so that the program works.
The function setPoint() must work with int.

Code to be copied
func setPoint(ptr *point) {
	ptr.x = 42
	ptr.y = 21
}

func main() {
	points := &point{}

	setPoint(points)

	fmt.Printf("x = %d, y = %d\n",points.x, points.y)
}
Usage
$ go run .
x = 42, y = 21
$
*/

struct point
{
    int x {0};
    int y {0};
};

void setPoint(point& ptr)
{
    ptr.x = 42;
    ptr.y = 21;
}

int main()
{
    point points {};

    setPoint(points);

    std::cout << "x = " << points.x << ", y = " << points.y << "\n";

    return EXIT_SUCCESS;
}
