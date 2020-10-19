#ifndef BULLET_H
#define BULLET_H
#include<SFML/Graphics.hpp>
#include<iostream>
class Bullet
{
private:
	//texture and sprite bullet
	sf::Sprite shape;
	sf::Texture* texture;

	//bullet status
	sf::Vector2f direction;
	float movementSpeed;

public:
	//bullet functions
	Bullet(sf::Texture* texture,float pos_x,float pos_y,float dir_X,float dir_Y,float movement_speed);
	virtual ~Bullet();
	
	//getBounds functions
	const sf::FloatRect getBounds() const;

	//render and update functions
	void update();
	void render(sf::RenderTarget*target);
};

#endif // !BULLET_H
