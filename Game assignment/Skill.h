#ifndef SKILL_H
#define SKILL_H

#include"Player.h"

class Skill
{
private:
	sf::Texture doubshottexture;
	sf::Sprite doubshotsprite;

	sf::Vector2f skillsposition;

	void initvariables();

	void initTexture();
	void initSprite();

public:
	Skill(float pos_x, float pos_y);
	virtual ~Skill();

	const sf::FloatRect getBounds() const;
	const int &doubshot() const;
	void update();
	void render(sf::RenderTarget* target);
};

#endif // !SKILL_H