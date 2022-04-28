#include <iostream>
#include <fstream>

void czytaj(const short N, short** plansza_liczb)
{
	std::ifstream in("plansza.txt");
	for (short i = 0; i < N; i++)
		for (short j = 0; j < N; j++)
			in >> plansza_liczb[i][j];
	in.close();
}

void zerowanie(const short N, bool*** plansza_prawd)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				plansza_prawd[i][j][k] = true;
}

void wypisz(const short N, short** plansza_liczb, bool*** plansza_prawd)
{
	for (short i = 0; i < N; i++)
	{
		for (short j = 0; j < N; j++)
			std::cout << plansza_liczb[i][j] << ' ';
		std::cout << '\n';
	}

	std::cout << "\n   1 2 3 4 5 6 7 8 9\n";

	for (short i = 0; i < N; i++)
	{
		for (short j = 0; j < N; j++)
		{
			std::cout << i << j << ' ';
			for (short k = 0; k < N; k++)
			{
				std::cout << plansza_prawd[i][j][k] << ' ';
			}
			std::cout << '\n';
		}
	}
}

void pozbycie_prawd(const short N, short** plansza_liczb, bool*** plansza_prawd)
{
	for (short i = 0; i < N; i++)
	{
		for (short j = 0; j < N; j++)
		{
			if (plansza_liczb[i][j] != 0)
				for (short k = 0; k < N; k++)
					plansza_prawd[i][j][k] = false;
		}
	}
}

void pozbycie_zer_linia(const short N, short x, short y, short** plansza_liczb, bool*** plansza_prawd)
{
	for (short i = 0; i < x; i++)
		if (plansza_liczb[i][y] != 0)
			plansza_prawd[x][y][plansza_liczb[i][y]-1] = false;
	for (short i = x + 1; i < N; i++)
		if (plansza_liczb[i][y] != 0)
			plansza_prawd[x][y][plansza_liczb[i][y]-1] = false;
	for (short i = 0; i < y; i++)
		if (plansza_liczb[x][i] != 0)
			plansza_prawd[x][y][plansza_liczb[x][i]-1] = false;
	for (short i = y + 1; i < N; i++)
		if (plansza_liczb[x][i] != 0)
			plansza_prawd[x][y][plansza_liczb[x][i]-1] = false;
}

void sprawdzanie_mozliwosci(const short N, short x, short y, short** plansza_liczb, bool*** plansza_prawd)
{
	short wynik = 0;
	for (short i = 0; i < N; i++)
		wynik += plansza_prawd[x][y][i];
	if (wynik == 1)
	{
		for (short i = 0; i < N; i++)
		{
			if (plansza_prawd[x][y][i])
			{
				plansza_liczb[x][y] = i + 1;
				break;
			}
		}
	}
}

void pozbycie_zer_kwadrat(const short N, short x, short y, short** plansza_liczb, bool*** plansza_prawd)
{
	if (x < 3)
	{
		if (y < 3)
		{
			for (short i = 0; i < 3; i++)
				for (short j = 0; j < 3; j++)
					if (plansza_liczb[i][j] != 0 && i != x && i != y)
						plansza_prawd[x][y][plansza_liczb[i][j] - 1] = false;
		}
		else if (y < 6)
		{
			for (short i = 0; i < 3; i++)
				for (short j = 3; j < 6; j++)
					if (plansza_liczb[i][j] != 0 && i != x && i != y)
						plansza_prawd[x][y][plansza_liczb[i][j] - 1] = false;
		}
		else
		{
			for (short i = 0; i < 3; i++)
				for (short j = 6; j < 9; j++)
					if (plansza_liczb[i][j] != 0 && i != x && i != y)
						plansza_prawd[x][y][plansza_liczb[i][j] - 1] = false;
		}
	}
	else if (x < 6)
	{
		if (y < 3)
		{
			for (short i = 3; i < 6; i++)
				for (short j = 0; j < 3; j++)
					if (plansza_liczb[i][j] != 0 && i != x && i != y)
						plansza_prawd[x][y][plansza_liczb[i][j] - 1] = false;
		}
		else if (y < 6)
		{
			for (short i = 3; i < 6; i++)
				for (short j = 3; j < 6; j++)
					if (plansza_liczb[i][j] != 0 && i != x && i != y)
						plansza_prawd[x][y][plansza_liczb[i][j] - 1] = false;
		}
		else
		{
			for (short i = 3; i < 6; i++)
				for (short j = 6; j < 9; j++)
					if (plansza_liczb[i][j] != 0 && i != x && i != y)
						plansza_prawd[x][y][plansza_liczb[i][j] - 1] = false;
		}
	}
	else
	{
		if (y < 3)
		{
			for (short i = 6; i < 9; i++)
				for (short j = 0; j < 3; j++)
					if (plansza_liczb[i][j] != 0 && i != x && i != y)
						plansza_prawd[x][y][plansza_liczb[i][j] - 1] = false;
		}
		else if (y < 6)
		{
			for (short i = 6; i < 9; i++)
				for (short j = 3; j < 6; j++)
					if (plansza_liczb[i][j] != 0 && i != x && i != y)
						plansza_prawd[x][y][plansza_liczb[i][j] - 1] = false;
		}
		else
		{
			for (short i = 6; i < 9; i++)
				for (short j = 6; j < 9; j++)
					if (plansza_liczb[i][j] != 0 && i != x && i != y)
						plansza_prawd[x][y][plansza_liczb[i][j] - 1] = false;
		}
	}
}

void pozbycie_wstep(const short N, short** plansza_liczb, bool*** plansza_prawd)
{
	for (short i = 0; i < N; i++)
		for (short j = 0; j < N; j++)
			if (plansza_liczb[i][j] == 0)
			{

				pozbycie_zer_linia(N, i, j, plansza_liczb, plansza_prawd);
				pozbycie_zer_kwadrat(N, i, j, plansza_liczb, plansza_prawd);
				sprawdzanie_mozliwosci(N, i, j, plansza_liczb, plansza_prawd);
			}
}

bool koniec(const short N, short** plansz_liczb)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (plansz_liczb[i][j] == 0)
				return true;
	return false;
}

int main()
{
	const short N = 9;
	short* plansza_liczb[N];
	bool** plansza_prawd[N];

	for (short i = 0; i < N; i++)
	{
		plansza_liczb[i] = new short [N];
		plansza_prawd[i] = new bool* [N];
		for (short j = 0; j < N; j++)
			plansza_prawd[i][j] = new bool [N];
	}

	czytaj(N, plansza_liczb);
	zerowanie(N, plansza_prawd);
	pozbycie_prawd(N, plansza_liczb, plansza_prawd);
	while (koniec)
		pozbycie_wstep(N, plansza_liczb, plansza_prawd);
	wypisz(N, plansza_liczb, plansza_prawd);
}