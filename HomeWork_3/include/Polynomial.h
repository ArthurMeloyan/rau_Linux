#include <cstddef>
#include <vector>
#ifndef Polynomial_is_defined
#define Polynomial_is_defined


namespace Linux103
{
    class Polynomial
    {
        private:
            std::vector<int> coef;
            std::vector<int> degree;
        public:
            Polynomial ();
            void add(std::vector<int> coef, std::vector<int> degree);
            void print();
            int calculate(int xValue);
            void derive();
    };
}



#endif

