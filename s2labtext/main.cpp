#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstring>

int is_ru_vowel(unsigned char c)
{
    unsigned char vowels[] = {224, 229, 184, 232, 238, 243, 253, 242, 250, 255}; // а, е, ё, и, о, у, ы, э, ю, я
    for (int i = 0; i < 10; i++)
        if (c == vowels[i])
            return 1;
    return 0;
}

unsigned char ru_to_upper(unsigned char c)
{
    if (c >= 224 && c <= 255)
        return c - 32;
    if (c == 184)
        return 168; // ё -> Ё
    return c;
}

void normalize_word(const char *src, char *dst)
{
    int k = 0;
    for (int i = 0; src[i]; i++)
    {
        unsigned char c = (unsigned char)src[i];
        if (c == '-')
            continue; // удалить дефис
        if (c >= 'A' && c <= 'Z')
            dst[k++] = c + 32;
        else if (c >= 192 && c <= 223)
            dst[k++] = c + 32;
        else
            dst[k++] = c;
    }
    dst[k] = '\0';
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "Таблица Буква/Код:\n";
    for (int c = 'A'; c <= 'Z'; c++)
        std::cout << (char)c << " = " << c << "\n";
    for (int c = 'a'; c <= 'z'; c++)
        std::cout << (char)c << " = " << c << "\n";

    // Русский алфавит (Windows-1251)
    for (int c = 192; c <= 223; c++)
        std::cout << (char)c << " = " << c << "\n"; // А-Я
    for (int c = 224; c <= 255; c++)
        std::cout << (char)c << " = " << c << "\n"; // а-я
    std::cout << (char)168 << " = " << 168 << "\n"; // Ё
    std::cout << (char)184 << " = " << 184 << "\n"; // ё

    // Цифры
    for (int c = '0'; c <= '9'; c++)
        std::cout << (char)c << " = " << c << "\n";

    // Стандартные знаки препинания
    const char punctuation[] = ".,!?;:-()\"'";
    for (int i = 0; i < sizeof(punctuation) - 1; i++)
        std::cout << punctuation[i] << " = " << (int)(unsigned char)punctuation[i] << "\n";
    // ---------------- Задача 1 ----------------
    char str[101];
    std::cout << "\nВведите строку (до 100 символов, Windows-1251):\n";
    std::cin.getline(str, 101);
    for (int i = 0; str[i]; i++)
    {
        unsigned char c = (unsigned char)str[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                str[i] = c - 32;
        }
        else
        {
            if (is_ru_vowel(c))
                str[i] = ru_to_upper(c);
        }
    }
    std::cout << "\nРезультат задачи 1:\n"
              << str << "\n";

    // ---------------- Задача 2 ----------------
    std::ifstream fin("input.txt");
    int N;
    char target;
    fin >> N >> target;
    fin.close();

    unsigned char target_uc = (unsigned char)target;
    if (target_uc >= 192 && target_uc <= 223)
        target_uc += 32;
    if (target_uc >= 'A' && target_uc <= 'Z')
        target_uc += 32;

    std::ifstream ftext("text.txt", std::ios::binary);
    char text[10000];
    ftext.read(text, sizeof(text));
    int text_len = (int)ftext.gcount();
    ftext.close();

    char words[1000][101];
    int word_count = 0, k = 0;
    for (int i = 0; i <= text_len; i++)
    {
        unsigned char c = (unsigned char)text[i];
        if ((c >= 192) || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '-')
        {
            if (c == '-' && k == 0)
                continue;
            if (c >= 'A' && c <= 'Z')
                c += 32;
            if (c >= 192 && c <= 223)
                c += 32;
            words[word_count][k++] = c;
        }
        else
        {
            if (k > 0)
            {
                words[word_count][k] = '\0';
                word_count++;
                k = 0;
            }
        }
    }

    char result[1000][101];
    char norm_result[1000][101];
    int res_count = 0;

    for (int i = 0; i < word_count; i++)
    {
        int len = (int)strlen(words[i]);
        if (len == 0)
            continue;
        int j = len - 1;
        while (j >= 0 && !((words[i][j] >= 'a' && words[i][j] <= 'z') || (unsigned char)words[i][j] >= 224 || (words[i][j] >= '0' && words[i][j] <= '9')))
            j--;
        if (j < 0)
            continue;

        unsigned char last = (unsigned char)words[i][j];
        if (last >= 192 && last <= 223)
            last += 32;
        if (last >= 'A' && last <= 'Z')
            last += 32;

        if (last == target_uc)
        {
            char norm[101];
            normalize_word(words[i], norm);

            int unique = 1;
            for (int k = 0; k < res_count; k++)
                if (strcmp(norm_result[k], norm) == 0)
                {
                    unique = 0;
                    break;
                }

            if (unique)
            {
                strcpy(result[res_count], words[i]);
                strcpy(norm_result[res_count], norm);
                res_count++;
            }
        }
    }

    // сортировка по длине
    for (int i = 0; i < res_count - 1; i++)
        for (int j = i + 1; j < res_count; j++)
            if (strlen(result[i]) < strlen(result[j]))
            {
                char tmp[101];
                strcpy(tmp, result[i]);
                strcpy(result[i], result[j]);
                strcpy(result[j], tmp);
            }

    if (res_count > N)
        res_count = N;

    std::ofstream fout("result.txt");
    for (int i = 0; i < res_count; i++)
        fout << result[i] << "\n";
    fout.close();

    std::cout << "\nРезультат задачи 2 записан в result.txt\n";
    return 0;
}