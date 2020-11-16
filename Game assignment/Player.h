#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
enum PlAYER_ANIMATION_STATES { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, MOVING_TOP, MOVING_DOWN }; //for check player direction 
class Player
{
private:
	//Sprite and Textures player
	sf::Sprite playersprite;
	sf::Texture playertexture;

	//Sprite and Textures spawnpoint 
	sf::Sprite spawnpointsprite;
	sf::Texture spawnpointtexture;

	sf::RectangleShape hitbox;
	sf::Vector2f velocity;
	sf::FloatRect nextpos;
	sf::RectangleShape nextbox;
	sf::FloatRect playerbounds;

	//Random spawnpoint
	int X;
	int Y;

	//attackvariables
	float attackcooldown_top;
	float attackcooldownmax_top;
	float attackcooldown_left;
	float attackcooldownmax_left;
	float attackcooldown_down;
	float attackcooldownmax_down;
	float attackcooldown_right;
	float attackcooldownmax_right;
	float attackcooldown_top_trip;
	float attackcooldownmax_top_trip;
	float attackcooldown_left_trip;
	float attackcooldownmax_left_trip;
	float attackcooldown_down_trip;
	float attackcooldownmax_down_trip;
	float attackcooldown_right_trip;
	float attackcooldownmax_right_trip;

	//hp variables
	int hp;
	int hpMax;

	int dircheck = 1;

	sf::Clock dirinput;
	//Animation 
	sf::Clock animatetimer; //to set animation time 
	short animState;
	sf::IntRect currentFrame; //for show next sprite

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

	//get position of player
	const sf::Vector2f& getPos() const;

	//get collision
	const sf::FloatRect getBounds() const;

	//Hp functions
	const int& getHp() const;
	const int& getHpMax() const;

	bool getdie();
	void setHp(const int hp);
	void loseHp(const int value);

	void doubattack(const int check);

	//Movement Update
	void updatemovement();
	void updateAnimations();
	const bool canAttack_top();
	const bool canAttack_left();
	const bool canAttack_right();
	const bool canAttack_down();
	const bool canAttack_top_trip();
	const bool canAttack_left_trip();
	const bool canAttack_right_trip();
	const bool canAttack_down_trip();

	//Player update and render
	void updateAttack();
	void updateCollision(sf::FloatRect box);
	void updated();
	void render(sf::RenderTarget& target);
};

