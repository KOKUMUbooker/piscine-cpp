#include <iostream>
#include <map>
#include <string>
#include <vector>

/*
You have a receipt from the grocery store and you want to know how many of each item you bought. 
Write a function that returns this summary.
Given a string count the total amount of times each item appears in it and return a summary 
including the item and its number of appearances as an int.

Expected function
func ShoppingSummaryCounter(str string) map[string]int {

}

Usage (Go) :
summary := "Burger Water Carrot Coffee Water Water Chips Carrot Carrot Burger Carrot Water"
for index, element := range piscine.ShoppingSummaryCounter(summary) {
    fmt.Println(index, "=>", element)

Output :
Burger => 2$
Water => 4$
Carrot => 4$
Coffee => 1$
Chips => 1$
*/

namespace piscine
{
    std::map<std::string,int> ShoppingSummaryCounter(const std::string& str)
    {
        std::map<std::string,int> res {};
        std::string word {""};

        for (const char& c : str)
        {
            if (c == ' ' && word != "")
            {
                if (res.find(word) != res.end()) // word exists
                    res[word] = ++res[word];
                else 
                    res[word] = 1;
                
                word = ""; // Reset word
            }
            else 
                word += c;
        }

        if (word != "")
        {
            if (res.find(word) != res.end()) // word exists
                res[word] = ++res[word];
            else 
                res[word] = 1;   
        }

        return res;
    }
    
} // namespace piscine

int main()
{
    std::string summary {"Burger Water Carrot Coffee Water Water Chips Carrot Carrot Burger Carrot Water"};
    for (std::pair<std::string,int> res : piscine::ShoppingSummaryCounter(summary))
        std::cout << res.first << " => " << res.second << "\n";

    return EXIT_SUCCESS;
}