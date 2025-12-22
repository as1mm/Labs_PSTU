//f(x) = 0.25x^3 + x - 1.2502
//[0,2]
//f'(x) = 0.75x^2 + 1
//ф(x) = x - lambd(0.25x^3 + x - 1.2502)
//r = max(|f'(a)|, |f'(b)|) = 4
//-1/r < lambd < 0, because f'(x) > 0
//-1/4 < lambd < 0 -> lambd = -0.5
#include <iostream>
#include <cmath>
int main()
{
    double x, xPrev;
    double eps = 0.000001;
    double lambda = -0.5;

    x = 1;
    xPrev = 0;

    while (abs(x - xPrev) > eps)
    {
        xPrev = x;
        x = lambda * (0.25 * pow(xPrev, 3) + xPrev - 1.2502) + xPrev;
    }
    std::cout << "KOREN po iter: " << x << std::endl;
    return 0;
}