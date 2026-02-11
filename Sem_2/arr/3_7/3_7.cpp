#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    const int n = 10;
    int a[n], max_a, min_a;

    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        a[i] = 1 + rand() % 1000;
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    max_a = a[0];
    min_a = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > max_a) { max_a = a[i]; }
        else if (a[i] < min_a) { min_a = a[i]; }
    }

    std::cout << "MAX = " << max_a << std::endl << "MIN = " << min_a;

    return 0;
}