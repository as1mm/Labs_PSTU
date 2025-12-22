//f(x) = 0.25x^3 + x - 1.2502
//[0,2]
//f'(x) = 0.75x^2 + 1
//f"(x) = 1.5x
#include <iostream>
#include <cmath>
int main()
{
    double x, xPrev;
    //f(b) * f"(b) > 0 -> x0 = b = 2
    x = 2;
    xPrev = 0;
    double eps = 0.000001;
    while (abs(x - xPrev) > eps)
    {
        xPrev = x;
        x = xPrev - (0.25 * pow(xPrev, 3) + xPrev - 1.2502)/(0.75 * pow(xPrev, 2) + 1);
    }
    std::cout << "KOREN: " << x << std::endl;
    return 0;
}