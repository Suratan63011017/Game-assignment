#include "lighting.h"

void lighting::initTexture()
{
	this->texture.loadFromFile("Sprite/lighting.png");
}

void lighting::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->currentFrame = sf::IntRect(0, 0, 184, 188);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(0.5f, 0.5f);
}

void lighting::initvariables()
{
}

void lighting::initAnimations()
{
	this->animatetimer.restart();
}

lighting::lighting(float pos_x, float pos_y)
{
	this->sprite.setPosition(sf::Vector2f(pos_x, pos_y));
	this->initTexture();
	this->initSprite();
	this->initvariables();
	this->initAnimations();
}

lighting::~lighting()
{

}

const sf::FloatRect lighting::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

void lighting::updateAnimations()
{
	if (this->animatetimer.getElapsedTime().asSeconds() >= 0.05f) {
		this->currentFrame.top = 0.f;
		this->currentFrame.left += 184.f;
		if (this->currentFrame.left >= 736.f) {
			this->currentFrame.top += 188.f;
		}
		this->animatetimer.restart();
		this->sprite.setTextureRect(this->currentFrame);
	}
}

void lighting::update()
{
	this->updateAnimations();
}

void lighting::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
