#include <iostream>
#include <vector>

/*
Deal a pack of 12 cards evenly between 4 players: Player 1, Player 2, Player 3 and Player 4.
Write a function DealAPackOfCards that takes a slice of integers deck representing a deck of cards, 
and prints the distribution of cards among the four players.

Each player must be printed in a different line.

Expected function
func DealAPackOfCards (deck []int) {

}

Usage (Go) :
deck := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}
piscine.DealAPackOfCards(deck)

Output :
Player 1: 1, 2, 3$
Player 2: 4, 5, 6$
Player 3: 7, 8, 9$
Player 4: 10, 11, 12$
*/

namespace piscine
{
    const int PlayerNum {4};
    void DealAPackOfCards(const std::vector<int>& deck)
    {
        int len {static_cast<int>(deck.size())};
        int start {1};
        for (int i {1}; i <= 4; ++i)
        {
            std::cout << "Player " << i << ": ";
            int end {i * 3};
            for (int j {start}; j <= end; ++j)
            {
                std::cout << j;
                if (j != end)
                    std::cout << ", ";
            }
            start = ++end;
            std::cout << "\n";
        }
    }
} // namespace piscine

int main()
{
    std::vector<int> deck {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    piscine::DealAPackOfCards(deck);

    return EXIT_SUCCESS;
}