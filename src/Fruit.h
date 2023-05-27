#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
using namespace sf;

class Fruit
{
public:
	Fruit();
	~Fruit();
	void update(RenderWindow* window);
	void render(RenderTarget* target);

	//Accessor
	const FloatRect getGlobalBounds() const;

	//Modifier
	void setPos(Vector2f newPosition);

private:

	RectangleShape shape;

	void initVariables();
	void initFruit();
};

