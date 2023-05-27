#include "Arrays.h"
#include <iostream>

Arrays::Arrays()
{
	for (size_t i = 0; i < 3; i++)
	{
		einD[i] = 0;
	}
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 3; k++)
		{
			zweiD[k][i] = 0;
		}
	}
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t k = 0; k < 3; k++)
		{
			for (size_t p = 0; p < 3; p++)
			{
				dreiD[p][k][i] = 0;
			}
		}
	}
}

Arrays::~Arrays()
{
}

void Arrays::ArrayApplication()
{
	int wahl;
	int value;
	int i = 0;
	int size = 0;

	do
	{
		std::cout << "Welches Array soll initialisiert werden? [1, 2, 3] \n\n";
		std::cin >> wahl;

		if (wahl == 1 || wahl == 2 || wahl == 3)
		{
			switch (wahl)
			{
			case 1: size = 3; break;
			case 2: size = 9; break;
			case 3: size = 27; break;
			}
			//std::cout << "Wie groß? [ganze Zahlen]";
			//std::cin >> groesse;
			std::cout << "jetzt Werte eingeben \n";
			do
			{
				std::cin >> value;
				initArray(value, wahl, i);
				i++;
			} while (i < size);
			showArray(wahl);
			std::cout << "\n";
		}
		i = 0;
		size = 0;
	} while (wahl != 0);
	std::cout << "\nArrayapplication beendet \n";
}

int Arrays::initArray(int val, int wahl, int stelle)
{
	switch (wahl) {
	case 1:
		init1D(val, stelle);
		break;
	case 2:
		init2D(val, stelle);
		break;
	case 3:
		init3D(val, stelle);
		break;
	}
	return 0;
}

int Arrays::showArray(int choice)
{
	switch (choice) {
	case 1:
		std::cout << "Eindimensionales Array: | ";
		for (size_t i = 0; i < 3; i++)
		{
			std::cout << einD[i] << " | ";
		}
		std::cout << "\n";
		break;
	case 2:
		std::cout << "Zweidimensionales Array: \n|";
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t k = 0; k < 3; k++)
			{
				std::cout << zweiD[k][i] << " | ";
			}
			if(i<2)
				std::cout << "\n|";
			else std::cout << "\n";
		}
		break;
	case 3:
		std::cout << "Dreidimensionales Array: \n|";
		std::cout << "|";
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t k = 0; k < 3; k++)
			{
				for (size_t p = 0; p < 3; p++)
				{
					std::cout << "( " << dreiD[p][k][i] <<" )" << " ";
				}
				std::cout << "|";
			}
			if (i < 2)
				std::cout << "\n|";
			else std::cout << "\n";
		}


		
		break;
	}
	return 0;
}

int Arrays::init1D(int val, int stelle)
{
	einD[stelle] = val;
	return 0;
}

int Arrays::init2D(int val, int stelle)
{
	switch(stelle)
	{
	case 0:
	case 1:
	case 2:
		zweiD[stelle][0] = val;
		break;
	case 3:
	case 4:
	case 5:
		zweiD[stelle-3][1] = val;
		break;
	case 6:
	case 7:
	case 8:
		zweiD[stelle-6][2] = val;
		break;
	}
	return 0;
}

int Arrays::init3D(int val, int stelle)
{
	if (stelle < 3)
	{
		dreiD[stelle][0][0] = val;
	}
	else if (stelle < 6)
	{
		dreiD[stelle-3][1][0] = val;
	}
	else if (stelle < 9)
	{
		dreiD[stelle-6][2][0] = val;
	}
	else if (stelle < 12)
	{
		dreiD[stelle-9][0][1] = val;
	}
	else if (stelle < 15)
	{
		dreiD[stelle-12][1][1] = val;
	}
	else if (stelle < 18)
	{
		dreiD[stelle-15][2][1] = val;
	}
	else if (stelle < 21)
	{
		dreiD[stelle-18][0][2] = val;
	}
	else if (stelle < 24)
	{
		dreiD[stelle-21][1][2] = val;
	}
	else if (stelle < 27)
	{
		dreiD[stelle-24][2][2] = val;
	}
	return 0;
}
