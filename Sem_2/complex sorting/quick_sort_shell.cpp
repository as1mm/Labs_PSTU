#include <iostream>

void shellSort(int arr[], int size)
{
    for (int step = size / 2; step > 0; step /= 2)
    {
        for (int i = step; i < size; i++)
        {
            int tmp = arr[i];
            int j;

            for (j = i; j >= i && arr[j - step] > tmp; j -= step)
            {
                arr[j] = arr[j - step];
            }
            arr[j] = tmp;
        }
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

    shellSort(arr, 9);

    for (int i = 0; i < 9; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}