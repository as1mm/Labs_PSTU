#include <iostream>

// функция разделения нашего массива на те что меньше pivot и больше
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // опорным элементом выбирают последний элемент (так по ломуто)
    int i = low - 1; // это индекс элемента до нашего pivot (после нашего цикла наш pivot должен стоять на i + 1)

    // в цикле идем по элементам массива, если они меньше или равны pivot, то мы сдвигаем i на 1 и меняем элементы
    // с помощью этого цикла мы сдвигаем все элементы меньше pivot слева от него, а больше pivot справа
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]); // ставим pivot на его индекс
    return (i + 1); // возвращаем индекс pivot
}

// функция рекурсивно сортирует массив
// по факту просто разделяет его до тех пор, пока не останется 1(2) элемент(а), а потом просто собирает его в правильном порядке
void quickSortLomuto(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);

        quickSortLomuto(arr, low, p - 1);
        quickSortLomuto(arr, p + 1, high);
    }
}

int main()
{
    int arr[9] = {3, 7, 8, 5, 2, 1, 9, 5, 4};

    for (int i = 0; i < 9; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    quickSortLomuto(arr, 0, 8);

    for (int i = 0; i < 9; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}