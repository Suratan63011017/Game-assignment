#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
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

	float attackcooldown_top;
	float attackcooldownmax_top;
	float attackcooldown_left;
	float attackcooldownmax_left;
	float attackcooldown_down;
	float attackcooldownmax_down;
	float attackcooldown_right;
	float attackcooldownmax_right;
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

	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;

	//Movement Update
	void updatemovement();
	void updateAnimations();
	const bool canAttack_top();
	const bool canAttack_left();
	const bool canAttack_right();
	const bool canAttack_down();

	//Player update and render
	void updateAttack();
	void updated();
	void render(sf::RenderTarget&target);
};

