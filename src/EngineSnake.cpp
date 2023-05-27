#include "EngineSnake.h"


//Konstruktor / Dekonstruktor
EngineSnake::EngineSnake()
{
	initVariables();
	initWindow();
	initGUI();
}

EngineSnake::~EngineSnake()
{
	delete window;
	delete fruit;
	for (auto* i : snake)
	{
		delete i;
	}
}


//Public Functions
void EngineSnake::play()
{
	while (window->isOpen())
	{
		
		sleep(Time(seconds(0.1)));
		update();
		render();
	}
}


//Private Functions
void EngineSnake::update()
{
	pollEvents();
	if (!endGame)
	{
		updateDirection();
		updateSnake();
		updateCollision();
	}
	updateGUI();
}

void EngineSnake::render()
{
	window->clear(Color(255, 248, 214, 255));
	if (!endGame)
	{
		renderGUI(window);
	}
	fruit->render(window);
	for (int i = snake.size()-1; i >= 0; i--)
	{
		snake[i]->render(window);
	}
	if (endGame)
	{
		renderGUI(window);
	}
	window->display();
}


//-----------------------------------------------------------------------------------------------
void EngineSnake::updateDirection()
{
	if (Keyboard::isKeyPressed(Keyboard::A) && snake[0]->getDirection() != Vector2f(movementSpeed, 0.f) && snake[0]->getDirection() != Vector2f(-movementSpeed, 0.f))
	{
		snake[0]->setNewDirection(Vector2f(-movementSpeed, 0.f));
	}
	else if (Keyboard::isKeyPressed(Keyboard::D) && snake[0]->getDirection() != Vector2f(-movementSpeed, 0.f) && snake[0]->getDirection() != Vector2f(movementSpeed, 0.f))
	{
		snake[0]->setNewDirection(Vector2f(movementSpeed, 0.f));
	}
	else if (Keyboard::isKeyPressed(Keyboard::W) && snake[0]->getDirection() != Vector2f(0.f, movementSpeed) && snake[0]->getDirection() != Vector2f(0.f, -movementSpeed))
	{

		snake[0]->setNewDirection(Vector2f(0.f, -movementSpeed));
	}
	else if (Keyboard::isKeyPressed(Keyboard::S) && snake[0]->getDirection() != Vector2f(0.f, -movementSpeed) && snake[0]->getDirection() != Vector2f(0.f, movementSpeed))
	{
		snake[0]->setNewDirection(Vector2f(0.f, movementSpeed));
	}
}

void EngineSnake::updateSnake() 
{
	snake[0]->savePosition();
	snake[0]->update();
	for (int i = 1; i < snake.size(); i++) {
		snake[i]->savePosition();
		snake[i]->setPos(snake[i - 1]->getOldPos());
	}
}

void EngineSnake::updateCollision()
{
	if (snake[0]->getGlobalBounds().intersects(fruit->getGlobalBounds()))
	{
		fruit->setPos(zufallRaster());
		spawnSnakeBody();
	}
	if (firstWaitOne)
	{
		for (int i = 1; i < snake.size(); i++)
		{
			if (snake[0]->getGlobalBounds().intersects(snake[i]->getGlobalBounds()))
			{
				endGame = true;
			}
		}
	}
	firstWaitOne = true;
	if (collisionWorldBorders())
	{
		endGame = true;
	}
}

void EngineSnake::updateGUI()
{
	std::stringstream ss;
	ss << "COUNT: " << snake.size() - 1;
	texts["Game"]->setString(ss.str());
}

void EngineSnake::renderGUI(RenderTarget *target)
{
	target->draw(*texts["Game"]);
	if (endGame)
	{
		target->draw(*texts["EndGame"]);
	}
}

bool EngineSnake::collisionWorldBorders()
{
	if (snake[0]->getPos().x < 0.f)
	{
		for (auto* i : snake)
		{
			i->bounceBack(1);
		}
		return true;
	}

	//right side
	if (snake[0]->getPos().x + snake[0]->getGlobalBounds().width > window->getSize().x)
	{
		for (auto* i : snake)
		{
			i->bounceBack(2);
		}
		return true;
	}

	//top
	if (snake[0]->getPos().y < 0.f)
	{
		for (auto* i : snake)
		{
			i->bounceBack(3);
		}
		return true;
	}

	//bottom
	if (snake[0]->getPos().y + snake[0]->getGlobalBounds().height > window->getSize().y)
	{
		for (auto* i : snake)
		{
			i->bounceBack(4);
		}
		return true;
	}
	return false;
}

void EngineSnake::spawnSnakeBody()
{
	snake.push_back(new Snaaaake(snake[snake.size() - 1]->getPos(), Color(69, 69, 69, 255)));
	if (snake.size() > 2)
	{
		snake[snake.size() - 2]->setColor(Color(10, 87, 0, 255));
	}
	if (snake.size() == 2)
	{
		firstWaitOne = false;
	}
}

//------------------------------------------------------------------------------------------------

Vector2f EngineSnake::zufallRaster()
{
	float posX;
	float posY;

	posX = static_cast<float>(rand() % 24) * 30;
	posY = static_cast<float>(rand() % 24) * 30;

	return Vector2f(posX, posY);
}

void EngineSnake::initVariables()
{
	window = nullptr;
	snake.push_back(new Snaaaake(Vector2f(30.f, 30.f), Color(194, 158, 0, 255)));
	fruit = new Fruiiiit();
	movementSpeed = 30.f;
	firstWaitOne = true;
}

void EngineSnake::initWindow()
{
	videomode.height = 720;
	videomode.width = 720;
	window = new RenderWindow(videomode, "Snake in gut", Style::Titlebar | Style::Close);
	window->setFramerateLimit(20);
	window->setVerticalSyncEnabled(false);
}

void EngineSnake::initGUI()
{
	fonts["Game"] = new Font();
	fonts["EndGame"] = new Font();

	if (!fonts["Game"]->loadFromFile("Fonts/Inconsolata-Black.ttf"))
	{
		std::cout << "FUCKING ERROR LOADING FUCKING GAME FONT";
	}
	if (!fonts["EndGame"]->loadFromFile("Fonts/1942.ttf"))
	{
		std::cout << "FUCKING ERROR LOADING FUCKING ENDGAME FONT";
	}

	texts["Game"] = new Text();
	texts["EndGame"] = new Text();

	texts["Game"]->setFont(*fonts["Game"]);
	texts["EndGame"]->setFont(*fonts["EndGame"]);

	texts["Game"]->setString("COUNT: X");
	texts["EndGame"]->setString("Game over");

	texts["Game"]->setCharacterSize(30);
	texts["EndGame"]->setCharacterSize(120);

	texts["Game"]->setPosition(Vector2f(window->getSize().x/2 - texts["Game"]->getGlobalBounds().width /2, 40.f));
	texts["EndGame"]->setPosition(Vector2f(window->getSize().x/2 - texts["EndGame"]->getGlobalBounds().width/2, window->getSize().y / 2 - 120));

	texts["Game"]->setFillColor(Color(69, 69, 69, 255));
	texts["EndGame"]->setFillColor(Color(158, 0, 0, 255));

}

void EngineSnake::pollEvents()
{
	while (window->pollEvent(closeEvent))
	{
		switch (closeEvent.type)
		{
		case Event::Closed:
			window->close();
			break;
		case Event::KeyPressed:
			if (closeEvent.key.code == Keyboard::Escape) window->close();
			break;
		}
	}
}
