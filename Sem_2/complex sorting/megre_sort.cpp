#include <iostream>

void merge(int arr[], int left, int mid, int right)
{
    int leftRange = mid - left + 1;
    int rightRange = right - mid;

    // память под новые массивы левой и правой части
    int* leftArr = new int[leftRange];
    int* rightArr = new int[rightRange];

    // заполняем массивы левой и правой части
    for (int i = 0; i < leftRange; i++)
    { leftArr[i] = arr[left + i]; }

    for (int i = 0; i < rightRange; i++)
    { rightArr[i] = arr[mid + 1 + i]; }

    // индексы
    int leftIndex = 0;
    int rightIndex = 0;
    int mergeIndex = left;

    while (leftIndex < leftRange && rightIndex < rightRange)
    {
        if (leftArr[leftIndex] <= rightArr[rightIndex])
        {
            arr[mergeIndex] = leftArr[leftIndex];
            leftIndex++;
        }
        else
        {
            arr[mergeIndex] = rightArr[rightIndex];
            rightIndex++;
        }
        mergeIndex++;
    }

    // еслси в правой или левой части еще остались элементы
    while (leftIndex < leftRange)
    {
        arr[mergeIndex] = leftArr[leftIndex];
        leftIndex++;
        mergeIndex++;
    }

    while (rightIndex < rightRange)
    {
        arr[mergeIndex] = rightArr[rightIndex];
        rightIndex++;
        mergeIndex++;
    }

    // освобождаем память
    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int arr[], int start, int end)
{
    if (start >= end) return;

    int mid = start + (end - start) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main()
{
    const int size = 10;
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        int value;
        std::cout << "Введите значение: ";
        std::cin >> value;
        arr[i] = value;
    }

    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    mergeSort(arr, 0, size - 1);

    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}