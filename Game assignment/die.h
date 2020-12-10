#ifndef DIE_H
#define DIE_H
#include<SFML/Graphics.hpp>
#include<iostream>
class die
{
private:
	//texture and sprite fire
	sf::Sprite shape;
	sf::Texture* texture;

	//fire status
	sf::Vector2f direction;
	float movementSpeed;

	sf::Clock animatetimer;
	short animState;
	sf::IntRect currentFrame;

	bool deleted;

public:
	//fire functions
	die(sf::Texture* texture, float pos_x, float pos_y);
	virtual ~die();

	const bool returndelete() const;
	//render and update functions
	void update();
	void render(sf::RenderTarget* target);
};
#endif // !DIE_H
