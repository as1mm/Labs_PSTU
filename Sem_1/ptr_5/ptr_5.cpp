#include <iostream>

int main()
{
    int n, factorial = 1;
    int *ptr_n = &n;
    int *ptr_factorial = &factorial;

    std::cin >> *ptr_n;

    for (int i = 2; i <= n; i++)
    {
        *ptr_factorial *= i;
    }
    std::cout << *ptr_factorial;
    return 0;
}