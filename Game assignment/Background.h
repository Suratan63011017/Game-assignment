#pragma once
#include "Player.h"
class Background
{
private:
	//variables
	sf::Sprite SpriteBG;
	sf::Texture TextureBG;
	sf::Texture ColdBG;
	sf::Texture FireBG;

	//Function
	void initSpiteBG();
	void initTextureBG();

public:
	Background();
	virtual ~Background();

	void update(int num);
	//render
	void render(sf::RenderTarget& target);
};

