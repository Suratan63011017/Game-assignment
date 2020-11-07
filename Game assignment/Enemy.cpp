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
}

void Enemy::initAnimations()
{
	this->animatetimer.restart();
}

Enemy::Enemy(float pos_x, float pos_y)
{
	this->enemyposition = sf::Vector2f(pos_x, pos_y);
	this->enemysprite.setPosition(sf::Vector2f(this->enemyposition));
	this->EnemyHpBar.setPosition(sf::Vector2f(this->enemyposition.x + 10, this->enemyposition.y));

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
	return this->enemysprite.getGlobalBounds();
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

void Enemy::updatemovement(int pos_x, int pos_y)
{
	if (this->enemyposition.y <= 640.f && enemyposition.y <= pos_y) { //down
		this->enemysprite.move(0.f, 1.f);
		this->enemyposition.y += 1.f;
		this->EnemyHpBar.move(0.f, 1.f);
	}
	if (this->enemyposition.x >= 0.f && enemyposition.x >= pos_x) { //left
		this->enemysprite.move(-1.f, 0.f);
		this->enemyposition.x -= 1.f;
		this->EnemyHpBar.move(-1.f, 0.f);
	}
	if (this->enemyposition.x <= 1000.f && enemyposition.x <= pos_x) { //right
		this->enemysprite.move(1.f, 0.f);
		this->enemyposition.x += 1.f;
		this->EnemyHpBar.move(1.f, 0.f);
	}
	if (this->enemyposition.y >= 0.f && enemyposition.y >= pos_y) { //top
		this->enemysprite.move(0.f, -1.f);
		this->enemyposition.y -= 1.f;
		this->EnemyHpBar.move(0.f, -1.f);
	}
}

void Enemy::updateAnimations(int pos_x, int pos_y)
{
	if (this->animatetimer.getElapsedTime().asSeconds() >= 0.05f && enemyposition.x > pos_x) { //moving left
		this->currentFrame.top = 80.f;
		this->currentFrame.left += 80.f;
		if (this->currentFrame.left >= 240.f) {
			this->currentFrame.left = 0;
		}
		this->animatetimer.restart();
		this->enemysprite.setTextureRect(this->currentFrame);
	}
	else if (this->animatetimer.getElapsedTime().asSeconds() >= 0.05f && enemyposition.x < pos_x) { //moving right
		this->currentFrame.top = 160.f;
		this->currentFrame.left += 80.f;
		if (this->currentFrame.left >= 240.f) {
			this->currentFrame.left = 0;
		}
		this->animatetimer.restart();
		this->enemysprite.setTextureRect(this->currentFrame);
	}
	else if (this->animatetimer.getElapsedTime().asSeconds() >= 0.05f && enemyposition.y < pos_y) { //moving down
		this->currentFrame.top = 0.f;
		this->currentFrame.left += 80.f;
		if (this->currentFrame.left >= 240.f) {
			this->currentFrame.left = 0;
		}
		this->animatetimer.restart();
		this->enemysprite.setTextureRect(this->currentFrame);
	}

	else if (this->animatetimer.getElapsedTime().asSeconds() >= 0.05f && enemyposition.y > pos_y) { //moving top
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
	if (movementspeed == 1) {
		this->updatemovement(pos_x, pos_y);
		this->updateAnimations(pos_x, pos_y);
		this->updateHpBar();
	}
	else {
		this->updateHpBar();
	}
}

void Enemy::updateHpBar()
{
	float hpPercent = (float)hp / (float)hpMax;
	this->EnemyHpBar.setSize(sf::Vector2f(60.f * hpPercent, this->EnemyHpBar.getSize().y));
}

void Enemy::render(sf::RenderTarget& target)
{
	target.draw(this->enemysprite);
	target.draw(this->EnemyHpBar);
}

