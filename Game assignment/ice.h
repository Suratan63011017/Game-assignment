#ifndef ICE_H
#define ICE_H
#include<SFML/Graphics.hpp>
#include<iostream>
class ice
{
private:
	//texture and sprite fire
	sf::Sprite shape;
	sf::Texture* texture;

public:
	//fire functions
	ice(sf::Texture* texture, float pos_x, float pos_y);
	virtual ~ice();

	//render and update functions
	void update();
	void render(sf::RenderTarget* target);
};
#endif // !FIREBALL_H

