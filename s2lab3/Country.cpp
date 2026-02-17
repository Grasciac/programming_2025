#include "Country.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

Country::Country()
{
    _name = "Россия";
    _capital = "Москва";
    _square = 17100000;
    _population = 146000000;
    _day = 12;
    _month = 12;
    _year = 1991;
    _cities.push_back("Москва");

    _cityData.push_back({"Москва", _population, 0});
}

Country::Country(const std::string &name, const std::string &capital,
                 int day, int month, int year,
                 long double square,
                 long long population,
                 const std::vector<std::string> &cities)
    : _name(name), _capital(capital), _day(day), _month(month), _year(year),
      _square(square), _population(population), _cities(cities)
{
    for (auto &c : cities)
    {
        _cityData.push_back({c, population / (int)cities.size(), 0});
    }
}

Country::Country(const Country &other)
    : _name(other._name), _capital(other._capital),
      _day(other._day), _month(other._month), _year(other._year),
      _square(other._square), _population(other._population),
      _cities(other._cities), _cityData(other._cityData)
{
}

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
        _population = other._population;
        _cities = other._cities;
        _cityData = other._cityData;
    }
    return *this;
}

Country::~Country()
{
    _cities.clear();
    _cityData.clear();
}

Country &Country::operator+=(const Country &other)
{
    _name = _name + "-" + other._name;

    if (other._square > _square)
        _capital = other._capital;

    _square += other._square;
    _population += other._population;

    for (const auto &city : other._cities)
        _cities.push_back(city);

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
    result._population = 0;

    result._cities.clear();
    result._cities.push_back(a._capital);
    result._cities.push_back(b._capital);

    return result;
}

void Country::setCapital(const std::string &capital)
{
    _capital = capital;
    _cities.push_back(capital);
}

void Country::setPopulation(long long population)
{
    _population = population;
}

void Country::addTerritory(long double additionalSquare)
{
    if (additionalSquare > 0)
        _square += additionalSquare;
}

void Country::print() const
{
    std::cout << "\n--- Информация о стране ---\n";
    std::cout << "Название: " << _name << "\n";
    std::cout << "Столица: " << _capital << "\n";
    std::cout << "Дата основания: " << _day << "." << _month << "." << _year << "\n";
    std::cout << "Площадь: " << static_cast<long long>(_square) << " кв. км\n";
    std::cout << "Население: " << _population << " чел.\n";
    std::cout << "Города: ";
    for (auto &city : _cities)
        std::cout << city << " ";
    std::cout << "\n";
}

void Country::distributeBudget(const Budget &budget)
{
    long long totalPop = 0;
    for (auto &c : _cityData)
        totalPop += c.population;

    if (totalPop == 0)
        return;

    long long capitalBonus = static_cast<long long>(budget.money * budget.coefficient);

    for (auto &c : _cityData)
    {
        long long share = (c.population * (budget.money - capitalBonus)) / totalPop;
        c.availableMoney = share;
        if (c.name == _capital)
            c.availableMoney += capitalBonus;
    }
}

void Country::printCities() const
{
    std::cout << "\n--- Распределение бюджета по городам ---\n";
    for (auto &c : _cityData)
        std::cout << c.name << " (" << c.population << " чел.): " << c.availableMoney << "\n";
}
