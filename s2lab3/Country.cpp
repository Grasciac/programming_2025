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

    _cityData.push_back({"Москва", _population, 0});

    _budget = Budget(1000000000, 0.2); // 1 млрд, 20% столице
}

Country::Country(const std::string &name, const std::string &capital,
                 int day, int month, int year,
                 long double square,
                 long long population,
                 const std::vector<std::string> &cities)
{
    _name = name;
    _capital = capital;
    _day = day;
    _month = month;
    _year = year;
    _square = square;
    _population = population;

    for (size_t i = 0; i < cities.size(); i++)
    {
        _cityData.push_back(
            City{
                cities[i],
                population / static_cast<long long>(cities.size()),
                0});
    }

    _budget = Budget(500000000, 0.2); // 500 млн по умолчанию
}

Country::Country(const Country &other)
    : _name(other._name), _capital(other._capital),
      _day(other._day), _month(other._month), _year(other._year),
      _square(other._square), _population(other._population),
      _cityData(other._cityData)
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
        _cityData = other._cityData;
    }
    return *this;
}

Country::~Country()
{
    _cityData.clear();
}

Country &Country::operator+=(const Country &other)
{
    _name = _name + "-" + other._name;

    if (other._square > _square)
        _capital = other._capital;

    _square += other._square;
    _population += other._population;

    for (const auto &city : other._cityData)
        _cityData.push_back(city);

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

    result._cityData.clear();
    result._cityData.push_back({a._capital, 0, 0});
    result._cityData.push_back({b._capital, 0, 0});

    return result;
}

void Country::setCapital(const std::string &capital)
{
    _capital = capital;
    _cityData.push_back({capital, 0, 0});
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

void Country::setBudget(long long money, double coeff)
{
    _budget.money = money;
    _budget.coefficient = coeff;
}

void Country::addBudget(long long amount)
{
    _budget.money += amount;
    distributeBudget();
}
void Country::distributeBudget()
{
    if (_cityData.empty())
        return;

    long long totalPopulation = 0;
    for (const auto &city : _cityData)
        totalPopulation += city.population;

    if (totalPopulation == 0)
        return;

    long long capitalBonus = static_cast<long long>(_budget.money * _budget.coefficient);

    long long remainingBudget = _budget.money - capitalBonus;

    for (auto &city : _cityData)
    {

        long long share = (city.population * remainingBudget) / totalPopulation;
        city.availableMoney = share;
        if (city.name == _capital)
            city.availableMoney += capitalBonus;
    }
}

void Country::printCities() const
{
    std::cout << "\n--- Распределение бюджета ---\n";

    for (int i = 0; i < _cityData.size(); i++)
    {
        std::cout << _cityData[i].name
                  << " (население: "
                  << _cityData[i].population
                  << ") — "
                  << _cityData[i].availableMoney
                  << "\n";
    }
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
    for (const auto &city : _cityData)
        std::cout << city.name << " ";
    std::cout << "\n";
}
