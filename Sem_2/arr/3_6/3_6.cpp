#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    const int n = 10;
    int a[n];

    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        a[i] = 1 + rand() % 100;
        std::cout << a[i] << " ";
    }

    int k;
    std::cin >> k;

    for (int i = 0; i < k; i++)
    {
        int temp = a[0];
        for (int j = 0; j < n - 1; j++)
        {
            a[j] = a[j + 1];
        }
        a[n - 1] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }

    return 0;
}