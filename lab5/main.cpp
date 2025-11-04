#include <iostream>
#include <cmath>

int getNumberLenth(int number)
{
    std::cout << "Выполняется: Функция получения длины числа" << std::endl;
    int lenth = 0;
    do
    {
        lenth++;
        number /= 10;
    } while (number > 0);
    return lenth;
}

int numbers(int a, int b)
{
    std::cout << "Выполняется: Функция для двух переменных" << std::endl;
    return a * pow(10, getNumberLenth(b)) + b;
}

int numbers(int a)
{
    std::cout << "Выполняется: Функция для одной переменной" << std::endl;
    return -a;
}

bool dataIsCorrect(int a, int b)
{
    std::cout << "Выполняется: функция проверки корректности данных" << std::endl;
    return ((a >= 0) && (b >= 0) && !((a == b) && (a == 0)));
}

void lr1()
{
    std::cout << "Первая сторона треугольника =" << std::endl;
    unsigned int a;
    std::cin >> a;
    std::cout << "Вторая сторона треугольника =" << std::endl;
    unsigned int b;
    std::cin >> b;
    std::cout << "Третья сторона треугольника =" << std::endl;
    unsigned int c;
    std::cin >> c;
    double p = (a + b + c) / 2.0;
    std::cout << "Полумериметр треугольника = " << p << std::endl;
    double S = sqrt(p * (p - a) * (p - b) * (p - c));
    std::cout << "int занимает = " << sizeof(int) * 8 << std::endl;
    std::cout << "MAX int значение = " << INT_MAX << std::endl;
    std::cout << "MIN int значение = " << INT_MIN << std::endl;
    std::cout << "double занимает = " << sizeof(double) * 8 << std::endl;
    std::cout << "MAX double значение = " << __DBL_MAX__ << std::endl;
    std::cout << "MIN double значение = " << std::numeric_limits<double>::lowest() << std::endl;
    std::cout << "Площадь по формуле герона = " << S << std::endl;
}

void task()
{
    std::cout << "Выполняется: функция для первого пункта" << std::endl;
    ;
    int taskType = 0;
    int resultValue = 0;
    int a = 0;
    int b = 0;
    std::cout << "Введите первое число: ";
    std::cin >> a;
    std::cout << "Введите второе число: ";
    std::cin >> b;
    if (!dataIsCorrect(a, b))
    {
        std::cout << "Введены не корректные данные" << std::endl;
        return;
    }
    if ((a == 0) || (b == 0))
    {
        if (b > a)
        {
            a = b;
        }
        resultValue = numbers(a);
    }
    else
    {
        resultValue = numbers(a, b);
    }
    std::cout << "Результат выполнения функции: " << resultValue << std::endl;
}

int main()
{
    int a;
    std::cout << "Какой пункт будет выполняться(1 или 2): ";
    std::cin >> a;
    if (a == 1)
    {
        std::cout << "Выполняется пункт первый: " << std::endl;
        task();
    }
    else if (a == 2)
    {
        std::cout << "Выполняется пункт второй: " << std::endl;
        lr1();
    }
    else
    {
        std::cout << "Введен пункт некорректно. Введите заново";
    }
    return 0;
}