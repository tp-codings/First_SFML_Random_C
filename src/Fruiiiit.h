#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/Color.hpp>

using namespace sf;

class Fruiiiit
{
public:
	Fruiiiit();
	~Fruiiiit();
	void update();
	void render(RenderTarget* target);

	//Accessor
	const FloatRect getGlobalBounds() const;

	//Modifier
	void setPos(Vector2f newPosition);

private:

	RectangleShape shape;

	void initVariables();
	void initShape();
};

