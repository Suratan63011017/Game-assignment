#include "shielder.h"
void shielder::initvariables()
{
	this->hpMax = 20;
	this->hp = this->hpMax;
}

void shielder::initshielderTexture()
{
	this->shieldertexture.loadFromFile("Sprite/Guard_Sprites.png");
	this->shieldt.loadFromFile("Sprite/blueshield.png");
}

void shielder::initshielderSprite()
{
	this->shieldersprite.setTexture(this->shieldertexture);
	this->currentFrame = sf::IntRect(0, 0, 38, 38);
	this->shieldersprite.setTextureRect(sf::IntRect(this->currentFrame));
	this->shieldersprite.setScale(2.0f, 2.0f);

	this->shielderHpBar.setSize(sf::Vector2f(60.f, 5.f));
	this->shielderHpBar.setFillColor(sf::Color::Red);

	this->shielderHpBarBack = this->shielderHpBar;
	this->shielderHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));

	this->shields.setTexture(this->shieldt);
	this->shields.setScale(0.05f, 0.05f);

	this->hitbox.setFillColor(sf::Color::Transparent);
	this->hitbox.setSize(sf::Vector2f(70.f, 70.f));

	nextbox.setSize(sf::Vector2f(70.f, 70.f));
	nextbox.setFillColor(sf::Color::Transparent);
	nextbox.setOutlineColor(sf::Color::Transparent);
	nextbox.setOutlineThickness(1.f);
}

void shielder::initAnimations()
{
	this->animatetimer.restart();
}

shielder::shielder(float pos_x, float pos_y)
{
	this->shielderposition = sf::Vector2f(pos_x, pos_y);
	this->shieldersprite.setPosition(sf::Vector2f(this->shielderposition));
	this->shielderHpBar.setPosition(sf::Vector2f(this->shielderposition.x + 17, this->shielderposition.y));
	this->shields.setPosition(sf::Vector2f(this->shielderposition.x + 23, this->shielderposition.y - 13));
	this->hitbox.setPosition(sf::Vector2f(pos_x + 3, pos_y + 10));

	this->initshielderTexture();
	this->initshielderSprite();

	this->initAnimations();
	this->initvariables();
}

shielder::~shielder()
{
}

const sf::Vector2f& shielder::getPos() const
{
	return this->shieldersprite.getPosition();
}

const sf::FloatRect shielder::getBounds() const
{
	return this->hitbox.getGlobalBounds();
}

const int& shielder::getHp() const
{
	return this->hp;
}

const int& shielder::getHpMax() const
{
	return this->hpMax;
}

void shielder::setHp(const int hp)
{
	this->hp = hp;
}

void shielder::loseHp(const int value)
{
	if (this->shieldtimes.getElapsedTime().asSeconds() > 2.f) {
		this->hp -= value;
		if (this->hp < 0)
			this->hp = 0;
	}
}

void shielder::setslow(const float slow)
{
	this->slowvariables = slow;
}

void shielder::updatemovement(int pos_x, int pos_y, int movementspeed)
{
	velocity.x = 0.f;
	velocity.y = 0.f;
	if (shielderposition.y <= pos_y && abs(shielderposition.x - pos_x) <= abs(shielderposition.y - pos_y)) { //down
		velocity.y += (0.5f * movementspeed * this->slowvariables);
	}
	else if (shielderposition.x >= pos_x && abs(shielderposition.x - pos_x) >= abs(shielderposition.y - pos_y)) { //left
		velocity.x -= (0.5f * movementspeed * this->slowvariables);
	}
	else if (shielderposition.x <= pos_x && abs(shielderposition.x - pos_x) >= abs(shielderposition.y - pos_y)) { //right
		velocity.x += (0.5f * movementspeed * this->slowvariables);
	}
	else if (shielderposition.y >= pos_y && abs(shielderposition.x - pos_x) <= abs(shielderposition.y - pos_y)) { //top
		velocity.y -= (0.5f * movementspeed * this->slowvariables);
	}
	shielderbounds = hitbox.getGlobalBounds();
	nextpos = shielderbounds;
	hitbox.move(velocity);
	shieldersprite.move(velocity);
	shielderHpBar.move(velocity);
	shields.move(velocity);
	nextpos.left += velocity.x;
	nextpos.top += velocity.y;
	shielderposition.x += velocity.x;
	shielderposition.y += velocity.y;
	nextbox.setPosition(nextpos.left, nextpos.top);
}

void shielder::updateAnimations(int pos_x, int pos_y, int cananimate)
{
	if (cananimate == 0) {}
	else {
		if (this->animatetimer.getElapsedTime().asSeconds() >= 0.5f && shielderposition.x > pos_x && abs(shielderposition.x - pos_x) >= abs(shielderposition.y - pos_y)) { //moving left
			this->currentFrame.left = 38.f;
			this->currentFrame.top += 38.f;
			if (this->currentFrame.top >= 76.f) {
				this->currentFrame.top = 0;
			}
			this->animatetimer.restart();
			this->shieldersprite.setTextureRect(this->currentFrame);
		}
		else if (this->animatetimer.getElapsedTime().asSeconds() >= 0.5f && shielderposition.x < pos_x && abs(shielderposition.x - pos_x) >= abs(shielderposition.y - pos_y)) { //moving right
			this->currentFrame.left = 114.f;
			this->currentFrame.top += 38.f;
			if (this->currentFrame.top >= 76.f) {
				this->currentFrame.top = 0;
			}
			this->animatetimer.restart();
			this->shieldersprite.setTextureRect(this->currentFrame);
		}
		else if (this->animatetimer.getElapsedTime().asSeconds() >= 0.5f && shielderposition.y < pos_y && abs(shielderposition.x - pos_x) <= abs(shielderposition.y - pos_y)) { //moving down
			this->currentFrame.left = 0.f;
			this->currentFrame.top += 38.f;
			if (this->currentFrame.top >= 76.f) {
				this->currentFrame.top = 0;
			}
			this->animatetimer.restart();
			this->shieldersprite.setTextureRect(this->currentFrame);
		}

		else if (this->animatetimer.getElapsedTime().asSeconds() >= 0.5f && shielderposition.y > pos_y && abs(shielderposition.x - pos_x) <= abs(shielderposition.y - pos_y)) { //moving top
			this->currentFrame.left = 76.f;
			this->currentFrame.top += 38.f;
			if (this->currentFrame.top >= 76.f) {
				this->currentFrame.top = 0;
			}
			this->animatetimer.restart();
			this->shieldersprite.setTextureRect(this->currentFrame);
		}
	}
}

void shielder::updated(int pos_x, int pos_y, int movementspeed)
{
	this->updatemovement(pos_x, pos_y, movementspeed);
	this->updateAnimations(pos_x, pos_y, movementspeed);
	this->updateHpBar();
	if (this->shieldtimes.getElapsedTime().asSeconds() >= 7.f) {
		this->shieldtimes.restart();
	}
}

void shielder::updateCollision(sf::FloatRect box)
{
	//bottom collision
	if (shielderbounds.top < box.top
		&& shielderbounds.top + shielderbounds.height < box.top + box.height
		&& shielderbounds.left<box.left + box.width
		&& shielderbounds.left + shielderbounds.width>box.left
		) {
		velocity.y = 0.f;
		if (this->shielderposition.x >= 0.f && shielderposition.x < 320.f) {
			velocity.x = 1.f;
		}
		else if (this->shielderposition.x >= 320.f && shielderposition.x < 640.f) {
			velocity.x = -1.f;
		}
		else if (this->shielderposition.x >= 640.f && shielderposition.x < 960.f) {
			velocity.x = 1.f;
		}
		else if (this->shielderposition.x >= 960.f && shielderposition.x < 1280.f) {
			velocity.x = -1.f;
		}
		hitbox.setPosition(shielderbounds.left, box.top - shielderbounds.height);
		shielderposition.x = shielderbounds.left - 3;
		shielderposition.y = box.top - shielderbounds.height - 10;
		shieldersprite.setPosition(this->shielderposition);
		shielderHpBar.setPosition(this->shielderposition.x + 17, this->shielderposition.y);
		shields.setPosition(this->shielderposition.x + 23, this->shielderposition.y - 13);

	}
	//top collision
	else if (shielderbounds.top > box.top
		&& shielderbounds.top + shielderbounds.height > box.top + box.height
		&& shielderbounds.left<box.left + box.width
		&& shielderbounds.left + shielderbounds.width>box.left
		) {
		velocity.y = 0.f;
		if (this->shielderposition.x >= 0.f && shielderposition.x < 320.f) {
			velocity.x = 1.f;
		}
		else if (this->shielderposition.x >= 320.f && shielderposition.x < 640.f) {
			velocity.x = -1.f;
		}
		else if (this->shielderposition.x >= 640.f && shielderposition.x < 960.f) {
			velocity.x = 1.f;
		}
		else if (this->shielderposition.x >= 960.f && shielderposition.x < 1280.f) {
			velocity.x = -1.f;
		}
		hitbox.setPosition(shielderbounds.left, box.top + box.height);
		shielderposition.x = shielderbounds.left - 3;
		shielderposition.y = box.top + box.height - 10;
		shieldersprite.setPosition(this->shielderposition);
		shielderHpBar.setPosition(this->shielderposition.x + 17, this->shielderposition.y);
		shields.setPosition(this->shielderposition.x + 23, this->shielderposition.y - 13);
	}
	//right collision
	else if (shielderbounds.left < box.left
		&& shielderbounds.left + shielderbounds.width < box.left + box.width
		&& shielderbounds.top<box.top + box.height
		&& shielderbounds.top + shielderbounds.height>box.top
		) {
		velocity.x = 0.f;
		if (this->shielderposition.y >= 0.f && shielderposition.y < 360.f && this->shielderposition.x >= 0 && this->shielderposition.x < 320.f) {
			velocity.y = -1.f;
		}
		else if (this->shielderposition.y >= 0.f && shielderposition.y < 360.f && this->shielderposition.x >= 320 && this->shielderposition.x < 640.f) {
			velocity.y = 1.f;
		}
		else if (this->shielderposition.y >= 0.f && shielderposition.y < 360.f && this->shielderposition.x >= 640 && this->shielderposition.x < 960.f) {
			velocity.y = -1.f;
		}
		else if (this->shielderposition.y >= 0.f && shielderposition.y < 360.f && this->shielderposition.x >= 960 && this->shielderposition.x < 1280.f) {
			velocity.y = 1.f;
		}
		else if (this->shielderposition.y >= 360.f && shielderposition.y < 720.f && this->shielderposition.x >= 0 && this->shielderposition.x < 320.f) {
			velocity.y = -1.f;
		}
		else if (this->shielderposition.y >= 360.f && shielderposition.y < 720.f && this->shielderposition.x >= 320 && this->shielderposition.x < 640.f) {
			velocity.y = 1.f;
		}
		else if (this->shielderposition.y >= 360.f && shielderposition.y < 720.f && this->shielderposition.x >= 640 && this->shielderposition.x < 960.f) {
			velocity.y = -1.f;
		}
		else if (this->shielderposition.y >= 360.f && shielderposition.y < 720.f && this->shielderposition.x >= 960 && this->shielderposition.x < 1280.f) {
			velocity.y = 1.f;
		}
		hitbox.setPosition(box.left - shielderbounds.width, shielderbounds.top);
		shielderposition.x = box.left - shielderbounds.width - 3;
		shielderposition.y = shielderbounds.top - 10;
		shieldersprite.setPosition(this->shielderposition);
		shielderHpBar.setPosition(this->shielderposition.x + 17, this->shielderposition.y);
		shields.setPosition(this->shielderposition.x + 23, this->shielderposition.y - 13);
	}
	//left collision
	else if (shielderbounds.left > box.left
		&& shielderbounds.left + shielderbounds.width > box.left + box.width
		&& shielderbounds.top<box.top + box.height
		&& shielderbounds.top + shielderbounds.height>box.top
		) {
		velocity.x = 0.f;
		if (this->shielderposition.y >= 0.f && shielderposition.y < 360.f && this->shielderposition.x >= 0 && this->shielderposition.x < 320.f) {
			velocity.y = -1.f;
		}
		else if (this->shielderposition.y >= 0.f && shielderposition.y < 360.f && this->shielderposition.x >= 320 && this->shielderposition.x < 640.f) {
			velocity.y = 1.f;
		}
		else if (this->shielderposition.y >= 0.f && shielderposition.y < 360.f && this->shielderposition.x >= 640 && this->shielderposition.x < 960.f) {
			velocity.y = -1.f;
		}
		else if (this->shielderposition.y >= 0.f && shielderposition.y < 360.f && this->shielderposition.x >= 960 && this->shielderposition.x < 1280.f) {
			velocity.y = 1.f;
		}
		else if (this->shielderposition.y >= 360.f && shielderposition.y < 720.f && this->shielderposition.x >= 0 && this->shielderposition.x < 320.f) {
			velocity.y = -1.f;
		}
		else if (this->shielderposition.y >= 360.f && shielderposition.y < 720.f && this->shielderposition.x >= 320 && this->shielderposition.x < 640.f) {
			velocity.y = 1.f;
		}
		else if (this->shielderposition.y >= 360.f && shielderposition.y < 720.f && this->shielderposition.x >= 640 && this->shielderposition.x < 960.f) {
			velocity.y = -1.f;
		}
		else if (this->shielderposition.y >= 360.f && shielderposition.y < 720.f && this->shielderposition.x >= 960 && this->shielderposition.x < 1280.f) {
			velocity.y = 1.f;
		}
		hitbox.setPosition(box.left + box.width, shielderbounds.top);
		shielderposition.x = box.left + box.width - 3;
		shielderposition.y = shielderbounds.top - 10;
		shieldersprite.setPosition(this->shielderposition);
		shielderHpBar.setPosition(this->shielderposition.x + 17, this->shielderposition.y);
		shields.setPosition(this->shielderposition.x + 23, this->shielderposition.y - 13);
	}
	hitbox.move(velocity);
	this->shieldersprite.move(this->velocity);
	this->shielderHpBar.move(this->velocity);
	shielderposition.x += velocity.x;
	shielderposition.y += velocity.y;
}

void shielder::updateHpBar()
{
	float hpPercent = (float)hp / (float)hpMax;
	this->shielderHpBar.setSize(sf::Vector2f(60.f * hpPercent, this->shielderHpBar.getSize().y));
}

void shielder::render(sf::RenderTarget& target)
{
	target.draw(this->hitbox);
	target.draw(this->nextbox);
	target.draw(this->shieldersprite);
	target.draw(this->shielderHpBar);
	if (this->shieldtimes.getElapsedTime().asSeconds() <= 2.f) {
		target.draw(this->shields);
	}
}

