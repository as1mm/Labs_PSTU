#include <iostream>

int main()
{
    const int n = 3, m = 3;
    int a[n][m] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}