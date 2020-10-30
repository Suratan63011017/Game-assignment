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
	this->spawnTimerMax = 200.f;
	this->spawnTimer = this->spawnTimerMax;
}

void Game::initskill()
{
	this->skillTimerMax = 1000.f;
	this->skillTimer = this->skillTimerMax;
	this->skillpics["SKILL"] = new sf::Texture();
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

//GUI
void Game::initGUI()
{
	this->font.loadFromFile("Font/sd cartoon 2.ttf");
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(36);
	this->pointText.setFillColor(sf::Color::White);
	this->pointText.setString("Score : ");
	this->pointText.setPosition(sf::Vector2f(900.f,10.f));

	this->playerHpBar.setSize(sf::Vector2f(300.f, 25.f));
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setPosition(sf::Vector2f(20.f, 20.f));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));
}

//System settings
void Game::initSystems()
{
	this->points = 0;
}

//Main starter functions
Game::Game()
{
	this->initwindow();
	this->initBackground();
	this->directioncheck = 0;
	this->initBulletTextures();
	this->initGUI();
	this->initSystems();
	this->initplayer();
	this->initenemy();
	this->initskill();
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
	for (auto* i : this->skills) {
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

//enemy updated
void Game::updateenemy()
{
	//spawn
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->enemies.push_back(new Enemy(rand() %this->window->getSize().x, -100.f));
		this->spawnTimer = 0.f;
	}
	//updated
	for (int i = 0; i < this->enemies.size();++i) {
		bool enemy_removed = false;
		this->enemies[i]->updated(this->player->getPos().x - 8, this->player->getPos().y - 5);
		for (size_t k = 0; k < this->bullets.size()&&!enemy_removed; k++) {
			if (this->bullets[k]->getBounds().intersects(this->enemies[i]->getBounds())) {
				this->enemies[i]->loseHp(5);
				this->bullets.erase(this->bullets.begin() + k);
				if (this->enemies[i]->getHp() == 0) {
					this->points += 5;
					this->enemies.erase(this->enemies.begin() + i);
					enemy_removed = true;
				}
			}
		}
	}
}

void Game::updateskill()
{
	//spawn
	this->skillTimer += 0.5f;
	if (this->skillTimer >= this->skillTimerMax)
	{
		this->type = 1+(rand()%2);
		if (this->type == 1) {
			this->skillpics["SKILL"]->loadFromFile("Sprite/doub skill.png");
		}
		else if (this->type == 2) {
			this->skillpics["SKILL"]->loadFromFile("Sprite/fire skill.png");
		}
		this->skilltimecheck.restart();
		this->skills.push_back(new Skill(this->skillpics["SKILL"],rand() % this->window->getSize().x, rand() % this->window->getSize().y));
		this->skillTimer = 0.f;
	}
	//update
	for (int i = 0; i < this->skills.size(); ++i) {
		bool skills_removed = false;
		if (this->skills[i]->getBounds().intersects(this->player->getBounds())&&this->type==1) {
			this->skills.erase(this->skills.begin() + i);
			this->skilltime.restart();
			skills_removed = true;
			if (this->skilltime.getElapsedTime().asSeconds() <= 15.f) {
				this->player->doubattack(1);
				this->textures["BULLET"]->loadFromFile("Sprite/doub ball.png");
			}
		}
		if (this->skilltimecheck.getElapsedTime().asSeconds() > 5.f) {
			this->skills.erase(this->skills.begin() + i);
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
	this->updateskill();
	this->updateCollision();
	this->updateGUI();
}

//update GUI
void Game::updateGUI()
{
	//scores
	std::stringstream ss;
	ss <<"Scores : "<< this->points;
	this->pointText.setString(ss.str());

	//hp of player
	float hpPercent = static_cast<float>(this->player->getHp())/this->player->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(300.f*hpPercent, this->playerHpBar.getSize().y));
}

//updated collision
void Game::updateCollision()
{
	int count = 0;
	for (int i = 0; i < this->enemies.size(); ++i) {
		if (this->player->getBounds().intersects(this->enemies[i]->getBounds())) {
			count++;
		}
	}
	if (this->skilltime.getElapsedTime().asSeconds() > 15.f) {
		this->player->doubattack(0);
		this->textures["BULLET"]->loadFromFile("Sprite/bullet.png");
	}
	if (this->clock.getElapsedTime().asSeconds() >= 1.f) {
		this->player->loseHp(5 * count);
		this->clock.restart();
	}
	count = 0;
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
	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);
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
	for (auto* Skill : this->skills) {
		Skill->render(this->window);
	}
	this->renderGUI();
	this->window->display(); //for update new frame
}
