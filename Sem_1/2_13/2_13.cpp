#include <iostream>
#include <cmath>
int main()
{
    float a, b, c, d, x1, x2, x;
    std::cin >> a >> b >> c;
    d = (b * b) - 4 * a * c;
    if (d == 0)
    {
        x = (-b) / (2 * a);
        std::cout << "ODIN KOREN: " << "x = " << x << std::endl;
    }
    else if (d > 0)
    {
        x1 = ((-b + sqrt(d)) / (2 * a));
        x2 = ((-b - sqrt(d)) / (2 * a));
        std::cout << "DVA KORNYA: " << "x1 = " << x1 << " x2 = " << x2 << std::endl;
    }
    else
    {
        std::cout << "KORNEY NET";
    }
    return 0;
}