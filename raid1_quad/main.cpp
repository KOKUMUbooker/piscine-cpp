#include <iostream>
#include "include/quadA.hpp" 
#include "include/quadB.hpp"

int main()
{
    std::cout << "============== QUAD A ===============\n";
    std::cout << "QuadA(5,3)\n";
    QuadA(5,3);
    std::cout << "QuadA(5,1)\n";
    QuadA(5,1);
    std::cout << "QuadA(1,1)\n";
    QuadA(1,1);
    std::cout << "QuadA(1,5)\n";
    QuadA(1,5);

    std::cout << "\n============== QUAD B ===============\n";
    std::cout << "QuadB(5,3)\n";
    QuadB(5,3);
    std::cout << "QuadB(5,1)\n";
    QuadB(5,1);
    std::cout << "QuadB(1,1)\n";
    QuadB(1,1);
    std::cout << "QuadB(1,5)\n";
    QuadB(1,5);
}