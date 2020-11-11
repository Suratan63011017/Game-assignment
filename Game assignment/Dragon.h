#ifndef DRAGON_H
#define DRAGON_H

#include"Player.h"
#include<math.h>
class Dragon
{
private:
	sf::Sprite dragonsprite;
	sf::Texture dragontexture;

	sf::Clock animatetimer;
	short animState;
	sf::IntRect currentFrame;
	sf::Vector2f dragonposition;

	sf::RectangleShape dragonHpBar;
	sf::RectangleShape dragonHpBarBack;

	int dircheck;

	int hp;
	int hpMax;

	void initdragonTexture();
	void initdragonSprite();
	void initvariables();
	void initAnimations();

	float attackcooldown_top;
	float attackcooldownmax_top;
	float attackcooldown_left;
	float attackcooldownmax_left;
	float attackcooldown_down;
	float attackcooldownmax_down;
	float attackcooldown_right;
	float attackcooldownmax_right;

public:
	Dragon(float pos_x, float pos_y);
	virtual ~Dragon();

	const sf::Vector2f& getPos() const;

	const sf::FloatRect getBounds() const;

	const int& getHp() const;
	const int& getHpMax() const;

	const int& getdir() const;

	void setHp(const int hp);
	void loseHp(const int value);

	const bool canAttack_top();
	const bool canAttack_left();
	const bool canAttack_right();
	const bool canAttack_down();


	void updateAttack();
	void updatemovement(int pos_x, int pos_y);
	void updateAnimations(int pos_x, int pos_y);
	void updated(int pos_x, int pos_y, int movementspeed);
	void updateCollision();
	void updateHpBar();
	void render(sf::RenderTarget& target);
};

#endif //!DRAGON_H