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
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                std::cout << '*';
            }
            std::cout << std::endl;
        }
    }
}