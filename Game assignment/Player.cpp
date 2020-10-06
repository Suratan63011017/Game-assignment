#include "Player.h"
//for check direction
void Player::initVariables()
{
	this->animState = PlAYER_ANIMATION_STATES::IDLE;
}

//include picture from files
void Player::initTexture()
{
	this->playertexture.loadFromFile("Sprite/Player.png");
}

//settings sprites of player
void Player::initSprite()
{
	this->playersprite.setTexture(this->playertexture);
	this->currentFrame = sf::IntRect(0, 0, 68,95 );
	this->playersprite.setTextureRect(sf::IntRect(this->currentFrame));
	this->playersprite.setScale(1.f, 1.f);
	this->playerposition = sf::Vector2f(RandomX, RandomY);
	this->playersprite.setPosition(sf::Vector2f(this->playerposition));
}

//include spawn point pics from files
void Player::initspawntexture()
{
	this->spawnpointtexture.loadFromFile("Sprite/Summoning ring.png");
}

//settings sprites of spawnpoint 
void Player::initspawnsprite()
{
	this->spawnpointsprite.setTexture(this->spawnpointtexture);
	this->spawnpointsprite.setTextureRect(sf::IntRect(0, 0, 68, 68));
	this->spawnpointsprite.setScale(1.f, 1.f);
	this->spawnpointsprite.setPosition(sf::Vector2f(RandomX, RandomY+27));
}

//settings animation timer 
void Player::initAnimations()
{
	this->animatetimer.restart();
}

//all funtion about player
Player::Player()
{
	//random spawn
	srand(time(NULL));
	this->RandomX = rand() % 1012;
	this->RandomY = rand() % 625;
	
	//variables
	this->initVariables();
	
	//spawnpoint sprite and texture
	this->initspawntexture();
	this->initspawnsprite();

	//player sprite and texture
	this->initTexture();
	this->initSprite();

	//player animations
	this->initAnimations();
}

Player::~Player()
{
}

//Movement functions
void Player::updatemovement()
{
	this->animState = PlAYER_ANIMATION_STATES::IDLE; //not walk
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (this->playerposition.y <= 625.f) {
			this->playersprite.move(0.f, 2.f);
			this->playerposition.y += 2.f;
		}
		this->animState = PlAYER_ANIMATION_STATES::MOVING_DOWN; //go down
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (this->playerposition.x >= 0) {
			this->playersprite.move(-2.f, 0.f);
			this->playerposition.x -= 2.f;
		}
		this->animState = PlAYER_ANIMATION_STATES::MOVING_LEFT; //go left
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (this->playerposition.x <= 1012.f) {
			this->playersprite.move(2.f, 0.f);
			this->playerposition.x += 2.f;
		}
		this->animState = PlAYER_ANIMATION_STATES::MOVING_RIGHT; //go right
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (this->playerposition.y >= 0.f) {
			this->playersprite.move(0.f, -2.f);
			this->playerposition.y -= 2.f;
		}
		this->animState = PlAYER_ANIMATION_STATES::MOVING_TOP; //go top
	}
}

//function for play next sprite
void Player::updateAnimations()
{
	if (this->animState == PlAYER_ANIMATION_STATES::IDLE) {}
	else if (this->animState == PlAYER_ANIMATION_STATES::MOVING_DOWN) {
		if (this->animatetimer.getElapsedTime().asSeconds() >= 0.1f) {
			this->currentFrame.top = 0.f;
			this->currentFrame.left += 68.f;
			if (this->currentFrame.left >= 137.f) {
				this->currentFrame.left = 0;
			}
			this->animatetimer.restart();
			this->playersprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animState == PlAYER_ANIMATION_STATES::MOVING_LEFT) {
		if (this->animatetimer.getElapsedTime().asSeconds() >= 0.1f) {
			this->currentFrame.top = 95.f;
			this->currentFrame.left += 68.f;
			if (this->currentFrame.left >= 137.f) {
				this->currentFrame.left = 0;
			}
			this->animatetimer.restart();
			this->playersprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animState == PlAYER_ANIMATION_STATES::MOVING_RIGHT) {
		if (this->animatetimer.getElapsedTime().asSeconds() >= 0.1f) {
			this->currentFrame.top = 190.f;
			this->currentFrame.left += 68.f;
			if (this->currentFrame.left >= 137.f) {
				this->currentFrame.left = 0;
			}
			this->animatetimer.restart();
			this->playersprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animState == PlAYER_ANIMATION_STATES::MOVING_TOP) {
		if (this->animatetimer.getElapsedTime().asSeconds() >= 0.1f) {
			this->currentFrame.top = 285.f;
			this->currentFrame.left += 68.f;
			if (this->currentFrame.left >= 137.f) {
				this->currentFrame.left = 0;
			}
			this->animatetimer.restart();
			this->playersprite.setTextureRect(this->currentFrame);
		}
	}
}

//player update
void Player::updated()
{
	this->updatemovement();
	this->updateAnimations();
}

//player render
void Player::render(sf::RenderTarget& target)
{
	target.draw(this->spawnpointsprite);
	target.draw(this->playersprite);
}
