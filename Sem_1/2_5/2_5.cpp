#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    if (n <= 2)
    {
        std::cout << "ERROR";
        return 0;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int k = 1; k < n - i ; k++)
            {
                std::cout << ' ';
            }
            for (int j = 0; j <= i; j++)
            {
                std::cout << '*';
            }
            std::cout << std::endl;
        }
    }
    return 0;
}