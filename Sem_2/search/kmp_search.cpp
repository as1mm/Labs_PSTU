#include <iostream>

void preFunc(const std::string& pattern, int* d)
{
    d[0] = 0;
    int j = 0, i = 1;

    while (i < pattern.length())
    {
        if (pattern[i] == pattern[j])
        {
            d[i] = j + 1;
            i++; j++;
        }
        else if (j == 0)
        {
            d[i] = 0;
            i++;
        }
        else j = d[j - 1];
    }
}

void KMPSearch(const std::string& text, const std::string& pattern)
{
    int* d = new int[pattern.length()] {0};
    preFunc(pattern, d);
    int i = 0, j = 0;
    while(i < text.length())
    {
        if (text[i] == pattern[j]) { i++; j++; }
        if (j == pattern.length())
        {
            std::cout << i - pattern.length();
            j = d[j - 1];
        }
        else if (i < text.length() && pattern[j] != text[i])
            if (j == 0) i++;
            else j = d[j - 1];
    }
    delete[] d;
}

int main()
{
    std::string str = "AABADABADBABDAABDA";
    std::string substr = "DAAB";
    KMPSearch(str, substr);
}