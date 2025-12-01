#include <iostream>

int main()
{
    int number, chislo, max = 0;
    std::cin >> number;
    if ((number == 0) or (number < 0))
    {
        std::cout << "Net posledovatelnosti";
    }
    else
    {
        for (int i = 1; i <= number; i++)
        {
            std::cin >> chislo;
            if (max < chislo)
            {
                max = chislo;
            }
        }
    }
    std::cout << max;
    return 0;
}