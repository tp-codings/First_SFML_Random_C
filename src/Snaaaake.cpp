#include "Snaaaake.h"

//Konstruktor / Dekonstruktor
Snaaaake::Snaaaake(Vector2f Position, Color color)
{
	initVariables();
	initShape(color);
	shape.setPosition(Position);
}

Snaaaake::~Snaaaake()
{
}


//Public Functions
void Snaaaake::update()
{
	move();
}

void Snaaaake::render(RenderTarget* target)
{
	target->draw(shape);
}


//Accessors
const FloatRect Snaaaake::getGlobalBounds() const
{
	return shape.getGlobalBounds();
}

const Vector2f Snaaaake::getPos() const
{
	return shape.getPosition();
}

const bool Snaaaake::isChanged() const
{
	return changedDir;
}

const Vector2f Snaaaake::getDirection() const
{
	return dirMerker;
}

const Vector2f Snaaaake::getOldPos() const
{
	return oldPosition;
}

void Snaaaake::savePosition()
{
	oldPosition = shape.getPosition();
}

void Snaaaake::bounceBack(int wahl)
{
	switch (wahl)
	{
	//left
	case 1:
		shape.move(Vector2f(30.f, 0.f));
		break;
	//right
	case 2:
		shape.move(Vector2f(-28.f, 0.f));
		break;
	//top
	case 3:
		shape.move(Vector2f(0.f, 28.f));
		break;
	//bottom
	case 4:
		shape.move(Vector2f(0.f, -30.f));
		break;
	}
}


//Modifier
void Snaaaake::setChanged(bool wahl)
{
	changedDir = wahl;
}

void Snaaaake::setNewDirection(Vector2f newDirection)
{
	dirMerker = newDirection;
}

void Snaaaake::setPos(Vector2f newPosition)
{
	shape.setPosition(newPosition);
}

void Snaaaake::setColor(Color color)
{
	shape.setFillColor(color);
}


//Private Functions
void Snaaaake::initVariables()
{
	changedDir = false;
}

void Snaaaake::initShape(Color color)
{
	shape.setSize(Vector2f(28.f, 28.f));
	shape.setFillColor(color);
	shape.setOutlineThickness(1.f);
	shape.setOutlineColor(Color(255, 248, 214, 255));
}

void Snaaaake::move()
{
	shape.move(dirMerker);
}


