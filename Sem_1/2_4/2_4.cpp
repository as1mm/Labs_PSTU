#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    if ((n <= 3) or (n % 2 == 0))
    {
        std::cout << "ERROR";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 != 0)
            {
                for (int q = 1; q <= (n - i) / 2; q++)
                {
                    std::cout << ' ';
                }
                for (int j = 0; j < i; j++)
                {
                    std::cout << '*';
                }
                std::cout << std::endl;
            }
        }
    }
    return 0;
}