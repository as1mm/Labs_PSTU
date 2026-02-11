#include <iostream>

int main()
{
    bool posl = false;
    const int n = 7;
    int a[n] = {1, 0, 3, 4, 6, 7, 8};

    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < n; i++)
    {
        if (a[i] <= a[i + 1])
        {
            posl = true;
        }
        else { posl = false; break; }
    }
    if (posl) { std::cout << "MASSIVE POSLEDOVAT"; }
    else { std::cout << "MASSIVE NEPOSL"; }
}