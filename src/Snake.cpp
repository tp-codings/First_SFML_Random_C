#include "Snake.h"


Snake::Snake()
{
	initVariables();
	initSnake();
}

Snake::~Snake()
{
}

void Snake::update(RenderWindow *window)
{
	changeDirection();
}

void Snake::render(RenderTarget* target)
{
	target->draw(shape);
}

const FloatRect Snake::getGlobalBounds() const
{
	return shape.getGlobalBounds();
}

const Vector2f Snake::getPos() const
{
	return shape.getPosition();
}

const bool Snake::isChanged() const
{
	return changedDir;
}

const Vector2f Snake::getDirection() const
{
	return dirMerker;
}

bool Snake::weitGenug()
{
	//std::cout << "TEST    0\n";
	//std::cout << shape.getPosition().x << "\n";
	//std::cout << shape.getPosition().y << "\n";
	//std::cout << direction.x << "\n";
	//std::cout << direction.y << "\n";
	if (dirMerker.x != 0)
	{
		//std::cout << "TEST    1\n";
		if (static_cast<int>(shape.getPosition().x) % 30 == 0)
		{
			//std::cout << "TEST    11\n";
			return true;
		}
	}

	if (dirMerker.y != 0)
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

void Snake::setChanged(bool wahl)
{
	changedDir = wahl;
}




//private Functions
void Snake::initSnake()
{
	shape.setSize(Vector2f(30.f, 30.f));
	shape.setPosition(Vector2f(30.f, 30.f));
	shape.setFillColor(Color::Green);
	//shape.setOutlineThickness(2.f);
	//shape.setOutlineColor(Color(0, 102, 39, 255));
}

void Snake::initVariables()
{
	movementSpeed = 6.f;
	changedDir = false;
}

void Snake::changeDirection()
{
	if (Keyboard::isKeyPressed(Keyboard::A) && dirMerker != Vector2f(movementSpeed, 0.f) && dirMerker != Vector2f(-movementSpeed, 0.f))
	{
			
		if (weitGenugY())
		{
			dirMerker = Vector2f(-movementSpeed, 0.f);
			changedDir = true;
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::D) && dirMerker != Vector2f(-movementSpeed, 0.f) && dirMerker != Vector2f(movementSpeed, 0.f))
	{
		if (weitGenugY())
		{
			dirMerker = Vector2f(movementSpeed, 0.f);
			changedDir = true;
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::W) && dirMerker != Vector2f(0.f, movementSpeed) && dirMerker != Vector2f(0.f, -movementSpeed))
	{
		
		if (weitGenugX())
		{
			dirMerker = Vector2f(0.f, -movementSpeed);
			changedDir = true;
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::S) && dirMerker != Vector2f(0.f, -movementSpeed) && dirMerker != Vector2f(0.f, movementSpeed))
	{
		if (weitGenugX())
		{
			dirMerker = Vector2f(0.f, movementSpeed);
			changedDir = true;
		}
	}
}

void Snake::move(RenderWindow *window)
{
	shape.move(dirMerker);
	//updateCollision(window);
}


void Snake::updateCollision(RenderWindow *window)
{
	//left side
	if (shape.getPosition().x <= 0.f)
	{
		shape.setPosition(0.f + shape.getOutlineThickness(), shape.getPosition().y);
	}

	//right side
	if (shape.getPosition().x + shape.getGlobalBounds().width > window->getSize().x)
	{
		shape.setPosition(window->getSize().x - shape.getGlobalBounds().width + shape.getOutlineThickness(), shape.getPosition().y);
	}

	//top
	if (shape.getPosition().y <= 0.f)
	{
		shape.setPosition(shape.getPosition().x, 0.f + shape.getOutlineThickness());
	}

	//bottom
	if (shape.getPosition().y + shape.getGlobalBounds().height > window->getSize().y)
	{
		shape.setPosition(shape.getPosition().x, window->getSize().y - shape.getGlobalBounds().height + shape.getOutlineThickness());
	}
}

bool Snake::weitGenugX()
{
	if (shape.getPosition().x == 0)
	{
		return true;
	}
	else if (static_cast<int>(shape.getPosition().x) % 30 == 0)
	{
		return true;
	}
	return false;
}

bool Snake::weitGenugY()
{
	if (shape.getPosition().y == 0)
	{
		return true;
	}
	else if (static_cast<int>(shape.getPosition().y) % 30 == 0)
	{
		return true;
	}
	return false;
}


