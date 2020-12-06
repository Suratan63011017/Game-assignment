#ifndef BLACKDRAGOON_H
#define BLACKDRAGOON_H

#include"Player.h"
class Blackdragoon
{
private:
	sf::Sprite Blackdragoonsprite;
	sf::Texture Blackdragoontexture;

	sf::Clock animatetimer;
	short animState;
	sf::IntRect currentFrame;
	sf::Vector2f Blackdragoonposition;

	void initBlackdragoonTexture();
	void initBlackdragoonSprite();
	void initvariables();
	void initAnimations();

public:
	Blackdragoon(float pos_x, float pos_y);
	virtual ~Blackdragoon();

	const sf::FloatRect getBounds() const;

	void updatemovement();
	void updateAnimations();
	void updated();
	void render(sf::RenderTarget& target);
};
#endif //!BLACKDRAGOON_H
