#include "Blackdragoon.h"

void Blackdragoon::initvariables()
{

}

void Blackdragoon::initBlackdragoonTexture()
{
	this->Blackdragoontexture.loadFromFile("Sprite/Blackdragon.png");
}

void Blackdragoon::initBlackdragoonSprite()
{
	this->Blackdragoonsprite.setTexture(this->Blackdragoontexture);
	this->currentFrame = sf::IntRect(0, 0, 96, 64);
	this->Blackdragoonsprite.setTextureRect(sf::IntRect(this->currentFrame));
	this->Blackdragoonsprite.setScale(1.2f, 1.2f);
}

void Blackdragoon::initAnimations()
{
	this->animatetimer.restart();
}

Blackdragoon::Blackdragoon(float pos_x, float pos_y)
{
	this->Blackdragoonposition = sf::Vector2f(pos_x, pos_y);
	this->Blackdragoonsprite.setPosition(sf::Vector2f(this->Blackdragoonposition));

	this->initBlackdragoonTexture();
	this->initBlackdragoonSprite();

	this->initAnimations();
	this->initvariables();
}

Blackdragoon::~Blackdragoon()
{
}

const sf::FloatRect Blackdragoon::getBounds() const
{
	return this->Blackdragoonsprite.getGlobalBounds();
}


void Blackdragoon::updatemovement()
{
	this->Blackdragoonsprite.move(0.f, 3.f);
}

void Blackdragoon::updateAnimations()
{
	if (this->animatetimer.getElapsedTime().asSeconds() >= 0.1f) {
		this->currentFrame.top = 0.f;
		this->currentFrame.left += 96.f;
		if (this->currentFrame.left >= 192.f) {
			this->currentFrame.left = 0;
		}
		this->animatetimer.restart();
		this->Blackdragoonsprite.setTextureRect(this->currentFrame);
	}
}

void Blackdragoon::updated()
{
	this->updatemovement();
	this->updateAnimations();
}

void Blackdragoon::render(sf::RenderTarget& target)
{
	target.draw(this->Blackdragoonsprite);
}
