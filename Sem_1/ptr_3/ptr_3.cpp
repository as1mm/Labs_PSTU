#include <iostream>

int main()
{
    float chislo_1, chislo_2, sum = 0;
    std::cin >> chislo_1 >> chislo_2;
    float *ptr1 = &chislo_1;
    float *ptr2 = &chislo_2;
    sum = *ptr1 + *ptr2;
    std::cout << "sum = " << sum;
    return 0;
}