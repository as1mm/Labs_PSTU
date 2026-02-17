#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    int size;
    int* a = new int[size];
    std::cin >> size;
    int new_size = size + 1;

    //заполняем массив
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        a[i] = 0 + rand() % 1000;
        if (a[i] == 0) { new_size--; }
        std::cout << a[i] << " ";
    }
    std::cout << "\n";

    //удаляем нули в массиве и создаем новый массив (изменяем динамически)
    int* new_a = new int[new_size];
    int index = 0;

    for (int i = 0; i < size; i++)
    {
        if (a[i] != 0)
        {
            new_a[index] = a[i];
            index++;
        }
    }

    delete[] a;
    int temp;

    //добавляем a[i - 1] + 2 перед первым ЧЕТНЫМ элементом
    for (int i = 0; i < new_size; i++)
    {
        if (new_a[i] % 2 == 0)
        {
            for (int j = new_size; j > 0 + i; j--)
            {
                temp = new_a[j];
                new_a[j] = new_a[j - 1];
                new_a[j - 1] = temp;
            }
            new_a[i] = new_a[i - 1] + 2;
            break;
        }
    }

    //выводим получившийся массив
    for (int i = 0; i < new_size; i++)
    {
        std::cout << new_a[i] << " ";
    }
    std::cout << "\n";

    return 0;
}