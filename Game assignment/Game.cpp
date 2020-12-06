#include "Game.h"
//start window
void Game::initwindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Escape", sf::Style::Close | sf::Style::Resize | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->menu = new Mainmenu(this->window->getSize().x, window->getSize().y);
	this->icon.loadFromFile("Sprite/icon.png");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

//get new player
void Game::initplayer()
{
	this->player = new Player();
}

void Game::initenemy()
{
	this->spawnTimerMax = 300.f;
	this->spawnTimer = this->spawnTimerMax;
}

void Game::initguard()
{
	this->spawnguardmax = 1000.f;
	this->spawnguard = 0;
}

void Game::initghost() {}

void Game::initdragon() {}

void Game::initblackdragon() {}

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

void Game::initdragonfire()
{
	this->dragontext["DRAGON"] = new sf::Texture();
	this->dragontext["DRAGON"]->loadFromFile("Sprite/dragonblass.png");
}

void Game::initice()
{
	this->icepillar["ICE"] = new sf::Texture();
	this->icepillar["ICE"]->loadFromFile("Sprite/ice.png");
}

//GUI
void Game::initGUI()
{
	this->bit8.loadFromFile("Font/2005_iannnnnAMD.ttf");

	this->pointText.setFont(this->bit8);
	this->pointText.setCharacterSize(60);
	this->pointText.setFillColor(sf::Color::White);
	this->pointText.setString("Score : ");
	this->pointText.setPosition(sf::Vector2f(1050.f, 10.f));

	this->shadowpointtext.setFont(this->bit8);
	this->shadowpointtext.setCharacterSize(60);
	this->shadowpointtext.setFillColor(sf::Color::Black);
	this->shadowpointtext.setString("Score : ");
	this->shadowpointtext.setPosition(sf::Vector2f(1055.f, 15.f));

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
	points = 0;
	//box1
	this->tbox1.loadFromFile("Sprite/Box.png");
	this->box_1.setTexture(&this->tbox1);
	this->box_1.setSize(sf::Vector2f(300.f, 50.f));
	this->box_1.setPosition(490.f, 150.f);
	box_1Bounds = box_1.getGlobalBounds();

	//box2
	this->tbox2.loadFromFile("Sprite/Box2.png");
	this->box_2.setTexture(&this->tbox2);
	this->box_2.setSize(sf::Vector2f(50.f, 300.f));
	this->box_2.setPosition(100.f, 250.f);
	box_2Bounds = box_2.getGlobalBounds();
	//box3
	this->tbox3.loadFromFile("Sprite/Box2.png");
	this->box_3.setTexture(&this->tbox3);
	this->box_3.setSize(sf::Vector2f(50.f, 300.f));
	this->box_3.setPosition(1130.f, 250.f);
	box_3Bounds = box_3.getGlobalBounds();
	//box4
	this->tbox4.loadFromFile("Sprite/Box.png");
	this->box_4.setTexture(&this->tbox4);
	this->box_4.setSize(sf::Vector2f(300.f, 50.f));
	this->box_4.setPosition(490.f, 520.f);
	box_4Bounds = box_4.getGlobalBounds();

	//sound
	this->shot.loadFromFile("Sound/Rim Shot.wav");
	this->shots.setBuffer(this->shot);

	this->enemydie.loadFromFile("Sound/enemy die.wav");
	this->enemydies.setBuffer(this->enemydie);

	this->ghostdie.loadFromFile("Sound/ghost die.wav");
	this->ghostdies.setBuffer(this->ghostdie);

	this->Fire_soundbuf.loadFromFile("Sound/Fireball.wav");
	this->Fire_sound.setBuffer(this->Fire_soundbuf);

	this->Freezer.loadFromFile("Sound/Freeze.wav");
	this->Freezers.setBuffer(this->Freezer);

	this->dragondie.loadFromFile("Sound/dragondies.wav");
	this->dragondies.setBuffer(this->dragondie);

	this->shieldsoundbuf.loadFromFile("Sound/shield.wav");
	this->shieldsound.setBuffer(this->shieldsoundbuf);

	this->keepitem.loadFromFile("Sound/keepitem.wav");
	this->keepitems.setBuffer(this->keepitem);

	this->Click.loadFromFile("Sound/Click.wav");
	this->clicks.setBuffer(this->Click);

	this->switc.loadFromFile("Sound/switch.wav");
	this->switcs.setBuffer(this->switc);

	this->dead.loadFromFile("Sound/maleyell.wav");
	this->deads.setBuffer(this->dead);

	music.openFromFile("Sound/music1.ogg");
	music.setVolume(30);
}

//Main starter functions
Game::Game()
{
	this->initwindow();
	this->initBackground();
	this->directioncheck = 0;
	this->initBulletTextures();
	this->initfireball();
	this->initdragon();
	this->initblackdragon();
	this->initdragonfire();
	this->initice();
	this->initGUI();
	this->initSystems();
	this->initplayer();
	this->initenemy();
	this->initguard();
	this->initghost();
	this->initskill();
}

//delete main function anythings 
Game::~Game()
{
	delete this->window;
	delete this->bg;
	delete this->player;
	delete this->menu;
	for (auto& i : this->textures) {
		delete i.second;
	}
	for (auto& i : this->dragontext) {
		delete i.second;
	}
	for (auto* i : this->bullets) {
		delete i;
	}
	for (auto* i : this->enemies) {
		delete i;
	}
	for (auto* i : this->dragon) {
		delete i;
	}
	for (auto* i : this->blackdragon) {
		delete i;
	}
	for (auto* i : this->dragonshooting) {
		delete i;
	}
	for (auto* i : this->ghost) {
		delete i;
	}
	for (auto* i : this->guard) {
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
	Textbox playernametextbox(100, sf::Color::White, true);
	playernametextbox.setFont(this->bit8);
	playernametextbox.setPosition({ 500.f,320.f });
	playernametextbox.setlimit(true, 10);

	int j = 0;

	this->fp = fopen("./score.txt", "r");
	for (int i = 0; i < 5; i++) {
		fscanf(fp, "%s", &temp);
		name[i] = temp;
		fscanf(fp, "%d", &score[i]);
		userScore.push_back(make_pair(score[i], name[i]));
	}

	sf::Event e;

	music.play();
	while (this->window->isOpen())
	{

		while (this->window->pollEvent(e))
		{
			switch (e.type)
			{
			case sf::Event::Closed:
				window->close();
			case sf::Event::TextEntered:
				if (playername) {
					playernametextbox.typeOn(e);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && this->dietimes.getElapsedTime().asSeconds() > 3.f) {
					gamestate = 0;
					checkname = false;
				}
			}

		}
		this->window->clear(); //for clear old frame
		this->updateMousePositions();
		if (gamestate == 0) {
			this->menu->getplay(playstatus);
			this->menu->update(this->window->getSize().x, window->getSize().y);
			this->menu->draw(*this->window);
			if (checkname && !(playstatus)) {
				this->menu->drawnamespace(*this->window);
				playernametextbox.drawTo(*this->window);
			}
			if (this->menu->getBounds_0().contains(this->mousePosview)) {
				if (canswitch) {
					this->switcs.play();
					canswitch = false;
				}
				this->menu->buttoncheck(0);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					this->clicks.play();
					if (playstatus) {
						gamestate = 1;
					}
					checkname = true;
					playername = true;
				}
			}
			else if (this->menu->getBounds_1().contains(this->mousePosview)) {
				if (canswitch) {
					this->switcs.play();
					canswitch = false;
				}
				this->menu->buttoncheck(1);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					this->clicks.play();
					gamestate = 2;
				}
			}
			else if (this->menu->getBounds_2().contains(this->mousePosview)) {
				if (canswitch) {
					this->switcs.play();
					canswitch = false;
				}
				this->menu->buttoncheck(2);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					this->clicks.play();
					gamestate = 3;
				}
			}
			else if (this->menu->getBounds_3().contains(this->mousePosview)) {
				if (canswitch) {
					this->switcs.play();
					canswitch = false;
				}
				this->menu->buttoncheck(3);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					this->clicks.play();
					this->window->close();
				}
			}
			else {
				canswitch = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && checkname) {
				playstatus = true;
				checkname = false;
				gamestate = 1;
				name[5] = playernametextbox.gettext();
			}
		}
		else if (gamestate == 1) {
			if (this->player->getHp() != 0) {
				this->update();
				this->render();
				cangetnewscores = true;
				candiesound = true;
			}
			else if (this->player->getHp() == 0 && dietimes.getElapsedTime().asSeconds() <= 3.f) {
				this->menu->drawdead(*this->window);
				if (candiesound == true) {
					deads.play();
					candiesound = false;
				}
			}
			else if (this->player->getHp() == 0 && cangetnewscores && dietimes.getElapsedTime().asSeconds() > 3.f) {
				this->updateenemy();
				this->updateghost();
				this->updatedragon();
				this->updateguard();
				this->updateblackdragon();

				j++;
				pointkeep = points;
				this->fp = fopen("./score.txt", "r");
				score[5] = pointkeep;
				userScore.push_back(make_pair(score[5], name[5]));
				sort(userScore.begin(), userScore.end());
				fclose(fp);
				fopen("./score.txt", "w");
				for (int i = 4 + j; i >= 0 + j; i--) {
					strcpy(temp, userScore[i].second.c_str());
					fprintf(fp, "%s %d\n", temp, userScore[i].first);
				}
				fclose(fp);

				this->player->setHp(100);
				cangetnewscores = false;
				this->gamestate = 0;
				playstatus = false;
				firstendgames = true;
				checkname = false;
				points = 0;
			}
		}
		else if (gamestate == 2) {
			this->menu->drawscore(*this->window);
			if (firstendgames == false) {
				for (int i = 135; i <= 475; i += 85) {
					showhighscore(950, i, to_string(userScore[(i - 135) / 85].first), *this->window, &bit8);
					showhighscore(250, i, userScore[j + (i - 135) / 85].second, *this->window, &bit8);
				}
			}
			else if (firstendgames == true) {
				for (int i = 135; i <= 475; i += 85) {
					showhighscore(950, i, to_string(userScore[(4 + j) - ((i - 135) / 85)].first), *this->window, &bit8);
					showhighscore(250, i, userScore[(4 + j) - ((i - 135) / 85)].second, *this->window, &bit8);
				}
			}
			if (this->menu->beforegetbounds().contains(this->mousePosview)) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->nextpage.getElapsedTime().asSeconds() > 0.25f) {
					this->clicks.play();
					this->gamestate = 0;
					this->nextpage.restart();
				}
			}
		}
		else if (gamestate == 3) {
			this->menu->howtoplay(*this->window);
			if (this->menu->nextgetbounds().contains(this->mousePosview)) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->nextpage.getElapsedTime().asSeconds() > 0.25f) {
					this->clicks.play();
					this->menu->nextpages();
					this->nextpage.restart();
				}
			}
			else if (this->menu->beforegetbounds().contains(this->mousePosview)) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->nextpage.getElapsedTime().asSeconds() > 0.25f) {
					this->clicks.play();
					if (this->menu->getpages() == 0) {
						this->gamestate = 0;
					}
					this->menu->beforepages();
					this->nextpage.restart();
				}
			}
		}
		this->window->display(); //for update new frame
	}
}

void Game::showhighscore(int x, int y, string word, sf::RenderWindow& window, sf::Font* font)
{
	sf::Text text;
	text.setFont(*font);
	text.setPosition(x, y);
	text.setString(word);
	text.setCharacterSize(120);
	window.draw(text);
}

void Game::updateMousePositions()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosview = this->window->mapPixelToCoords(this->mousePosWindow);
}

//player updated
void Game::updatePlayer()
{
	if (this->player->getBounds().intersects(this->box_1Bounds)) {
		this->player->updateCollision(this->box_1Bounds);
	}
	if (this->player->getBounds().intersects(this->box_2Bounds)) {
		this->player->updateCollision(this->box_2Bounds);
	}
	if (this->player->getBounds().intersects(this->box_3Bounds)) {
		this->player->updateCollision(this->box_3Bounds);
	}
	if (this->player->getBounds().intersects(this->box_4Bounds)) {
		this->player->updateCollision(this->box_4Bounds);
	}
	this->player->updated();
}

//enemy updated
void Game::updateenemy()
{
	//spawn
	if (this->checkice == 0) {
		this->spawnTimer += 0.5f;
	}
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->checkspawn = rand() % 4;
		if (this->checkspawn == 0) {
			this->enemies.push_back(new Enemy(rand() % this->window->getSize().x, -200.f));
		}
		else if (this->checkspawn == 1) {
			this->enemies.push_back(new Enemy(rand() % this->window->getSize().x, 920.f));
		}
		else if (this->checkspawn == 2) {
			this->enemies.push_back(new Enemy(-200.f, rand() % this->window->getSize().y));
		}
		else if (this->checkspawn == 3) {
			this->enemies.push_back(new Enemy(1480.f, rand() % this->window->getSize().y));
		}
		this->spawnTimer = 0.f;
	}
	//updated
	for (int i = 0; i < this->enemies.size(); ++i) {
		bool enemy_removed = false;
		if (this->checkice == 0) {
			for (int j = 0; j < this->enemies.size(); ++j) {
				if (i != j) {
					if (this->player->getBounds().left > this->enemies[i]->getBounds().left &&
						this->enemies[i]->getBounds().left > this->enemies[j]->getBounds().left &&
						this->enemies[i]->getBounds().left - this->enemies[j]->getBounds().left <= 3.f) {
						this->enemies[j]->setslow(0.8f);
					}
					else if (this->player->getBounds().left < this->enemies[i]->getBounds().left &&
						this->enemies[i]->getBounds().left < this->enemies[j]->getBounds().left &&
						this->enemies[j]->getBounds().left - this->enemies[i]->getBounds().left <= 3.f) {
						this->enemies[j]->setslow(0.8f);
					}
					else if (this->player->getBounds().top < this->enemies[i]->getBounds().top &&
						this->enemies[i]->getBounds().top < this->enemies[j]->getBounds().top &&
						this->enemies[j]->getBounds().top - this->enemies[i]->getBounds().top <= 3.f) {
						this->enemies[j]->setslow(0.8f);
					}
					else if (this->player->getBounds().top > this->enemies[i]->getBounds().top &&
						this->enemies[i]->getBounds().top > this->enemies[j]->getBounds().top &&
						this->enemies[i]->getBounds().top - this->enemies[j]->getBounds().top <= 3.f) {
						this->enemies[j]->setslow(0.8f);
					}
					else {
						this->enemies[j]->setslow(1.f);
					}
				}
				else {
					if (this->enemies[i]->getBounds().intersects(this->box_1Bounds)) {
						this->enemies[i]->updateCollision(this->box_1Bounds);
					}
					if (this->enemies[i]->getBounds().intersects(this->box_2Bounds)) {
						this->enemies[i]->updateCollision(this->box_2Bounds);
					}
					if (this->enemies[i]->getBounds().intersects(this->box_3Bounds)) {
						this->enemies[i]->updateCollision(this->box_3Bounds);
					}
					if (this->enemies[i]->getBounds().intersects(this->box_4Bounds)) {
						this->enemies[i]->updateCollision(this->box_4Bounds);
					}
					this->enemies[i]->updated(this->player->getPos().x - 8, this->player->getPos().y - 5, 1);
				}
			}
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
					enemydies.play();
					points += 5;
					this->enemies.erase(this->enemies.begin() + i);
					enemy_removed = true;
					(this->countkill)++;
					(this->countfordragon)++;
				}
			}
		}
		for (size_t k = 0; k < this->fire.size() && !enemy_removed; k++) {
			if (this->fire[k]->getBounds().intersects(this->enemies[i]->getBounds())) {
				this->enemies[i]->loseHp(1);
				if (this->enemies[i]->getHp() == 0) {
					enemydies.play();
					points += 5;
					this->enemies.erase(this->enemies.begin() + i);
					enemy_removed = true;
					(this->countkill)++;
					(this->countfordragon)++;
				}
			}
		}
		if (this->player->getHp() == 0) {
			if (enemies.size() == 1) {
				this->enemies.erase(this->enemies.begin());
			}
			else {
				if (i == 0) {
					this->enemies.erase(this->enemies.begin());
				}
				this->enemies.erase(this->enemies.begin() + i);
			}
		}
	}
}

void Game::updateguard()
{
	//spawn
	if (this->checkice == 0) {
		this->spawnguard += 0.5f;
	}
	if (this->spawnguard >= this->spawnguardmax)
	{
		this->checkspawn = rand() % 4;
		if (this->checkspawn == 0) {
			this->guard.push_back(new shielder(rand() % this->window->getSize().x, -100.f));
		}
		else if (this->checkspawn == 1) {
			this->guard.push_back(new shielder(rand() % this->window->getSize().x, 820.f));
		}
		else if (this->checkspawn == 2) {
			this->guard.push_back(new shielder(-100.f, rand() % this->window->getSize().y));
		}
		else if (this->checkspawn == 3) {
			this->guard.push_back(new shielder(1380.f, rand() % this->window->getSize().y));
		}
		this->spawnguard = 0.f;
	}
	//updated
	for (int i = 0; i < this->guard.size(); ++i) {
		bool guard_removed = false;
		if (this->checkice == 0) {
			for (int j = 0; j < this->guard.size(); ++j) {
				if (i != j) {
					if (this->player->getBounds().left > this->guard[i]->getBounds().left &&
						this->guard[i]->getBounds().left > this->guard[j]->getBounds().left &&
						this->guard[i]->getBounds().left - this->guard[j]->getBounds().left <= 3.f) {
						this->guard[j]->setslow(0.8f);
					}
					else if (this->player->getBounds().left < this->guard[i]->getBounds().left &&
						this->guard[i]->getBounds().left < this->guard[j]->getBounds().left &&
						this->guard[j]->getBounds().left - this->guard[i]->getBounds().left <= 3.f) {
						this->guard[j]->setslow(0.8f);
					}
					else if (this->player->getBounds().top < this->guard[i]->getBounds().top &&
						this->guard[i]->getBounds().top < this->guard[j]->getBounds().top &&
						this->guard[j]->getBounds().top - this->guard[i]->getBounds().top <= 3.f) {
						this->guard[j]->setslow(0.8f);
					}
					else if (this->player->getBounds().top > this->guard[i]->getBounds().top &&
						this->guard[i]->getBounds().top > this->guard[j]->getBounds().top &&
						this->guard[i]->getBounds().top - this->guard[j]->getBounds().top <= 3.f) {
						this->guard[j]->setslow(0.8f);
					}
					else {
						this->guard[j]->setslow(1.f);
					}
				}
				else {
					if (this->guard[i]->getBounds().intersects(this->box_1Bounds)) {
						this->guard[i]->updateCollision(this->box_1Bounds);
					}
					if (this->guard[i]->getBounds().intersects(this->box_2Bounds)) {
						this->guard[i]->updateCollision(this->box_2Bounds);
					}
					if (this->guard[i]->getBounds().intersects(this->box_3Bounds)) {
						this->guard[i]->updateCollision(this->box_3Bounds);
					}
					if (this->guard[i]->getBounds().intersects(this->box_4Bounds)) {
						this->guard[i]->updateCollision(this->box_4Bounds);
					}
					this->guard[i]->updated(this->player->getPos().x - 8, this->player->getPos().y - 5, 1);
				}
			}
		}
		else if (this->checkice == 1) {
			this->guard[i]->updated(this->player->getPos().x - 8, this->player->getPos().y - 5, 0);
			this->ices.push_back(new ice(this->icepillar["ICE"], this->guard[i]->getPos().x + 10, this->guard[i]->getPos().y + 20));
		}

		for (size_t k = 0; k < this->bullets.size() && !guard_removed; k++) {
			if (this->bullets[k]->getBounds().intersects(this->guard[i]->getBounds())) {
				this->guard[i]->loseHp(5);
				this->bullets.erase(this->bullets.begin() + k);
				if (this->guard[i]->getHp() == 0) {
					//enemydies.play();
					points += 5;
					this->guard.erase(this->guard.begin() + i);
					guard_removed = true;
					(this->countkill)++;
					(this->countfordragon)++;
				}
			}
		}
		for (size_t k = 0; k < this->fire.size() && !guard_removed; k++) {
			if (this->fire[k]->getBounds().intersects(this->guard[i]->getBounds())) {
				this->guard[i]->loseHp(1);
				if (this->guard[i]->getHp() == 0) {
					//enemydies.play();
					points += 5;
					this->guard.erase(this->guard.begin() + i);
					guard_removed = true;
					(this->countkill)++;
					(this->countfordragon)++;
				}
			}
		}
		if (this->player->getHp() == 0) {
			if (guard.size() == 1) {
				this->guard.erase(this->guard.begin());
			}
			else {
				if (i == 0) {
					this->guard.erase(this->guard.begin());
				}
				this->guard.erase(this->guard.begin() + i);
			}
		}
	}
}

void Game::updateghost()
{
	//spawn
	if (this->countkill % 5 == 0 && this->countkill != 0 && this->checkice == 0)
	{
		this->checkspawn = rand() % 4;
		if (this->checkspawn == 0) {
			this->ghost.push_back(new Ghost(rand() % this->window->getSize().x, -200.f));
		}
		else if (this->checkspawn == 1) {
			this->ghost.push_back(new Ghost(rand() % this->window->getSize().x, 920.f));
		}
		else if (this->checkspawn == 2) {
			this->ghost.push_back(new Ghost(-200.f, rand() % this->window->getSize().y));
		}
		else if (this->checkspawn == 3) {
			this->ghost.push_back(new Ghost(1480.f, rand() % this->window->getSize().y));
		}
		(this->countkill) -= 5;
	}
	//updated
	for (int i = 0; i < this->ghost.size(); ++i) {
		bool ghost_removed = false;
		if (this->checkice == 0) {
			this->ghost[i]->updated(this->player->getPos().x + 3, this->player->getPos().y + 10, 1);
		}
		else if (this->checkice == 1) {
			this->ghost[i]->updated(this->player->getPos().x + 5, this->player->getPos().y + 13, 0);
			this->ices.push_back(new ice(this->icepillar["ICE"], this->ghost[i]->getPos().x + 10, this->ghost[i]->getPos().y + 20));
		}
		for (size_t k = 0; k < this->bullets.size() && !ghost_removed; k++) {
			if (this->bullets[k]->getBounds().intersects(this->ghost[i]->getBounds())) {
				this->ghost[i]->loseHp(5);
				this->bullets.erase(this->bullets.begin() + k);
				if (this->ghost[i]->getHp() == 0) {
					ghostdies.play();
					points += 10;
					this->ghost.erase(this->ghost.begin() + i);
					ghost_removed = true;
					(this->countkill)++;
					(this->countfordragon)++;
				}
			}
		}
		for (size_t k = 0; k < this->fire.size() && !ghost_removed; k++) {
			if (this->fire[k]->getBounds().intersects(this->ghost[i]->getBounds())) {
				this->ghost[i]->loseHp(1);
				if (this->ghost[i]->getHp() == 0) {
					ghostdies.play();
					points += 10;
					this->ghost.erase(this->ghost.begin() + i);
					ghost_removed = true;
					(this->countkill)++;
					(this->countfordragon)++;
				}
			}
		}
		if (this->player->getHp() == 0) {
			if (ghost.size() == 1) {
				this->ghost.erase(this->ghost.begin());
			}
			else {
				if (i == 0) {
					this->ghost.erase(this->ghost.begin());
				}
				this->ghost.erase(this->ghost.begin() + i);
			}
		}
	}
}

void Game::updateblackdragon()
{
	//spawn
	if (this->blackdragonspawn.getElapsedTime().asSeconds() >= 20.f)
	{
		this->blackdragon.push_back(new Blackdragoon(rand() % 1180, -100.f));
		this->blackdragonspawn.restart();
	}
	//updated
	for (int i = 0; i < this->blackdragon.size(); ++i) {
		bool blackdragon_removed = false;
		this->blackdragon[i]->updated();

		if (blackdragon[i]->getBounds().left + blackdragon[i]->getBounds().width >= 1280.f) {
			this->blackdragon.erase(this->blackdragon.begin() + i);
		}
		if (this->player->getHp() == 0) {
			if (blackdragon.size() == 1) {
				this->blackdragon.erase(this->blackdragon.begin());
			}
			else {
				if (i == 0) {
					this->blackdragon.erase(this->blackdragon.begin());
				}
				this->blackdragon.erase(this->blackdragon.begin() + i);
			}
		}
	}
}

void Game::updatedragon()
{
	//spawn
	if (this->countfordragon % 50 == 0 && this->countfordragon != 0 && this->checkice == 0)
	{
		this->checkspawn = rand() % 4;
		if (this->checkspawn == 0) {
			this->dragon.push_back(new Dragon(rand() % this->window->getSize().x, -200.f));
		}
		else if (this->checkspawn == 1) {
			this->dragon.push_back(new Dragon(rand() % this->window->getSize().x, 920.f));
		}
		else if (this->checkspawn == 2) {
			this->dragon.push_back(new Dragon(-200.f, rand() % this->window->getSize().y));
		}
		else if (this->checkspawn == 3) {
			this->dragon.push_back(new Dragon(1480.f, rand() % this->window->getSize().y));
		}
		(this->countfordragon) -= 50;
	}
	//updated
	for (int i = 0; i < this->dragon.size(); ++i) {
		bool dragon_removed = false;
		if (this->dragon[i]->canAttack_top() && this->dragon[i]->getdir() == 4) {
			this->dragonshooting.push_back(new Bullet(this->dragontext["DRAGON"], this->dragon[i]->getPos().x + 50, this->dragon[i]->getPos().y - 50, 0.f, -1.f, 2.f));
			this->Fire_sound.play();
		}
		else if (this->dragon[i]->canAttack_left() && this->dragon[i]->getdir() == 2) {
			this->dragonshooting.push_back(new Bullet(this->dragontext["DRAGON"], this->dragon[i]->getPos().x - 20, this->dragon[i]->getPos().y + 20, -1.f, 0.f, 2.f));
			this->Fire_sound.play();
		}
		else if (this->dragon[i]->canAttack_down() && this->dragon[i]->getdir() == 1) {
			this->dragonshooting.push_back(new Bullet(this->dragontext["DRAGON"], this->dragon[i]->getPos().x + 50, this->dragon[i]->getPos().y + 70, 0.f, 1.f, 2.f));
			this->Fire_sound.play();
		}
		else if (this->dragon[i]->canAttack_right() && this->dragon[i]->getdir() == 3) {
			this->dragonshooting.push_back(new Bullet(this->dragontext["DRAGON"], this->dragon[i]->getPos().x + 70, this->dragon[i]->getPos().y + 20, 1.f, 0.f, 2.f));
			this->Fire_sound.play();
		}
		if (this->checkice == 0) {
			if (this->dragon[i]->getBounds().intersects(this->box_1Bounds)) {
				this->dragon[i]->updateCollision(this->box_1Bounds);
			}
			if (this->dragon[i]->getBounds().intersects(this->box_2Bounds)) {
				this->dragon[i]->updateCollision(this->box_2Bounds);
			}
			if (this->dragon[i]->getBounds().intersects(this->box_3Bounds)) {
				this->dragon[i]->updateCollision(this->box_3Bounds);
			}
			if (this->dragon[i]->getBounds().intersects(this->box_4Bounds)) {
				this->dragon[i]->updateCollision(this->box_4Bounds);
			}
			this->dragon[i]->updated(this->player->getPos().x - 8, this->player->getPos().y - 5, 1);
		}
		else if (this->checkice == 1) {
			this->dragon[i]->updated(this->player->getPos().x + 5, this->player->getPos().y + 13, 0);
			this->ices.push_back(new ice(this->icepillar["ICE"], this->dragon[i]->getPos().x + 35, this->dragon[i]->getPos().y + 20));
		}
		for (size_t k = 0; k < this->bullets.size() && !dragon_removed; k++) {
			if (this->bullets[k]->getBounds().intersects(this->dragon[i]->getBounds())) {
				this->dragon[i]->loseHp(5);
				this->bullets.erase(this->bullets.begin() + k);
				if (this->dragon[i]->getHp() == 0) {
					points += 1000;
					dragondies.play();
					this->dragon.erase(this->dragon.begin() + i);
					dragon_removed = true;
					(this->countkill)++;
				}
			}
		}
		for (size_t k = 0; k < this->fire.size() && !dragon_removed; k++) {
			if (this->fire[k]->getBounds().intersects(this->dragon[i]->getBounds())) {
				this->dragon[i]->loseHp(1);
				if (this->dragon[i]->getHp() == 0) {
					points += 1000;
					dragondies.play();
					this->dragon.erase(this->dragon.begin() + i);
					dragon_removed = true;
					(this->countkill)++;
				}
			}
		}
		if (this->player->getHp() == 0) {
			if (dragon.size() == 1) {
				this->dragon.erase(this->dragon.begin());
			}
			else {
				if (i == 0) {
					this->dragon.erase(this->dragon.begin());
				}
				this->dragon.erase(this->dragon.begin() + i);
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
		this->type = 1 + rand() % 5;
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
		if (this->skills[i]->getBounds().intersects(this->box_1Bounds)) {
			this->skills.erase(this->skills.begin() + i);
			this->skillTimer += 1000.f;
		}
		else if (this->skills[i]->getBounds().intersects(this->box_2Bounds)) {
			this->skills.erase(this->skills.begin() + i);
			this->skillTimer += 1000.f;
		}
		else if (this->skills[i]->getBounds().intersects(this->box_3Bounds)) {
			this->skills.erase(this->skills.begin() + i);
			this->skillTimer += 1000.f;
		}
		else if (this->skills[i]->getBounds().intersects(this->box_4Bounds)) {
			this->skills.erase(this->skills.begin() + i);
			this->skillTimer += 1000.f;
		}
		//1 skill
		else if (this->skills[i]->getBounds().intersects(this->player->getBounds()) && this->type == 1) {
			this->skills.erase(this->skills.begin() + i);
			this->keepitems.play();
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
			this->keepitems.play();
		}
		//3 skill
		else if (this->skills[i]->getBounds().intersects(this->player->getBounds()) && this->type == 3) {
			this->skills.erase(this->skills.begin() + i);
			this->keepitems.play();
			this->triptime.restart();
			this->checktriple = 1;
		}
		//4 skill
		else if (this->skills[i]->getBounds().intersects(this->player->getBounds()) && this->type == 4) {
			this->skills.erase(this->skills.begin() + i);
			this->keepitems.play();
			this->shieldsound.play();
			this->shieldtime.restart();
			this->checkshield = 1;
		}
		//5 skill
		else if (this->skills[i]->getBounds().intersects(this->player->getBounds()) && this->type == 5) {
			(this->canicepillar)++;
			this->skills.erase(this->skills.begin() + i);
			this->keepitems.play();
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
		this->shield.push_back(new Shield(this->player->getPos().x - 25, this->player->getPos().y - 5));
		checkshield = 0;
	}
	for (int i = 0; i < this->shield.size(); ++i) {
		this->shield[i]->update(this->player->getPos().x - 25, this->player->getPos().y - 5);
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack_top_trip()
		&& this->directioncheck == 1 && this->checktriple == 1 && this->triptime.getElapsedTime().asSeconds() <= 15.f) {
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 15, this->player->getPos().y, 1.f, -1.f, 5.f));
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 15, this->player->getPos().y, -1.f, -1.f, 5.f));
		this->shots.play();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack_left_trip() && this->directioncheck == 2
		&& this->checktriple == 1 && this->triptime.getElapsedTime().asSeconds() <= 15.f) {
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x, this->player->getPos().y + 28, -1.f, 1.f, 5.f));
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x, this->player->getPos().y + 28, -1.f, -1.f, 5.f));
		this->shots.play();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack_right_trip() && this->directioncheck == 3
		&& this->checktriple == 1 && this->triptime.getElapsedTime().asSeconds() <= 15.f) {
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 68, this->player->getPos().y + 28, 1.f, 1.f, 5.f));
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 68, this->player->getPos().y + 28, 1.f, -1.f, 5.f));
		this->shots.play();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack_down_trip() && this->directioncheck == 0
		&& this->checktriple == 1 && this->triptime.getElapsedTime().asSeconds() <= 15.f) {
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 15, this->player->getPos().y + 95, 1.f, 1.f, 5.f));
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 15, this->player->getPos().y + 95, -1.f, 1.f, 5.f));
		this->shots.play();
	}
	//normal shooting
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack_top() && this->directioncheck == 1) {
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 15, this->player->getPos().y, 0.f, -1.f, 5.f));
		this->shots.play();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack_left() && this->directioncheck == 2) {
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x, this->player->getPos().y + 28, -1.f, 0.f, 5.f));
		this->shots.play();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack_right() && this->directioncheck == 3) {
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 68, this->player->getPos().y + 28, 1.f, 0.f, 5.f));
		this->shots.play();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack_down() && this->directioncheck == 0) {
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 15, this->player->getPos().y + 95, 0.f, 1.f, 5.f));
		this->shots.play();
	}
	//fire ball
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && this->directioncheck == 1 && this->canfireball > 0 && this->firetime.getElapsedTime().asSeconds() >= 1.f) {
		this->fireballs["FIREBALL"]->loadFromFile("Sprite/fireball.png");
		this->fire.push_back(new fireball(this->fireballs["FIREBALL"], this->player->getPos().x, this->player->getPos().y, 0.f, -1.f, 5.f, 1, -1));
		(this->canfireball)--;
		this->Fire_sound.play();
		this->firetime.restart();
		this->bg->update(2);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && this->directioncheck == 0 && this->canfireball > 0 && this->firetime.getElapsedTime().asSeconds() >= 1.f) {
		this->fireballs["FIREBALL"]->loadFromFile("Sprite/fireball.png");
		this->fire.push_back(new fireball(this->fireballs["FIREBALL"], this->player->getPos().x, this->player->getPos().y, 0.f, 1.f, 5.f, 1, 1));
		(this->canfireball)--;
		this->Fire_sound.play();
		this->firetime.restart();
		this->bg->update(2);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && this->directioncheck == 3 && this->canfireball > 0 && this->firetime.getElapsedTime().asSeconds() >= 1.f) {
		this->fireballs["FIREBALL"]->loadFromFile("Sprite/fireblass.png");
		this->fire.push_back(new fireball(this->fireballs["FIREBALL"], this->player->getPos().x, this->player->getPos().y, 1.f, 0.f, 5.f, 1, 1));
		(this->canfireball)--;
		this->Fire_sound.play();
		this->firetime.restart();
		this->bg->update(2);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && this->directioncheck == 2 && this->canfireball > 0 && this->firetime.getElapsedTime().asSeconds() >= 1.f) {
		this->fireballs["FIREBALL"]->loadFromFile("Sprite/fireblass.png");
		this->fire.push_back(new fireball(this->fireballs["FIREBALL"], this->player->getPos().x, this->player->getPos().y, -1.f, 0.f, 5.f, -1, 1));
		(this->canfireball)--;
		this->Fire_sound.play();
		this->firetime.restart();
		this->bg->update(2);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->canicepillar > 0 && this->icetypetime.getElapsedTime().asSeconds() >= 1.f) {
		this->checkice = 1;
		(this->canicepillar)--;
		this->Freezers.play();
		this->icetime.restart();
		this->icetypetime.restart();
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
		else if (bullet->getBounds().intersects(this->box_1Bounds)) {
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		else if (bullet->getBounds().intersects(this->box_2Bounds)) {
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		else if (bullet->getBounds().intersects(this->box_3Bounds)) {
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		else if (bullet->getBounds().intersects(this->box_4Bounds)) {
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		++counter;
	}
}

void Game::updatedragonshooting()
{
	unsigned countered = 0;
	for (auto* shoot : this->dragonshooting) {
		shoot->update();
		if (shoot->getBounds().top + shoot->getBounds().height < 0.f) {
			delete this->dragonshooting.at(countered);
			this->dragonshooting.erase(this->dragonshooting.begin() + countered);
			--countered;
		}
		else if (shoot->getBounds().left + shoot->getBounds().width < 0.f) {
			delete this->dragonshooting.at(countered);
			this->dragonshooting.erase(this->dragonshooting.begin() + countered);
			--countered;
		}
		else if (shoot->getBounds().left + shoot->getBounds().width > 1280.f) {
			delete this->dragonshooting.at(countered);
			this->dragonshooting.erase(this->dragonshooting.begin() + countered);
			--countered;
		}
		else if (shoot->getBounds().top + shoot->getBounds().height > 720.f) {
			delete this->dragonshooting.at(countered);
			this->dragonshooting.erase(this->dragonshooting.begin() + countered);
			--countered;
		}
		else if (shoot->getBounds().intersects(this->box_1Bounds)) {
			delete this->dragonshooting.at(countered);
			this->dragonshooting.erase(this->dragonshooting.begin() + countered);
			--countered;
		}
		else if (shoot->getBounds().intersects(this->box_2Bounds)) {
			delete this->dragonshooting.at(countered);
			this->dragonshooting.erase(this->dragonshooting.begin() + countered);
			--countered;
		}
		else if (shoot->getBounds().intersects(this->box_3Bounds)) {
			delete this->dragonshooting.at(countered);
			this->dragonshooting.erase(this->dragonshooting.begin() + countered);
			--countered;
		}
		else if (shoot->getBounds().intersects(this->box_4Bounds)) {
			delete this->dragonshooting.at(countered);
			this->dragonshooting.erase(this->dragonshooting.begin() + countered);
			--countered;
		}
		else if (shoot->getBounds().intersects(this->player->getBounds())) {
			delete this->dragonshooting.at(countered);
			this->dragonshooting.erase(this->dragonshooting.begin() + countered);
			this->player->loseHp(5);
			--countered;
		}
		++countered;
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
	this->updateInput();
	this->updateCollision();
	this->updateBullets();
	this->updateFireball();
	this->updateice();
	this->updatePlayer();
	this->updateenemy();
	this->updateghost();
	this->updateguard();
	this->updateblackdragon();
	this->updatedragon();
	this->updatedragonshooting();
	this->updateskill();
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

	ss << "Scores : " << points;
	this->shadowpointtext.setString(ss.str());
	this->pointText.setString(ss.str());

	firenumber << this->canfireball;
	this->FIRETEXT.setString(firenumber.str());

	icenumber << this->canicepillar;
	this->ICETEXT.setString(icenumber.str());

	//hp of player
	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(300.f * hpPercent, this->playerHpBar.getSize().y));

	if (this->gametimes.getElapsedTime().asSeconds() >= 10.f) {
		this->spawnTimerMax -= 5.f;
		this->gametimes.restart();
	}

	if (this->player->getHp() == 0) {
		this->dietimes.restart();
		this->gametimes.restart();
		this->spawnTimerMax = 300.f;
		this->blackdragonspawn.restart();
	}
}

//updated collision
void Game::updateCollision()
{
	int count = 0;
	int blackdragonhits = 0;
	float skillshield = 0.4;
	for (int i = 0; i < this->enemies.size(); ++i) {
		if (this->player->getBounds().intersects(this->enemies[i]->getBounds())) {
			count++;
		}
	}
	for (int i = 0; i < this->ghost.size(); ++i) {
		if (this->player->getBounds().intersects(this->ghost[i]->getBounds())) {
			count += 2;
		}
	}
	for (int i = 0; i < this->guard.size(); ++i) {
		if (this->player->getBounds().intersects(this->guard[i]->getBounds())) {
			count += 2;
		}
	}
	for (int i = 0; i < this->blackdragon.size(); ++i) {
		if (this->player->getBounds().intersects(this->blackdragon[i]->getBounds())) {
			blackdragonhits += 2;
		}
	}
	for (int i = 0; i < this->dragon.size(); ++i) {
		if (this->player->getBounds().intersects(this->dragon[i]->getBounds())) {
			count += 2;
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

	if (this->blackdragondamages.getElapsedTime().asSeconds() >= 0.25f) {
		if (this->keepshield == 1) {
			this->player->loseHp(5 * blackdragonhits * skillshield);
			this->blackdragondamages.restart();
		}
		else {
			this->player->loseHp(5 * blackdragonhits);
			this->blackdragondamages.restart();
		}
	}
	count = 0;
	blackdragonhits = 0;
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

	window->draw(this->box_1);
	window->draw(this->box_2);
	window->draw(this->box_3);
	window->draw(this->box_4);

	window->draw(this->firepicx);
	window->draw(this->icepicx);
}

//render window
void Game::render()
{

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
	for (auto* ghosts : this->ghost) {
		ghosts->render(*this->window);
	}
	for (auto* guards : this->guard) {
		guards->render(*this->window);
	}
	for (auto* blackdrgn : this->blackdragon) {
		blackdrgn->render(*this->window);
	}
	for (auto* dragoon : this->dragon) {
		dragoon->render(*this->window);
	}
	for (auto* dragonic : this->dragonshooting) {
		dragonic->render(this->window);
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

}

