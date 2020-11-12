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

	this->hitbox.setFillColor(sf::Color::Transparent);
	this->hitbox.setSize(sf::Vector2f(90.f, 60.f));

	nextbox.setSize(sf::Vector2f(90.f, 60.f));
	nextbox.setFillColor(sf::Color::Transparent);
	nextbox.setOutlineColor(sf::Color::Transparent);
	nextbox.setOutlineThickness(1.f);
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
	this->hitbox.setPosition(sf::Vector2f(pos_x + 5, pos_y + 5));

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
	return this->hitbox.getGlobalBounds();
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
	velocity.x = 0.f;
	velocity.y = 0.f;
	if (dragonposition.y <= pos_y && abs(dragonposition.x - pos_x) <= abs(dragonposition.y - pos_y)) { //down
		velocity.y += 1.f;
		this->dircheck = 1;
	}
	else if (dragonposition.x >= pos_x && abs(dragonposition.x - pos_x) >= abs(dragonposition.y - pos_y)) { //left
		velocity.x -= 1.f;
		this->dircheck = 2;
	}
	else if (dragonposition.x <= pos_x && abs(dragonposition.x - pos_x) >= abs(dragonposition.y - pos_y)) { //right
		velocity.x += 1.f;
		this->dircheck = 3;
	}
	else if (dragonposition.y >= pos_y && abs(dragonposition.x - pos_x) <= abs(dragonposition.y - pos_y)) { //top
		velocity.y -= 1.f;
		this->dircheck = 4;
	}
	dragonbounds = hitbox.getGlobalBounds();
	nextpos = dragonbounds;
	hitbox.move(velocity);
	dragonsprite.move(velocity);
	dragonHpBar.move(velocity);
	nextpos.left += velocity.x;
	nextpos.top += velocity.y;
	dragonposition.x += velocity.x;
	dragonposition.y += velocity.y;
	nextbox.setPosition(nextpos.left, nextpos.top);
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

void Dragon::updateCollision(sf::FloatRect box)
{
	//bottom collision
	if (dragonbounds.top < box.top
		&& dragonbounds.top + dragonbounds.height < box.top + box.height
		&& dragonbounds.left<box.left + box.width
		&& dragonbounds.left + dragonbounds.width>box.left
		) {
		velocity.y = 0.f;
		hitbox.setPosition(dragonbounds.left, box.top - dragonbounds.height);
		dragonposition.x = dragonbounds.left - 5;
		dragonposition.y = box.top - dragonbounds.height - 5;
		dragonsprite.setPosition(this->dragonposition);
		dragonHpBar.setPosition(this->dragonposition.x + 10, this->dragonposition.y);

	}
	//top collision
	else if (dragonbounds.top > box.top
		&& dragonbounds.top + dragonbounds.height > box.top + box.height
		&& dragonbounds.left<box.left + box.width
		&& dragonbounds.left + dragonbounds.width>box.left
		) {
		velocity.y = 0.f;
		hitbox.setPosition(dragonbounds.left, box.top + box.height);
		dragonposition.x = dragonbounds.left - 5;
		dragonposition.y = box.top + box.height - 5;
		dragonsprite.setPosition(this->dragonposition);
		dragonHpBar.setPosition(this->dragonposition.x + 10, this->dragonposition.y);
	}
	//right collision
	else if (dragonbounds.left < box.left
		&& dragonbounds.left + dragonbounds.width < box.left + box.width
		&& dragonbounds.top<box.top + box.height
		&& dragonbounds.top + dragonbounds.height>box.top
		) {
		velocity.x = 0.f;
		hitbox.setPosition(box.left - dragonbounds.width, dragonbounds.top);
		dragonposition.x = box.left - dragonbounds.width - 5;
		dragonposition.y = dragonbounds.top - 5;
		dragonsprite.setPosition(this->dragonposition);
		dragonHpBar.setPosition(this->dragonposition.x + 10, this->dragonposition.y);
	}
	//left collision
	else if (dragonbounds.left > box.left
		&& dragonbounds.left + dragonbounds.width > box.left + box.width
		&& dragonbounds.top<box.top + box.height
		&& dragonbounds.top + dragonbounds.height>box.top
		) {
		velocity.x = 0.f;
		hitbox.setPosition(box.left + box.width, dragonbounds.top);
		dragonposition.x = box.left + box.width - 5;
		dragonposition.y = dragonbounds.top - 5;
		dragonsprite.setPosition(this->dragonposition);
		dragonHpBar.setPosition(this->dragonposition.x + 10, this->dragonposition.y);
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
