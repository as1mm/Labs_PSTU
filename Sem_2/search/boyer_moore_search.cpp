#include <iostream>

int BoyerMooreSearch(const std::string& text, const std::string& pattern) // типо умный, не засоряем память, а создаем ссылку =)))
{
    int patternLen = pattern.length(); // длина текста
    int textLen = text.length(); // длина паттерна
    if (patternLen == 0 || textLen == 0 || patternLen > textLen) return -1;

    int CharTable[256]; // таблица сдвигов для всех букв

    for (int i = 0; i < 256; i++)
        CharTable[i] = patternLen; // заполняем таблицу по дефолту длинной паттерна

    for (int i = 0; i < patternLen - 1; i++)
        CharTable[(unsigned char)pattern[i]] = patternLen - 1 - i; // вычисляем для каждого символа паттерна его сдвиг(кроме последнего)
        // unsigned char для того чтобы индексы были от 0-255
        // по факту мы записываем в нашу таблицу под каждой буквой его сдвиг по формуле **длина патерна - его первое вхождение**

    int pos = patternLen - 1; // позиция в тексте на которую смотрит последний символ образца (хвост)

    while (pos < textLen) // пока хвост не вышел за длину строки
    {
        int i = patternLen - 1; // индекс символа в образце, мы начинаем сравнивать строку с конца (справа налево)

        while (i >= 0 && pattern[i] == text[pos - (patternLen - 1 - i)]) // пока не дошли до начала образца и символы образца и строки совпадают
            i--;                                                         // уменьшаем i тем самым смотря на следующий элемент

        if (i == -1) // если i == -1, то мы нашли наш паттерн, возвращаем индекс начала (от этого индекса начинается наш паттерн)
            return pos - patternLen + 1;

        pos += CharTable[(unsigned char)text[pos - (patternLen - 1 - i)]]; // если не нашли, то сдвигаем наш паттерн по нашей таблице сдвигов
    }

    return -1; // если ничего не нашли
}

int main()
{
    std::string str = "AABADABADBABDAABDA";
    std::string substr = "DAAB";
    std::cout << BoyerMooreSearch(str, substr);
}

// а еще это оказывается бойер-мур-хорспул