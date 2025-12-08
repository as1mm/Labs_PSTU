#include <iostream>

int main()
{
    int number, chislo;
    bool minusFirst = false, plusFirst = false;
    std::cin >> number;
    if (number <= 0)
    {
        std::cout << "Net posledovatelnosti";
    }
    else
    {
        for (int i = 1; i <= number; i++)
        {
            std::cin >> chislo;
            if (!minusFirst and !plusFirst)
            {
                if (chislo < 0)
                {
                    minusFirst = true;
                }
                if (chislo > 0)
                {
                    plusFirst = true;
                }
            }

        }
    }
    if (minusFirst)
    {
        std::cout << "FIRST MINUS";
    }
    else if (plusFirst)
    {
        std::cout << "FIRST PLUS";
    }
    else
    {
        std::cout << "POSL. NUL";
    }
    return 0;
}