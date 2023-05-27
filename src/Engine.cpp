#include "Engine.h"
#include <iostream>


Engine::Engine()
{
	initVariables();
	initWindow();
}

Engine::~Engine()
{
	delete window;
	delete player;
	for (auto* i : schlangenKoerper)
	{
		delete i;
	}
}

void Engine::play()
{
	while (window->isOpen())
	{
		//sleep(Time(seconds(0.05)));
		update();
		render();
	}
}


//Private Functions

void Engine::update()
{
	pollEvents();
	player->update(window);
	updateCollision();
	updateSnake();
	//std::cout << player->isChanged() <<"\n";
	//std::cout << "X Richtung: " << player->getDirection().x << "\n";
	//std::cout << "Y Richtung: " << player->getDirection().y <<"\n";
}

void Engine::render()
{
	window->clear(Color(255, 248, 214,255));
	player->render(window);
	fruit->render(window);
	for (auto *i : schlangenKoerper)
	{
		i->render(window);
	}
	window->display();
}

void Engine::updateCollision()
{
	if (player->getGlobalBounds().intersects(fruit->getGlobalBounds()))
	{
		fruit->setPos(zufallRaster());
		spawnSnakeBody();
	}
}

void Engine::updateSnake()
{
	player->move(window);
	if (!schlangenKoerper.empty())
	{
		if (player->isChanged())
		{
			if (einMalMoveSnake)
			{
				schlangenKoerper[0]->moveDirection();
				einMalMoveSnake = false;
			}
			if (schlangenKoerper[0]->weitGenug())
			{
				std::cout << "Richtungswechsel: 0" << "\n";
				schlangenKoerper[0]->setNewDirection(player->getDirection());
				player->setChanged(false);
				schlangenKoerper[0]->setChanged(true);
				einMalMoveSnake = true;
				schlangenKoerper[0]->moveOpposite();
			}
		}
		schlangenKoerper[0]->moveDirection();
		
		for (int i = 1; i < schlangenKoerper.size(); i++)
		{
			schlangenKoerper[i]->moveDirection();
			if (schlangenKoerper[i - 1]->isChanged())
			{
				if (einMalMove)
				{
					for (int k = 1; k <= i; k++)
					{
						schlangenKoerper[i]->moveDirection();
					}
					einMalMove = false;
					//	std::cout << "einMalMoved\n";
				}

				if (schlangenKoerper[i]->weitGenug())
				{
					std::cout << "Richtungswechsel: " << i << "\n";

					schlangenKoerper[i]->setNewDirection(schlangenKoerper[i - 1]->getDirection());
					schlangenKoerper[i - 1]->setChanged(false);
					schlangenKoerper[i]->setChanged(true);
					einMalMove = true;
					for (int k = 1; k <= i; k++)
					{
						schlangenKoerper[i]->moveOpposite();
					}
				}
			}
		
		}
		//if (schlangenKoerper.size() > 2)
		//{
		//	std::cout << "\n-------------------------------------------------------------\nPlayer:\n" << player->getPos().x << "\n";
		//	std::cout << player->getPos().y << "\n\n";
		//
		//	std::cout << "Schlange  0:\n" << schlangenKoerper[0]->getPos().x << "\n";
		//	std::cout << schlangenKoerper[0]->getPos().y << "\n\n\n";
		//
		//	std::cout << "Schlange  1:\n" << schlangenKoerper[1]->getPos().x << "\n";
		//	std::cout << schlangenKoerper[1]->getPos().y << "\n\n\n";
		//
		//	std::cout << "Schlange  2:\n" << schlangenKoerper[2]->getPos().x << "\n";
		//	std::cout << schlangenKoerper[2]->getPos().y << "\n\n\n";
		//}
	}
}


void Engine::initVariables()
{
	window = nullptr;
	player = new Snake();
	fruit = new Fruit();
	counter = 0;
	einMalMove = true;
	einMalMoveSnake = true;
}

void Engine::initWindow()
{
	videomode.height = 720;
	videomode.width = 720;
	window = new RenderWindow(videomode, "Snake in gut", Style::Titlebar | Style::Close);
	window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(false);
}

void Engine::pollEvents()
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

Vector2f Engine::zufallRaster()
{
	float posX;
	float posY;

	posX = static_cast<float>(rand() % 24) * 30;
	posY = static_cast<float>(rand() % 24) * 30;
	
	return Vector2f(posX, posY);
}

void Engine::spawnSnakeBody()
{
	if (schlangenKoerper.empty())
	{
		player->setChanged(false);
		//std::cout << player->isChanged();
		//nach links gehend (1)
		if (
			player->getDirection().x < 0
			&& player->getDirection().y == 0)
		{
			schlangenKoerper.push_back(new SnakeBody(Vector2f(player->getPos().x + 30.f, player->getPos().y)));
		}

		//nach rechts gehend(2)
		else if (
			player->getDirection().x > 0
			&& player->getDirection().y == 0)
		{
			schlangenKoerper.push_back(new SnakeBody(Vector2f(player->getPos().x - 30.f, player->getPos().y)));
		}

		//nach oben gehend (3)
		else if (
			player->getDirection().x == 0
			&& player->getDirection().y < 0)
		{
			schlangenKoerper.push_back(new SnakeBody(Vector2f(player->getPos().x, player->getPos().y + 30.f)));
		}

		//nach unten gehend (4)
		else if (
			player->getDirection().x == 0
			&& player->getDirection().y > 0)
		{
			schlangenKoerper.push_back(new SnakeBody(Vector2f(player->getPos().x, player->getPos().y - 30.f)));
		}
		schlangenKoerper[0]->setNewDirection(player->getDirection());
	}



	else
	{
		schlangenKoerper[schlangenKoerper.size() - 1]->setChanged(false);
		//nach links gehend (1)
		if (
			schlangenKoerper[schlangenKoerper.size() - 1]->getDirection().x < 0
			&& schlangenKoerper[schlangenKoerper.size() - 1]->getDirection().y == 0)
		{
			schlangenKoerper.push_back(new SnakeBody(Vector2f(schlangenKoerper[schlangenKoerper.size() - 1]->getPos().x + 30.f, schlangenKoerper[schlangenKoerper.size() - 1]->getPos().y)));
		}

		//nach rechts gehend(2)
		else if (
			schlangenKoerper[schlangenKoerper.size() - 1]->getDirection().x > 0
			&& schlangenKoerper[schlangenKoerper.size() - 1]->getDirection().y == 0)
		{
			schlangenKoerper.push_back(new SnakeBody(Vector2f(schlangenKoerper[schlangenKoerper.size() - 1]->getPos().x - 30.f, schlangenKoerper[schlangenKoerper.size() - 1]->getPos().y)));
		}

		//nach oben gehend (3)
		else if (
			schlangenKoerper[schlangenKoerper.size() - 1]->getDirection().x == 0
			&& schlangenKoerper[schlangenKoerper.size() - 1]->getDirection().y < 0)
		{
			schlangenKoerper.push_back(new SnakeBody(Vector2f(schlangenKoerper[schlangenKoerper.size() - 1]->getPos().x, schlangenKoerper[schlangenKoerper.size() - 1]->getPos().y +30.f)));
		}

		//nach unten gehend (4)
		else if (
			schlangenKoerper[schlangenKoerper.size() - 1]->getDirection().x == 0
			&& schlangenKoerper[schlangenKoerper.size() - 1]->getDirection().y > 0)
		{
			schlangenKoerper.push_back(new SnakeBody(Vector2f(schlangenKoerper[schlangenKoerper.size() - 1]->getPos().x, schlangenKoerper[schlangenKoerper.size() - 1]->getPos().y -30.f)));
		}
		schlangenKoerper[schlangenKoerper.size() - 1]->setNewDirection(schlangenKoerper[schlangenKoerper.size() - 2]->getDirection());
		
	}
}

bool Engine::einGewartet()
{
	if (counter == 1)
	{
		counter = 0;
		return true;
	}
	counter++;
	return false;
}

//void Engine::spawnSnakeBody()
//{
//	if (schlangenKoerper.empty())
//	{
//		schlangenKoerper.push_back(new SnakeBody(player->getPos()));
//	}
//	else
//	{
//		switch (schlangenKoerper[schlangenKoerper.size() - 1]->getOrientation())
//		{
//		case 1:
//			schlangenKoerper.push_back(new SnakeBody(Vector2f(schlangenKoerper[schlangenKoerper.size() - 1]->getPos().x + 30.f, schlangenKoerper[schlangenKoerper.size() - 1]->getPos().y)));
//			break;
//		case 2:
//			schlangenKoerper.push_back(new SnakeBody(Vector2f(schlangenKoerper[schlangenKoerper.size() - 1]->getPos().x - 30.f, schlangenKoerper[schlangenKoerper.size() - 1]->getPos().y)));
//			break;
//		case 3:
//			schlangenKoerper.push_back(new SnakeBody(Vector2f(schlangenKoerper[schlangenKoerper.size() - 1]->getPos().x, schlangenKoerper[schlangenKoerper.size() - 1]->getPos().y + 30.f)));
//			break;
//		case 4:
//			schlangenKoerper.push_back(new SnakeBody(Vector2f(schlangenKoerper[schlangenKoerper.size() - 1]->getPos().x , schlangenKoerper[schlangenKoerper.size() - 1]->getPos().y - 30.f)));
//			break;
//		default:
//			break;
//		}
//	}
//}

bool Engine::isPlayerMoved30()
{
	if (counter >= 30)
	{
		counter = 0;
		return true;
	}
	counter += 6;
	//std::cout << counter << "\n";
	return false;
}



//switch (player->getChangeDirection())
//{
//case 1:
//	schlangenKoerper[0]->follow(Vector2f(player->getPos().x + 30.f, player->getPos().y), 1);
//	break;
//case 2:
//	schlangenKoerper[0]->follow(Vector2f(player->getPos().x - 30.f, player->getPos().y), 2);
//	break;
//case 3:
//	schlangenKoerper[0]->follow(Vector2f(player->getPos().x, player->getPos().y + 30.f), 3);
//	break;
//case 4:
//	schlangenKoerper[0]->follow(Vector2f(player->getPos().x, player->getPos().y - 30.f), 4);
//	break;
//}