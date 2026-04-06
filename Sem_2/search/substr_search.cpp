#include <iostream>

int SubStrSearch(std::string str, std::string substr)
{
    int a = str.length();
    int b = substr.length();

    if (a == 0 || b == 0 || b > a) return -1;

    for (int i = 0; i <= a - b; i++)
    {
        int j = 0;
        while (j < b && str[i + j] == substr[j]) j++;

        if (j == b) return i;
    }

    return -1;
}

int main()
{
    std::string str = "AABADABADBABDAABDA";
    std::string substr = "DAAB";
    std::cout << SubStrSearch(str, substr);
}