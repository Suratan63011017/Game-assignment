#ifndef WIZARD_H
#define WIZARD_H

#include"Player.h"
class wizard
{
private:
	sf::Sprite wizardsprite;
	sf::Texture wizardtexture;

	sf::RectangleShape hitbox;

	sf::Clock animatetimer;
	short animState;
	sf::IntRect currentFrame;
	sf::Vector2f wizardposition;

	int type;
	void initwizardTexture();
	void initwizardSprite();
	void initvariables();
	void initAnimations();

public:
	wizard(float pos_x, float pos_y);
	virtual ~wizard();

	const sf::FloatRect getBounds() const;

	const int gettype() const;
	void updatemovement();
	void updateAnimations();
	void updated();
	void render(sf::RenderTarget& target);
};
#endif //!WIZARD_H
