#ifndef ENEMY_H
#define ENEMY_H

#include"Player.h"
class Enemy
{
private:
	sf::Sprite enemysprite;
	sf::Texture enemytexture;

	sf::Clock animatetimer;
	short animState;
	sf::IntRect currentFrame;
	sf::Vector2f enemyposition;

	sf::RectangleShape EnemyHpBar;
	sf::RectangleShape EnemyHpBarBack;

	sf::RectangleShape hitbox;
	sf::Vector2f velocity;
	sf::FloatRect nextpos;
	sf::RectangleShape nextbox;
	sf::FloatRect enemybounds;

	int dircheck;

	int hp;
	int hpMax;

	void initenemyTexture();
	void initenemySprite();
	void initvariables();
	void initAnimations();

public:
	Enemy(float pos_x, float pos_y);
	virtual ~Enemy();

	const sf::Vector2f& getPos() const;

	const sf::FloatRect getBounds() const;

	const int& getHp() const;
	const int& getHpMax() const;

	void setHp(const int hp);
	void loseHp(const int value);

	void updatemovement(int pos_x, int pos_y);
	void updateAnimations(int pos_x, int pos_y);
	void updated(int pos_x, int pos_y, int movementspeed);
	void updateCollision(sf::FloatRect box);
	void updateHpBar();
	void render(sf::RenderTarget& target);
};
#endif //!ENEMY_H
