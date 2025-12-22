#include <iostream>

int main()
{
    int chislo1, chislo2, temp;
    std::cin >> chislo1 >> chislo2;
    int *ptr1 = &chislo1;
    int *ptr2 = &chislo2;
    temp = *ptr1;
    *ptr1 = chislo2;
    *ptr2 = temp;
    std::cout << "now CHISLO1 = " << chislo1 << std::endl << "now chislo2 = " << chislo2;
    return 0;
}