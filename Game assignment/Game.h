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
	sf::Font font;
	sf::Text pointText;
	Player* player;
	Background* bg;
	std::map<std::string, sf::Texture*> textures;
	std::vector<Enemy*> enemies;
	std::vector<Bullet*> bullets;
	int directioncheck;
	float spawnTimer;
	float spawnTimerMax;


	//Function
	void initwindow();
	void initplayer();
	void initenemy();
	void initBackground();
	void initBulletTextures();
	void initGUI();

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
	void updateGUI();

	//render function
	void renderBackground();
	void renderPlayer();
	void renderGUI();
	void render();
};

