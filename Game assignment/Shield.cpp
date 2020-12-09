#include "Shield.h"

void Shield::initTexture()
{
	this->texture.loadFromFile("Sprite/golden shield.png");
}

void Shield::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(1.f, 1.f);

}

Shield::Shield(float pos_x, float pos_y)
{
	this->shieldposit = sf::Vector2f(pos_x, pos_y);
	this->sprite.setPosition(sf::Vector2f(this->shieldposit));
	this->initTexture();
	this->initSprite();
}

Shield::~Shield()
{
}

void Shield::updatemovement(float pos_x, float pos_y)
{
	this->sprite.setPosition(pos_x, pos_y);
}

void Shield::update(float pos_x, float pos_y)
{
	this->updatemovement(pos_x, pos_y);
}

void Shield::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}

