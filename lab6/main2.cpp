#include <iostream>
int main()
{
    int *a = new int;
    int *b = new int;
    std::cout << "Введите значение a: ";
    std::cin >> *a;
    std::cout << "Введите значение b: ";
    std::cin >> *b;
    int **pa = &a;
    int **pb = &b;
    **pa *= 2;
    std::cout << "Значение A, увеличенное через указатель в 2 раза: " << *a << std::endl;
    std::swap(**pa, **pb);
    std::cout << "После операций: a = " << *a << std::endl
              << "b = " << *b << std::endl;
    delete a;
    delete b;
    return 0;
}