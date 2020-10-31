#ifndef SHIELD_H
#define SHIELD_H
#include<SFML/Graphics.hpp>
#include<iostream>
class Shield
{
private:
	//texture and sprite bullet
	sf::Sprite sprite;
	sf::Texture texture;

	//bullet status
	sf::Vector2f shieldposit;

	void initTexture();
	void initSprite();


public:
	//bullet functions
	Shield(float pos_x, float pos_y);
	virtual ~Shield();

	//render and update functions
	void updatemovement(float pos_x, float pos_y);
	void update(float pos_x, float pos_y);
	void render(sf::RenderTarget* target);
};

#endif // !SHIELD_H