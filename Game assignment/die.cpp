#include "die.h"

die::die(sf::Texture* texture, float pos_x, float pos_y)
{
	this->deleted = false;
	this->shape.setTexture(*texture);
	this->currentFrame = sf::IntRect(0, 0, 112, 112);
	this->shape.setTextureRect(this->currentFrame);
	this->shape.setPosition(pos_x, pos_y);
	this->shape.setScale(0.5f, 0.5f);
}

die::~die()
{
}

const bool die::returndelete() const
{
	return this->deleted;
}

void die::update()
{
	if (this->animatetimer.getElapsedTime().asSeconds() >= 0.1f) {
		this->currentFrame.top = 0.f;
		this->currentFrame.left += 112.f;
		if (this->currentFrame.left >= 336.f) {
			this->currentFrame.left = 0;
			this->deleted = true;
		}
		this->animatetimer.restart();
		this->shape.setTextureRect(this->currentFrame);
	}
}

void die::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
