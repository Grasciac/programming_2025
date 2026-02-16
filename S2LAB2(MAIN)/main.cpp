#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "Country.cpp"

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
    std::cout << "7. Изменить столицу страны\n";
    std::cout << "8. Изменить население страны\n";
    std::cout << "Выберите: ";
}

int main()
{
    std::vector<Country> countries;
    countries.push_back(Country());
    countries.push_back(Country("Германия", "Берлин", 3, 10, 1990, 357022, 83000000, {"Берлин", "Гамбург", "Мюнхен"}));
    countries.push_back(Country("Франция", "Париж", 22, 9, 1792, 551695, 67000000, {"Париж", "Марсель", "Лион"}));
    countries.push_back(Country("Япония", "Токио", 11, 2, -660, 377975, 125000000, {"Токио", "Осака", "Киото"}));

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
            long long population;
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

            std::cout << "Население страны: ";
            std::cin >> population;

            std::cout << "Количество городов: ";
            std::cin >> cityCount;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            for (int i = 0; i < cityCount; i++)
            {
                std::cout << "Город " << i + 1 << ": ";
                std::getline(std::cin, city);
                cities.push_back(city);
            }

            countries.push_back(Country(name, capital, day, month, year, square, population, cities));
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
        else if (choice == 7)
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
        else if (choice == 8)
        {
            int idx;
            long long newPopulation;
            std::cout << "Индекс страны: ";
            std::cin >> idx;
            if (idx >= 0 && idx < countries.size())
            {
                std::cout << "Новое население: ";
                std::cin >> newPopulation;
                countries[idx].setPopulation(newPopulation);
                std::cout << "Население изменено.\n";
            }
        }

    } while (choice != 0);

    std::cout << "Выход из программы.\n";
    return 0;
}
