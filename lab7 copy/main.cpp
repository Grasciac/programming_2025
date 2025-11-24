#include <iostream>
#include <vector>
#include <array>
#include <ctime>

void ArrStat(std::array<int, 10> &row)
{
    const size_t ARRAY_SIZE = 10;
    std::srand(std::time(0));
    for (size_t i = 0; i < ARRAY_SIZE; ++i)
    {
        row[i] = std::rand() % 21 - 10;
    }
    std::cout << "[";
    for (const int &element : row)
    {
        std::cout << element << " ";
    }
    std::cout << "\b]" << std::endl;
}

void vivod(std::array<int, 10> row)
{
    std::cout << "[";
    for (const int &element : row)
    {
        std::cout << element << " ";
    }
    std::cout << "\b]" << std::endl;
}

void SorPoZnacheniu(std::array<int, 10> row)
{
    for (size_t i = 0; i < row.size() - 1; ++i)
    {
        for (size_t j = 0; j < row.size() - 1 - i; ++j)
        {
            if (row[j] > row[j + 1])
            {
                std::swap(row[j], row[j + 1]);
            }
        }
    }
    std::cout << "Функция сортировки: ";
    vivod(row);
}

void SorPoSsilki(std::array<int, 10> &row)
{
    for (size_t i = 0; i < row.size() - 1; ++i)
    {
        for (size_t j = 0; j < row.size() - 1 - i; ++j)
        {
            if (row[j] > row[j + 1])
            {
                std::swap(row[j], row[j + 1]);
            }
        }
    }
    std::cout << "Функция сортировки: ";
    vivod(row);
}

void SorPoYkazatelu(std::array<int, 10> *row)
{
    for (int i = 0; i < (*row).size() - 1; ++i)
    {
        for (int j = 0; j < (*row).size() - 1 - i; ++j)
        {
            if ((*row)[j] < (*row)[j + 1])
            {
                std::swap((*row)[j], (*row)[j + 1]);
            }
        }
    }
    std::cout << "Функция сортировки: ";
    vivod((*row));
}

void ArrDyn(std::vector<int> &row)
{
    std::cout << "[";
    for (size_t i = 0; i < row.size(); ++i)
    {
        std::cout << row[i];
        if (i != row.size() - 1)
        {
            std::cout << " ";
        }
    }
    std::cout << "]";
}

void FirstNumber(std::vector<int> &row, int a)
{
    row.insert(row.begin(), a);
}

void LastNumber(std::vector<int> &row, int a)
{
    row.push_back(a);
}

void ClearArray(std::vector<int> &row)
{
    row.clear();
}

void SearchElements(std::vector<int> &row, int a)
{
    bool isFounded = false;
    std::cout << "Найденные индексы: [";
    for (int i = 0; i < row.size(); ++i)
    {
        if (row[i] == a)
        {
            if (isFounded)
            {
                std::cout << ", ";
            }
            std::cout << i;
            isFounded = true;
        }
    }
    std::cout << "]" << std::endl;
}

void NechetChisla(std::vector<int> row)
{
    std::cout << "До: " << std::endl;
    ArrDyn(row);
    std::cout << std::endl;
    bool Hz = false;
    for (int i = row.size() - 1; i >= 0; --i)
    {
        if (i % 2 == 0 && row[i] % 2 != 0)
        {
            row.insert(row.begin() + i + 1, 0);
            Hz = true;
        }
    }

    if (!Hz)
    {
        row.insert(row.begin(), -1);
        row.push_back(-1);
    }
    std::cout << "После: " << std::endl;
    ArrDyn(row);
}
int main()
{
    std::array<int, 10> low;
    std::vector<int> gow;
    int choice;
    int elements;
    do
    {
        std::cout << "\n---Меню--- " << std::endl;
        std::cout << "0. Выход." << std::endl;
        std::cout << "1. Просмотр массива." << std::endl;
        std::cout << "2. Добавить элемент в начало. " << std::endl;
        std::cout << "3. Добавить элемент в конец. " << std::endl;
        std::cout << "4. Очистка Массива. " << std::endl;
        std::cout << "5. Поиск индекса по значению. " << std::endl;
        std::cout << "6. Нечетные числа. " << std::endl;
        std::cout << "7. Просмотр массива фиксированной длины: " << std::endl;
        std::cout << "8. Сортировка массива (демонстрация разницы передачи аргументов). " << std::endl;
        std::cout << "Выбор пункта: ";
        std::cin >> choice;
        switch (choice)
        {
        case 0:
            std::cout << "Выход. " << std::endl;
            break;
        case 1:
            std::cout << "Просмотр Массива: " << std::endl;
            ArrDyn(gow);
            break;
        case 2:
            std::cout << "Добавить элемент в начало: " << std::endl;
            std::cin >> elements;
            FirstNumber(gow, elements);
            break;
        case 3:
            std::cout << "Добавить элемент в конец: " << std::endl;
            std::cin >> elements;
            LastNumber(gow, elements);
            break;
        case 4:
            std::cout << "Очистка всего массива." << std::endl;
            ClearArray(gow);
            break;
        case 5:
            std::cout << "Поиск элемента: " << std::endl;
            std::cin >> elements;
            SearchElements(gow, elements);
            break;
        case 6:
            std::cout << "Задание по варианту: " << std::endl;
            NechetChisla(gow);
            break;
        case 7:
            std::cout << "Массив Array: ";
            ArrStat(low);
            break;
        case 8:
            std::cout << "Сортировка: " << std::endl;
            std::cout << "До сортировки по ссылке: ";
            ArrStat(low);
            SorPoSsilki(low);
            std::cout << "После сортировки: ";
            vivod(low);
            std::cout << std::endl;
            std::cout << "До сортировки по указателю: ";
            vivod(low);
            SorPoYkazatelu(&low);
            std::cout << "После сортировки: ";
            vivod(low);
            std::cout << std::endl;
            std::cout << "До сортировки по значению: ";
            vivod(low);
            SorPoZnacheniu(low);
            std::cout << "После сортировки: ";
            vivod(low);
            std::cout << std::endl;
            break;
        default:
            std::cout << "Неверный ввод. " << std::endl;
            break;
        }
    } while (choice != 0);
    return 0;
}