#include <iostream>
#include <fstream>

void czytaj(const int N, int** liczby)
{
	std::ifstream in("plansza.txt");
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			in >> liczby[i][j];
	in.close();
}

void wypisz(const int N, int** liczby)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			std::cout << liczby[i][j] << ' ';
		std::cout << '\n';
	}
}

bool mozliwosci(const int N, int** liczby, int y, int x, int n)
{
	for (int i = 0; i < N; i++)
		if (liczby[y][i] == n || liczby[i][x] == n)
			return false;
	int x0 = (x / 3) * 3;
	int y0 = (y / 3) * 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (liczby[y0 + i][x0 + j] == n)
				return false;
	return true;
}

void rozwiazanie(const int N, int** liczby)
{
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			if (liczby[i][j] == 0)
			{
				for (int n = 1; n < 10; n++)
					if (mozliwosci(N, liczby, i, j, n))
					{
						liczby[i][j] = n;
						rozwiazanie(N, liczby);
						liczby[i][j] = 0;
					}
				return;
			}
	wypisz(N, liczby);
}

int main()
{
	const int N = 9;
	int* liczby[N];
	for (int i = 0; i < N; i++)
		liczby[i] = new int [N];

	czytaj(N, liczby);
	rozwiazanie(N, liczby);
}