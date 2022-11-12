#include <iostream>
#include <vector>
#include <cstdlib>
#include "polynomial.h"



int main(int argc, char** argv)
{
    std::vector<int> cf;
    std::vector<int> dg;
    for (int i = 1; i < argc; ++i)
    {
        if (i % 2 != 0)
        {
            cf.push_back(std::atoi(argv[i]));
        }
        else
        {
           dg.push_back(std::atoi(argv[i]));
        }
    }
    
   Linux103::Polynomial Pol;
   Pol.add(cf, dg);
   Pol.print();
   std::cout << std::endl;
   std::cout << Pol.calculate(72) << std::endl;
   Pol.derive();
   std::cout << std::endl;
   return 0;
   

}