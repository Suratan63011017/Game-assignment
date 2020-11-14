#include "Player.h"
//for variables
void Player::initVariables()
{
	this->animState = PlAYER_ANIMATION_STATES::IDLE; //direct status

	//attacking 
	this->attackcooldownmax_top = 30.f;
	this->attackcooldown_top = this->attackcooldownmax_top;
	this->attackcooldownmax_left = 30.f;
	this->attackcooldown_left = this->attackcooldownmax_left;
	this->attackcooldownmax_down = 30.f;
	this->attackcooldown_down = this->attackcooldownmax_down;
	this->attackcooldownmax_right = 30.f;
	this->attackcooldown_right = this->attackcooldownmax_right;
	this->attackcooldownmax_top_trip = 30.f;
	this->attackcooldown_top_trip = this->attackcooldownmax_top_trip;
	this->attackcooldownmax_left_trip = 30.f;
	this->attackcooldown_left_trip = this->attackcooldownmax_left_trip;
	this->attackcooldownmax_down_trip = 30.f;
	this->attackcooldown_down_trip = this->attackcooldownmax_down_trip;
	this->attackcooldownmax_right_trip = 30.f;
	this->attackcooldown_right_trip = this->attackcooldownmax_right_trip;

	//player hp
	this->hpMax = 100;
	this->hp = this->hpMax;

	//random spawn
	this->X = 606;
	this->Y = 292;


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
	this->currentFrame = sf::IntRect(0, 0, 68, 95);
	this->playersprite.setTextureRect(sf::IntRect(this->currentFrame));
	this->playersprite.setScale(1.f, 1.f);
	this->playersprite.setPosition(sf::Vector2f(sf::Vector2f(X, Y)));

	this->hitbox.setFillColor(sf::Color::Transparent);
	this->hitbox.setSize(sf::Vector2f(50.f, 80.f));
	this->hitbox.setPosition(sf::Vector2f(X + 10, Y + 10));

	nextbox.setSize(sf::Vector2f(50.f, 80.f));
	nextbox.setFillColor(sf::Color::Transparent);
	nextbox.setOutlineColor(sf::Color::Transparent);
	nextbox.setOutlineThickness(1.f);
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
	this->spawnpointsprite.setPosition(sf::Vector2f(X, Y + 27));
}

//settings animation timer 
void Player::initAnimations()
{
	this->animatetimer.restart();
}

//all funtion about player
Player::Player()
{
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

//get position player
const sf::Vector2f& Player::getPos() const
{
	return this->hitbox.getPosition();
}

//get colision player
const sf::FloatRect Player::getBounds() const
{
	return this->nextpos;
}

//get HP of player
const int& Player::getHp() const
{
	return this->hp;
}

//get HPMax of player
const int& Player::getHpMax() const
{
	return this->hpMax;
}

bool Player::getdie()
{
	if (this->hp == 0) {
		return true;
	}
	else return false;
}

//setting player HP
void Player::setHp(const int hp)
{
	this->hp = hp;
}

//lose Hp function
void Player::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

void Player::doubattack(const int check)
{
	if (check == 1) {
		this->attackcooldownmax_top = 15.f;
		this->attackcooldownmax_down = 15.f;
		this->attackcooldownmax_left = 15.f;
		this->attackcooldownmax_right = 15.f;
	}
	else {
		this->attackcooldownmax_top = 30.f;
		this->attackcooldownmax_down = 30.f;
		this->attackcooldownmax_left = 30.f;
		this->attackcooldownmax_right = 30.f;
	}
}

//Movement functions
void Player::updatemovement()
{
	velocity.x = 0.f;
	velocity.y = 0.f;
	this->animState = PlAYER_ANIMATION_STATES::IDLE; //not walk
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		velocity.y += 2.f;
		this->animState = PlAYER_ANIMATION_STATES::MOVING_DOWN; //go down
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		velocity.x -= 2.f;
		this->animState = PlAYER_ANIMATION_STATES::MOVING_LEFT; //go left
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		velocity.x += 2.f;
		this->animState = PlAYER_ANIMATION_STATES::MOVING_RIGHT; //go right
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		velocity.y -= 2.f;
		this->animState = PlAYER_ANIMATION_STATES::MOVING_TOP; //go top
	}
	playerbounds = hitbox.getGlobalBounds();
	nextpos = playerbounds;
	hitbox.move(velocity);
	playersprite.move(velocity);
	nextpos.left += velocity.x;
	nextpos.top += velocity.y;
	nextbox.setPosition(nextpos.left, nextpos.top);
	//leftcheck
	if (hitbox.getPosition().x < 0.f) {
		hitbox.setPosition(0.f, hitbox.getPosition().y);
		playersprite.setPosition(0.f - 10, hitbox.getPosition().y - 10);
	}
	//top check
	if (hitbox.getPosition().y < 0.f) {
		hitbox.setPosition(hitbox.getPosition().x, 0.f);
		playersprite.setPosition(hitbox.getPosition().x - 10, 0.f - 10);
	}
	//right check
	if (hitbox.getPosition().x + hitbox.getGlobalBounds().width > 1280.f) {
		hitbox.setPosition(1280.f - hitbox.getGlobalBounds().width, hitbox.getPosition().y);
		playersprite.setPosition(1280.f - hitbox.getGlobalBounds().width - 10, hitbox.getPosition().y - 10);
	}
	//bottom check
	if (hitbox.getPosition().y + hitbox.getGlobalBounds().height > 720.f) {
		hitbox.setPosition(hitbox.getPosition().x, 720.f - hitbox.getGlobalBounds().height);
		playersprite.setPosition(hitbox.getPosition().x - 10, 720.f - hitbox.getGlobalBounds().height - 10);
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

//check can attack functions
const bool Player::canAttack_top()
{
	if (this->attackcooldown_top >= this->attackcooldownmax_top) {
		this->attackcooldown_top = 0.f;
		return true;
	}
	return false;
}
const bool Player::canAttack_left()
{
	if (this->attackcooldown_left >= this->attackcooldownmax_left) {
		this->attackcooldown_left = 0.f;
		return true;
	}
	return false;
}
const bool Player::canAttack_right()
{
	if (this->attackcooldown_right >= this->attackcooldownmax_right) {
		this->attackcooldown_right = 0.f;
		return true;
	}
	return false;
}
const bool Player::canAttack_down()
{
	if (this->attackcooldown_down >= this->attackcooldownmax_down) {
		this->attackcooldown_down = 0.f;
		return true;
	}
	return false;
}

const bool Player::canAttack_top_trip()
{
	if (this->attackcooldown_top_trip >= this->attackcooldownmax_top_trip) {
		this->attackcooldown_top_trip = 0.f;
		return true;
	}
	return false;
}

const bool Player::canAttack_left_trip()
{
	if (this->attackcooldown_left_trip >= this->attackcooldownmax_left_trip) {
		this->attackcooldown_left_trip = 0.f;
		return true;
	}
	return false;
}

const bool Player::canAttack_right_trip()
{
	if (this->attackcooldown_right_trip >= this->attackcooldownmax_right_trip) {
		this->attackcooldown_right_trip = 0.f;
		return true;
	}
	return false;
}

const bool Player::canAttack_down_trip()
{
	if (this->attackcooldown_down_trip >= this->attackcooldownmax_down_trip) {
		this->attackcooldown_down_trip = 0.f;
		return true;
	}
	return false;
}

//update attack functions
void Player::updateAttack()
{
	if (this->attackcooldown_top < this->attackcooldownmax_top)
		this->attackcooldown_top += 0.5f;
	if (this->attackcooldown_left < this->attackcooldownmax_left)
		this->attackcooldown_left += 0.5f;
	if (this->attackcooldown_right < this->attackcooldownmax_right)
		this->attackcooldown_right += 0.5f;
	if (this->attackcooldown_down < this->attackcooldownmax_down)
		this->attackcooldown_down += 0.5f;
	if (this->attackcooldown_top_trip < this->attackcooldownmax_top_trip)
		this->attackcooldown_top_trip += 0.5f;
	if (this->attackcooldown_left_trip < this->attackcooldownmax_left_trip)
		this->attackcooldown_left_trip += 0.5f;
	if (this->attackcooldown_right_trip < this->attackcooldownmax_right_trip)
		this->attackcooldown_right_trip += 0.5f;
	if (this->attackcooldown_down_trip < this->attackcooldownmax_down_trip)
		this->attackcooldown_down_trip += 0.5f;
}

void Player::updateCollision(sf::FloatRect box)
{
	//bottom collision
	if (playerbounds.top < box.top
		&& playerbounds.top + playerbounds.height < box.top + box.height
		&& playerbounds.left<box.left + box.width
		&& playerbounds.left + playerbounds.width>box.left
		) {
		velocity.y = 0.f;
		hitbox.setPosition(playerbounds.left, box.top - playerbounds.height);
		playersprite.setPosition(playerbounds.left - 10, box.top - playerbounds.height - 10);
	}
	//top collision
	else if (playerbounds.top > box.top
		&& playerbounds.top + playerbounds.height > box.top + box.height
		&& playerbounds.left<box.left + box.width
		&& playerbounds.left + playerbounds.width>box.left
		) {
		velocity.y = 0.f;
		hitbox.setPosition(playerbounds.left, box.top + box.height);
		playersprite.setPosition(playerbounds.left - 10, box.top + box.height - 10);
	}
	//right collision
	else if (playerbounds.left < box.left
		&& playerbounds.left + playerbounds.width < box.left + box.width
		&& playerbounds.top<box.top + box.height
		&& playerbounds.top + playerbounds.height>box.top
		) {
		velocity.x = 0.f;
		hitbox.setPosition(box.left - playerbounds.width, playerbounds.top);
		playersprite.setPosition(box.left - playerbounds.width - 10, playerbounds.top - 10);
	}
	//left collision
	else if (playerbounds.left > box.left
		&& playerbounds.left + playerbounds.width > box.left + box.width
		&& playerbounds.top<box.top + box.height
		&& playerbounds.top + playerbounds.height>box.top
		) {
		velocity.x = 0.f;
		hitbox.setPosition(box.left + box.width, playerbounds.top);
		playersprite.setPosition(box.left + box.width - 10, playerbounds.top - 10);
	}
}

//player update
void Player::updated()
{
	this->updatemovement();
	this->updateAnimations();
	this->updateAttack();
}

//player render
void Player::render(sf::RenderTarget& target)
{
	target.draw(this->hitbox);
	target.draw(this->nextbox);
	target.draw(this->spawnpointsprite);
	target.draw(this->playersprite);
}
