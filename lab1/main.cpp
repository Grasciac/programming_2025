#include <iostream> 
#include <cmath> //<cmath> - математический модуль
int main() { //функция мейн
    setlocale(LC_ALL, "RU"); 
    std::cout <<"Первая сторона треугольника" <<std::endl; // endl - скидывает на след строку
    unsigned int a; // unsigned int - тип целочисленных данных (только положительные), по условию
    std:: cin >> a; 
    std::cout <<"Вторая сторона треугольника" <<std::endl;
    unsigned int b;
    std:: cin >> b;
    std::cout <<"Третья сторона треугольника" <<std::endl;
    unsigned int c;
    std:: cin >> c;
    double p = (a+b+c)/2.0; // double - тип вещественных данных, с плавающей точкой
    std:: cout <<"Полумериметр треугольника = "  << p << std::endl;
    double S = sqrt(p *(p-a) * (p-b) * (p-c)); // sqrt - корень, для которого нужен модуль cmath
    std:: cout <<"int занимает = " << sizeof(int)*8 << std::endl;
    std:: cout <<"MAX int значение = " << INT_MAX << std::endl;
    std:: cout <<"MIN int значение = " << INT_MIN << std::endl; 
    std:: cout <<"double занимает = " << sizeof(double)*8 << std::endl;
    std:: cout <<"MAX double значение = " << __DBL_MAX__ << std::endl;
    std:: cout <<"MIN double значение = " << __DBL_MIN__ << std::endl;
    std:: cout <<"Площадь по формуле герона = " << S << std::endl;
    return 0;
}