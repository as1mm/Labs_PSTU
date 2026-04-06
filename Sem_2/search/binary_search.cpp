#include <iostream>

// функция принимает массив, левую и правую границу, а так же ключ
int BinarySearch(int arr[], int left, int right, int key)
{
    bool flag = false;
    int mid;

    while ((!flag) && (left <= right))
    {
        mid = (left + right) / 2; // находим центр нашего массива

        if (arr[mid] == key) flag = true; // если заданный ключ равен центральному элементу, то мы завершаем цикл, поднимаем флаг и возвращаем индекс этого элемента
        if (arr[mid] >= key) right = mid - 1; // если заданный ключ меньше mid, то мы ищем элементы меньше его (которые слева)
        else left = mid + 1; // если заданный ключ больше mid, то мы ищем элементы больше его (которые справа)
    }
    return mid;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    std::cout << BinarySearch(arr, 0, 4, 3);
}