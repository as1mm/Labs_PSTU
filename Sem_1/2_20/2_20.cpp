#include <iostream>
#include <cmath>
int main()
{
    float a, s;
    bool vh = false;
    int n;
    std::cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        a = sin(n + i / n);
        if (a == s)
        {
            vh = true;
            break;
        }
    }
    if (vh)
    {
        std::cout << "ELEMENT VHODIT";
    }
    else
    {
        std::cout << "ELEMENT NE VHODIT";
    }
    return 0;
}