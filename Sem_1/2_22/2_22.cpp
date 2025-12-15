#include <iostream>
#include <cmath>
int main()
{
    float a, n ,max;
    int i = 2;
    int num = 1;
    std::cin >> n;
    max = sin(n + 1 / n);
    while (i <= n)
    {
        a = sin(n + i / n);
        if (a > max)
        {
            max = a;
            num = i;
        }
        i++;
    }

    std::cout << "ZNACH a = " << max << " NUMBER i = " << num;
    return 0;
}