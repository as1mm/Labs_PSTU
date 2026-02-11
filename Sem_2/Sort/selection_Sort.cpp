#include <iostream>

int main()
{
    const int n = 10;
    int temp, min_index;
    int a[n] = {123, 412, 656, 54, 2, 676, 67, 12, 9854, 10};
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < n - 1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_index])
            {min_index = j;}
        }
        temp = a[min_index];
        a[min_index] = a[i];
        a[i] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}