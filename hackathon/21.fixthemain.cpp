#include <iostream>
#include <string>

/*
Fix the following program.

Program to fix
package piscine

func PrintStr(s string) {
	for _, r := range s {
		z01.PrintRune(r)
	}
}

func CloseDoor(ptrDoor *Door) bool {
	PrintStr("Door Closing...")
	state = CLOSE
	return true
}

func IsDoorOpen(Door Door) {
	PrintStr("is the Door opened ?")
	return Door.state = OPEN
}

func IsDoorClose(ptrDoor *Door) bool {
	PrintStr("is the Door closed ?")
}

func main() {
	door := &Door{}

	OpenDoor(door)
	if IsDoorClose(door) {
		OpenDoor(door)
	}
	if IsDoorOpen(door) {
		CloseDoor(door)
	}
	if door.state == OPEN {
		CloseDoor(door)
	}
}
*/

const std::string OPEN {"OPEN"};
const std::string CLOSE {"CLOSE"};
struct Door
{
    std::string state{""};
};

void CloseDoor(Door& ptrDoor)
{
    std::cout << "Door Closing...\n";
    ptrDoor.state = CLOSE;
}

void OpenDoor(Door& ptrDoor)
{
    std::cout << "Door Opening...\n";
    ptrDoor.state = OPEN;
}

bool IsDoorOpen(const Door& Door)
{
    std::cout << "is the Door opened ?\n";
    return Door.state == OPEN;
}

bool IsDoorClose(const Door& Door)
{
    std::cout << "is the Door closed ?\n";
    return Door.state == CLOSE;
}

int main()
{
    Door door {};
    OpenDoor(door);
	if (IsDoorClose(door)) 
		OpenDoor(door);

    if (IsDoorOpen(door)) 
		CloseDoor(door);

    if (door.state == OPEN) 
		CloseDoor(door);

    return EXIT_SUCCESS;
}