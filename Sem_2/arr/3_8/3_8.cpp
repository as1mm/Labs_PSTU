#include <iostream>

int main()
{
    const int n = 10;
    int new_n = n;
    int* a = new int[n] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < n; i++)
    {

        std::cout << a[i] << " ";
        if (a[i] % 2 == 0) { new_n++; }
    }
    std::cout << std::endl;

    int* new_a = new int[new_n];
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            new_a[index] = -1;
            index++;
        }
        new_a[index] = a[i];
        index++;
    }

    delete[] a;

    for (int i = 0; i < new_n; i++)
    {
        std::cout << new_a[i] << " ";
    }

    return 0;
}