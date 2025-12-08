#include <iostream>

int main()
{
    int number, chislo, max = 0, min;
    std::cin >> number;
    for (int i = 1; i <= number; i++)
    {
        std::cin >> chislo;
        if (i == 1)
        {
            min = chislo;
        }
        if (max < chislo)
        {
            max = chislo;
        }
        if (min > chislo)
        {
            min = chislo;
        }
    }
    std::cout << "sum = " << max + min;
    return 0;
}