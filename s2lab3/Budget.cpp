#include <iostream>
#include "Budget.hpp"

Budget::Budget()
    : money(0), coefficient(1.0)
{
}

Budget::Budget(long long m, double coeff)
    : money(m), coefficient(coeff)
{
}

void Budget::changeBy(long long amount)
{
    money += amount;
}

void Budget::print() const
{
    std::cout << "\n--- Информация о бюджете ---\n";
    std::cout << "Всего денег: " << money << "\n";
    std::cout << "Коэффициент столицы: " << coefficient << "\n";
}
