#include "Fruiiiit.h"


//Konstruktor / Dekonstruktor
Fruiiiit::Fruiiiit()
{
	initVariables();
	initShape();
}

Fruiiiit::~Fruiiiit()
{
}

//Public Functions
void Fruiiiit::update()
{
}

void Fruiiiit::render(RenderTarget* target)
{
	target->draw(shape);
}

//Accessors
const FloatRect Fruiiiit::getGlobalBounds() const
{
	return shape.getGlobalBounds();
}

//Modifier
void Fruiiiit::setPos(Vector2f newPosition)
{
	shape.setPosition(newPosition);
}

//Private Functions
void Fruiiiit::initVariables()
{

}

void Fruiiiit::initShape()
{
	shape.setSize(Vector2f(28.f, 28.f));
	shape.setPosition(Vector2f(static_cast<float>(rand() % 24) * 30, static_cast<float>(rand() % 24) * 30));
	shape.setFillColor(Color(84, 0, 117, 255));
	//shape.setOutlineThickness(2.f);
	//shape.setOutlineColor(Color(194, 158, 0, 255));
}
