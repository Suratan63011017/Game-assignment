#pragma once
#include"Player.h"
#include"Background.h"
#include<map>
#include"Bullet.h"
#include"Enemy.h"
class Game
{
private:
	//Variables
	sf::RenderWindow* window;
	Player* player;
	Enemy* enemy;
	Background* bg;
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;
	int directioncheck;

	//Function
	void initwindow();
	void initplayer();
	void initenemy();
	void initBackground();
	void initBulletTextures();

public:
	//Game
	Game();
	virtual ~Game();

	//Update and render
	void run();

	//update function
	void updatePlayer();
	void updateenemy();
	void updateInput();
	void updateBullets();
	void update();

	//render function
	void renderBackground();
	void renderPlayer();
	void renderenemy();
	void render();
};

