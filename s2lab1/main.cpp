#include <iostream>
#include <limits>

class DateOfFound
{
public:
    DateOfFound() = default;
    DateOfFound(const DateOfFound &other) : _day(other._day), _month(other._month), _year(other._year) {}
    DateOfFound(unsigned short day, unsigned short month, int year) : _day(day), _month(month), _year(year) {}
    ~DateOfFound() = default;
    std::string toString()
    {
        std::string date;
        std::string yearType;
        int year = _year;
        yearType = "";
        if (_year <= 0)
        {
            year = -year;
            yearType = " ДО Н.Э.";
        }
        date = std::to_string(_day) + "." + std::to_string(_month) + "." + std::to_string(year) + yearType;
        return date;
    }
    unsigned short getDay() const { return _day; }
    unsigned short getMonth() const { return _month; }
    int getYear() const { return _year; }

private:
    unsigned short _day;
    unsigned short _month;
    int _year;
};

class Country
{
public:
    Country()
    {
        _name = "Россия";
        _capital = "Москва";
        _dateOfFound = DateOfFound(12, 12, 1991);
        _square = 17100000;
        _population = 14600000;
    };
    Country(const std::string &name, const std::string capital, const DateOfFound &dateOfFound, double square, double popalation) : _name(name), _capital(capital), _dateOfFound(dateOfFound), _square(square), _population(popalation)
    {
        std::cout << "Страна создана: " << _name << std::endl;
    }
    Country(const Country &other) : _name(other._name), _capital(other._capital), _dateOfFound(other._dateOfFound), _square(other._square), _population(other._population)
    {
        std::cout << "Страна скопирована" << std::endl;
    }
    ~Country()
    {
        std::cout << "Страна удалена из списка: " << _name << std::endl;
    }

    void set_capital(std::string &capital)
    {
        _capital = capital;
    }
    void accessionSquare(double new_square, double new_population)
    {
        if (new_square < 0 || new_population < 0)
        {
            std::cout << "Площадь или население не может быть отрицательными." << std::endl;
            return;
        }
        _square += new_square;
        _population += new_population;
        std::cout << "Присоединена территория:" << std::endl;
        std::cout << "Площадь: +" << new_square << " кв. км" << std::endl;
        std::cout << "Население: +" << new_population << " чел." << std::endl;
        std::cout << "Общая площадь: " << _square << " кв. км" << std::endl;
        std::cout << "Общее население: " << _population << " чел." << std::endl;
    }
    std::string get_name() const { return _name; }
    std::string get_capital() const { return _capital; }
    DateOfFound get_dateOfFound() const { return _dateOfFound; }
    double get_square() const { return _square; }
    double get_population() const { return _population; }

private:
    std::string _name;
    std::string _capital;
    DateOfFound _dateOfFound;
    long double _square;
    long double _population;
};

void PrintMenu()
{
    std::cout << "\n---МЕНЮ---" << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << "1. Просмотр информации" << std::endl;
    std::cout << "2. Сделать новую столицу" << std::endl;
    std::cout << "3. Присоединить новую территорию" << std::endl;
    std::cout << "Выберите: ";
}
void ViewInfo(const Country &country)
{
    std::cout << "\n--- Информация о стране ---" << std::endl;
    std::cout << "Название: " << country.get_name() << std::endl;
    std::cout << "Столица: " << country.get_capital() << std::endl;
    std::cout << "Дата основания: " << country.get_dateOfFound().toString() << std::endl;
    std::cout << "Площадь: " << country.get_square() << " кв. км" << std::endl;
    std::cout << "Население: " << country.get_population() << " чел." << std::endl;
}

int main()
{
    int choice;
    std::string capital;
    Country country = Country();
    do
    {
        PrintMenu();
        std::cin >> choice;
        switch (choice)
        {
        case 0:
            std::cout << " Выход. " << std::endl;
            break;
        case 1:
            ViewInfo(country);
            break;
        case 2:
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, capital);
            country.set_capital(capital);
            break;
        case 3:
            double square;
            double population;
            std::cout << "Введите число кв.км новой территории и число населения" << "\n";
            std::cin >> square >> population;
            country.accessionSquare(square, population);
            break;
        }
    } while (choice != 0);
    return 0;
}