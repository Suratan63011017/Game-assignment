#include "skill.h"

Skill::Skill(sf::Texture* texture, float pos_x, float pos_y)
{
	this->shape.setTexture(*texture);
	this->shape.setScale(1.2f, 1.2f);
	this->shape.setPosition(pos_x, pos_y);
}

Skill::~Skill()
{
}

const sf::FloatRect Skill::getBounds() const
{
	return this->shape.getGlobalBounds();
}

void Skill::update()
{
}

void Skill::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
