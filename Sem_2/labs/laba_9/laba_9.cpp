#include <iostream>
#include <string>
#include <fstream>
#include <clocale>
bool palindrom(std::string slovo)
{
    char first = slovo.front();
    char last = slovo.back();
    return (first == last);
}

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    std::string slovo;
    int ans = 0;

    std::ifstream file1("F1.txt");
    std::ofstream file2("F2.txt");

    while(std::getline(file1, slovo))
    {
        if (palindrom(slovo))
        {
            file2 << slovo << "\n";
            ans++;
        }
    }

    file1.close();
    file2.close();

    std::cout << "Столько строчек палиндром: " << ans;
    return 0;
}