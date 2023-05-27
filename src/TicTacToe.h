#pragma once
#include <iostream>
#include <stdlib.h>

class TicTacToe
{
public:
	TicTacToe();
	~TicTacToe();
	void play();


private:
	void update(unsigned zeile, unsigned spalte, int player);
	void render();
	int pruefeEndGame();
	int countZaehler(int a, int b,int* cA, int* cB);
	void initVariables();
	bool pruefeBelegt(unsigned zeile, unsigned spalte);
	int pruefeNichtMehrGewinnbar();
	void KI();
	unsigned zufall();
	void pruefeUndSetze();
	bool wennGehtGewinnen();
	bool endGame;
	char raster[3][3];
};

