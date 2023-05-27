#include "Fruit.h"

Fruit::Fruit()
{
	initVariables(); 
	initFruit();
}

Fruit::~Fruit()
{
}


//Public Functions
void Fruit::update(RenderWindow* window)
{
}

void Fruit::render(RenderTarget* target)
{
	target->draw(shape);
}

const FloatRect Fruit::getGlobalBounds() const
{
	return shape.getGlobalBounds();
}

void Fruit::setPos(Vector2f newPosition)
{
	shape.setPosition(newPosition);
}

//Private Functions
void Fruit::initVariables()
{
}

void Fruit::initFruit()
{
	shape.setSize(Vector2f(30.f, 30.f));
	shape.setPosition(Vector2f(static_cast<float>(rand() % 24) * 30, static_cast<float>(rand() % 24) * 30));
	shape.setFillColor(Color(84, 0, 117, 255));
	//shape.setOutlineThickness(2.f);
	//shape.setOutlineColor(Color(16, 0, 117, 255));
}
