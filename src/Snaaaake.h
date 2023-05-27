#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/Color.hpp>

using namespace sf;
class Snaaaake {
public:
	Snaaaake(Vector2f Position, Color color);
	~Snaaaake();
	void update();
	void render(RenderTarget* target);

	//Accessor
	const FloatRect getGlobalBounds() const;
	const Vector2f getPos() const;
	const bool isChanged() const;
	const Vector2f getDirection() const;
	const Vector2f getOldPos() const;

	void savePosition();
	void bounceBack(int wahl);

	//Modifier
	void setChanged(bool wahl);
	void setNewDirection(Vector2f newDirection);
	void setPos(Vector2f newPosition);
	void setColor(Color color);

private:

	RectangleShape shape;
	Vector2f dirMerker;

	void initVariables();
	void initShape(Color color);

	void move();

	bool changedDir;
	Vector2f oldPosition;
};