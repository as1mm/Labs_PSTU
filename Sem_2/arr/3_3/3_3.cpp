#include <iostream>

int main()
{
    int a_max, count = 0;
    const int n = 7;
    int a[n] = {22, 22, 3, 4, 6, 7, 8};
    a_max = a[0];
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 1; i < n; i++)
    {
        if (a[i] > a_max)
        {
            a_max = a[i];
            count = 1;
        }
        if (a[i] == a_max) { count++; }
    }
    std::cout << "MAX CHISLO = " << a_max << " " << "KOL-VO SOVPD = " << count;
    return 0;
}