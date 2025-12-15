#include <iostream>

int main()
{
    bool uporyadochno = true;
    int chislo, last;
    std::cin >> chislo;
    last = chislo;
    while (chislo != 0)
    {
        if (chislo >= last)
        {
            last = chislo;
            std::cin >> chislo;
        }
        else
        {
            last = chislo;
            uporyadochno = false;
            std::cin >> chislo;
        }
    }
    if (uporyadochno) {std::cout << "PO VOZRASTANIYU";}
    else {std::cout << "NE PO VOZRASTANIYU";}
    return 0;
}