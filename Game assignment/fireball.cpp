#include "fireball.h"

fireball::fireball(sf::Texture* texture, float pos_x, float pos_y, float dir_X, float dir_Y, float movement_speed, int x, int y)
{
	this->shape.setTexture(*texture);
	this->shape.setScale(2.0f * x, 2.0f * y);
	this->shape.setPosition(pos_x, pos_y);
	this->direction.x = dir_X;
	this->direction.y = dir_Y;
	this->movementSpeed = movement_speed;
}

fireball::~fireball()
{
}

const sf::FloatRect fireball::getBounds() const
{
	return this->shape.getGlobalBounds();
}

void fireball::update()
{
	this->shape.move(this->movementSpeed * this->direction);
}

void fireball::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
