#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <stdlib.h>
enum PlAYER_ANIMATION_STATES { IDLE = 0,MOVING_LEFT,MOVING_RIGHT,MOVING_TOP,MOVING_DOWN}; //for check player direction 
class Player
{
private:
	//Sprite and Textures player
	sf::Sprite playersprite;
	sf::Texture playertexture;

	//Sprite and Textures spawnpoint 
	sf::Sprite spawnpointsprite;
	sf::Texture spawnpointtexture;

	//Random spawnpoint
	int RandomX;
	int RandomY;

	//Animation 
	sf::Clock animatetimer; //to set animation time 
	short animState; 
	sf::IntRect currentFrame; //for show next sprite
	sf::Vector2f playerposition;

	//Function
	void initVariables();

	//player texture and sprite function
	void initTexture();
	void initSprite();

	//spawnpoint texture and sprite function
	void initspawntexture();
	void initspawnsprite();

	//player animation function
	void initAnimations();

public:
	//Player
	Player();
	virtual ~Player();

	//Movement Update
	void updatemovement();
	void updateAnimations();

	//Player update and render
	void updated();
	void render(sf::RenderTarget&target);
};

