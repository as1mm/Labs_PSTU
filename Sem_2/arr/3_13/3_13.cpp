#include <iostream>

int main()
{
    const int n = 3, m = 3;
    int a[n][m] = {{21, 12, 63}, {14, 25, 6}, {57, 18, 9}};
    int tmp, k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    std::cin >> k;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[k][j] > a[k][j+1])
            {
                for (int r = 0; r < n; r++)
                {
                    tmp = a[r][j];
                    a[r][j] = a[r][j+1];
                    a[r][j+1] = tmp;
                }
            }
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