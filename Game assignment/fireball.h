#ifndef FIREBALL_H
#define FIREBALL_H
#include<SFML/Graphics.hpp>
#include<iostream>
class fireball
{
private:
	//texture and sprite fire
	sf::Sprite shape;
	sf::Texture* texture;

	//fire status
	sf::Vector2f direction;
	float movementSpeed;

public:
	//fire functions
	fireball(sf::Texture* texture, float pos_x, float pos_y, float dir_X, float dir_Y, float movement_speed,int x,int y);
	virtual ~fireball();

	//getBounds functions
	const sf::FloatRect getBounds() const;

	//render and update functions
	void update();
	void render(sf::RenderTarget* target);
};
#endif // !FIREBALL_H
