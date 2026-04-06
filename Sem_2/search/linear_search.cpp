#include <iostream>

// возвращает индекс элемента с заданным ключом, либо -1 если такой элемент не найден
int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key) return i;
    }
    return -1;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    std::cout << linearSearch(arr, 5, 3);
}