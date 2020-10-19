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

void Game::initenemy()
{
	this->enemy = new Enemy();
}

//start BG
void Game::initBackground()
{
	this->bg = new Background();
}

//start bullet
void Game::initBulletTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("Sprite/bullet.png");
}

//Main starter functions
Game::Game()
{
	this->initwindow();
	this->initBackground();
	this->directioncheck = 0;
	this->initBulletTextures();
	this->initplayer();
	this->initenemy();
}

//delete main function anythings 
Game::~Game()
{
	delete this->window;
	delete this->bg;
	delete this->player;
	for (auto &i : this->textures) {
		delete i.second;
	}
	for (auto *i : this->bullets) {
		delete i;
	}
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

void Game::updateenemy()
{
	this->enemy->updated(this->player->getPos().x-8, this->player->getPos().y-5);
}

//update input
void Game::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		this->directioncheck = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		this->directioncheck = 2;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		this->directioncheck = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		this->directioncheck = 3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&this->player->canAttack_top()&&this->directioncheck==1) {
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x+25, this->player->getPos().y, 0.f, -1.f, 5.f));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&this->player->canAttack_left() && this->directioncheck==2) {
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x, this->player->getPos().y+28, -1.f, 0.f, 5.f));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack_right() && this->directioncheck == 3) {
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x+68, this->player->getPos().y + 28, 1.f, 0.f, 5.f));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack_down() && this->directioncheck == 0) {
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 25, this->player->getPos().y + 95, 0.f, 1.f, 5.f));
	}
}

//update bullets
void Game::updateBullets()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets) {
		bullet->update();
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f) {
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin()+counter);
			--counter;
		}
		else if (bullet->getBounds().left + bullet->getBounds().width < 0.f) {
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		else if (bullet->getBounds().left + bullet->getBounds().width > 1080.f) {
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		else if (bullet->getBounds().top + bullet->getBounds().height > 720.f) {
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		++counter;
	}
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
	this->updateenemy();
	this->updateInput();
	this->updateBullets();
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

void Game::renderenemy()
{
	this->enemy->render(*this->window);
}

//render window
void Game::render()
{
	this->window->clear(); //for clear old frame
	this->renderBackground(); //for made background
	this->renderPlayer(); //for made player
	this->renderenemy();
	for (auto* bullet : this->bullets) {
		bullet->render(this->window);
	}
	this->window->display(); //for update new frame
}
