#include <iostream>

int main()
{
    int chislo, s;
    bool fhod = false;
    std::cin >> chislo >> s;
    while (chislo > 0)
    {
        if (chislo % 10 == s)
        {
            fhod = true;
        }
        chislo /= 10;
    }
    if (fhod) {std::cout << "CHISLO VHODIT";}
    else {std::cout << "CHISLO NE VHODIT";}
    return 0;
}