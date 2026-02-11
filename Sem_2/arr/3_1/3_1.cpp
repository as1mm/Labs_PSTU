#include <iostream>

int main()
{
    int temp;
    const int n = 7;
    int a[n] = {1, 2, 3, 4, 5, 6, 7};

    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < n / 2; i++)
    {
        temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}