#include <iostream>

int main()
{
    const int n = 7;
    int a[n] = {1, 2, 3, 4, 5, 6, 7};
    int max_a = a[0];

    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 1; i < n; i++)
    {
        if (a[i] > max_a)
        {
            max_a = a[i];
        }
    }
    std::cout << "max el massiva = " << max_a;
    return 0;
}