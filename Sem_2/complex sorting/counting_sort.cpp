#include <iostream>

void countingSort(int arr[], int size)
{
    if (size <= 1) return;

    int max = arr[0];
    for (int i = 0; i < size; i++)
    { if (arr[i] > max) max = arr[i]; } // находим макс элемент

    int* count = new int[max + 1]{0};   // заполняем массив нулями
    int* output = new int[size];

    // считаем УНИКАЛЬНЫЕ значения
    for (int i = 0; i < size; i++)
    { count[arr[i]]++; }

    // префиксные суммы
    for (int i = 1; i <= max; i++)
    { count[i] += count[i - 1]; }

    // заполнение массива по алгоритму с конца
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // заменяем наш исходный массив на отсортированный
    for (int i = 0; i < size; i++)
    { arr[i] = output[i]; }

    // очищаем память
    delete[] count;
    delete[] output;
}

int main()
{
    int arr[10] = {2, 3, 3, 1, 1, 9, 5, 4, 2, 9};
    for (int i = 0; i < 10; i++) { std::cout << arr[i] << " "; }
    std::cout << "\n";

    countingSort(arr, 10);

    for (int i = 0; i < 10; i++) { std::cout << arr[i] << " "; }
}