#include "County.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

Country::Country()
{
    _name = "Россия";
    _capital = "Москва";
    _square = 17100000;
    _day = 12;
    _month = 12;
    _year = 1991;
    _cities.push_back("Москва");
}

Country::Country(const std::string &name, const std::string &capital,
                 int day, int month, int year,
                 long double square, const std::vector<std::string> &cities)
    : _name(name), _capital(capital), _day(day), _month(month), _year(year),
      _square(square), _cities(cities) {}

Country::Country(const Country &other)
    : _name(other._name), _capital(other._capital),
      _day(other._day), _month(other._month), _year(other._year),
      _square(other._square), _cities(other._cities) {}

Country &Country::operator=(const Country &other)
{
    if (this != &other)
    {
        _name = other._name;
        _capital = other._capital;
        _day = other._day;
        _month = other._month;
        _year = other._year;
        _square = other._square;
        _cities = other._cities;
    }
    return *this;
}

Country::~Country()
{
    _cities.clear();
}

Country &Country::operator+=(const Country &other)
{
    _name = _name + "-" + other._name;

    if (other._square > _square)
        _capital = other._capital;

    _square += other._square;

    for (const auto &city : other._cities)
    {
        bool exists = false;
        for (const auto &c : _cities)
        {
            if (c == city)
            {
                exists = true;
                break;
            }
        }
        _cities.push_back(exists ? city + " (новый)" : city);
    }
    return *this;
}

Country operator+(Country left, const Country &right)
{
    left += right;
    return left;
}

Country operator*(const Country &a, const Country &b)
{
    Country result;
    std::srand(std::time(0));
    result._name = "путь " + a._name + "->" + b._name;
    result._capital = "нет";
    result._day = a._day;
    result._month = a._month;
    result._year = a._year;
    result._square = (a._square < b._square) ? a._square : b._square;

    result._cities.clear();
    result._cities.push_back(a._capital);
    result._cities.push_back(b._capital);

    if (!a._cities.empty())
        result._cities.push_back(a._cities[std::rand() % a._cities.size()]);
    if (!b._cities.empty())
        result._cities.push_back(b._cities[std::rand() % b._cities.size()]);

    return result;
}

void Country::setCapital(const std::string &capital)
{
    _capital = capital;
    _cities.push_back(capital);
}

void Country::print() const
{
    std::cout << "\n--- Информация о стране ---\n";
    std::cout << "Название: " << _name << "\n";
    std::cout << "Столица: " << _capital << "\n";
    std::cout << "Дата основания: " << _day << "." << _month << "." << _year << "\n";
    std::cout << "Площадь: " << static_cast<long long>(_square) << " кв. км\n";
    std::cout << "Города: ";
    for (const auto &city : _cities)
        std::cout << city << " ";
    std::cout << "\n";
}
