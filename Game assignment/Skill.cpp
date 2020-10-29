#include "Skill.h"

void Skill::initvariables()
{
}

void Skill::initTexture()
{
	this->doubshottexture.loadFromFile("Sprite/doub skill.png");
}

void Skill::initSprite()
{
	this->doubshotsprite.setTexture(this->doubshottexture);
	this->doubshotsprite.setScale(1.2f, 1.2f);
	this->doubshotsprite.setPosition(sf::Vector2f(this->skillsposition));
}

Skill::Skill(float pos_x, float pos_y)
{
	this->skillsposition = sf::Vector2f(pos_x, pos_y);
	this->doubshotsprite.setPosition(sf::Vector2f(this->skillsposition));
	this->initvariables();
	this->initTexture();
	this->initSprite();
}

Skill::~Skill()
{
}

const sf::FloatRect Skill::getBounds() const
{
	return this->doubshotsprite.getGlobalBounds();
}

const int& Skill::doubshot() const
{
	return 15.f;
}

void Skill::update()
{

}

void Skill::render(sf::RenderTarget* target)
{
	target->draw(this->doubshotsprite);
}
