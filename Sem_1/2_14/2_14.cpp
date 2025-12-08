#include <iostream>

int main()
{
    int chislo, sum = 0;
    std::cin >> chislo;
    if (chislo < 0)
    {
        std::cout << "ERROR";
        return 0;
    }
    while (chislo > 0)
    {
        sum = sum + (chislo % 10);
        chislo /= 10;
    }
    std::cout << "sum = " << sum;
    return 0;
}