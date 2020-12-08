#include "wizard.h"

void wizard::initvariables()
{

}

void wizard::initwizardTexture()
{
	this->wizardtexture.loadFromFile("Sprite/wizard.png");
}

void wizard::initwizardSprite()
{
	this->wizardsprite.setTexture(this->wizardtexture);
	this->currentFrame = sf::IntRect(0, 0, 512, 512);
	this->wizardsprite.setTextureRect(sf::IntRect(this->currentFrame));
	this->wizardsprite.setScale(0.3f, 0.3f);
}

void wizard::initAnimations()
{
	this->animatetimer.restart();
}

wizard::wizard(float pos_x, float pos_y)
{
	this->wizardposition = sf::Vector2f(pos_x, pos_y);
	this->wizardsprite.setPosition(sf::Vector2f(this->wizardposition));

	this->initwizardTexture();
	this->initwizardSprite();

	this->initAnimations();
	this->initvariables();
}

wizard::~wizard()
{
}

const sf::FloatRect wizard::getBounds() const
{
	return this->wizardsprite.getGlobalBounds();
}


void wizard::updatemovement()
{
	this->wizardsprite.move(-3.f, 0.f);
}

void wizard::updateAnimations()
{
	if (this->animatetimer.getElapsedTime().asSeconds() >= 0.1f) {
		this->currentFrame.top = 0.f;
		this->currentFrame.left += 512.f;
		if (this->currentFrame.left >= 1536.f) {
			this->currentFrame.left = 0;
		}
		this->animatetimer.restart();
		this->wizardsprite.setTextureRect(this->currentFrame);
	}
}

void wizard::updated()
{
	this->updatemovement();
	this->updateAnimations();
}

void wizard::render(sf::RenderTarget& target)
{
	target.draw(this->wizardsprite);
}
