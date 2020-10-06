#include "Game.h"
//start window
void Game::initwindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1080, 720), "Game", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
}

//get new player
void Game::initplayer()
{
	this->player = new Player();
}

//start BG
void Game::initBackground()
{
	this->bg = new Background();
}

//Main starter functions
Game::Game()
{
	this->initwindow();
	this->initBackground();
	this->initplayer();
}

//delete main function anythings 
Game::~Game()
{
	delete this->window;
	delete this->bg;
	delete this->player;
}

//run your game
void Game::run()
{
	while (this->window->isOpen()) 
	{
		this->update();
		this->render();
	}
}

//player updated
void Game::updatePlayer()
{
	this->player->updated();
}

//window updated  
void Game::update()
{
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
			this->window->close();
	}
	this->updatePlayer(); //for update player in window 
}

//render BG
void Game::renderBackground()
{
	this->bg->render(*this->window);
}

//render player
void Game::renderPlayer()
{
	this->player->render(*this->window);
}

//render window
void Game::render()
{
	this->window->clear(); //for clear old frame
	this->renderBackground(); //for made background
	this->renderPlayer(); //for made player
	this->window->display(); //for update new frame
}
