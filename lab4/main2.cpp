#include <iostream>
int main()
{
    int summax = 0;
    int index = 0;
    const int ww = 3;
    const int ll = 4;
    int mass[ww][ll];
    for (int i = 0; i < ww; ++i)
    {
        int summ = 0;
        for (int j = 0; j < ll; ++j)
        {
            std::cout << "Строка " << i + 1 << " Столбец " << j + 1 << ": ";
            std::cin >> mass[i][j];
            summ += mass[i][j];
        }
        if (abs(summ) > summax)
        {
            summax = abs(summ);
            index = i;
        }
    }
    for (int i = 0; i < ll; ++i)
    {
        mass[index][i] = 999;
    }
    for (int i = 0; i < ww; ++i)
    {
        for (int j = 0; j < ll; ++j)
        {
            std::cout << mass[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}