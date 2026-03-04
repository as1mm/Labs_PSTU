#include <iostream>

int multpl(int a, int b)
{
    return a * b;
}

double multpl(double a, double b)
{
    return a * b;
}

int main()
{
    std::cout << "int answer = " << multpl(3, 3) << "\n" << "double answer = " << multpl(3.2, 3.2);
    return 0;
}