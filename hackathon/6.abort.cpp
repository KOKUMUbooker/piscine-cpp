#include <iostream>
#include <vector>

/*
Write a function that returns the median value of five int arguments.

Expected function
func Abort(a, b, c, d, e int) int {

}

Usage (Go) :
middle := piscine.Abort(2, 3, 8, 5, 7)
fmt.Println(middle)

Output : 
5
*/

namespace piscine
{
    void bubbleSort(std::vector<int>& list)
    {
        int len {static_cast<int>(list.size())};
        for (int i {0}; i < len; ++i)
        {
            for (int j {0}; j < len-1-i; ++j)
            {
                if (list[j] > list[j+1])
                {
                    int temp {list[j]};
                    list[j] = list[j+1];
                    list[j+1] = temp;
                }
            }
        }
    }

    int Abort(int a, int b, int c, int d, int e)
    {
        std::vector<int> list {a,b,c,d,e};
        bubbleSort(list);

        return list.at(2);
    }
} // namespace piscine


int main()
{
    std::cout << piscine::Abort(2, 3, 8, 5, 7);

    return EXIT_SUCCESS;
}