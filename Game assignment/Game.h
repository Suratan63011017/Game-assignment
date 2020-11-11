#pragma once
#include"Player.h"
#include"Background.h"
#include<string>
#include<sstream>
#include<map>
#include"Bullet.h"
#include"Enemy.h"
#include"Skill.h"
#include"fireball.h"
#include"Shield.h"
#include"ice.h"
#include"Ghost.h"
#include"Dragon.h"
class Game
{
private:
	//Variables
	sf::RenderWindow* window;
	sf::Font font;
	sf::Font bit8;
	sf::Text pointText;
	sf::Text shadowpointtext;
	sf::Text FIRETEXT;
	sf::Text ICETEXT;
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;
	unsigned points;
	Player* player;
	Background* bg;
	std::map<std::string, sf::Texture*> textures;
	std::map<std::string, sf::Texture*> skillpics;
	std::map<std::string, sf::Texture*> fireballs;
	std::map<std::string, sf::Texture*> icepillar;
	std::map<std::string, sf::Texture*> dragontext;
	std::vector<Enemy*> enemies;
	std::vector<Dragon*> dragon;
	std::vector<Ghost*> ghost;
	std::vector<Bullet*> bullets;
	std::vector<Bullet*> dragonshooting;
	std::vector<fireball*> fire;
	std::vector<Skill*> skills;
	std::vector<Shield*> shield;
	std::vector<ice*> ices;
	int directioncheck;
	float spawnTimer;
	float spawnTimerMax;
	int countkill = 0;
	int countfordragon = 0;
	sf::Clock clock;
	sf::Clock skilltime;
	sf::Clock triptime;
	sf::Clock skilltimecheck;
	sf::Clock firetime;
	sf::Clock shieldtime;
	sf::Clock icetime;
	sf::Clock inputcheck;
	float skillTimer;
	float skillTimerMax;
	int type;
	int checktriple = 0;
	int canfireball = 0;
	int checkshield = 0;
	int checkice = 0;
	int keepshield = 0;
	int canicepillar = 0;

	sf::Texture tbox1;
	sf::Sprite sbox1;
	sf::Texture tbox2;
	sf::Sprite sbox2;
	sf::Texture tbox3;
	sf::Sprite sbox3;
	sf::Texture tbox4;
	sf::Sprite sbox4;

	sf::Texture firepics;
	sf::Sprite firepicx;

	sf::Texture icepics;
	sf::Sprite icepicx;

	//Function
	void initwindow();
	void initplayer();
	void initenemy();
	void initghost();
	void initdragon();
	void initskill();
	void initBackground();
	void initBulletTextures();
	void initfireball();
	void initdragonfire();
	void initice();
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
	void updateghost();
	void updatedragon();
	void updateskill();
	void updateshield();
	void updateInput();
	void updateBullets();
	void updatedragonshooting();
	void updateFireball();
	void updateice();
	void update();
	void updateGUI();
	void updateCollision();

	//render function
	void renderBackground();
	void renderPlayer();
	void renderGUI();
	void render();
};

