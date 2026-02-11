#include <iostream>

int main()
{
    int p, q, temp;
    std::cin >> p >> q;
    const int n = 7;
    int a[n] = {1, 2, 3, 4, 5, 6, 7};

    for (int i = 0; i < n; i++)
    { std::cout << a[i] << " "; }
    std::cout << std::endl;

    while (p < q)
    {
        temp = a[p];
        a[p] = a[q];
        a[q] = temp;
        p++;
    }

    for (int i = 0; i < n; i++)
    { std::cout << a[i] << " "; }
    std::cout << std::endl;

    return 0;
}