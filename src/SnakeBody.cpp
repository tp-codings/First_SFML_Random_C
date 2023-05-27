#include "SnakeBody.h"
#include <iostream>
#pragma once

SnakeBody::SnakeBody(Vector2f pos)
{
	initVariables();
	initShape(pos);
	
}

SnakeBody::~SnakeBody()
{
}
//Public Functions
void SnakeBody::update(Vector2f direction)
{
	//follow(direction);
}

void SnakeBody::render(RenderTarget* target)
{
	target->draw(shape);
}

const FloatRect SnakeBody::getGlobalBounds() const
{
	return shape.getGlobalBounds();
}

const Vector2f SnakeBody::getPos() const
{
	return shape.getPosition();
}

const Vector2f SnakeBody::getDirection() const
{
	return direction;
}

const bool SnakeBody::isChanged() const
{
	return changedDir;
}

bool SnakeBody::weitGenug()
{
	//std::cout << "TEST    0\n";
	//std::cout << shape.getPosition().x << "\n";
	//std::cout << shape.getPosition().y << "\n";
	//std::cout << direction.x << "\n";
	//std::cout << direction.y << "\n";
	if (direction.x != 0)
	{
		//std::cout << "TEST    1\n";
		if (static_cast<int>(shape.getPosition().x) % 30 == 0)
		{
			//std::cout << "TEST    11\n";
			return true;
		}
	}

	if (direction.y != 0)
	{
		//std::cout << "TEST    2\n";
		if (static_cast<int>(shape.getPosition().y) % 30 == 0)
		{
			//std::cout << "TEST    22\n";
			return true;
		}
	}

	return false;
}

void SnakeBody::setNewDirection(Vector2f newDirection)
{
	direction = newDirection;
	//std::cout << direction.x << "\n";
	//std::cout << direction.y << "\n";
}

void SnakeBody::moveDirection()
{
	shape.move(direction);
}

void SnakeBody::moveOpposite()
{
	shape.move(-direction);
}

void SnakeBody::setChanged(bool wahl)
{
	changedDir = wahl;
}


void SnakeBody::initVariables()
{
	changedDir = false;
}

void SnakeBody::initShape(Vector2f pos)
{
	shape.setSize(Vector2f(30.f, 30.f));
	shape.setPosition(Vector2f(pos));
	shape.setFillColor(Color::Magenta);
	//shape.setOutlineThickness(2.f);
	//shape.setOutlineColor(Color(255, 248, 214, 255));
}

