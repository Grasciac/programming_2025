#include <iostream>

int main()
{
    int a;
    int b;
    std::cout << "A = ";
    std::cin >> a;
    std::cout << "B = ";
    std::cin >> b;
    int *tmp = new int;
    int *Ax;
    int *Bx;
    Ax = &a;
    Bx = &b;
    *Ax = *Ax * 2;
    std::cout << "Значение A = " << a << std::endl;

    *tmp = *Ax;
    *Ax = *Bx;
    *Bx = *tmp;
    delete tmp;
    return 0;
}