#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>

void summ(int** a, int** b, int** res, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
}

int main()
{
    int size;
    int** arr = new int*[size];
    int** trns = new int*[size];
    int** res = new int*[size];
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    std::cout << "Введите размер массива/матрицы" << "\n";
    std::cin >> size;
    std::cout << "\n";

    std::cout << "Ориг матрица" << "\n";
    std::cout << "\n";
    //выделяем память и заполняем ориг матрицу + выводим ее
    //матрицу я заполняю просто от 1 - size
    for (int i = 0; i < size; i++)
    {
        arr[i] = new int[size];
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = i + 1;
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    //

    //выделяем память под транспонированную матрицу
    for (int i = 0; i < size; i++)
    {
        trns[i] = new int[size];
    }
    //

    std::cout << "Транспонированная матрица" << "\n";
    //транспонируем матрицу + выводим ее
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            trns[i][j] = arr[j][i];
            std::cout << trns[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    //

    //выделяем память под матрицу суммы матриц (итоговая матрица)
    for (int i = 0; i < size; i++)
    {
        res[i] = new int[size];
    }
    //

    //применяем функцию для суммы матриц (ориг + трансп)
    summ(arr, trns, res, size);
    //

    std::cout << "Итоговая матрциа" << "\n";
    //выводим итоговую матрицу с суммой двух матриц
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << res[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    //

    //освобождаем память всех матриц
    for (int i = 0; i < size; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    for (int i = 0; i < size; i++)
    {
        delete[] trns[i];
    }
    delete[] trns;

    for (int i = 0; i < size; i++)
    {
        delete[] res[i];
    }
    delete[] res;
    //

    //Здравстуйте, Денис Владимирович, на самом деле можно было сделать много функций
    //и было бы меньше строчек кода, но я лентяй

    return 0;
}