#include <iostream>
#include <cmath>

#include "polynomial.h"

Linux103::Polynomial::Polynomial()
{
    std::vector<int> coefs;
    std::vector<int> degrees;
}


void Linux103::Polynomial::add(std::vector<int> coefs, std::vector<int> degrees)
{
    coef = coefs;
    degree = degrees;
}

void Linux103::Polynomial::print()
{
    int size = coef.size() + degree.size();   
    if (size % 2 == 0)
    {
        for (int i = 0; i < coef.size(); ++i)
        {
            std::cout << coef[i] << "x^" << degree[i] << "  ";
        }
    }
    else
    {
        degree.push_back(1);
        for (int i = 0; i < coef.size(); ++i)
        {
            std::cout << coef[i] << "x^" << degree[i] << "  ";
        }
    }
}

int Linux103::Polynomial::calculate(int xValue)
{
    int size = coef.size() + degree.size();   
    int res = 0;
    if (size % 2 == 0)
    {
        for (int i = 0; i < coef.size(); ++i)
        {
            res += coef[i] * pow(xValue, degree[i]);
        }
    }
    else
    {
        degree.push_back(1);
        for (int i = 0; i < coef.size(); ++i)
        {
            res += coef[i] * pow(xValue, degree[i]);
        }
    }
    return res;
}

void Linux103::Polynomial::derive()
{
    int size = coef.size() + degree.size();
    if (size % 2 == 0)
    {
        for (int i = 0; i < coef.size(); ++i)
        {
            std::cout << coef[i] * degree[i] << "*x^" << degree[i] - 1 << "     ";
        }
    }
    else
    {
        degree.push_back(1);
        for (int i = 0; i < coef.size(); ++i)
        {
            std::cout << coef[i] * degree[i] << "*x^" << degree[i] - 1 << "     ";  
        }
    }
}