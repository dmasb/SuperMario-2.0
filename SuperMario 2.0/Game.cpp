#include "Game.h"
#include <iostream>

Game::Game()
{
}


Game::~Game()
{

}

void Game::runGame(RenderWindow *window, Clock *clock)
{
	
	float totaltime = 0.0f;
	while (window->isOpen())
	{
		float elapsedTime = clock->restart().asSeconds();
		
		totaltime += elapsedTime;
		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
		
		update(totaltime);
		window->clear();
		draw(window);
		window->display();
	}
}

void Game::update(float &totaltime)
{
	this->collision.setBackgroundPos(this->collision.getMarioSprite().getPosition().x - 250, 0);
	this->collision.updateCharacter();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->collision.MarioMoveRight();
		this->collision.moveViewRight();
		this->collision.animateMario(totaltime, 1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->collision.MarioMoveLeft();
		this->collision.moveViewLeft();
		this->collision.animateMario(totaltime, -1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		this->collision.jump();
	}
	
}

void Game::draw(RenderWindow * window)
{
	window->draw(collision.getMap());
	window->draw(collision.getMarioSprite());
}