#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/Color.hpp>
#include <iostream>

using namespace sf;

class Snake
{
public:
	Snake();
	~Snake();
	void update(RenderWindow *window);
	void render(RenderTarget *target);

	//Accessor
	const FloatRect getGlobalBounds() const;
	const Vector2f getPos() const;
	const bool isChanged() const;
	const Vector2f getDirection() const;

	bool weitGenug();
	//Modifier
	void setChanged(bool wahl);
	void move(RenderWindow *window);
	
private:

	RectangleShape shape;
	float movementSpeed;
	Vector2f dirMerker;

	void initVariables();
	void initSnake();
	void changeDirection();
	void updateCollision(RenderWindow *window);
	bool weitGenugX();
	bool weitGenugY();

	bool changedDir;
	
};

