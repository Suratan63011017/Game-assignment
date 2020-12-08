#include "Ghost.h"

void Ghost::initvariables()
{
	this->hpMax = 5;
	this->hp = this->hpMax;
}

void Ghost::initghostTexture()
{
	this->ghosttexture.loadFromFile("Sprite/ghost.png");
}

void Ghost::initghostSprite()
{
	this->ghostsprite.setTexture(this->ghosttexture);
	this->currentFrame = sf::IntRect(0, 0, 47, 47);
	this->ghostsprite.setTextureRect(sf::IntRect(this->currentFrame));
	this->ghostsprite.setScale(1.2f, 1.2f);

	this->ghostHpBar.setSize(sf::Vector2f(30.f, 5.f));
	this->ghostHpBar.setFillColor(sf::Color::Red);

	this->ghostHpBarBack = this->ghostHpBar;
	this->ghostHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));
}

void Ghost::initAnimations()
{
	this->animatetimer.restart();
}

Ghost::Ghost(float pos_x, float pos_y)
{
	this->ghostposition = sf::Vector2f(pos_x, pos_y);
	this->ghostsprite.setPosition(sf::Vector2f(this->ghostposition));
	this->ghostHpBar.setPosition(sf::Vector2f(this->ghostposition.x + 5, this->ghostposition.y - 10));

	this->initghostTexture();
	this->initghostSprite();

	this->initAnimations();
	this->initvariables();
}

Ghost::~Ghost()
{
}

const sf::Vector2f& Ghost::getPos() const
{
	return this->ghostsprite.getPosition();
}

const sf::FloatRect Ghost::getBounds() const
{
	return this->ghostsprite.getGlobalBounds();
}

void Ghost::takespark(bool sparks)
{
	this->spark = sparks;
}

const bool& Ghost::getspark() const
{
	return this->spark;
}

void Ghost::takeice(bool ices)
{
	this->ice = ices;
}

const bool& Ghost::getice() const
{
	return this->ice;
}

const int& Ghost::getHp() const
{
	return this->hp;
}

const int& Ghost::getHpMax() const
{
	return this->hpMax;
}

void Ghost::setHp(const int hp)
{
	this->hp = hp;
}

void Ghost::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

void Ghost::updatemovement(int pos_x, int pos_y)
{
	if (ghostposition.y <= pos_y) { //down
		this->ghostsprite.move(0.f, 2.f);
		this->ghostposition.y += 2.f;
		this->ghostHpBar.move(0.f, 2.f);
	}
	if (ghostposition.x >= pos_x) { //left
		this->ghostsprite.move(-2.f, 0.f);
		this->ghostposition.x -= 2.f;
		this->ghostHpBar.move(-2.f, 0.f);
	}
	if (ghostposition.x <= pos_x) { //right
		this->ghostsprite.move(2.f, 0.f);
		this->ghostposition.x += 2.f;
		this->ghostHpBar.move(2.f, 0.f);
	}
	if (ghostposition.y >= pos_y) { //top
		this->ghostsprite.move(0.f, -2.f);
		this->ghostposition.y -= 2.f;
		this->ghostHpBar.move(0.f, -2.f);
	}
}

void Ghost::updateAnimations(int pos_x, int pos_y)
{
	if (this->animatetimer.getElapsedTime().asSeconds() >= 0.1f && ghostposition.x > pos_x) { //moving left
		this->currentFrame.top = 47.f;
		this->currentFrame.left += 47.f;
		if (this->currentFrame.left >= 235.f) {
			this->currentFrame.left = 0;
		}
		this->animatetimer.restart();
		this->ghostsprite.setTextureRect(this->currentFrame);
	}
	else if (this->animatetimer.getElapsedTime().asSeconds() >= 0.1f && ghostposition.x < pos_x) { //moving right
		this->currentFrame.top = 94.f;
		this->currentFrame.left += 47.f;
		if (this->currentFrame.left >= 235.f) {
			this->currentFrame.left = 0;
		}
		this->animatetimer.restart();
		this->ghostsprite.setTextureRect(this->currentFrame);
	}
	else if (this->animatetimer.getElapsedTime().asSeconds() >= 0.1f && ghostposition.y < pos_y) { //moving down
		this->currentFrame.top = 0.f;
		this->currentFrame.left += 47.f;
		if (this->currentFrame.left >= 235.f) {
			this->currentFrame.left = 0;
		}
		this->animatetimer.restart();
		this->ghostsprite.setTextureRect(this->currentFrame);
	}

	else if (this->animatetimer.getElapsedTime().asSeconds() >= 0.1f && ghostposition.y > pos_y) { //moving top
		this->currentFrame.top = 141.f;
		this->currentFrame.left += 47.f;
		if (this->currentFrame.left >= 235.f) {
			this->currentFrame.left = 0;
		}
		this->animatetimer.restart();
		this->ghostsprite.setTextureRect(this->currentFrame);
	}
}

void Ghost::updated(int pos_x, int pos_y, int movementspeed)
{
	if (movementspeed == 1) {
		this->updatemovement(pos_x, pos_y);
		this->updateAnimations(pos_x, pos_y);
		this->updateHpBar();
	}
	else {
		this->updateHpBar();
	}
}

void Ghost::updateHpBar()
{
	float hpPercent = (float)hp / (float)hpMax;
	this->ghostHpBar.setSize(sf::Vector2f(30.f * hpPercent, this->ghostHpBar.getSize().y));
}

void Ghost::render(sf::RenderTarget& target)
{
	target.draw(this->ghostsprite);
	target.draw(this->ghostHpBar);
}
