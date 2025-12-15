#include <iostream>

int main()
{
    int sum = 0, n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (i % 3 == 0)
        {
            sum -=i;
        }
        else
        {
            sum +=i;
        }
    }
    std::cout << "sum = " << sum;
    return 0;
}