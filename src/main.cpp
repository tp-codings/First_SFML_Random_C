#include "Liste.h"
#include "Arrays.h"
#include "Zugriff.h"
#include "TicTacToe.h"
#include "Engine.h"
#include "EngineSnake.h"
#include <ctime>
#include <string>


int main() {

	srand(time(0));

	Liste liste;
	liste.listenApplication();
	liste.push(3);
	liste.print();

	Arrays array;
	//array.ArrayApplication();

	Zugriff zugriff;
	//zugriff.zugriffApplication();

	TicTacToe ticitaca;
	//ticitaca.play();

	Engine snake;
	//snake.play();

	EngineSnake Snake;
	//Snake.play();
}
