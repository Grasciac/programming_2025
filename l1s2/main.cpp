#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <cmath>

void color(int c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

bool vowel(char c)
{
    std::string s = "аеёиоуыэюяАЕЁИОУЫЭЮЯaeiouyAEIOUY";

    for (int i = 0; i < s.length(); i++)
    {
        if (c == s[i])
            return true;
    }

    return false;
}

bool consonant(char c)
{
    std::string s = "бвгджзйклмнпрстфхцчшщБВГДЖЗЙКЛМНПРСТФХЦЧШЩbcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ";

    for (int i = 0; i < s.length(); i++)
    {
        if (c == s[i])
            return true;
    }

    return false;
}

bool digit(char c)
{
    return c >= '0' && c <= '9';
}

class JaggedArray
{
private:
    std::vector<std::vector<char>> a;

public:
    JaggedArray()
    {
        a.resize(4);
    }

    // Обращение A[i][j]
    std::vector<char> &operator[](int i)
    {
        return a[i];
    }

    // Добавление элемента
    void add(int row, char c)
    {
        if (row >= 0 && row < a.size())
            a[row].push_back(c);
    }

    // Количество строк
    int rows()
    {
        return a.size();
    }

    // Удаление элемента по двойному индексу delete(строка, номер)
    void deleteByIndex(int row, int index)
    {
        if (row >= 0 && row < a.size())
        {
            if (index >= 0 && index < a[row].size())
            {
                a[row].erase(a[row].begin() + index);
            }
        }
    }

    // Удаление элемента по значению delete(item)
    void deleteByValue(char item)
    {
        for (int i = 0; i < a.size(); i++)
        {
            a[i].erase(
                std::remove(a[i].begin(), a[i].end(), item),
                a[i].end());
        }
    }

    // Вывод массива
    void print()
    {
        std::cout << "\nЗубчатый массив:\n";

        for (int i = 0; i < a.size(); i++)
        {
            std::cout << "[" << i << "]: ";

            for (int j = 0; j < a[i].size(); j++)
            {
                std::cout << a[i][j] << " ";
            }

            std::cout << "\n";
        }
    }

    // Просмотр массива с цветами
    void printColor()
    {
        std::cout << "\nЦветной массив:\n";

        for (int i = 0; i < a.size(); i++)
        {
            std::cout << "[" << i << "]: ";

            for (int j = 0; j < a[i].size(); j++)
            {
                if (i == 0)
                    color(12); // красный
                else if (i == 1)
                    color(9); // синий
                else if (i == 2)
                    color(10); // зеленый
                else
                    color(14); // желтый

                std::cout << a[i][j] << " ";
            }

            color(7);
            std::cout << "\n";
        }
    }

    // Сортировка строк
    void sortRows()
    {
        for (int i = 0; i < a.size(); i++)
        {
            std::sort(a[i].begin(), a[i].end());
        }
    }

    // Вариант 3
    // operator -: унарный минус - построчное удаление дубликатов
    JaggedArray operator-() const
    {
        JaggedArray result;

        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < a[i].size(); j++)
            {
                bool found = false;

                // Проверяем, есть ли этот элемент в result[i]
                for (int k = 0; k < result[i].size(); k++)
                {
                    if (result[i][k] == a[i][j])
                    {
                        found = true;
                        break;
                    }
                }

                if (!found)
                    result[i].push_back(a[i][j]);
            }
        }

        return result;
    }

    // Вариант 3
    // operator --: для цифр извлечение корня, для символов сдвиг по коду
    JaggedArray &operator--()
    {
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < a[i].size(); j++)
            {
                if (digit(a[i][j]))
                {
                    int n = a[i][j] - '0';
                    int root = static_cast<int>(sqrt(n));
                    a[i][j] = root + '0';
                }
                else
                {
                    // Сдвиг символа по коду (уменьшение на 1)
                    a[i][j]--;
                }
            }
        }

        return *this;
    }
};

// Создание зубчатого массива
JaggedArray createArray(std::string text)
{
    JaggedArray a;

    for (int i = 0; i < text.length(); i++)
    {
        char c = text[i];

        int row = -1;

        if (vowel(c))
            row = 0;
        else if (consonant(c))
            row = 1;
        else if (digit(c))
            row = 2;
        else if (c != ' ' && c != '\n' && c != '\t')
            row = 3;

        if (row != -1)
        {
            a.add(row, c);
        }
    }

    return a;
}

// Поиск символа в зубчатом массиве
int findRow(JaggedArray &a, char c)
{
    for (int i = 0; i < a.rows(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            if (a[i][j] == c)
                return i;
        }
    }

    return -1;
}

// Раскраска строки
void printColored(std::string text, JaggedArray &a)
{
    for (int i = 0; i < text.length(); i++)
    {
        int row = findRow(a, text[i]);

        if (row == 0)
        {
            color(12); // красный
        }
        else if (row == 1)
        {
            color(9); // синий
        }
        else if (row == 2)
        {
            color(10); // зеленый
        }
        else if (row == 3)
        {
            color(14); // желтый
        }
        else
        {
            color(7);
        }

        std::cout << text[i];
    }

    color(7);
    std::cout << "\n";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string text;

    std::cout << "Введите строку (не более 50 символов):\n";
    std::getline(std::cin, text);

    if (text.length() > 50)
    {
        std::cout << "Ошибка! Слишком длинная строка.\n";
        return 0;
    }

    JaggedArray a = createArray(text);

    std::cout << "\nИсходный массив:\n";
    a.printColor();

    // Сортировка
    a.sortRows();

    std::cout << "\nПосле сортировки:\n";
    a.printColor();

    // operator - (унарный)
    // Удаление дубликатов
    JaggedArray b = -a; // ИСПОЛЬЗУЕМ УНАРНЫЙ МИНУС

    std::cout << "\nПосле operator - (удаление дубликатов):\n";
    b.printColor();

    // operator --
    --b;

    std::cout << "\nПосле operator -- (корень для цифр, сдвиг для символов):\n";
    b.printColor();

    // Проверка удаления элемента по индексу
    if (b[0].size() > 0)
    {
        std::cout << "\nУдаление элемента по индексу [0][0]...\n";
        b.deleteByIndex(0, 0);
        b.printColor();
    }

    // Проверка удаления элемента по значению
    if (b[1].size() > 0)
    {
        char value = b[1][0];
        std::cout << "\nУдаление элемента по значению '" << value << "'...\n";
        b.deleteByValue(value);
        b.printColor();
    }

    color(7);

    return 0;
}