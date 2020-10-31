#include "Shield.h"

void Shield::initTexture()
{
	this->texture.loadFromFile("Sprite/golden shield.png");
}

void Shield::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(0.1f, 0.1f);

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
	if (this->shieldposit.y <= 640.f && shieldposit.y <= pos_y) { //down
		this->sprite.move(0.f, 2.f);
		this->shieldposit.y += 2.f;
	}
	if (this->shieldposit.x >= 0.f && shieldposit.x >= pos_x) { //left
		this->sprite.move(-2.f, 0.f);
		this->shieldposit.x -= 2.f;
	}
	if (this->shieldposit.x <= 1000.f && shieldposit.x <= pos_x) { //right
		this->sprite.move(2.f, 0.f);
		this->shieldposit.x += 2.f;
	}
	if (this->shieldposit.y >= 0.f && shieldposit.y >= pos_y) { //top
		this->sprite.move(0.f, -2.f);
		this->shieldposit.y -= 2.f;
	}
}

void Shield::update(float pos_x, float pos_y)
{
	this->updatemovement(pos_x, pos_y);
}

void Shield::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}

