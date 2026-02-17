#pragma once
#include <iostream>

class Budget
{
public:
    long long money;
    double coefficient;

    Budget();
    Budget(long long money, double coeff);

    void changeBy(long long amount);
    void print() const;
};
