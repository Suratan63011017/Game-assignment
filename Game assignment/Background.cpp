#include "Background.h"

//Texture BG
void Background::initTextureBG()
{
	this->TextureBG.loadFromFile("Sprite/BG.png");
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

//render BG
void Background::render(sf::RenderTarget& target)
{
	target.draw(this->SpriteBG);
}
