#ifndef SKILL_H
#define SKILL_H

#include"Player.h"

class Skill
{
private:
	//texture and sprite skill
	sf::Sprite shape;
	sf::Texture* texture;

	//skills status
	sf::Vector2f direction;
	float movementSpeed;

public:
	//bullet functions
	Skill(sf::Texture* texture, float pos_x, float pos_y);
	virtual ~Skill();

	//getBounds functions
	const sf::FloatRect getBounds() const;

	//render and update functions
	void update();
	void render(sf::RenderTarget* target);
};

#endif // !SKILL_H