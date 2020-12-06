#ifndef shielder_H
#define shielder_H

#include"Player.h"

class shielder
{
private:
	sf::Sprite shieldersprite;
	sf::Texture shieldertexture;
	sf::Sprite shields;
	sf::Texture shieldt;

	sf::Clock Slowtimes;
	sf::Clock animatetimer;
	sf::Clock shieldtimes;

	short animState;
	sf::IntRect currentFrame;
	sf::Vector2f shielderposition;

	sf::RectangleShape shielderHpBar;
	sf::RectangleShape shielderHpBarBack;

	sf::RectangleShape hitbox;
	sf::Vector2f velocity;
	sf::FloatRect nextpos;
	sf::RectangleShape nextbox;
	sf::FloatRect shielderbounds;

	int dircheck;

	int hp;
	int hpMax;

	float slowvariables = 1;

	void initshielderTexture();
	void initshielderSprite();
	void initvariables();
	void initAnimations();

public:
	shielder(float pos_x, float pos_y);
	virtual ~shielder();

	const sf::Vector2f& getPos() const;

	const sf::FloatRect getBounds() const;

	const int& getHp() const;
	const int& getHpMax() const;

	void setHp(const int hp);
	void loseHp(const int value);

	void setslow(const float slow);

	void updatemovement(int pos_x, int pos_y, int movementspeed);
	void updateAnimations(int pos_x, int pos_y, int cananimate);
	void updated(int pos_x, int pos_y, int movementspeed);
	void updateCollision(sf::FloatRect box);
	void updateHpBar();
	void render(sf::RenderTarget& target);
};
#endif //!SHEILDER_H
