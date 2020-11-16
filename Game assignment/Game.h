#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<SFML/Audio.hpp>
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
#include"Mainmenu.h"
#include"Textbox.h"
#include<utility>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>

using namespace std;
class Game
{
private:
	//Variables
	sf::RenderWindow* window;
	Mainmenu* menu;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosview;
	bool checkname = false;

	FILE* fp;
	char temp[255];
	int score[6];
	string name[6];
	vector<pair<int, string>>userScore;
	int gamestate = 0;
	bool playername = false;
	bool playstatus = false;
	bool cangetnewscores = false;

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
	sf::Clock nextpage;
	float skillTimer;
	float skillTimerMax;
	int type;
	int checktriple = 0;
	int canfireball = 0;
	int checkshield = 0;
	int checkice = 0;
	int keepshield = 0;
	int canicepillar = 0;

	int checkspawn;

	sf::Texture tbox1;
	sf::Texture tbox2;
	sf::Texture tbox3;
	sf::Texture tbox4;

	sf::RectangleShape box_1;
	sf::RectangleShape box_2;
	sf::RectangleShape box_3;
	sf::RectangleShape box_4;

	sf::FloatRect box_1Bounds;
	sf::FloatRect box_2Bounds;
	sf::FloatRect box_3Bounds;
	sf::FloatRect box_4Bounds;


	sf::Texture firepics;
	sf::Sprite firepicx;

	sf::Texture icepics;
	sf::Sprite icepicx;

	sf::SoundBuffer shot;
	sf::Sound shots;
	sf::SoundBuffer enemydie;
	sf::Sound enemydies;
	sf::SoundBuffer ghostdie;
	sf::Sound ghostdies;
	sf::SoundBuffer Fire_soundbuf;
	sf::Sound Fire_sound;
	sf::SoundBuffer Freezer;
	sf::Sound Freezers;


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

	void showhighscore(int x, int y, string word, sf::RenderWindow& window, sf::Font* font);
	//update function
	void updateMousePositions();
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

