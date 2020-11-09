#ifndef GHOST_H
#define GHOST_H

#include"Player.h"
class Ghost
{
private:
	sf::Sprite ghostsprite;
	sf::Texture ghosttexture;

	sf::Clock animatetimer;
	short animState;
	sf::IntRect currentFrame;
	sf::Vector2f ghostposition;

	sf::RectangleShape ghostHpBar;
	sf::RectangleShape ghostHpBarBack;

	int dircheck;

	int hp;
	int hpMax;

	void initghostTexture();
	void initghostSprite();
	void initvariables();
	void initAnimations();

public:
	Ghost(float pos_x, float pos_y);
	virtual ~Ghost();

	const sf::Vector2f& getPos() const;

	const sf::FloatRect getBounds() const;

	const int& getHp() const;
	const int& getHpMax() const;

	void setHp(const int hp);
	void loseHp(const int value);

	void updatemovement(int pos_x, int pos_y);
	void updateAnimations(int pos_x, int pos_y);
	void updated(int pos_x, int pos_y, int movementspeed);
	void updateHpBar();
	void render(sf::RenderTarget& target);
};
#endif //!GHOST_H
