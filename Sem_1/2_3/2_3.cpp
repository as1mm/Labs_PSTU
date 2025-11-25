#include <iostream>

int main()
{
    int n, sum =0;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int k = i;
        for (int j = i + 1; j <= i * 2; j++)
        {
            k *= j;
        }
        sum += k;
    }
    std::cout << sum << std::endl;
    return 0;
}