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
}