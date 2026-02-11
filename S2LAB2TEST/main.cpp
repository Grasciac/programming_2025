#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <ctime>

class Country
{
public:
    // Конструктор по умолчанию
    Country()
    {
        _name = "Россия";
        _capital = "Москва";
        _square = 17100000;
        _day = 12;
        _month = 12;
        _year = 1991;
        _cities.push_back("Москва");
    }

    // Конструктор с параметрами
    Country(const std::string &name, const std::string &capital,
            int day, int month, int year,
            long double square, const std::vector<std::string> &cities)
        : _name(name), _capital(capital), _day(day), _month(month), _year(year),
          _square(square), _cities(cities) {}

    // Конструктор копирования
    Country(const Country &other)
        : _name(other._name), _capital(other._capital),
          _day(other._day), _month(other._month), _year(other._year),
          _square(other._square), _cities(other._cities) {}

    // Оператор присваивания
    Country &operator=(const Country &other)
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

    // Деструктор
    ~Country()
    {
        _cities.clear(); // очищаем, но ничего не выводим
    }

    // Оператор +=
    Country &operator+=(const Country &other)
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

    // Операторы + и *
    friend Country operator+(Country left, const Country &right)
    {
        left += right;
        return left;
    }

    friend Country operator*(const Country &a, const Country &b)
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

    void setCapital(const std::string &capital)
    {
        _capital = capital;
        _cities.push_back(capital);
    }

    void print() const
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

private:
    std::string _name;
    std::string _capital;
    int _day = 1;
    int _month = 1;
    int _year = 1;
    long double _square;
    std::vector<std::string> _cities;
};

// Меню
void PrintMenu()
{
    std::cout << "\n--- МЕНЮ ---\n";
    std::cout << "0. Выход\n";
    std::cout << "1. Показать все страны\n";
    std::cout << "2. Создать новую страну\n";
    std::cout << "3. Операция +=\n";
    std::cout << "4. Операция + (создать новую)\n";
    std::cout << "5. Операция * (путь)\n";
    std::cout << "6. Операция =\n";
    std::cout << "7. Новая Столица: \n";
    std::cout << "Выберите: ";
}

int main()
{
    std::vector<Country> countries;
    countries.push_back(Country());
    countries.push_back(Country("Германия", "Берлин", 3, 10, 1990, 357022, {"Берлин", "Гамбург", "Мюнхен"}));
    countries.push_back(Country("Франция", "Париж", 22, 9, 1792, 551695, {"Париж", "Марсель", "Лион"}));
    countries.push_back(Country("Япония", "Токио", 11, 2, -660, 377975, {"Токио", "Осака", "Киото"}));

    int choice;
    do
    {
        PrintMenu();
        std::cin >> choice;

        if (choice == 1)
        {
            for (int i = 0; i < countries.size(); i++)
            {
                std::cout << "\nИндекс: " << i << "\n";
                countries[i].print();
            }
        }
        else if (choice == 2)
        {
            std::string name, capital, city;
            int day, month, year, cityCount;
            long double square;
            std::vector<std::string> cities;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Название: ";
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

            countries.push_back(Country(name, capital, day, month, year, square, cities));
        }
        else if (choice == 3)
        {
            int a, b;
            std::cout << "Индекс первой страны: ";
            std::cin >> a;
            std::cout << "Индекс второй страны: ";
            std::cin >> b;
            if (a >= 0 && a < countries.size() && b >= 0 && b < countries.size())
                countries[a] += countries[b];
        }
        else if (choice == 4)
        {
            int a, b;
            std::cout << "Индекс первой страны: ";
            std::cin >> a;
            std::cout << "Индекс второй страны: ";
            std::cin >> b;
            if (a >= 0 && a < countries.size() && b >= 0 && b < countries.size())
                countries.push_back(countries[a] + countries[b]);
        }
        else if (choice == 5)
        {
            int a, b;
            std::cout << "Индекс первой страны: ";
            std::cin >> a;
            std::cout << "Индекс второй страны: ";
            std::cin >> b;
            if (a >= 0 && a < countries.size() && b >= 0 && b < countries.size())
                countries.push_back(countries[a] * countries[b]);
        }
        else if (choice == 6)
        {
            int a, b;
            std::cout << "Куда копировать (индекс): ";
            std::cin >> a;
            std::cout << "Откуда копировать (индекс): ";
            std::cin >> b;
            if (a >= 0 && a < countries.size() && b >= 0 && b < countries.size())
                countries[a] = countries[b];
        }
        else if (choice == 7) // изменение столицы
        {
            int idx;
            std::string newCapital;
            std::cout << "Индекс страны для изменения столицы: ";
            std::cin >> idx;
            if (idx >= 0 && idx < countries.size())
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Новая столица: ";
                std::getline(std::cin, newCapital);
                countries[idx].setCapital(newCapital);
                std::cout << "Столица изменена.\n";
            }
        }

    } while (choice != 0);

    std::cout << "Выход из программы. Все страны будут удалены автоматически.\n";
    return 0;
}
