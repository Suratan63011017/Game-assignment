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

	int hp;
	int hpMax;
	int damage;
	int points;
	int type;

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
	void updatemovement(int pos_x, int pos_y);
	void updateAnimations(int pos_x, int pos_y);
	void updated(int pos_x, int pos_y);
	void render(sf::RenderTarget& target);
};
#endif //!ENEMY_H
