#include "Bullet.h"

//Bullet functions
Bullet::Bullet(sf::Texture* texture, float pos_x, float pos_y, float dir_X, float dir_Y, float movement_speed)
{
	this->shape.setTexture(*texture);
	this->shape.setScale(0.8f, 0.8f);
	this->shape.setPosition(pos_x, pos_y);
	this->direction.x = dir_X;
	this->direction.y = dir_Y;
	this->movementSpeed = movement_speed;
}

Bullet::~Bullet()
{

}

//getBounds functions
const sf::FloatRect Bullet::getBounds() const
{
	return this->shape.getGlobalBounds();
}

//update and render functions
void Bullet::update()
{
	this->shape.move(this->movementSpeed * this->direction);
}
void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
