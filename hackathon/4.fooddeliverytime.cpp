#include <iostream>
#include <string>
#include <map>

/*
Given the following menu with the corresponding times that each item takes to cook (burger takes 15 min, chips takes 10 min and nuggets takes 12 min), return the time that each order item takes to be prepared and the total amount of time for the order to be ready assuming the items are cooked one after the other.
Write a function FoodDeliveryTime() that takes a string and returns an int.

Use structs to answer the subject.
If any of the order items don't exist in the menu above return the error message 404.

type food struct {
  preptime int
}

func FoodDeliveryTime(order string) int {

}

Usage (Go) :
fmt.Println(piscine.FoodDeliveryTime("burger"))
fmt.Println(piscine.FoodDeliveryTime("chips"))
fmt.Println(piscine.FoodDeliveryTime("nuggets"))
fmt.Println(piscine.FoodDeliveryTime("burger") + piscine.FoodDeliveryTime("chips") + piscine.FoodDeliveryTime("nuggets"))

Output : 
15
10
12
37
*/

struct Food
{
    int preptime {0};
};

namespace piscine
{
    int FoodDeliveryTime(const std::string order)
    {
        static std::map<std::string, Food> freq = {
            {"burger", Food{15}},
            {"chips", Food{10}},
            {"nuggets", Food{12}}
        };

        auto it = freq.find(order);
        if (it == freq.end())
            return -1;

        return it->second.preptime;
    }
    
} // namespace piscine

int main()
{
    std::cout << piscine::FoodDeliveryTime("burger") << "\n"; 
    std::cout << piscine::FoodDeliveryTime("chips") << "\n"; 
    std::cout << piscine::FoodDeliveryTime("nuggets") << "\n"; 
    std::cout << piscine::FoodDeliveryTime("burger") + piscine::FoodDeliveryTime("chips") + piscine::FoodDeliveryTime("nuggets") << "\n"; 

    return EXIT_SUCCESS;
}