#include <iostream>
#include <clocale>
int main()
{
	float a, b;
	setlocale(LC_ALL, "");
	std::cin >> a >> b;
	if (b == 0)
	{
		std::wcout << L"невозможно";
	}
	else
	{
		std::cout << a / b;
	}
	return 0;
}