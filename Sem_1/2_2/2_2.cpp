#include <iostream>
#include <clocale>
int main()
{
	setlocale(LC_ALL, "");
	int n, sum = 1;
	std::cin >> n;
	if (n <= 0)
	{
		std::wcout << L"невозможно";
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			sum *= i;
		}
	std::cout << sum;
	}
}