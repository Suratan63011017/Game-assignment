#include "wizard.h"

void wizard::initvariables()
{
	this->type = 1 + rand() % 3;
}

void wizard::initwizardTexture()
{
	this->wizardtexture.loadFromFile("Sprite/wizard.png");
}

void wizard::initwizardSprite()
{
	this->wizardsprite.setTexture(this->wizardtexture);
	this->currentFrame = sf::IntRect(0, 0, 128, 128);
	this->wizardsprite.setTextureRect(sf::IntRect(this->currentFrame));
	this->wizardsprite.setScale(1.f, 1.f);

	this->hitbox.setSize(sf::Vector2f(40.f, 50.f));
	this->hitbox.setFillColor(sf::Color::Transparent);
	this->hitbox.setPosition(sf::Vector2f(this->wizardsprite.getPosition().x + 40, this->wizardsprite.getPosition().y + 60));
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
	return this->hitbox.getGlobalBounds();
}


const int wizard::gettype() const
{
	return this->type;
}

void wizard::updatemovement()
{
	this->wizardsprite.move(-3.f, 0.f);
	this->hitbox.setPosition(this->wizardsprite.getPosition().x + 50, this->wizardsprite.getPosition().y + 65);
}

void wizard::updateAnimations()
{
	if (this->animatetimer.getElapsedTime().asSeconds() >= 0.1f) {
		if (this->type == 1) {
			this->currentFrame.top = 0.f;
		}
		else if (this->type == 2) {
			this->currentFrame.top = 128.f;
		}
		else if (this->type == 3) {
			this->currentFrame.top = 256.f;
		}
		this->currentFrame.left += 128.f;
		if (this->currentFrame.left >= 384.f) {
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
	target.draw(this->hitbox);
	target.draw(this->wizardsprite);
}
