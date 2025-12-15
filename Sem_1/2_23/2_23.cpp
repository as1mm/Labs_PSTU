#include <iostream>
#include <cmath>
int main()
{
    float a, n ,max;
    int i = 2;
    int count = 1;
    std::cin >> n;
    max = sin(n + 1 / n);
    while (i <= n)
    {
        a = sin(n + i / n);
        if (a > max)
        {
            max = a;
            count = 1;
        }
        else if (a == max) {count++;}
        i++;
    }

    std::cout << "ZNACH a = " << max << " KOLLICHEVO count = " << count;
    return 0;
}