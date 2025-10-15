#include <iostream>

int main()
{
    const int ww = 9;
    int mass[ww];
    bool three = 0;
    int x;
    int y;
    for (int i = 0; i < ww; ++i)
    {
        std::cout << "Число " << i + 1 << ": ";
        std::cin >> mass[i];
        y = abs(mass[i]);
        while (y % 10)
        {
            x = y % 10;
            y /= 10;
        }
        if (x == 3)
        {
            three = 1;
        }
    }
    if (three)
    {
        std::cout << "Найдено число начинающиеся с 3, массив отсортирован по восрастанию: ";
        for (int k = 0; k < ww - 1; ++k)
        {
            for (int j = k + 1; j < ww; ++j)
            {
                if (mass[k] > mass[j])
                {
                    std::swap(mass[k], mass[j]);
                }
            }
        }
    }
    else
    {
        std::cout << "Нет чисел начинающихся с 3: ";
    }
    for (int i = 0; i < ww; ++i)
    {
        std::cout << mass[i] << " ";
    }
    return 0;
}