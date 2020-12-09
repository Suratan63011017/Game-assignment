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
#include"shielder.h"
#include"ice.h"
#include"Ghost.h"
#include"Dragon.h"
#include"Mainmenu.h"
#include"Textbox.h"
#include"lighting.h"
#include"Blackdragoon.h"
#include<utility>
#include<algorithm>
#include<vector>
#include<iostream>
#include"wizard.h"

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
	bool firstendgames = false;

	sf::Font bit8;
	sf::Text pointText;
	sf::Text shadowpointtext;
	sf::Text FIRETEXT;
	sf::Text ICETEXT;
	sf::Text LIGHTTEXT;
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;
	sf::RectangleShape playerstamina;
	unsigned points;
	unsigned pointkeep;
	Player* player;
	Background* bg;
	std::map<std::string, sf::Texture*> textures;
	std::map<std::string, sf::Texture*> skillpics;
	std::map<std::string, sf::Texture*> fireballs;
	std::map<std::string, sf::Texture*> icepillar;
	std::map<std::string, sf::Texture*> dragontext;
	std::vector<Enemy*> enemies;
	std::vector<lighting*> spark;
	std::vector<shielder*> guard;
	std::vector<Dragon*> dragon;
	std::vector<Ghost*> ghost;
	std::vector<Blackdragoon*> blackdragon;
	std::vector<wizard*> Wizard;
	std::vector<Bullet*> bullets;
	std::vector<Bullet*> dragonshooting;
	std::vector<fireball*> fire;
	std::vector<Skill*> skills;
	std::vector<Shield*> shield;
	std::vector<ice*> ices;

	int directioncheck;
	float spawnTimer;
	float spawnTimerMax;
	float spawnguard;
	float spawnguardmax;
	int countkill = 0;
	int countfordragon = 0;
	sf::Clock clock;
	sf::Clock skilltime;
	sf::Clock triptime;
	sf::Clock skilltimecheck;
	sf::Clock firetime;
	sf::Clock shieldtime;
	sf::Clock icetime;
	sf::Clock icetypetime;
	sf::Clock inputcheck;
	sf::Clock nextpage;
	sf::Clock dietimes;
	sf::Clock gametimes;
	sf::Clock sparktimes;
	sf::Clock startsparks;
	sf::Clock blackdragonspawn;
	sf::Clock wizardspawn;
	sf::Clock blackdragondamages;
	sf::Clock stuntimes;
	sf::Clock slowtimes;
	float skillTimer;
	float skillTimerMax;
	int type;
	int checktriple = 0;
	int canfireball = 0;
	int checkshield = 0;
	int checkice = 0;
	int checkspark = 0;
	int keepshield = 0;
	int canicepillar = 0;
	int canspark = 0;
	int checkspawn;
	bool canlighting = false;
	bool canswitch;
	bool candiesound = false;
	bool checkstun = false;
	bool checkslow = false;

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

	sf::Texture lightpics;
	sf::Sprite lightpicx;

	sf::Image icon;

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
	sf::SoundBuffer dragondie;
	sf::Sound dragondies;
	sf::SoundBuffer shieldsoundbuf;
	sf::Sound shieldsound;
	sf::SoundBuffer keepitem;
	sf::Sound keepitems;
	sf::SoundBuffer Click;
	sf::Sound clicks;
	sf::SoundBuffer switc;
	sf::Sound switcs;
	sf::SoundBuffer dead;
	sf::Sound deads;
	sf::Music music;

	//Function
	void initwindow();
	void initplayer();
	void initenemy();
	void initguard();
	void initghost();
	void initdragon();
	void initblackdragon();
	void initwizard();
	void initskill();
	void initBackground();
	void initBulletTextures();
	void initfireball();
	void initdragonfire();
	void initice();
	void initspark();
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
	void updateguard();
	void updateghost();
	void updateblackdragon();
	void updatewizard();
	void updatedragon();
	void updateskill();
	void updateshield();
	void updateInput();
	void updateBullets();
	void updatedragonshooting();
	void updateFireball();
	void updateice();
	void updatespark();
	void update();
	void updateGUI();
	void updateCollision();

	//render function
	void renderBackground();
	void renderPlayer();
	void renderGUI();
	void render();
};

