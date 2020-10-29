#pragma once
#include"Player.h"
#include"Background.h"
#include<string>
#include<sstream>
#include<map>
#include"Bullet.h"
#include"Enemy.h"
#include"Skill.h"
class Game
{
private:
	//Variables
	sf::RenderWindow* window;
	sf::Font font;
	sf::Text pointText;
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;
	unsigned points;
	Player* player;
	Background* bg;
	std::map<std::string, sf::Texture*> textures;
	std::vector<Enemy*> enemies;
	std::vector<Bullet*> bullets;
	std::vector<Skill*> skills;
	int directioncheck;
	float spawnTimer;
	float spawnTimerMax;
	sf::Clock clock;
	sf::Clock skilltime;
	float skillTimer;
	float skillTimerMax;

	//Function
	void initwindow();
	void initplayer();
	void initenemy();
	void initskill();
	void initBackground();
	void initBulletTextures();
	void initGUI();
	void initSystems();

public:
	//Game
	Game();
	virtual ~Game();

	//Update and render
	void run();

	//update function
	void updatePlayer();
	void updateenemy();
	void updateskill();
	void updateInput();
	void updateBullets();
	void update();
	void updateGUI();
	void updateCollision();

	//render function
	void renderBackground();
	void renderPlayer();
	void renderGUI();
	void render();
};

