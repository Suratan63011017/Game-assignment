#include "Background.h"

//Texture BG
void Background::initTextureBG()
{
	this->TextureBG.loadFromFile("Sprite/BG.png");
	this->ColdBG.loadFromFile("Sprite/ColdBG.png");
	this->FireBG.loadFromFile("Sprite/FireBG.png");
}

//Sprite BG
void Background::initSpiteBG()
{
	this->SpriteBG.setTexture(this->TextureBG);
}

Background::Background()
{
	//texture and Sprite
	this->initTextureBG();
	this->initSpiteBG();
}

Background::~Background()
{
}

void Background::update(int num)
{
	if (num == 0) {
		this->SpriteBG.setTexture(this->TextureBG);
	}
	else if (num == 1) {
		this->SpriteBG.setTexture(this->ColdBG);
	}
	else if (num == 2) {
		this->SpriteBG.setTexture(this->FireBG);
	}
}

//render BG
void Background::render(sf::RenderTarget& target)
{
	target.draw(this->SpriteBG);
}
