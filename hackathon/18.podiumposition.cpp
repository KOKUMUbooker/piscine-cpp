#include <iostream>
#include <vector>
#include <string>

/*
A F1 race just finished and the commentator is calling the finishing positions incorrectly. 
Help to fix this before the contestants arrive at the podium by providing the commentator with the correct podium position.
Write a function PodiumPosition that takes a slice of slices of type string and returns the competitor positions correctly.

Expected function
func PodiumPosition(podium [][]string) [][]string {
}

Usage (Go) :
p4 := []string{"4th Place"}
p3 := []string{"3rd Place"}
p2 := []string{"2nd Place"}
p1 := []string{"1st Place"}

position := [][]string{p4, p3, p2, p1}
fmt.Println(piscine.PodiumPosition(position))

Output :
[[1st Place] [2nd Place] [3rd Place] [4th Place]]$
*/

namespace piscine
{
    std::vector<std::vector<std::string>> PodiumPosition(std::vector<std::vector<std::string>> podium)
    {
        int len {static_cast<int>(podium.size())};
        for (int i {0}; i < len-1; ++i)
        {
            for (int j {0}; j < len-1-i; ++j)
            {
                if (podium[j][0] > podium[j+1][0])
                {
                    std::string temp {podium[j][0]};
                    podium[j][0] =  podium[j+1][0];
                    podium[j+1][0] = temp;
                }
            }
        }

        return podium;
    }

    void PrintVector(const std::vector<std::string>& vec, bool isLast)
    {
        int len {static_cast<int>(vec.size())};
        std::cout << "[";
        for(int i {0}; i < len; ++i)
        {
            std::cout << vec.at(i);
            if (i != len-1)
                std::cout << " ";
        }
        std::cout << "]";
        if (!isLast) std::cout << " ";
    }

    void Print2DVector(const std::vector<std::vector<std::string>>& vec)
    {
        int len {static_cast<int>(vec.size())};
        std::cout << "[";

        for(int i {0}; i < len; ++i)
            PrintVector(vec[i], i == (len-1)); 

        std::cout << "]\n";
    }
} // namespace piscine


int main()
{
    std::vector<std::string> p4 = {"4th Place"};
    std::vector<std::string> p3 = {"3rd Place"};
    std::vector<std::string> p2 = {"2nd Place"};
    std::vector<std::string> p1 = {"1st Place"};

    std::vector<std::vector<std::string>> position {p4, p3, p2, p1};
    piscine::Print2DVector(piscine::PodiumPosition(position));

    return EXIT_SUCCESS;
}