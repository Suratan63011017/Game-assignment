#ifndef LIGHTING_H
#define LIGHTING_H
#include<SFML/Graphics.hpp>
#include<iostream>
class lighting
{
private:
	//texture and sprite fire
	sf::Sprite sprite;
	sf::Texture texture;

	sf::Clock animatetimer;
	short animState;
	sf::IntRect currentFrame;

	void initTexture();
	void initSprite();
	void initvariables();
	void initAnimations();

public:
	//fire functions
	lighting(float pos_x, float pos_y);
	virtual ~lighting();

	const sf::FloatRect getBounds() const;

	void updateAnimations();
	//render and update functions
	void update();
	void render(sf::RenderTarget& target);
};
#endif // !FIREBALL_H

