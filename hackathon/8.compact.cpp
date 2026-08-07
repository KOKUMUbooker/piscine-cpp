#include <iostream>
#include <string>
#include <vector>

/*
Write a function Compact that takes a pointer to a slice of strings as its argument.
The function must:
Return the number of elements with a non-zero value (i.e., non-empty strings) in the slice.
Compact the slice by removing all elements that have the zero value for a string (an empty string "").

Expected function
func Compact(ptr *[]string) int {

}

Usage (Go) :
const N = 6
a := make([]string, N)
a[0] = "a"
a[2] = "b"
a[4] = "c"

for _, v := range a {
    fmt.Println(v)
}

fmt.Println("Size after compacting:", piscine.Compact(&a))

for _, v := range a {
    fmt.Println(v)
}

Output : 
a

b

c

Size after compacting: 3
a
b
c
*/

namespace piscine
{
   int Compact(std::vector<std::string>& ptr)
   {
        int len {static_cast<int>(ptr.size())};
        int nonBlank {0};
        for(int i {0}; i < len; ++i)
        {
            if (ptr[i]=="")
            {
                int j {i+1};
                while (j < len)
                {
                    if (ptr[j] != "")
                    {
                        ptr[i] = ptr[j]; // Move next non blank val into the current blank position
                        ptr[j] = ""; // Reset previously non blank slot as its value got moved
                        ++nonBlank; // Update nonBlank count as previously blank value is now filled
                        break;
                    }
                    ++j;
                }
            }
            else 
            {
                ++nonBlank;
            }
        }

        // Shrink vector
        if (nonBlank != len)
            ptr.erase(ptr.begin() + nonBlank, ptr.end());

        return nonBlank;
   } 
} // namespace piscine

const int N {6};
int main()
{
    std::vector<std::string> a (N);
    a[0] = "a";
    a[2] = "b";
    a[4] = "c";

    for (std::string s : a)
        std::cout << s << "\n";
    
    std::cout << "Size after compacting: " << piscine::Compact(a) << "\n";
    
    for (std::string s : a)
        std::cout << s << "\n";

    return EXIT_SUCCESS;
}