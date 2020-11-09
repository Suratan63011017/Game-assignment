#include "Game.h"
//start window
void Game::initwindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Game", sf::Style::Close | sf::Style::Resize | sf::Style::Titlebar);
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
	this->spawnTimerMax = 1000.f;
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

void Game::initfireball()
{
	this->fireballs["FIREBALL"] = new sf::Texture();
}

void Game::initice()
{
	this->icepillar["ICE"] = new sf::Texture();
	this->icepillar["ICE"]->loadFromFile("Sprite/ice.png");
}

//GUI
void Game::initGUI()
{
	this->font.loadFromFile("Font/sd cartoon 2.ttf");
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(36);
	this->pointText.setFillColor(sf::Color::White);
	this->pointText.setString("Score : ");
	this->pointText.setPosition(sf::Vector2f(1100.f, 10.f));

	this->shadowpointtext.setFont(this->font);
	this->shadowpointtext.setCharacterSize(36);
	this->shadowpointtext.setFillColor(sf::Color::Black);
	this->shadowpointtext.setString("Score : ");
	this->shadowpointtext.setPosition(sf::Vector2f(1105.f, 15.f));

	this->bit8.loadFromFile("Font/2005_iannnnnAMD.ttf");
	this->FIRETEXT.setFont(this->bit8);
	this->FIRETEXT.setCharacterSize(40);
	this->FIRETEXT.setFillColor(sf::Color::White);
	this->FIRETEXT.setString("0");
	this->FIRETEXT.setPosition(sf::Vector2f(1130.f, 570.f));

	this->ICETEXT.setFont(this->bit8);
	this->ICETEXT.setCharacterSize(40);
	this->ICETEXT.setFillColor(sf::Color::White);
	this->ICETEXT.setString("0");
	this->ICETEXT.setPosition(sf::Vector2f(1200.f, 570.f));

	this->playerHpBar.setSize(sf::Vector2f(300.f, 25.f));
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setPosition(sf::Vector2f(20.f, 20.f));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));

	this->firepics.loadFromFile("Sprite/Firepics.png");
	this->firepicx.setTexture(this->firepics);
	this->firepicx.setPosition(sf::Vector2f(1110.f, 620.f));

	this->icepics.loadFromFile("Sprite/icepics.png");
	this->icepicx.setTexture(this->icepics);
	this->icepicx.setPosition(sf::Vector2f(1180.f, 620.f));
}

//System settings
void Game::initSystems()
{
	this->points = 0;
	//box1
	this->tbox1.loadFromFile("Sprite/Box.png");
	this->sbox1.setTexture(this->tbox1);
	this->sbox1.setPosition(490.f, 150.f);
	//box2
	this->tbox2.loadFromFile("Sprite/Box2.png");
	this->sbox2.setTexture(this->tbox2);
	this->sbox2.setPosition(100.f, 250.f);
	//box3
	this->tbox3.loadFromFile("Sprite/Box2.png");
	this->sbox3.setTexture(this->tbox3);
	this->sbox3.setPosition(1130.f, 250.f);
	//box4
	this->tbox4.loadFromFile("Sprite/Box.png");
	this->sbox4.setTexture(this->tbox4);
	this->sbox4.setPosition(490.f, 520.f);
}

//Main starter functions
Game::Game()
{
	this->initwindow();
	this->initBackground();
	this->directioncheck = 0;
	this->initBulletTextures();
	this->initfireball();
	this->initice();
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
	for (auto& i : this->textures) {
		delete i.second;
	}
	for (auto* i : this->bullets) {
		delete i;
	}
	for (auto* i : this->enemies) {
		delete i;
	}
	for (auto* i : this->skills) {
		delete i;
	}
	for (auto* i : this->fire) {
		delete i;
	}
	for (auto* i : this->shield) {
		delete i;
	}
	for (auto* i : this->ices) {
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
	if (this->player->getBounds().intersects(this->sbox1.getGlobalBounds())) {
		this->player->updateCollision(this->directioncheck);
	}
	else if (this->player->getBounds().intersects(this->sbox2.getGlobalBounds())) {
		this->player->updateCollision(this->directioncheck);
	}
	else if (this->player->getBounds().intersects(this->sbox3.getGlobalBounds())) {
		this->player->updateCollision(this->directioncheck);
	}
	else if (this->player->getBounds().intersects(this->sbox4.getGlobalBounds())) {
		this->player->updateCollision(this->directioncheck);
	}
	else this->player->updated();
}

//enemy updated
void Game::updateenemy()
{
	//spawn
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->enemies.push_back(new Enemy(rand() % this->window->getSize().x, -100.f));
		this->spawnTimer = 0.f;
	}
	//updated
	for (int i = 0; i < this->enemies.size(); ++i) {
		bool enemy_removed = false;
		if (this->checkice == 0) {
			if (this->enemies[i]->getBounds().intersects(this->sbox1.getGlobalBounds())) {
				this->enemies[i]->updateCollision();
			}
			else if (this->enemies[i]->getBounds().intersects(this->sbox2.getGlobalBounds())) {
				this->enemies[i]->updateCollision();
			}
			else if (this->enemies[i]->getBounds().intersects(this->sbox3.getGlobalBounds())) {
				this->enemies[i]->updateCollision();
			}
			else if (this->enemies[i]->getBounds().intersects(this->sbox4.getGlobalBounds())) {
				this->enemies[i]->updateCollision();
			}
			else this->enemies[i]->updated(this->player->getPos().x - 8, this->player->getPos().y - 5, 1);

		}
		else if (this->checkice == 1) {
			this->enemies[i]->updated(this->player->getPos().x - 8, this->player->getPos().y - 5, 0);
			this->ices.push_back(new ice(this->icepillar["ICE"], this->enemies[i]->getPos().x + 10, this->enemies[i]->getPos().y + 20));
		}
		for (size_t k = 0; k < this->bullets.size() && !enemy_removed; k++) {
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
		for (size_t k = 0; k < this->fire.size() && !enemy_removed; k++) {
			if (this->fire[k]->getBounds().intersects(this->enemies[i]->getBounds())) {
				this->enemies[i]->loseHp(1);
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
		this->type = 1 + (rand() % 5);
		if (this->type == 1) {
			this->skillpics["SKILL"]->loadFromFile("Sprite/doub skill.png");
		}
		else if (this->type == 2) {
			this->skillpics["SKILL"]->loadFromFile("Sprite/fire skill.png");
		}
		else if (this->type == 3) {
			this->skillpics["SKILL"]->loadFromFile("Sprite/triple skill.png");
		}
		else if (this->type == 4) {
			this->skillpics["SKILL"]->loadFromFile("Sprite/shield skill.png");
		}
		else if (this->type == 5) {
			this->skillpics["SKILL"]->loadFromFile("Sprite/ice skill.png");
		}
		this->skilltimecheck.restart();
		this->skills.push_back(new Skill(this->skillpics["SKILL"], rand() % this->window->getSize().x - 40, rand() % this->window->getSize().y - 40));
		this->skillTimer = 0.f;
	}
	//update
	for (int i = 0; i < this->skills.size(); ++i) {
		if (this->skills[i]->getBounds().intersects(this->sbox1.getGlobalBounds())) {
			this->skills.erase(this->skills.begin() + i);
			this->skillTimer += 1000.f;
		}
		else if (this->skills[i]->getBounds().intersects(this->sbox2.getGlobalBounds())) {
			this->skills.erase(this->skills.begin() + i);
			this->skillTimer += 1000.f;
		}
		else if (this->skills[i]->getBounds().intersects(this->sbox3.getGlobalBounds())) {
			this->skills.erase(this->skills.begin() + i);
			this->skillTimer += 1000.f;
		}
		else if (this->skills[i]->getBounds().intersects(this->sbox4.getGlobalBounds())) {
			this->skills.erase(this->skills.begin() + i);
			this->skillTimer += 1000.f;
		}
		//1 skill
		else if (this->skills[i]->getBounds().intersects(this->player->getBounds()) && this->type == 1) {
			this->skills.erase(this->skills.begin() + i);
			this->skilltime.restart();
			if (this->skilltime.getElapsedTime().asSeconds() <= 15.f) {
				this->player->doubattack(1);
				this->textures["BULLET"]->loadFromFile("Sprite/doub ball.png");
			}
		}
		//2 skill
		else if (this->skills[i]->getBounds().intersects(this->player->getBounds()) && this->type == 2) {
			(this->canfireball)++;
			this->skills.erase(this->skills.begin() + i);
		}
		//3 skill
		else if (this->skills[i]->getBounds().intersects(this->player->getBounds()) && this->type == 3) {
			this->skills.erase(this->skills.begin() + i);
			this->triptime.restart();
			this->checktriple = 1;
		}
		//4 skill
		else if (this->skills[i]->getBounds().intersects(this->player->getBounds()) && this->type == 4) {
			this->skills.erase(this->skills.begin() + i);
			this->shieldtime.restart();
			this->checkshield = 1;
		}
		//5 skill
		else if (this->skills[i]->getBounds().intersects(this->player->getBounds()) && this->type == 5) {
			(this->canicepillar)++;
			this->skills.erase(this->skills.begin() + i);
		}
		//remove skilled 
		if (this->skilltimecheck.getElapsedTime().asSeconds() > 5.f) {
			this->skills.erase(this->skills.begin() + i);
		}
	}
}
void Game::updateshield()
{
	if (this->checkshield == 1)
	{
		this->shield.push_back(new Shield(this->player->getPos().x - 16, this->player->getPos().y - 5));
		checkshield = 0;
	}
	for (int i = 0; i < this->shield.size(); ++i) {
		this->shield[i]->update(this->player->getPos().x - 16, this->player->getPos().y - 5);
		if (this->shieldtime.getElapsedTime().asSeconds() > 5.f) {
			this->shield.erase(this->shield.begin() + i);
			this->keepshield = 0;
		}
		else {
			this->keepshield = 1;
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
	//triple balls
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack_top_trip() && this->directioncheck == 1 && this->checktriple == 1 && this->triptime.getElapsedTime().asSeconds() <= 15.f) {
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 25, this->player->getPos().y, 1.f, -1.f, 5.f));
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 25, this->player->getPos().y, -1.f, -1.f, 5.f));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack_left_trip() && this->directioncheck == 2 && this->checktriple == 1 && this->triptime.getElapsedTime().asSeconds() <= 15.f) {
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x, this->player->getPos().y + 28, -1.f, 1.f, 5.f));
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x, this->player->getPos().y + 28, -1.f, -1.f, 5.f));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack_right_trip() && this->directioncheck == 3 && this->checktriple == 1 && this->triptime.getElapsedTime().asSeconds() <= 15.f) {
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 68, this->player->getPos().y + 28, 1.f, 1.f, 5.f));
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 68, this->player->getPos().y + 28, 1.f, -1.f, 5.f));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack_down_trip() && this->directioncheck == 0 && this->checktriple == 1 && this->triptime.getElapsedTime().asSeconds() <= 15.f) {
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 25, this->player->getPos().y + 95, 1.f, 1.f, 5.f));
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 25, this->player->getPos().y + 95, -1.f, 1.f, 5.f));
	}
	//normal shooting
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack_top() && this->directioncheck == 1) {
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 25, this->player->getPos().y, 0.f, -1.f, 5.f));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack_left() && this->directioncheck == 2) {
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x, this->player->getPos().y + 28, -1.f, 0.f, 5.f));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack_right() && this->directioncheck == 3) {
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 68, this->player->getPos().y + 28, 1.f, 0.f, 5.f));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack_down() && this->directioncheck == 0) {
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 25, this->player->getPos().y + 95, 0.f, 1.f, 5.f));
	}
	//fire ball
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && this->directioncheck == 1 && this->canfireball > 0 && this->firetime.getElapsedTime().asSeconds() >= 1.f) {
		this->fireballs["FIREBALL"]->loadFromFile("Sprite/fireball.png");
		this->fire.push_back(new fireball(this->fireballs["FIREBALL"], this->player->getPos().x, this->player->getPos().y, 0.f, -1.f, 5.f, 1, -1));
		(this->canfireball)--;
		this->firetime.restart();
		this->bg->update(2);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && this->directioncheck == 0 && this->canfireball > 0 && this->firetime.getElapsedTime().asSeconds() >= 1.f) {
		this->fireballs["FIREBALL"]->loadFromFile("Sprite/fireball.png");
		this->fire.push_back(new fireball(this->fireballs["FIREBALL"], this->player->getPos().x, this->player->getPos().y, 0.f, 1.f, 5.f, 1, 1));
		(this->canfireball)--;
		this->firetime.restart();
		this->bg->update(2);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && this->directioncheck == 3 && this->canfireball > 0 && this->firetime.getElapsedTime().asSeconds() >= 1.f) {
		this->fireballs["FIREBALL"]->loadFromFile("Sprite/fireblass.png");
		this->fire.push_back(new fireball(this->fireballs["FIREBALL"], this->player->getPos().x, this->player->getPos().y, 1.f, 0.f, 5.f, 1, 1));
		(this->canfireball)--;
		this->firetime.restart();
		this->bg->update(2);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && this->directioncheck == 2 && this->canfireball > 0 && this->firetime.getElapsedTime().asSeconds() >= 1.f) {
		this->fireballs["FIREBALL"]->loadFromFile("Sprite/fireblass.png");
		this->fire.push_back(new fireball(this->fireballs["FIREBALL"], this->player->getPos().x, this->player->getPos().y, -1.f, 0.f, 5.f, -1, 1));
		(this->canfireball)--;
		this->firetime.restart();
		this->bg->update(2);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->canicepillar > 0) {
		this->checkice = 1;
		(this->canicepillar)--;
		this->icetime.restart();
		this->bg->update(1);
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
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		else if (bullet->getBounds().left + bullet->getBounds().width < 0.f) {
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		else if (bullet->getBounds().left + bullet->getBounds().width > 1280.f) {
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		else if (bullet->getBounds().top + bullet->getBounds().height > 720.f) {
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		else if (bullet->getBounds().intersects(this->sbox1.getGlobalBounds())) {
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		else if (bullet->getBounds().intersects(this->sbox2.getGlobalBounds())) {
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		else if (bullet->getBounds().intersects(this->sbox3.getGlobalBounds())) {
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		else if (bullet->getBounds().intersects(this->sbox4.getGlobalBounds())) {
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		++counter;
	}
}

void Game::updateFireball()
{
	unsigned counters = 0;
	for (auto* fireball : this->fire) {
		fireball->update();
		if (fireball->getBounds().top + fireball->getBounds().height < 0.f) {
			delete this->fire.at(counters);
			this->fire.erase(this->fire.begin() + counters);
			--counters;
			this->bg->update(0);
		}
		else if (fireball->getBounds().left + fireball->getBounds().width < 0.f) {
			delete this->fire.at(counters);
			this->fire.erase(this->fire.begin() + counters);
			--counters;
			this->bg->update(0);
		}
		else if (fireball->getBounds().left + fireball->getBounds().width > 1280.f) {
			delete this->fire.at(counters);
			this->fire.erase(this->fire.begin() + counters);
			--counters;
			this->bg->update(0);
		}
		else if (fireball->getBounds().top + fireball->getBounds().height > 720.f) {
			delete this->fire.at(counters);
			this->fire.erase(this->fire.begin() + counters);
			--counters;
			this->bg->update(0);
		}
		++counters;
	}
}

void Game::updateice()
{
	for (int i = 0; i < this->ices.size(); ++i) {
		if (this->icetime.getElapsedTime().asSeconds() > 5.f) {
			this->ices.erase(this->ices.begin() + i);
			checkice = 0;
			this->bg->update(0);
		}
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
	this->updateFireball();
	this->updateice();
	this->updateenemy();
	this->updateskill();
	this->updateCollision();
	this->updateshield();
	this->updateGUI();
}

//update GUI
void Game::updateGUI()
{
	//scores
	std::stringstream ss;
	std::stringstream icenumber;
	std::stringstream firenumber;

	ss << "Scores : " << this->points;
	this->shadowpointtext.setString(ss.str());
	this->pointText.setString(ss.str());

	firenumber << this->canfireball;
	this->FIRETEXT.setString(firenumber.str());

	icenumber << this->canicepillar;
	this->ICETEXT.setString(icenumber.str());

	//hp of player
	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(300.f * hpPercent, this->playerHpBar.getSize().y));
}

//updated collision
void Game::updateCollision()
{
	int count = 0;
	float skillshield = 0.4;
	for (int i = 0; i < this->enemies.size(); ++i) {
		if (this->player->getBounds().intersects(this->enemies[i]->getBounds())) {
			count++;
		}
	}
	if (this->skilltime.getElapsedTime().asSeconds() > 15.f) {
		this->player->doubattack(0);
		this->textures["BULLET"]->loadFromFile("Sprite/bullet.png");
	}
	if (this->triptime.getElapsedTime().asSeconds() > 15.f) {
		this->checktriple = 0;
	}
	if (this->shieldtime.getElapsedTime().asSeconds() > 5.f) {
		this->checkshield = 0;
	}
	if (this->clock.getElapsedTime().asSeconds() >= 1.f) {
		if (this->keepshield == 1) {
			this->player->loseHp(5 * count * skillshield);
			this->clock.restart();
		}
		else {
			this->player->loseHp(5 * count);
			this->clock.restart();
		}
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
	this->window->draw(this->shadowpointtext);
	this->window->draw(this->pointText);

	this->window->draw(this->FIRETEXT);
	this->window->draw(this->ICETEXT);

	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);

	window->draw(this->sbox1);
	window->draw(this->sbox2);
	window->draw(this->sbox3);
	window->draw(this->sbox4);

	window->draw(this->firepicx);
	window->draw(this->icepicx);
}

//render window
void Game::render()
{
	this->window->clear(); //for clear old frame
	this->renderBackground(); //for made background
	for (auto* Shield : this->shield) {
		Shield->render(this->window);
	}
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
	for (auto* fireball : this->fire) {
		fireball->render(this->window);
	}
	for (auto* ice : this->ices) {
		ice->render(this->window);
	}
	this->window->display(); //for update new frame
}
