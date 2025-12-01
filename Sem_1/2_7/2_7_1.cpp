#include <iostream>
#include <cmath>
int main()
{
    int n, k;
    std::cin >> n;
    k = sqrt(n);
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
    return 0;
}