#include <iostream>
#include <fstream>

class Time
{
    private:
    int minutes;
    int seconds;

    // нормализуем секунды
    void normalize()
    {
        if (seconds >= 60)
        {
            minutes += seconds / 60;
            seconds %= 60;
        }
    }

    public:
    Time() : minutes(0), seconds(0) {}
    Time(int m, int s) : minutes(m), seconds(s) { normalize(); }

    Time& plusSeconds(int sec)
    {
        seconds = seconds + sec;
        normalize();
        return *this;
    }

    Time& minusSeconds(int sec)
    {
        seconds = seconds - sec;
        normalize();
        return *this;
    }

    Time& minusPoltora()
    {
        int totalSeconds = minutes * 60 + seconds;
        totalSeconds -= 90;
        if (totalSeconds < 0) totalSeconds = 0;
        minutes = totalSeconds / 60;
        seconds = totalSeconds % 60;
        return *this;
    }

    Time& operator=(const Time& t)
    {
        if (this == &t) return *this;
        minutes = t.minutes;
        seconds = t.seconds;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Time& t)
    {
        os << (t.minutes < 10 ? "0" : "") << t.minutes << ":" << (t.seconds < 10 ? "0" : "") << t.seconds << "\n";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Time& t)
    {
        int m, s;
        is >> m >> s;
        t = Time(m, s);
        return is;
    }

    friend std::fstream& operator>>(std::fstream& in, Time& t)
    {
        char colon;
        in >> t.minutes >> colon >> t.seconds;
        return in;
    }

    friend std::fstream& operator<<(std::fstream& out, const Time &t)
    {
        out << (t.minutes < 10 ? "0" : "") << t.minutes << ":" << (t.seconds < 10 ? "0" : "") << t.seconds << "\n";
        return out;
    }
};

int makeFile(const char* file_name)
{
    std::fstream outFile(file_name, std::ios::out | std::ios::trunc);
    if (!outFile) return -1; // файл не открылся
    int n;
    Time t;
    std::cout << "How many elements? "; std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter minutes and seconds: ";
        std::cin >> t;
        outFile << t << "\n";
    }
    outFile.close();
    return n; // сколько элементов добавили
}

int printFile(const char* file_name)
{
    std::fstream outFile(file_name, std::ios::in);
    if (!outFile) return -1;
    Time t;
    int k;
    while (outFile >> t)
    {
        std::cout << t;
        k++;
    }
    outFile.close();
    return k;
}

int deleteElemN(const char* file_name, int n)
{
    std::fstream tmp("temp", std::ios::out); // создаем новый вспомогатеьный файл
    std::fstream outFile(file_name, std::ios::in);
    if (!outFile) return -1;
    Time t;
    int k = 0;
    while (outFile >> t)
    {
        //if (outFile.eof()) break; // если файл закончился то выходим из цикла p.s. в методичке так написано, а по факту вообще не нужная проверка, так как while норм работает
        k++;
        if (k != n) tmp << t; // если это не тот элемент, который надо удалить, то записываем его в спомогательный файл
    }
    outFile.close();
    tmp.close();
    std::remove(file_name);
    std::rename("temp", file_name);
    return k;
}

int decreaseRecord(const char* file_name, int n)
{
    std::fstream outFile(file_name, std::ios::in);
    std::fstream tmp("temp", std::ios::out);
    if (!outFile) return -1;
    Time t;
    int k = 0;
    while (outFile >> t)
    {
        k++;
        if (k == n) tmp << t.minusPoltora();
        else tmp << t;
    }

    outFile.close();
    tmp.close();
    std::remove(file_name);
    std::rename("temp", file_name);
    return k;
}

int addRecords(const char* file_name, int n, int k) // n - после какого, k - сколько
{
    std::fstream outFile(file_name, std::ios::in);
    std::fstream tmp("temp", std::ios::out);
    if (!outFile) return -1;
    Time t;
    int i = 0;
    while (outFile >> t)
    {
        i++;
        if (i == n)
        {
            tmp << t;
            // вписываем в наш файл k новых елементов
            for (int j = 0; j < k; j++)
            {
                Time tt;
                std::cout << "Enter minutes and seconds: ";
                std::cin >> tt;
                tmp << tt;
            }
        }
        else tmp << t;
    }

    outFile.close();
    tmp.close();
    std::remove(file_name);
    std::rename("temp", file_name);
    return i;
}

class Menu
{
    public:
    void run()
    {
        char cmd;
        char f_name[30];
        std::cout << "Commands:\n"
                  << "1. Make file\n"
                  << "2. Print file\n"
                  << "3. delete records == n\n"
                  << "4. decrease n record by 1 min 30 sec\n"
                  << "5. add k records after record == n\n"
                  << "0. quit\n"
                  << ">> ";

        while(std::cin >> cmd)
        {
            if (cmd == '0') break;
            switch (cmd)
            {
            case '1':
            {
                std::cout << "Enter file name: "; std::cin >> f_name;
                if (makeFile(f_name) < 0) std::cout << "Cant make file(\n";
                else std::cout << f_name << " created!\n";
                break;
            }
            case '2':
            {
                std::cout << "Enter file name: "; std::cin >> f_name;
                if (printFile(f_name) < 0) std::cout << "Cant print file(\n";
                break;
            }
            case '3':
            {
                int n;
                std::cout << "Enter n: ";
                std::cin >> n;
                if (deleteElemN(f_name, n) < 0) std::cout << "Cant delete element(\n";
                break;
            }
            case '4':
            {
                int n;
                std::cout << "Enter n: ";
                std::cin >> n;
                if (decreaseRecord(f_name, n) < 0) std::cout << "Cant decrease element(\n";
                break;
            }
            case '5':
            {
                int n, k;
                std::cout << "Enter n and k: ";
                std::cin >> n >> k;
                if (addRecords(f_name, n, k) < 0) std::cout << "Cant add elements(\n";
                break;
            }
            default:
                std::cout << "Unknown command!\n";
                break;
            }
            std::cout << ">> ";
        }
    }
};

int main()
{
    Menu cmd;
    cmd.run();
}