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

	int hp;
	int hpMax;

	float attackcooldown;
	float attackcooldownMax;


	int RandomX;
	int RandomY;
	void initenemyTexture();
	void initenemySprite();
	void initvariables();
	void initAnimations();

public:
	Enemy(float pos_x, float pos_y);
	virtual ~Enemy();

	const sf::FloatRect getBounds() const;

	const int& getHp() const;
	const int& getHpMax() const;

	void setHp(const int hp);
	void loseHp(const int value);

	void updatemovement(int pos_x, int pos_y);
	void updateAnimations(int pos_x, int pos_y);
	void updated(int pos_x, int pos_y);
	void updateHpBar();
	void render(sf::RenderTarget& target);
};
#endif //!ENEMY_H
