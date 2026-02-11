#include <iostream>
#include <algorithm>

int main()
{
    const int n = 10;
    int a[n] = {102, 14, 22, 67, 69, 12, 11, 435, 100, 14};
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                std::swap(a[i], a[i + 1]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    return 0;
}