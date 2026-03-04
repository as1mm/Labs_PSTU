#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    std::string text;
    std::string str;
    std::cout << "Введите слова на английском с пробелами!!!" << "\n";
    std::getline(std::cin, text); //получаем строку нашего "текста" с пробелами
    std::stringstream ss(text); //разделяем наш текст по пробелам на слова
    std::cout << "\n";

    while (ss >> str)
    {
        bool glas = false;
        for (int i = 0; i < str.size(); i++) //тут еще можно (или нужно) использовать size_t i = 0, тк str_size() вернет нам кол-во элементов в слове с типом size_t
        {
            char bukva = std::tolower(str[i]);
            if (bukva == 'a' || bukva == 'e' || bukva == 'y' || bukva == 'u' || bukva == 'i' || bukva == 'o')
            {
                glas = true;
                break;
            }
        }
        if (glas == false)
        {
            std::cout << str << " ";
        }
    }
    //пока слова в ss есть они передаются в str где мы смотрим есть ли гласная буква в слове (str)
    //если есть то поднимаем флажок и выходим из цикла, если нет, то выводим слово

    return 0;
}