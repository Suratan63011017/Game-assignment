#pragma once
#include"Player.h"
#include"Background.h"
class Game
{
private:
	//Variables
	sf::RenderWindow* window;
	Player* player;
	Background* bg;

	//Function
	void initwindow();
	void initplayer();
	void initBackground();

public:
	//Game
	Game();
	virtual ~Game();

	//Update and render
	void run();

	//update function
	void updatePlayer();
	void update();

	//render function
	void renderBackground();
	void renderPlayer();
	void render();
};

