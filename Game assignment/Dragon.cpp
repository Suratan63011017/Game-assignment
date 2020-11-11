#include "Dragon.h"

void Dragon::initdragonTexture()
{
	this->hpMax = 100;
	this->hp = this->hpMax;
}

void Dragon::initdragonSprite()
{
	this->dragontexture.loadFromFile("Sprite/Dragon.png");
}

void Dragon::initvariables()
{
	this->dragonsprite.setTexture(this->dragontexture);
	this->currentFrame = sf::IntRect(0, 0, 100, 70);
	this->dragonsprite.setTextureRect(sf::IntRect(this->currentFrame));
	this->dragonsprite.setScale(1.5f, 1.5f);

	this->attackcooldownmax_top = 100.f;
	this->attackcooldown_top = this->attackcooldownmax_top;
	this->attackcooldownmax_left = 100.f;
	this->attackcooldown_left = this->attackcooldownmax_left;
	this->attackcooldownmax_down = 100.f;
	this->attackcooldown_down = this->attackcooldownmax_down;
	this->attackcooldownmax_right = 100.f;
	this->attackcooldown_right = this->attackcooldownmax_right;

	this->dragonHpBar.setSize(sf::Vector2f(100.f, 5.f));
	this->dragonHpBar.setFillColor(sf::Color::Red);

	this->dragonHpBarBack = this->dragonHpBar;
	this->dragonHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));
}

void Dragon::initAnimations()
{
	this->animatetimer.restart();
}

Dragon::Dragon(float pos_x, float pos_y)
{
	this->dragonposition = sf::Vector2f(pos_x, pos_y);
	this->dragonsprite.setPosition(sf::Vector2f(this->dragonposition));
	this->dragonHpBar.setPosition(sf::Vector2f(this->dragonposition.x + 10, this->dragonposition.y));

	this->initdragonTexture();
	this->initdragonSprite();

	this->initAnimations();
	this->initvariables();
}

Dragon::~Dragon()
{
}

const sf::Vector2f& Dragon::getPos() const
{
	return this->dragonsprite.getPosition();
}

const sf::FloatRect Dragon::getBounds() const
{
	return this->dragonsprite.getGlobalBounds();
}

const int& Dragon::getHp() const
{
	return this->hp;
}

const int& Dragon::getHpMax() const
{
	return this->hpMax;
}

const int& Dragon::getdir() const
{
	return this->dircheck;
}

void Dragon::setHp(const int hp)
{
	this->hp = hp;
}

void Dragon::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

const bool Dragon::canAttack_top()
{
	if (this->attackcooldown_top >= this->attackcooldownmax_top) {
		this->attackcooldown_top = 0.f;
		return true;
	}
	return false;
}

const bool Dragon::canAttack_left()
{
	if (this->attackcooldown_left >= this->attackcooldownmax_left) {
		this->attackcooldown_left = 0.f;
		return true;
	}
	return false;
}

const bool Dragon::canAttack_right()
{
	if (this->attackcooldown_right >= this->attackcooldownmax_right) {
		this->attackcooldown_right = 0.f;
		return true;
	}
	return false;
}

const bool Dragon::canAttack_down()
{
	if (this->attackcooldown_down >= this->attackcooldownmax_down) {
		this->attackcooldown_down = 0.f;
		return true;
	}
	return false;
}

void Dragon::updateAttack()
{
	if (this->attackcooldown_top < this->attackcooldownmax_top)
		this->attackcooldown_top += 0.5f;
	if (this->attackcooldown_left < this->attackcooldownmax_left)
		this->attackcooldown_left += 0.5f;
	if (this->attackcooldown_right < this->attackcooldownmax_right)
		this->attackcooldown_right += 0.5f;
	if (this->attackcooldown_down < this->attackcooldownmax_down)
		this->attackcooldown_down += 0.5f;
}

void Dragon::updatemovement(int pos_x, int pos_y)
{
	if (dragonposition.y <= pos_y && abs(dragonposition.x - pos_x) <= abs(dragonposition.y - pos_y)) { //down
		this->dragonsprite.move(0.f, 1.f);
		this->dragonposition.y += 1.f;
		this->dragonHpBar.move(0.f, 1.f);
		this->dircheck = 1;
	}
	if (dragonposition.x >= pos_x && abs(dragonposition.x - pos_x) >= abs(dragonposition.y - pos_y)) { //left
		this->dragonsprite.move(-1.f, 0.f);
		this->dragonposition.x -= 1.f;
		this->dragonHpBar.move(-1.f, 0.f);
		this->dircheck = 2;
	}
	if (dragonposition.x <= pos_x && abs(dragonposition.x - pos_x) >= abs(dragonposition.y - pos_y)) { //right
		this->dragonsprite.move(1.f, 0.f);
		this->dragonposition.x += 1.f;
		this->dragonHpBar.move(1.f, 0.f);
		this->dircheck = 3;
	}
	if (dragonposition.y >= pos_y && abs(dragonposition.x - pos_x) <= abs(dragonposition.y - pos_y)) { //top
		this->dragonsprite.move(0.f, -1.f);
		this->dragonposition.y -= 1.f;
		this->dragonHpBar.move(0.f, -1.f);
		this->dircheck = 4;
	}
}

void Dragon::updateAnimations(int pos_x, int pos_y)
{
	if (this->animatetimer.getElapsedTime().asSeconds() >= 0.05f && dragonposition.x > pos_x && abs(dragonposition.x - pos_x) >= abs(dragonposition.y - pos_y)) { //moving left
		this->currentFrame.top = 70.f;
		this->currentFrame.left += 100.f;
		if (this->currentFrame.left >= 200.f) {
			this->currentFrame.left = 0;
		}
		this->animatetimer.restart();
		this->dragonsprite.setTextureRect(this->currentFrame);
	}
	else if (this->animatetimer.getElapsedTime().asSeconds() >= 0.05f && dragonposition.x < pos_x && abs(dragonposition.x - pos_x) >= abs(dragonposition.y - pos_y)) { //moving right
		this->currentFrame.top = 140.f;
		this->currentFrame.left += 100.f;
		if (this->currentFrame.left >= 200.f) {
			this->currentFrame.left = 0;
		}
		this->animatetimer.restart();
		this->dragonsprite.setTextureRect(this->currentFrame);
	}
	else if (this->animatetimer.getElapsedTime().asSeconds() >= 0.05f && dragonposition.y < pos_y && abs(dragonposition.x - pos_x) <= abs(dragonposition.y - pos_y)) { //moving down
		this->currentFrame.top = 0.f;
		this->currentFrame.left += 100.f;
		if (this->currentFrame.left >= 200.f) {
			this->currentFrame.left = 0;
		}
		this->animatetimer.restart();
		this->dragonsprite.setTextureRect(this->currentFrame);
	}

	else if (this->animatetimer.getElapsedTime().asSeconds() >= 0.05f && dragonposition.y > pos_y && abs(dragonposition.x - pos_x) <= abs(dragonposition.y - pos_y)) { //moving top
		this->currentFrame.top = 210.f;
		this->currentFrame.left += 100.f;
		if (this->currentFrame.left >= 200.f) {
			this->currentFrame.left = 0;
		}
		this->animatetimer.restart();
		this->dragonsprite.setTextureRect(this->currentFrame);
	}
}

void Dragon::updated(int pos_x, int pos_y, int movementspeed)
{
	if (movementspeed == 1) {
		this->updatemovement(pos_x, pos_y);
		this->updateAnimations(pos_x, pos_y);
		this->updateAttack();
		this->updateHpBar();
	}
	else {
		this->updateHpBar();
	}
}

void Dragon::updateCollision()
{
	if (dircheck == 4) {
		this->dragonsprite.move(0.f, 1.f);
		this->dragonposition.y += 1.f;
		this->dragonHpBar.move(0.f, 1.f);
		this->updateAttack();
	}
	else if (dircheck == 2) {
		this->dragonsprite.move(1.f, 0.f);
		this->dragonposition.x += 1.f;
		this->dragonHpBar.move(1.f, 0.f);
		this->updateAttack();
	}
	else if (dircheck == 1) {
		this->dragonsprite.move(0.f, -1.f);
		this->dragonposition.y -= 1.f;
		this->dragonHpBar.move(0.f, -1.f);
		this->updateAttack();
	}
	else if (dircheck == 3) {
		this->dragonsprite.move(-1.f, 0.f);
		this->dragonposition.x -= 1.f;
		this->dragonHpBar.move(-1.f, 0.f);
		this->updateAttack();
	}
}

void Dragon::updateHpBar()
{
	float hpPercent = (float)hp / (float)hpMax;
	this->dragonHpBar.setSize(sf::Vector2f(100.f * hpPercent, this->dragonHpBar.getSize().y));
}

void Dragon::render(sf::RenderTarget& target)
{
	target.draw(this->dragonsprite);
	target.draw(this->dragonHpBar);
}
