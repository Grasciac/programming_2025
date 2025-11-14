#include <iostream>

void printMatrix(int **matrix, unsigned int rows, int columns)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int *getRowsToDelete(int **matrix, int rows, int columns)
{
    int *zeroArray = (int *)malloc(sizeof(int));
    int count = 0;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            if (matrix[i][j] == 0)
            {
                ++count;
                zeroArray[0] = count;
                zeroArray = (int *)realloc(zeroArray, count * sizeof(int));
                zeroArray[zeroArray[0]] = i;
                break;
            }
        }
    }
    return zeroArray;
}

int main()
{
    int a, b, c, d;
    int **matrix = (int **)malloc(sizeof(int *) * 2);
    matrix[0] = (int *)malloc(sizeof(int) * 2);
    matrix[1] = (int *)malloc(sizeof(int) * 2);
    do
    {
        std::cout << "Введите A (неотрицательное): ";
        std::cin >> a;
        if (a < 0)
        {
            std::cout << "Ошибка! A должно быть неотрицательным. Повторите ввод." << std::endl;
        }
    } while (a < 0);
    do
    {
        std::cout << "Введите B (неотрицательное): ";
        std::cin >> b;
        if (b < 0)
        {
            std::cout << "Ошибка! B должно быть неотрицательным. Повторите ввод." << std::endl;
        }
    } while (b < 0);
    std::cout << "C = ";
    std::cin >> c;
    std::cout << "D = ";
    std::cin >> d;
    std::cout << "Инициализация и заполнение массива:" << std::endl;
    matrix[0][0] = a;
    matrix[0][1] = b;
    matrix[1][0] = c;
    matrix[1][1] = d;
    unsigned int rows = a + 2;
    unsigned int columns = b + 2;
    printMatrix(matrix, 2, 2);
    matrix = (int **)realloc(matrix, rows * sizeof(int *));
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = i < 2 ? (int *)realloc(matrix[i], columns * sizeof(int *)) : (int *)malloc(columns * sizeof(int));
        for (int j = 0; j < columns; ++j)
        {
            matrix[i][j] = i * c + j * d;
        }
    }
    std::cout << "Преобразованная начальная матрица: " << std::endl;
    matrix[rows - 2][columns - 2] = a;
    matrix[rows - 2][columns - 1] = b;
    matrix[rows - 1][columns - 2] = c;
    matrix[rows - 1][columns - 1] = d;
    printMatrix(matrix, rows, columns);
    int *zeroRows = getRowsToDelete(matrix, rows, columns);
    std::cout << "Окончательная матрица: " << std::endl;
    for (int index = 1; index < zeroRows[0] + 1; ++index)
    {
        --rows;
        int *pointer = matrix[zeroRows[index]];
        for (int i = zeroRows[index]; i < rows; ++i)
        {
            matrix[i] = matrix[i + 1];
        }
        for (int i = index; i <= zeroRows[0]; ++i)
        {
            --zeroRows[i];
        }

        free(pointer);
    }
    matrix = (int **)realloc(matrix, rows * sizeof(int *));
    printMatrix(matrix, rows, columns);
    for (int i = 0; i < rows; ++i)
    {
        free(matrix[i]);
    }
    free(matrix);
    free(zeroRows);
    return 0;
}