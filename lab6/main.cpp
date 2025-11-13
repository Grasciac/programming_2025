#include <iostream>

int *zeroNumbers(int **a, int rows, int cols)
{
    int zero;
    int *d = (int *)calloc(rows, sizeof(int));
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (0 == a[i][j])
            {
                ++zero;
                d[zero - 1] = i;
                break;
            }
        }
    }
    return d;
}

int main()
{
    int a;
    int b;
    int c;
    int d;
    std::cout << "A = ";
    std::cin >> a;
    std::cout << "B = ";
    std::cin >> b;
    std::cout << "C = ";
    std::cin >> c;
    std::cout << "D = ";
    std::cin >> d;
    if ((a < 0) || (b < 0))
    {
        std::cout << "Неккоректный ввод переменных(A или B)." << std::endl;
        return -1;
    }
    int **arr = nullptr;
    arr = (int **)malloc(2 * sizeof(int *));
    for (int i = 0; i < 2; ++i)
    {
        arr[i] = (int *)malloc(2 * sizeof(int));
    }
    std::cout << "Инициализация и заполнение массива:" << std::endl;
    arr[0][0] = a;
    arr[0][1] = b;
    arr[1][0] = c;
    arr[1][1] = d;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    int rows = 2 + a;
    int cols = 2 + b;
    arr = (int **)realloc(arr, rows * sizeof(int *));
    for (int i = 0; i < rows; ++i)
    {
        if (i < 2)
        {
            arr[i] = (int *)realloc(arr[i], sizeof(int) * cols);
        }
        else
        {
            arr[i] = (int *)malloc(cols * sizeof(int));
        }
    }
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            arr[i][j] = i * c + j * d;
        }
    }
    arr[rows - 2][cols - 2] = a;
    arr[rows - 2][cols - 1] = b;
    arr[rows - 1][cols - 2] = c;
    arr[rows - 1][cols - 1] = d;
    std::cout << "Преобразованная начальная матрица: " << std::endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    int *tmp = zeroNumbers(arr, rows, cols);
    int countToDelete = rows;
    std::cout << "Окончательная матрица: " << std::endl;
    for (int i = 1; i < rows; ++i)
    {
        if (tmp[i] == 0)
        {
            countToDelete = i;
            break;
        }
    }
    for (int index = 0; index < countToDelete; ++index)
    {
        --rows;
        int *pointer = arr[tmp[index]]; // Указатель на строку, которую удаляем
        for (int i = tmp[index]; i < rows; ++i)
        {
            arr[i] = arr[i + 1];
        }
        for (int i = index + 1; i < countToDelete; ++i) // уменьшаем номера строк, которые мы получили через функцию
        {
            --tmp[i];
        }
        free(pointer);
    }
    if (rows)
    {
        arr = (int **)realloc(arr, rows * sizeof(int *));
    }
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < rows; ++i)
    {
        free(arr[i]);
    }
    free(arr);
    free(tmp);
    return 0;
}