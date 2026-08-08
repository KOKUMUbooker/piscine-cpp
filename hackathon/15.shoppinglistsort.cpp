#include <iostream>
#include <string>
#include <vector>

/*
You were sent to the supermarket with a shopping list. To make your shopping faster, 
write a function ShoppingListSort() that takes a slice of strings and sorts it, 
according to the string length, returning a slice in which the strings appear in ascending order.

Strings within the input slice must be of different lengths.
Expected function
func ShoppingListSort(slice []string) []string {

}

Usage (Go) :
slice := []string{"Pineapple", "Honey", "Mushroom", "Tea", "Pepper", "Milk"}
fmt.Println(piscine.ShoppingListSort(slice))

Output : 
[Tea Milk Honey Pepper Mushroom Pineapple]
*/

namespace piscine
{
    std::vector<std::string> ShoppingListSort(std::vector<std::string> slice)
    {
        int len {static_cast<int>(slice.size())};
        for (int i {0}; i < len-1; ++i)
        {
            for (int j {0}; j < len-1-i; ++j)
            {
                if (slice[j].size() > slice[j+1].size())
                {
                    std::string temp {slice[j]};
                    slice[j] = slice[j+1];
                    slice[j+1] = temp;
                }
            }
        }

        return slice;
    }

    void PrintVector(const std::vector<std::string>& vec)
    {
        int len {static_cast<int>(vec.size())};
        std::cout << "[";
        for(int i {0}; i < len; ++i)
        {
            std::cout << vec.at(i);
            if (i != len-1)
                std::cout << " ";
        }
        std::cout << "]\n";
    }
} // namespace piscine

int main()
{
    std::vector<std::string> slice {"Pineapple", "Honey", "Mushroom", "Tea", "Pepper", "Milk"};
    piscine::PrintVector(piscine::ShoppingListSort(slice));

    return EXIT_SUCCESS;
}