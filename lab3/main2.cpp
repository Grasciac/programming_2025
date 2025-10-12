#include <iostream>
int main()
{
    short x;
    short raz;
    short i;
    std::cout << "Число = ";
    std::cin >> x;
    if (abs(x) >= 1000)
    {
        std::cout << "Число X не удовлетворяет условию";
        return 1;
    }
    do
    {
        raz += 1;
        i = x % 10;
        x /= 10;
    } while (x % 10);
    std::cout << "Количество разрядов числа: " << raz << std::endl;
    std::cout << "Первая цифра числа: " << i << std::endl;

    return 0;
}