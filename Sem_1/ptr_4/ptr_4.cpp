#include <iostream>

int main()
{
    int number;
    float temp, min, max;
    float *ptr_max = &max;
    float *ptr_min = &min;
    std::cin >> number;
    std::cin >> *ptr_max;
    *ptr_min = *ptr_max;
    for (int i = 2; i <= number; i++)
    {
        std::cin >> temp;
        if (temp > *ptr_max) { *ptr_max = temp; }
        if (temp < *ptr_min) { *ptr_min = temp; }
    }
    std::cout << "max = " << *ptr_max << std::endl << "min = " << *ptr_min;
    return 0;
}