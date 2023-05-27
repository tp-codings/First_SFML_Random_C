#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
using namespace sf;
class SnakeBody
{
public:
	SnakeBody(Vector2f pos);
	~SnakeBody();
	void update(Vector2f direction);
	void render(RenderTarget* target);

	//Accessor
	const FloatRect getGlobalBounds() const;
	const Vector2f getPos() const;

	const Vector2f getDirection() const;
	const bool isChanged() const;

	bool weitGenug();

	//Modifier

	void setNewDirection(Vector2f newDirection);
	void moveDirection();
	void moveOpposite();
	void setChanged(bool wahl);

private:

	RectangleShape shape;
	void initVariables();
	void initShape(Vector2f pos);


	Vector2f direction;
	bool changedDir;
};

