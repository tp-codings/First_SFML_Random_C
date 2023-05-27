#include "TicTacToe.h"


TicTacToe::TicTacToe()
{
	initVariables();
}

TicTacToe::~TicTacToe()
{
}

void TicTacToe::play()
{
	int player = 1;
	int winner = 0;
	int spielen = 1;
	int zuegePlayer = 1;
	char choice = '-';
	unsigned zeile = 0;
	unsigned spalte = 0;

	std::cout << "\nTIC TAC TOE\n\n\n";
	std::cout << "Gegen KI oder Freund spielen? [KI: k; Freund: f]\n";
	std::cin >> choice;
	while (choice != 'k' && choice != 'f')
	{
		std::cout << "ERROR: FALSCHE EINGABE [KI: k; Freund: f]\n";
		std::cin >> choice;
	}

	do
	{
			
		if (endGame)
		{
			std::cout << "\nNoch mal Spielen? [Zahl druecken, ansonsten 0 fuer Abbruch]\n";
			std::cin >> spielen;
			if (spielen != 0)
			{
				player = 1;
				initVariables();
				winner = 0;
				zeile = 0;
				spalte = 0;
				zuegePlayer = 0;
				std::cout << "Gegen KI oder Freund spielen? [KI: k; Freund: f]\n";
				std::cin >> choice;
				while (choice != 'k' && choice != 'f')
				{
					std::cout << "ERROR: FALSCHE EINGABE [KI: k; Freund: f]\n";
					std::cin >> choice;
				}
			}
			system("CLS");
		}
		if (!endGame)
		{

			if (choice == 'f')
			{
				std::cout << "Player: " << player << " waehlen!\n";
				std::cin >> zeile;
				std::cin >> spalte;
				std::cout << "\n";
				if (!pruefeBelegt(zeile, spalte))
				{
					if (zeile > 2 || spalte > 2) std::cout << "ERROR: Außerhalb der Range\n\n";
					else
					{
						update(zeile, spalte, player);
						winner = pruefeEndGame();
						if (player == 2)
							player = 1;
						else
							player++;
						system("CLS");
						render();
					}
					if (winner != 0 && winner != 4)
						std::cout << "Player: " << winner << " hat gewonnen!!\nPlayer: " << player << " Verloren!\n";
					if (winner == 4)
						std::cout << "DRAW\n";
				}
				else
					std::cout << "\nFeld belegt!\n\n";
			}
			else if (choice == 'k')
			{
				std::cout << "Waehlen!\n";
				std::cin >> zeile;
				std::cin >> spalte;
				std::cout << "\n";
				if (!pruefeBelegt(zeile, spalte))
				{
					if (zeile > 2 || spalte > 2) std::cout << "ERROR: Außerhalb der Range\n\n";
					else
					{
						update(zeile, spalte, 1);
						winner = pruefeEndGame();
						if (!endGame)
						{
							KI();
							winner = pruefeEndGame();
						}
						system("CLS");
						render();
						zuegePlayer++;
					}
					if (winner == 1)
						std::cout << "Player hat gewonnen!!\n";
					else if (winner == 2)
						std::cout << "KI hat gewonnen!!\n";
					if (winner == 4)
						std::cout << "DRAW\n";
				}
				else
					std::cout << "\nFeld belegt!\n\n";
			}
		}
	} while (!endGame || spielen != 0);
	std::cout << "TicTacToe beendet!\n";
	system("PAUSE");
}

void TicTacToe::update(unsigned zeile, unsigned spalte, int player)
{
	
	if (player == 1)
	{
		raster[zeile][spalte] = 'O';
	}
	else
	{
		raster[zeile][spalte] = 'X';
	}
}

void TicTacToe::render()
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 3; k++)
		{
			std::cout << raster[i][k] << " ";
		} std::cout << "\n";
	}
	std::cout << "\n";
	std::cout << "\n";
}

int TicTacToe::pruefeEndGame()
{
	int countX = 0;
	int countO = 0;
	int winner = 0;

	//Zeilen Prüfen
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 3; k++)
		{
			if (raster[i][k] == 'O')
				countO++;
			else if (raster[i][k] == 'X')
				countX++;
		}
		winner = countZaehler(countO, countX, &countO, &countX);
		if (winner != 0) return winner;
	}
	//Spalten Prüfen
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 3; k++)
		{
			if (raster[k][i] == 'O')
				countO++;
			else if (raster[k][i] == 'X')
				countX++;
		}
		winner = countZaehler(countO, countX, &countO, &countX);
		if (winner != 0) return winner;
	}

	//erste Hauptdiagonale
	for (size_t i = 0; i < 3; i++)
	{
		if (raster[i][i] == 'O')
			countO++;
		else if (raster[i][i] == 'X')
			countX++;
	}

	winner = countZaehler(countO, countX, &countO, &countX);
	if (winner != 0) return winner;
	
	//zweite Hauptdiagonale
	int i = 2;
	int k = 0;
	while (i >= 0 && k < 3)
	{
		if (raster[i][k] == 'O')
			countO++;
		else if (raster[i][k] == 'X')
			countX++;
		i--;
		k++;
	}
	winner = countZaehler(countO, countX, &countO, &countX);
	if (winner != 0) return winner;
	if (pruefeNichtMehrGewinnbar() == 4) return 4;
	return 0;
}

int TicTacToe::countZaehler(int a, int b, int *cA, int *cB)
{
	int winner = 0;
	if (a == 3)
	{
		endGame = true;
		winner = 1;
	}
	else if (b == 3)
	{
		endGame = true;
		winner = 2;
	}
	*cA = 0;
	*cB = 0;
	return winner;
}

void TicTacToe::initVariables()
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 3; k++)
		{
			this->raster[i][k] = '-';
		}
	}
	endGame = false;
}

bool TicTacToe::pruefeBelegt(unsigned zeile, unsigned spalte)
{
	if (raster[zeile][spalte] == 'X' || raster[zeile][spalte] == 'O')
		return true;
	else
		return false;
}

int TicTacToe::pruefeNichtMehrGewinnbar()
{
	int count = 0;
	int k = 0;
	int i = 0;
	bool zeileVoll = false;
	bool spalteVoll = false;
	bool ersteHD = false;
	bool zweiteHD = false;

	//Zeilen prüfen
	
	for (size_t i = 0; i < 3; i++)
	{
		if (
			raster[i][k] == 'O' && raster[i][k + 1] == 'X' ||
			raster[i][k] == 'X' && raster[i][k + 1] == 'O' ||
			raster[i][k] == 'O' && raster[i][k + 2] == 'X' ||
			raster[i][k] == 'X' && raster[i][k + 2] == 'O' ||
			raster[i][k+1] == 'O' && raster[i][k + 2] == 'X' ||
			raster[i][k+1] == 'X' && raster[i][k + 2] == 'O' 
			)
			count++;
	}
	if (count == 3) zeileVoll = true;
	count = 0;

	//Spalten prüfen
	for (size_t k = 0; k < 3; k++)
	{
		if (
			raster[i][k] == 'O' && raster[i+1][k] == 'X' ||
			raster[i][k] == 'X' && raster[i+1][k] == 'O' ||
			raster[i][k] == 'O' && raster[i+2][k] == 'X' ||
			raster[i][k] == 'X' && raster[i+2][k] == 'O' ||
			raster[i+1][k] == 'O' && raster[i+2][k] == 'X' ||
			raster[i+1][k] == 'X' && raster[i+2][k] == 'O'
			)
			count++;
	}
	if (count == 3) spalteVoll = true;
	count = 0;

	//erste Hauptdiagonale
	i = 0;
	k = 0;
	if (
		raster[i][k] == 'O' && raster[i + 1][k + 1] == 'X' ||
		raster[i][k] == 'X' && raster[i + 1][k + 1] == 'O' ||
		raster[i + 1][k + 1] == 'O' && raster[i + 2][k + 2] == 'X' ||
		raster[i + 1][k + 1] == 'X' && raster[i + 2][k + 2] == 'O' ||
		raster[i][k] == 'O' && raster[i + 2][k + 2] == 'X' ||
		raster[i][k] == 'X' && raster[i + 2][k + 2] == 'O'
		)
		ersteHD = true;

	//zweite Hauptdiagonale
	i = 2;
	k = 0;
	if (
		raster[i][k] == 'O' && raster[i - 1][k + 1] == 'X' ||
		raster[i][k] == 'X' && raster[i - 1][k + 1] == 'O' ||
		raster[i - 1][k + 1] == 'O' && raster[i - 2][k + 2] == 'X' ||
		raster[i - 1][k + 1] == 'X' && raster[i - 2][k + 2] == 'O' ||
		raster[i][k] == 'O' && raster[i - 2][k + 2] == 'X' ||
		raster[i][k] == 'X' && raster[i - 2][k + 2] == 'O'
		)
		zweiteHD = true;


	if (zeileVoll && spalteVoll && ersteHD && zweiteHD)
	{
		endGame = true;
		return 4;
	}
	return 0;
}

void TicTacToe::KI()
{
		pruefeUndSetze();
}

unsigned TicTacToe::zufall()
{
	return static_cast<unsigned>(rand() % 3);
}

void TicTacToe::pruefeUndSetze()
{
	int k = 0;
	int i = 0;
	unsigned zeilenWahl = 3;
	unsigned spaltenWahl = 3;

	//Gewinnen prüfen
	if (wennGehtGewinnen())
	{
		return;
	}

	//Zeilen prüfen
	for (size_t i = 0; i < 3; i++)
	{
		if (raster[i][k] == 'O' && raster[i][k + 1] == 'O' && raster[i][k + 2] != 'X')
		{
			update(i, k + 2, 2);
			return;
		}
		if (raster[i][k] == 'O' && raster[i][k + 2] == 'O' && raster[i][k + 1] != 'X')
		{
			update(i, k + 1, 2);
			return;
		}
		if (raster[i][k+1] == 'O' && raster[i][k + 2] == 'O' && raster[i][k] != 'X')
		{
			update(i, k, 2);
			return;
		}
	}

	//Spalten prüfen
	for (size_t k = 0; k < 3; k++)
	{
		if (raster[i][k] == 'O' && raster[i+1][k] == 'O' && raster[i+2][k] != 'X')
		{
			update(i+2, k, 2);
			return;
		}
		if (raster[i][k] == 'O' && raster[i+2][k] == 'O' && raster[i+1][k] != 'X')
		{
			update(i+1, k, 2);
			return;
		}
		if (raster[i+1][k] == 'O' && raster[i+2][k] == 'O' && raster[i][k] != 'X')
		{
			update(i, k, 2);
			return;
		}
	}

	//Erste HD prüfen
	{
		if (raster[i][k] == 'O' && raster[i + 1][k + 1] == 'O' && raster[i + 2][k + 2] != 'X')
		{
			update(i + 2, k + 2, 2);
			return;
		}
		if (raster[i][k] == 'O' && raster[i + 2][k + 2] == 'O' && raster[i + 1][k + 1] != 'X')
		{
			update(i + 1, k + 1, 2);
			return;
		}
		if (raster[i + 2][k + 2] == 'O' && raster[i + 1][k + 1] == 'O' && raster[i][k] != 'X')
		{
			update(i, k, 2);
			return;
		}
	}

	//Zweite HD prüfen
	{
		
		if (raster[i+2][k] == 'O' && raster[i + 1][k + 1] == 'O' && raster[i][k + 2] != 'X')
		{
			update(i, k + 2, 2);
			return;
		}
		if (raster[i+2][k] == 'O' && raster[i][k + 2] == 'O' && raster[i + 1][k + 1] != 'X')
		{
			update(i + 1, k + 1, 2);
			return;
		}
		if (raster[i + 1][k + 1] == 'O' && raster[i][k + 2] == 'O' && raster[i+2][k] != 'X')
		{
			update(i+2, k, 2);
			return;
		}
	}

	//sonst ein Zug
	do
	{
		zeilenWahl = zufall();
		spaltenWahl = zufall();
	} while (pruefeBelegt(zeilenWahl, spaltenWahl));
	update(zeilenWahl, spaltenWahl, 2);
	return;
}

bool TicTacToe::wennGehtGewinnen()
{
	int k = 0;
	int i = 0;
	//Zeilen prüfen
	for (size_t i = 0; i < 3; i++)
	{
		if (raster[i][k] == 'X' && raster[i][k + 1] == 'X' && raster[i][k + 2] != 'O')
		{
			update(i, k + 2, 2);
			return true;
		}
		if (raster[i][k] == 'X' && raster[i][k + 2] == 'X' && raster[i][k + 1] != 'O')
		{
			update(i, k + 1, 2);
			return true;
		}
		if (raster[i][k + 1] == 'X' && raster[i][k + 2] == 'X' && raster[i][k] != 'O')
		{
			update(i, k, 2);
			return true;
		}
	}

	//Spalten prüfen
	for (size_t k = 0; k < 3; k++)
	{
		if (raster[i][k] == 'X' && raster[i + 1][k] == 'X' && raster[i + 2][k] != 'O')
		{
			update(i + 2, k, 2);
			return true;
		}
		if (raster[i][k] == 'X' && raster[i + 2][k] == 'X' && raster[i + 1][k] != 'O')
		{
			update(i + 1, k, 2);
			return true;
		}
		if (raster[i + 1][k] == 'X' && raster[i + 2][k] == 'X' && raster[i][k] != 'O')
		{
			update(i, k, 2);
			return true;
		}
	}

	//Erste HD prüfen
	{
		if (raster[i][k] == 'X' && raster[i + 1][k + 1] == 'X' && raster[i + 2][k + 2] != 'O')
		{
			update(i + 2, k + 2, 2);
			return true;
		}
		if (raster[i][k] == 'X' && raster[i + 2][k + 2] == 'X' && raster[i + 1][k + 1] != 'O')
		{
			update(i + 1, k + 1, 2);
			return true;
		}
		if (raster[i + 2][k + 2] == 'X' && raster[i + 1][k + 1] == 'X' && raster[i][k] != 'O')
		{
			update(i, k, 2);
			return true;
		}
	}

	//Zweite HD prüfen
	{

		if (raster[i + 2][k] == 'X' && raster[i + 1][k + 1] == 'X' && raster[i][k + 2] != 'O')
		{
			update(i, k + 2, 2);
			return true;
		}
		if (raster[i + 2][k] == 'X' && raster[i][k + 2] == 'X' && raster[i + 1][k + 1] != 'O')
		{
			update(i + 1, k + 1, 2);
			return true;
		}
		if (raster[i + 1][k + 1] == 'X' && raster[i][k + 2] == 'X' && raster[i + 2][k] != 'O')
		{
			update(i + 2, k, 2);
			return true;
		}
	}
	return false;
}
