#include "ice.h"

ice::ice(sf::Texture* texture, float pos_x, float pos_y)
{
	this->shape.setTexture(*texture);
	this->shape.setScale(0.7f, 0.7f);
	this->shape.setPosition(pos_x, pos_y);
}

ice::~ice()
{
}

void ice::update()
{
}

void ice::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
