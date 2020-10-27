#include "Enemy.h"

void Enemy::initvariables()
{
	this->hpMax   = 10;
	this->hp	  = 0;
	this->damage  = 1;
	this->type    = 0;
	this->points  = 5;

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
}

void Enemy::initAnimations()
{
	this->animatetimer.restart();
}

Enemy::Enemy(float pos_x,float pos_y)
{
	this->enemyposition = sf::Vector2f(pos_x, pos_y);
	this->enemysprite.setPosition(sf::Vector2f(this->enemyposition));

	this->initenemyTexture();
	this->initenemySprite();

	this->initAnimations();
}

Enemy::~Enemy()
{
}

const sf::FloatRect Enemy::getBounds() const
{
	return this->enemysprite.getGlobalBounds();
}

void Enemy::updatemovement(int pos_x,int pos_y)
{
	if (this->enemyposition.y <= 640.f&&enemyposition.y<=pos_y) { //down
		this->enemysprite.move(0.f, 1.f);
		this->enemyposition.y += 1.f;
	}
	if (this->enemyposition.x >= 0.f && enemyposition.x >= pos_x) { //left
		this->enemysprite.move(-1.f, 0.f);
		this->enemyposition.x -= 1.f;
	}
	if (this->enemyposition.x <= 1000.f && enemyposition.x <= pos_x) { //right
		this->enemysprite.move(1.f, 0.f);
		this->enemyposition.x += 1.f;
	}
	if (this->enemyposition.y >= 0.f && enemyposition.y >= pos_y) { //top
		this->enemysprite.move(0.f, -1.f);
		this->enemyposition.y -= 1.f;
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

void Enemy::updated(int pos_x, int pos_y)
{
	this->updatemovement(pos_x,pos_y);
	this->updateAnimations(pos_x,pos_y);
}

void Enemy::render(sf::RenderTarget& target)
{
	target.draw(this->enemysprite);
}

