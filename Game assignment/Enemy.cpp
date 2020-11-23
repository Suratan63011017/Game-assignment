#include "Enemy.h"

void Enemy::initvariables()
{
	this->hpMax = 10;
	this->hp = this->hpMax;
}

void Enemy::initenemyTexture()
{
	this->enemytexture.loadFromFile("Sprite/Wolf.png");
}

void Enemy::initenemySprite()
{
	this->enemysprite.setTexture(this->enemytexture);
	this->currentFrame = sf::IntRect(0, 0, 80, 80);
	this->enemysprite.setTextureRect(sf::IntRect(this->currentFrame));
	this->enemysprite.setScale(1.2f, 1.2f);

	this->EnemyHpBar.setSize(sf::Vector2f(60.f, 5.f));
	this->EnemyHpBar.setFillColor(sf::Color::Red);

	this->EnemyHpBarBack = this->EnemyHpBar;
	this->EnemyHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));

	this->hitbox.setFillColor(sf::Color::Transparent);
	this->hitbox.setSize(sf::Vector2f(70.f, 70.f));

	nextbox.setSize(sf::Vector2f(70.f, 70.f));
	nextbox.setFillColor(sf::Color::Transparent);
	nextbox.setOutlineColor(sf::Color::Transparent);
	nextbox.setOutlineThickness(1.f);
}

void Enemy::initAnimations()
{
	this->animatetimer.restart();
}

Enemy::Enemy(float pos_x, float pos_y)
{
	this->enemyposition = sf::Vector2f(pos_x, pos_y);
	this->enemysprite.setPosition(sf::Vector2f(this->enemyposition));
	this->EnemyHpBar.setPosition(sf::Vector2f(this->enemyposition.x + 17, this->enemyposition.y));
	this->hitbox.setPosition(sf::Vector2f(pos_x + 13, pos_y + 20));

	this->initenemyTexture();
	this->initenemySprite();

	this->initAnimations();
	this->initvariables();
}

Enemy::~Enemy()
{
}

const sf::Vector2f& Enemy::getPos() const
{
	return this->enemysprite.getPosition();
}

const sf::FloatRect Enemy::getBounds() const
{
	return this->hitbox.getGlobalBounds();
}

const int& Enemy::getHp() const
{
	return this->hp;
}

const int& Enemy::getHpMax() const
{
	return this->hpMax;
}

void Enemy::setHp(const int hp)
{
	this->hp = hp;
}

void Enemy::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

void Enemy::setslow(const float slow)
{
	this->slowvariables = slow;
}

void Enemy::updatemovement(int pos_x, int pos_y, int movementspeed)
{
	velocity.x = 0.f;
	velocity.y = 0.f;
	if (enemyposition.y <= pos_y && abs(enemyposition.x - pos_x) <= abs(enemyposition.y - pos_y)) { //down
		velocity.y += (1.f * movementspeed * this->slowvariables);
	}
	else if (enemyposition.x >= pos_x && abs(enemyposition.x - pos_x) >= abs(enemyposition.y - pos_y)) { //left
		velocity.x -= (1.f * movementspeed * this->slowvariables);
	}
	else if (enemyposition.x <= pos_x && abs(enemyposition.x - pos_x) >= abs(enemyposition.y - pos_y)) { //right
		velocity.x += (1.f * movementspeed * this->slowvariables);
	}
	else if (enemyposition.y >= pos_y && abs(enemyposition.x - pos_x) <= abs(enemyposition.y - pos_y)) { //top
		velocity.y -= (1.f * movementspeed * this->slowvariables);
	}
	enemybounds = hitbox.getGlobalBounds();
	nextpos = enemybounds;
	hitbox.move(velocity);
	enemysprite.move(velocity);
	EnemyHpBar.move(velocity);
	nextpos.left += velocity.x;
	nextpos.top += velocity.y;
	enemyposition.x += velocity.x;
	enemyposition.y += velocity.y;
	nextbox.setPosition(nextpos.left, nextpos.top);
}

void Enemy::updateAnimations(int pos_x, int pos_y)
{
	if (this->animatetimer.getElapsedTime().asSeconds() >= 0.05f && enemyposition.x > pos_x && abs(enemyposition.x - pos_x) >= abs(enemyposition.y - pos_y)) { //moving left
		this->currentFrame.top = 80.f;
		this->currentFrame.left += 80.f;
		if (this->currentFrame.left >= 240.f) {
			this->currentFrame.left = 0;
		}
		this->animatetimer.restart();
		this->enemysprite.setTextureRect(this->currentFrame);
	}
	else if (this->animatetimer.getElapsedTime().asSeconds() >= 0.05f && enemyposition.x < pos_x && abs(enemyposition.x - pos_x) >= abs(enemyposition.y - pos_y)) { //moving right
		this->currentFrame.top = 160.f;
		this->currentFrame.left += 80.f;
		if (this->currentFrame.left >= 240.f) {
			this->currentFrame.left = 0;
		}
		this->animatetimer.restart();
		this->enemysprite.setTextureRect(this->currentFrame);
	}
	else if (this->animatetimer.getElapsedTime().asSeconds() >= 0.05f && enemyposition.y < pos_y && abs(enemyposition.x - pos_x) <= abs(enemyposition.y - pos_y)) { //moving down
		this->currentFrame.top = 0.f;
		this->currentFrame.left += 80.f;
		if (this->currentFrame.left >= 240.f) {
			this->currentFrame.left = 0;
		}
		this->animatetimer.restart();
		this->enemysprite.setTextureRect(this->currentFrame);
	}

	else if (this->animatetimer.getElapsedTime().asSeconds() >= 0.05f && enemyposition.y > pos_y && abs(enemyposition.x - pos_x) <= abs(enemyposition.y - pos_y)) { //moving top
		this->currentFrame.top = 240.f;
		this->currentFrame.left += 80.f;
		if (this->currentFrame.left >= 240.f) {
			this->currentFrame.left = 0;
		}
		this->animatetimer.restart();
		this->enemysprite.setTextureRect(this->currentFrame);
	}
}

void Enemy::updated(int pos_x, int pos_y, int movementspeed)
{
	this->updatemovement(pos_x, pos_y, movementspeed);
	this->updateAnimations(pos_x, pos_y);
	this->updateHpBar();
}

void Enemy::updateCollision(sf::FloatRect box)
{
	//bottom collision
	if (enemybounds.top < box.top
		&& enemybounds.top + enemybounds.height < box.top + box.height
		&& enemybounds.left<box.left + box.width
		&& enemybounds.left + enemybounds.width>box.left
		) {
		velocity.y = 0.f;
		if (this->enemyposition.x >= 0.f && enemyposition.x < 320.f) {
			velocity.x = 1.f;
		}
		else if (this->enemyposition.x >= 320.f && enemyposition.x < 640.f) {
			velocity.x = -1.f;
		}
		else if (this->enemyposition.x >= 640.f && enemyposition.x < 960.f) {
			velocity.x = 1.f;
		}
		else if (this->enemyposition.x >= 960.f && enemyposition.x < 1280.f) {
			velocity.x = -1.f;
		}
		hitbox.setPosition(enemybounds.left, box.top - enemybounds.height);
		enemyposition.x = enemybounds.left - 13;
		enemyposition.y = box.top - enemybounds.height - 20;
		enemysprite.setPosition(this->enemyposition);
		EnemyHpBar.setPosition(this->enemyposition.x + 17, this->enemyposition.y);

	}
	//top collision
	else if (enemybounds.top > box.top
		&& enemybounds.top + enemybounds.height > box.top + box.height
		&& enemybounds.left<box.left + box.width
		&& enemybounds.left + enemybounds.width>box.left
		) {
		velocity.y = 0.f;
		if (this->enemyposition.x >= 0.f && enemyposition.x < 320.f) {
			velocity.x = 1.f;
		}
		else if (this->enemyposition.x >= 320.f && enemyposition.x < 640.f) {
			velocity.x = -1.f;
		}
		else if (this->enemyposition.x >= 640.f && enemyposition.x < 960.f) {
			velocity.x = 1.f;
		}
		else if (this->enemyposition.x >= 960.f && enemyposition.x < 1280.f) {
			velocity.x = -1.f;
		}
		hitbox.setPosition(enemybounds.left, box.top + box.height);
		enemyposition.x = enemybounds.left - 13;
		enemyposition.y = box.top + box.height - 20;
		enemysprite.setPosition(this->enemyposition);
		EnemyHpBar.setPosition(this->enemyposition.x + 17, this->enemyposition.y);
	}
	//right collision
	else if (enemybounds.left < box.left
		&& enemybounds.left + enemybounds.width < box.left + box.width
		&& enemybounds.top<box.top + box.height
		&& enemybounds.top + enemybounds.height>box.top
		) {
		velocity.x = 0.f;
		if (this->enemyposition.y >= 0.f && enemyposition.y < 360.f) {
			velocity.y = -1.f;
		}
		else if (this->enemyposition.y >= 360.f && enemyposition.y < 720.f) {
			velocity.y = 1.f;
		}
		hitbox.setPosition(box.left - enemybounds.width, enemybounds.top);
		enemyposition.x = box.left - enemybounds.width - 13;
		enemyposition.y = enemybounds.top - 20;
		enemysprite.setPosition(this->enemyposition);
		EnemyHpBar.setPosition(this->enemyposition.x + 17, this->enemyposition.y);
	}
	//left collision
	else if (enemybounds.left > box.left
		&& enemybounds.left + enemybounds.width > box.left + box.width
		&& enemybounds.top<box.top + box.height
		&& enemybounds.top + enemybounds.height>box.top
		) {
		velocity.x = 0.f;
		if (this->enemyposition.y >= 0.f && enemyposition.y < 360.f) {
			velocity.y = -1.f;
		}
		else if (this->enemyposition.y >= 360.f && enemyposition.y < 720.f) {
			velocity.y = 1.f;
		}
		hitbox.setPosition(box.left + box.width, enemybounds.top);
		enemyposition.x = box.left + box.width - 13;
		enemyposition.y = enemybounds.top - 20;
		enemysprite.setPosition(this->enemyposition);
		EnemyHpBar.setPosition(this->enemyposition.x + 17, this->enemyposition.y);
	}
	hitbox.move(velocity);
	this->enemysprite.move(this->velocity);
	this->EnemyHpBar.move(this->velocity);
	enemyposition.x += velocity.x;
	enemyposition.y += velocity.y;
}

void Enemy::updateHpBar()
{
	float hpPercent = (float)hp / (float)hpMax;
	this->EnemyHpBar.setSize(sf::Vector2f(60.f * hpPercent, this->EnemyHpBar.getSize().y));
}

void Enemy::render(sf::RenderTarget& target)
{
	target.draw(this->hitbox);
	target.draw(this->nextbox);
	target.draw(this->enemysprite);
	target.draw(this->EnemyHpBar);
}

