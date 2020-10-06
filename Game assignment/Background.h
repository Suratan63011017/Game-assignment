#pragma once
#include "Player.h"
class Background
{
private:
	//variables
	sf::Sprite SpriteBG;
	sf::Texture TextureBG;

	//Function
	void initSpiteBG();
	void initTextureBG();

public:
	Background();
	virtual ~Background();

	//render
	void render(sf::RenderTarget& target);
};

