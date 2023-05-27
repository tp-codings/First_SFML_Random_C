#pragma once
#include "Snaaaake.h"
#include "Fruiiiit.h"
#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace sf;

class EngineSnake {
public:
	EngineSnake();
	~EngineSnake();
	void play();

private:
	//Window
	RenderWindow* window;
	VideoMode videomode;

	//Events
	Event closeEvent;

	//Game Objects
	Fruiiiit* fruit;
	std::vector<Snaaaake*> snake;

	//Game logic
	float movementSpeed;
	bool endGame;
	bool firstWaitOne;

	//Ressources
	std::map<std::string, Font*> fonts;
	
	//Text
	std::map<std::string, Text*> texts;

	//Private Functions
	void update();
	void render();

	void updateDirection();
	void updateSnake();
	void updateCollision();
	void updateGUI();
	
	void renderGUI(RenderTarget *target);

	void spawnSnakeBody();
	bool collisionWorldBorders();
	Vector2f zufallRaster();

	void initVariables();
	void initWindow();
	void initGUI();
	void pollEvents();
};