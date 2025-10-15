#include <iostream>

int main()
{
    int kc;
    int c;
    int summa{0};
    int maxuim{INT_MIN};
    int number{0};
    std::cout << "Количество чисел в последовательности: ";
    std::cin >> kc;
    if ((0 < kc) && (INT_MAX >= kc))
    {
        for (unsigned int i = 0; i < kc; ++i)
        {
            std::cout << "Число " << i + 1 << ": ";
            std::cin >> c;
            if ((c % 3 != 0) && (c % 5 != 0) && (c % 7 != 0))
            {
                summa += c;
                if ((c > maxuim) || (number == 0))
                {
                    maxuim = c;
                    number = i + 1;
                }
            }
        }
    }
    else
    {
        std::cout << "Ошибка ввода количества чисел";
        return 1;
    }
    if (number == 0)
    {
        std::cout << "Нет чисел удовлетворяющих условию.\n";
        return 1;
    }
    std::cout << "Cумма чисел, удовлетворяющие условие = " << summa << std::endl;
    std::cout << "Максимальное число последовательности, удовлетворяющее условию: " << maxuim << std::endl;
    std::cout << "Номер максимального числа в последовательности: " << number << std::endl;
    return 0;
}