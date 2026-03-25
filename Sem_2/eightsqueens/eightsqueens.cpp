#include <iostream>

const int N = 8;

void vizualization(int arr[N][N])
{

	std::cout << "\t";
	for (int i = 0; i < N; i++)
    {
		std::cout << "  " << i << " ";
	}
	// cout << "  columns";
	std::cout << "\n";

	for (int i = 0; i < N; i++)
    {
		std::cout << "\t";
		for (int j = 0; j < N; j++)
        {
			std::cout << "----";
		}
		std::cout << "-" << "\n";
		std::cout << "     " << i << "\t";

		for (int j = 0; j < N; j++)
        {
			std::cout << "| ";
			if (arr[i][j] == 1) std::cout << "Q ";
			else std::cout << "  ";
		}
		std::cout << "|" << "\n";
	}
	// cout << "   rows";
	std::cout << "\t";
	for (int j = 0; j < N; j++)
    {
		std::cout << "----";
	}
	std::cout << "-" << "\n" << "\n" << "\n";
}

bool canSetQueen(int arr[N][N], int x, int y)
{
	for (int row = 0; row < y; row++)
    {
		for (int col = 0; col < N; col++)
        {
			if (arr[row][col] == 1)
            {
				if ((x == col) || (y == row) || (x - y == col - row) || ((N - x) - y == (N - col) - row))
					return 0;
			}
		}
	}
	return 1;
}

void eightQueen(int arr[N][N], int row)
{
	static int count = 0;
	for (int col = 0; col < N; col++)
    {
		if (canSetQueen(arr, col, row))
        {
			if (row == N-1)
            {
				arr[row][col] = 1;
				vizualization(arr);
				arr[row][col] = 0;
				count++;
			}
			else
            {
				arr[row][col] = 1;
				eightQueen(arr, row + 1);
				arr[row][col] = 0;
			}
		}
	}
	if (row == 0) std::cout << "\ttotal boards: " << count << "\n" << "\n" << "\n";
}


int main()
{
	int arr[N][N];

	for (int i = 0; i < N; i++)
    {
		for (int j = 0; j < N; j++)
        {
			arr[i][j] = 0;
		}
	}
	eightQueen(arr, 0);
}