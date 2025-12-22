#include <iostream>

int main()
{
    int chislo, x;
    std::cin >> chislo;
    int *ptr = &chislo;
    std::cin >> x;
    *ptr = x;
    std::cout << "now CHISLO = " << chislo;
    return 0;
}