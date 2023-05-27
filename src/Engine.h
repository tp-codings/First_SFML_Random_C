#pragma once
#include "Snake.h"
#include "Fruit.h"
#include "SnakeBody.h"
#include <vector>
using namespace sf;

class Engine
{
public:
	Engine();
	~Engine();
	void play();

private:

	//Window
	RenderWindow* window;
	VideoMode videomode;

	//Events
	Event closeEvent;

	//Game Objects
	Snake* player;
	Fruit* fruit;
	std::vector<SnakeBody*> schlangenKoerper;

	//Ressources

	//Text

	//Private Functions
	void update();
	void render();
	void updateCollision();
	void updateSnake();
	void initVariables();
	void initWindow();
	void pollEvents();
	Vector2f zufallRaster();
	void spawnSnakeBody();
	bool einGewartet();
	bool isPlayerMoved30();
	int counter;

	bool einMalMove;
	bool einMalMoveSnake;

	bool farfarAway;
};

