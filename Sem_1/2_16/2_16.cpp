#include <iostream>

int main()
{
    int sum = 0, n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            sum = sum - i;
        }
        else
        {
            sum = sum + i;
        }
    }
    std::cout << "sum = " << sum;
    return 0;
}