#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

class JaggedArray
{
public:
    std::vector<std::vector<std::string>> data;

    JaggedArray() {}

    bool loadFromFile(const std::string &filename)
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            std::cout << "[Ошибка] Не удалось открыть файл: " << filename << std::endl;
            return false;
        }
        data.clear();
        std::string line;
        while (std::getline(file, line))
        {
            std::vector<std::string> row;
            std::stringstream ss(line);
            std::string word;
            while (ss >> word)
            {
                row.push_back(word);
            }
            data.push_back(row);
        }
        file.close();
        return true;
    }

    std::string &operator()(int i, int j)
    {
        if (i < 0 || i >= data.size())
        {
            std::cout << "\n[Ошибка] Индекс строки i (" << i << ") не существует!" << std::endl;
            static std::string empty_str;
            empty_str = "";
            return empty_str;
        }
        if (j < 0 || j >= data[i].size())
        {
            std::cout << "\n[Ошибка] Индекс элемента j (" << j << ") не существует в строке " << i << "!" << std::endl;
            static std::string empty_str;
            empty_str = "";
            return empty_str;
        }
        return data[i][j];
    }

    void delete_by_index(int i, int j)
    {
        if (i >= 0 && i < data.size() && j >= 0 && j < data[i].size())
        {
            data[i].erase(data[i].begin() + j);
            std::cout << "Элемент [" << i << "][" << j << "] успешно удален." << std::endl;
        }
        else
        {
            std::cout << "\n[Ошибка удаления] Индексы (" << i << ", " << j << ") не существуют!" << std::endl;
        }
    }

    void delete_by_value(const std::string &item)
    {
        bool found = false;
        for (size_t i = 0; i < data.size(); ++i)
        {
            for (size_t j = 0; j < data[i].size(); ++j)
            {
                if (data[i][j] == item)
                {
                    data[i].erase(data[i].begin() + j);
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }
        if (found)
        {
            std::cout << "Первое вхождение слова \"" << item << "\" успешно удалено." << std::endl;
        }
        else
        {
            std::cout << "\nСлово \"" << item << "\" не найдено для удаления." << std::endl;
        }
    }

    void add_endline(int k, const std::string &item)
    {
        if (k >= 0 && k < data.size())
        {
            data[k].push_back(item);
            std::cout << "Слово \"" << item << "\" добавлено в строку " << k << "." << std::endl;
        }
        else
        {
            std::cout << "\n[Ошибка добавления] Строки " << k << " не существует!" << std::endl;
        }
    }

    void sort_rows()
    {
        for (size_t i = 0; i < data.size(); ++i)
        {
            std::sort(data[i].begin(), data[i].end());
        }
    }

    void print()
    {
        std::vector<std::string> colors = {"\033[31m", "\033[32m", "\033[33m", "\033[34m", "\033[35m", "\033[36m"};
        std::string reset = "\033[0m";

        if (data.empty())
        {
            std::cout << "(массив пуст / не загружен)" << std::endl;
            return;
        }

        for (size_t i = 0; i < data.size(); ++i)
        {
            std::cout << colors[i % colors.size()];
            std::cout << "  Строка " << i << ": ";
            for (size_t j = 0; j < data[i].size(); ++j)
            {
                std::cout << data[i][j] << " ";
            }
            std::cout << reset << std::endl;
        }
    }

    JaggedArray operator-()
    {
        JaggedArray result = *this;
        for (size_t i = 0; i < result.data.size(); ++i)
        {
            std::vector<std::string> unique_row;
            for (const std::string &word : result.data[i])
            {
                if (std::find(unique_row.begin(), unique_row.end(), word) == unique_row.end())
                {
                    unique_row.push_back(word);
                }
            }
            result.data[i] = unique_row;
        }
        return result;
    }
    JaggedArray &operator--()
    {
        for (size_t i = 0; i < data.size(); ++i)
        {
            for (size_t j = 0; j < data[i].size(); ++j)
            {
                std::string clean_word = "";
                for (char c : data[i][j])
                {
                    if (!std::isdigit(static_cast<unsigned char>(c)))
                    {
                        clean_word += c;
                    }
                }
                data[i][j] = clean_word;
            }
        }
        return *this;
    }
};

int main()
{
    std::setlocale(LC_ALL, "Russian");

    JaggedArray array1;
    JaggedArray array2;

    const std::string file1 = "file1.txt";
    const std::string file2 = "file2.txt";

    array1.loadFromFile(file1);
    array2.loadFromFile(file2);

    JaggedArray *current_array = &array1;
    std::string current_filename = file1;
    int active_num = 1;

    int choice = -1;
    while (choice != 0)
    {
        std::cout << "\n================ ОБА МАССИВА ================" << std::endl;
        std::cout << ">>> МАССИВ 1 (" << file1 << "):" << std::endl;
        array1.print();
        std::cout << "\n>>> МАССИВ 2 (" << file2 << "):" << std::endl;
        array2.print();
        std::cout << "=============================================" << std::endl;
        std::cout << "СЕЙЧАС ВЫБРАН: Массив " << active_num << " (" << current_filename << ")" << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "1. Переключить активный массив (1 <=> 2)" << std::endl;
        std::cout << "2. Получить элемент по индексам A(i, j)" << std::endl;
        std::cout << "3. Добавить элемент в конец строки add_endline(k, item)" << std::endl;
        std::cout << "4. Удалить элемент по индексам delete(i, j)" << std::endl;
        std::cout << "5. Удалить элемент по значению delete(item)" << std::endl;
        std::cout << "6. Отсортировать строки" << std::endl;
        std::cout << "7. Применить оператор - (Удалить дубликаты)" << std::endl;
        std::cout << "8. Применить оператор -- (Удалить цифры)" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        if (choice == 1)
        {
            if (active_num == 1)
            {
                current_array = &array2;
                current_filename = file2;
                active_num = 2;
            }
            else
            {
                current_array = &array1;
                current_filename = file1;
                active_num = 1;
            }
            std::cout << "Переключено на Массив " << active_num << std::endl;
        }
        else if (choice == 2)
        {
            int i, j;
            std::cout << "Введите индекс строки i: ";
            std::cin >> i;
            std::cout << "Введите индекс элемента j: ";
            std::cin >> j;

            std::string res = (*current_array)(i, j);
            if (!res.empty())
            {
                std::cout << "Найдено значение: " << res << std::endl;
            }
        }
        else if (choice == 3)
        {
            int k;
            std::string item;
            std::cout << "Введите номер строки k: ";
            std::cin >> k;
            std::cout << "Введите слово для добавления: ";
            std::cin >> item;
            current_array->add_endline(k, item);
        }
        else if (choice == 4)
        {
            int i, j;
            std::cout << "Введите i: ";
            std::cin >> i;
            std::cout << "Введите j: ";
            std::cin >> j;
            current_array->delete_by_index(i, j);
        }
        else if (choice == 5)
        {
            std::string item;
            std::cout << "Введите слово для удаления: ";
            std::cin >> item;
            current_array->delete_by_value(item);
        }
        else if (choice == 6)
        {
            current_array->sort_rows();
            std::cout << "Строки отсортированы." << std::endl;
        }
        else if (choice == 7)
        {
            *current_array = -(*current_array);
            std::cout << "Дубликаты удалены оператором [-]." << std::endl;
        }
        else if (choice == 8)
        {
            --(*current_array);
            std::cout << "Цифры удалены оператором [--]." << std::endl;
        }
    }

    std::cout << "Программа завершена." << std::endl;
    return 0;
}
