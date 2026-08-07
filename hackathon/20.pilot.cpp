#include <iostream>
#include <string>

/*
Create a directory called pilot.
Inside the directory pilot create a file main.go.
Copy the code below to main.go and add the code needed so that the program compiles.

Note: You can only add code, not delete.

package main

import "fmt"

func main() {
	var donnie Pilot
	donnie.Name = "Donnie"
	donnie.Life = 100.0
	donnie.Age = 24
	donnie.Aircraft = AIRCRAFT1

	fmt.Println(donnie)
}

const AIRCRAFT1 = 1
*/

struct Pilot
{
    std::string Name {""};
    float Life {0.0f};
    int Age {0};
    int Aircraft {0};

    void Print()
    {
        std::cout << "{ " + Name + " " + std::to_string(Life) + " " + std::to_string(Age) + " " + std::to_string(Aircraft) + " }\n";
    }
};


const int AIRCRAFT1 = 1;
int main()
{
    Pilot donnie {};
	donnie.Name = "Donnie";
	donnie.Life = 100.0f;
	donnie.Age = 24;
	donnie.Aircraft = AIRCRAFT1;

    donnie.Print();

    return EXIT_SUCCESS;
}
