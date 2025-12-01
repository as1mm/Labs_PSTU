#include <iostream>
int main()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cout << "* ";
    }
    std::cout << std::endl;

    for (int j = 1; j <= n - 2; j++)
    {
        std::cout << "* ";
        for (int k = 1; k <= n - 2; k++)
        {
            std::cout << "  ";
        }
        std::cout << "* " << std::endl;
    }

    for (int z = 1; z <= n; z++)
    {
        std::cout << "* ";
    }
    std::cout << std::endl;
    return 0;
}