#include "Game.h"
//start window
void Game::initwindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1080, 720), "Game", sf::Style::Close |sf::Style::Resize| sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
}

//get new player
void Game::initplayer()
{
	this->player = new Player();
}

void Game::initenemy()
{
	//this->enemy = new Enemy();
	this->spawnTimerMax = 100.f;
	this->spawnTimer = this->spawnTimerMax;
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

void Game::initGUI()
{
	this->font.loadFromFile("Font/sd cartoon 2.ttf");
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(36);
	this->pointText.setFillColor(sf::Color::White);
	this->pointText.setString("Score : ");
}

//Main starter functions
Game::Game()
{
	this->initwindow();
	this->initBackground();
	this->directioncheck = 0;
	this->initBulletTextures();
	this->initGUI();
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
	for (auto* i : this->enemies) {
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
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->enemies.push_back(new Enemy(rand() %this->window->getSize().x, -100.f));
		this->spawnTimer = 0.f;
	}
	for (int i = 0; i < this->enemies.size();++i) {
		bool enemy_removed = false;
		this->enemies[i]->updated(this->player->getPos().x - 8, this->player->getPos().y - 5);

		for (size_t k = 0; k < this->bullets.size()&&!enemy_removed; k++) {
			if (this->bullets[k]->getBounds().intersects(this->enemies[i]->getBounds())) {
				this->bullets.erase(this->bullets.begin() + k);
				this->enemies.erase(this->enemies.begin() + i);
				enemy_removed = true;
			}
		}
	}
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
	this->updateInput();
	this->updateBullets();
	this->updateenemy();
	this->updateGUI();
}

void Game::updateGUI()
{
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

void Game::renderGUI()
{
	this->window->draw(this->pointText);
}

//render window
void Game::render()
{
	this->window->clear(); //for clear old frame
	this->renderBackground(); //for made background
	this->renderPlayer(); //for made player
	for (auto* bullet : this->bullets) {
		bullet->render(this->window);
	}
	for (auto* enemy : this->enemies) {
		enemy->render(*this->window);
	}
	this->renderGUI();
	this->window->display(); //for update new frame
}
