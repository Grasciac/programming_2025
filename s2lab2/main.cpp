#include <iostream>
#include <vector>
#include <string>
#include <limits>

class DateOfFound
{
public:
    DateOfFound() = default;
    DateOfFound(unsigned short day, unsigned short month, int year)
        : _day(day), _month(month), _year(year) {}

    std::string toString() const
    {
        return std::to_string(_day) + "." +
               std::to_string(_month) + "." +
               std::to_string(_year);
    }

private:
    unsigned short _day = 1;
    unsigned short _month = 1;
    int _year = 1;
};

class Country
{
public:
    Country()
    {
        _name = "Россия";
        _capital = "Москва";
        _square = 17100000;
        _cities.push_back("Москва");
        _dateOfFound = DateOfFound(12, 12, 1991);

        std::cout << "Страна создана: " << _name << std::endl;
    }

    Country(const std::string &name, const std::string &capital, const DateOfFound &dateOfFound, long double square, const std::vector<std::string> &cities)
    {
        _name = name;
        _capital = capital;
        _dateOfFound = dateOfFound;
        _square = square;
        _cities = cities;

        std::cout << "Страна создана: " << _name << std::endl;
    }

    Country(const Country &other)
    {
        _name = other._name;
        _capital = other._capital;
        _dateOfFound = other._dateOfFound;
        _square = other._square;
        _cities = other._cities;

        std::cout << "Страна скопирована: " << _name << std::endl;
    }

    Country &operator=(const Country &other)
    {
        if (this != &other)
        {
            _name = other._name;
            _capital = other._capital;
            _dateOfFound = other._dateOfFound;
            _square = other._square;
            _cities = other._cities;
        }
        return *this;
    }

    ~Country()
    {
        _cities.clear();
        std::cout << "Страна удалена: " << _name << std::endl;
    }

    Country &operator+=(const Country &other)
    {
        _name = _name + "-" + other._name;

        if (other._square > _square)
            _capital = other._capital;

        _square = _square + other._square;

        for (int i = 0; i < (int)other._cities.size(); i++)
        {
            bool exists = false;
            for (int j = 0; j < (int)_cities.size(); j++)
            {
                if (_cities[j] == other._cities[i])
                {
                    exists = true;
                    break;
                }
            }
            if (!exists)
                _cities.push_back(other._cities[i] + " (новый)");
        }
        return *this;
    }

    friend Country operator+(Country left, const Country &right)
    {
        left += right;
        return left;
    }

    friend Country operator*(const Country &a, const Country &b)
    {
        Country result;

        result._name = "путь " + a._name + "->" + b._name;
        result._capital = "нет";
        result._dateOfFound = a._dateOfFound;

        if (a._square < b._square)
            result._square = a._square;
        else
            result._square = b._square;

        result._cities.clear();
        result._cities.push_back(a._capital);
        result._cities.push_back(b._capital);

        if (a._cities.size() > 0)
            result._cities.push_back(a._cities[0]);
        if (b._cities.size() > 0)
            result._cities.push_back(b._cities[0]);

        return result;
    }

    void setCapital(const std::string &capital)
    {
        _capital = capital;
    }

    void print() const
    {
        std::cout << "\n--- Информация о стране ---\n";
        std::cout << "Название: " << _name << std::endl;
        std::cout << "Столица: " << _capital << std::endl;
        std::cout << "Дата основания: " << _dateOfFound.toString() << std::endl;
        long long squareInt = (long long)_square;
        std::cout << "Площадь: " << squareInt << " кв. км" << std::endl;

        std::cout << "Города: ";
        for (int i = 0; i < (int)_cities.size(); i++)
            std::cout << _cities[i] << " ";
        std::cout << std::endl;
    }

private:
    std::string _name;
    std::string _capital;
    DateOfFound _dateOfFound;
    long double _square;
    std::vector<std::string> _cities;
};

void PrintMenu()
{
    std::cout << "\n--- МЕНЮ ---\n";
    std::cout << "0. Выход\n";
    std::cout << "1. Просмотр информации\n";
    std::cout << "2. Сделать новую столицу\n";
    std::cout << "3. Присоединить страну\n";
    std::cout << "4. Построить путь\n";
    std::cout << "Выберите: ";
}

int main()
{
    Country country;
    int choice;
    do
    {
        PrintMenu();
        std::cin >> choice;

        if (choice == 1)
        {
            country.print();
        }
        else if (choice == 2)
        {
            std::string capital;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, capital);
            country.setCapital(capital);
        }
        else if (choice == 3)
        {
            std::string name, capital, city;
            int day, month, year;
            long double square;
            int cityCount;
            std::vector<std::string> cities;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Название страны: ";
            std::getline(std::cin, name);

            std::cout << "Столица: ";
            std::getline(std::cin, capital);

            std::cout << "Дата основания (день месяц год): ";
            std::cin >> day >> month >> year;

            std::cout << "Площадь: ";
            std::cin >> square;

            std::cout << "Количество городов: ";
            std::cin >> cityCount;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            for (int i = 0; i < cityCount; i++)
            {
                std::cout << "Город " << i + 1 << ": ";
                std::getline(std::cin, city);
                cities.push_back(city);
            }

            Country other(name, capital, DateOfFound(day, month, year), square, cities);
            country += other;
        }
        else if (choice == 4)
        {
            std::string name, capital, city;
            int day, month, year;
            long double square;
            int cityCount;
            std::vector<std::string> cities;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Название второй страны: ";
            std::getline(std::cin, name);

            std::cout << "Столица: ";
            std::getline(std::cin, capital);

            std::cout << "Дата основания (день месяц год): ";
            std::cin >> day >> month >> year;

            std::cout << "Площадь: ";
            std::cin >> square;

            std::cout << "Количество городов: ";
            std::cin >> cityCount;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            for (int i = 0; i < cityCount; i++)
            {
                std::cout << "Город " << i + 1 << ": ";
                std::getline(std::cin, city);
                cities.push_back(city);
            }

            Country other(name, capital, DateOfFound(day, month, year), square, cities);
            Country path = country * other;
            path.print();
        }

    } while (choice != 0);

    return 0;
}
