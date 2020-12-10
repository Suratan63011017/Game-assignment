#include "Mainmenu.h"

Mainmenu::Mainmenu(float width, float height)
{
	BGTexture.loadFromFile("Sprite/BGmenu.png");
	BGSprite.setTexture(this->BGTexture);

	scoreTexture.loadFromFile("Sprite/scoreBG.png");
	scoresprite.setTexture(this->scoreTexture);

	Deadtexture.loadFromFile("Sprite/Dead.png");
	Deadsprite.setTexture(this->Deadtexture);

	howtoplays[0].loadFromFile("Sprite/1.png");
	howtoplays[1].loadFromFile("Sprite/2.png");
	howtoplays[2].loadFromFile("Sprite/3.png");
	howtoplays[3].loadFromFile("Sprite/4.png");
	howtoplays[4].loadFromFile("Sprite/BGty.png");
	for (int i = 0; i < 5; i++) {
		howtoplaysprites[i].setTexture(howtoplays[i]);
	}

	font.loadFromFile("Font/2005_iannnnnAMD.ttf");
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setCharacterSize(40);
	menu[0].setPosition(sf::Vector2f((width / 2) - 15.f, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	button[0].setSize(sf::Vector2f(200.f, 50.f));
	button[0].setFillColor(sf::Color::Black);
	button[0].setPosition(sf::Vector2f((width / 2) - 100.f, (height / (MAX_NUMBER_OF_ITEMS + 1) * 1) + 10.f));


	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("score");
	menu[1].setCharacterSize(40);
	menu[1].setPosition(sf::Vector2f((width / 2) - 15.f, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
	button[1].setSize(sf::Vector2f(200.f, 50.f));
	button[1].setFillColor(sf::Color::Black);
	button[1].setPosition(sf::Vector2f((width / 2) - 100.f, (height / (MAX_NUMBER_OF_ITEMS + 1) * 2) + 10.f));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("how to play");
	menu[2].setCharacterSize(40);
	menu[2].setPosition(sf::Vector2f((width / 2) - 50.f, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	button[2].setSize(sf::Vector2f(200.f, 50.f));
	button[2].setFillColor(sf::Color::Black);
	button[2].setPosition(sf::Vector2f((width / 2) - 100.f, (height / (MAX_NUMBER_OF_ITEMS + 1) * 3) + 10.f));


	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Exit");
	menu[3].setCharacterSize(40);
	menu[3].setPosition(sf::Vector2f((width / 2) - 15.f, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));
	button[3].setSize(sf::Vector2f(200.f, 50.f));
	button[3].setFillColor(sf::Color::Black);
	button[3].setPosition(sf::Vector2f((width / 2) - 100.f, (height / (MAX_NUMBER_OF_ITEMS + 1) * 4) + 10.f));

	buttonname.loadFromFile("Sprite/namespace.png");
	namebuttonsprite.setTexture(this->buttonname);
	namebuttonsprite.setPosition(sf::Vector2f((width / 2) - 250.f, (height / 2) - 150.f));

	nextbutton.loadFromFile("Sprite/Arrow.png");
	nextbuttonsprite.setSize(sf::Vector2f(105.f, 75.f));
	nextbuttonsprite.setTexture(&this->nextbutton);
	nextbuttonsprite.setPosition(1150.f, 600.f);

	beforebuttonsprite.setSize(sf::Vector2f(105.f, 75.f));
	beforebuttonsprite.setScale(-1.f, 1.f);
	beforebuttonsprite.setTexture(&this->nextbutton);
	beforebuttonsprite.setPosition(130.f, 600.f);
	selectedITEMindex = 0;

	hitbox.setSize(sf::Vector2f(100.f, 100.f));
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setPosition(sf::Vector2f(400.f, 170.f));
}

Mainmenu::~Mainmenu()
{

}

void Mainmenu::draw(sf::RenderWindow& window)
{
	window.draw(this->BGSprite);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		window.draw(button[i]);
	}
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		window.draw(menu[i]);
	}
}

void Mainmenu::drawscore(sf::RenderWindow& window)
{
	window.draw(this->scoresprite);
	window.draw(this->beforebuttonsprite);
}

void Mainmenu::drawnamespace(sf::RenderWindow& window)
{
	window.draw(namebuttonsprite);
}

void Mainmenu::drawdead(sf::RenderWindow& window)
{
	window.draw(Deadsprite);
}

void Mainmenu::drawblass(sf::RenderWindow& window)
{
	window.draw(this->hitbox);
}

void Mainmenu::getplay(bool play)
{
	this->playstate = play;
}

void Mainmenu::Moveup()
{
	if (selectedITEMindex - 1 >= 0) {
		menu[selectedITEMindex].setFillColor(sf::Color::White);
		selectedITEMindex--;
		menu[selectedITEMindex].setFillColor(sf::Color::Red);
	}
}

void Mainmenu::Movedown()
{
	if (selectedITEMindex + 1 < MAX_NUMBER_OF_ITEMS) {
		menu[selectedITEMindex].setFillColor(sf::Color::White);
		selectedITEMindex++;
		menu[selectedITEMindex].setFillColor(sf::Color::Red);
	}
}

void Mainmenu::buttoncheck(const int button)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		if (button == i) {
			selectedITEMindex = button;
			menu[selectedITEMindex].setFillColor(sf::Color::Red);
		}
		else {
			menu[i].setFillColor(sf::Color::White);
		}
	}
}
const sf::FloatRect Mainmenu::getBounds_0() const
{
	return this->button[0].getGlobalBounds();
}
const sf::FloatRect Mainmenu::getBounds_1() const
{
	return this->button[1].getGlobalBounds();
}

const sf::FloatRect Mainmenu::getBounds_2() const
{
	return this->button[2].getGlobalBounds();
}

const sf::FloatRect Mainmenu::getBounds_3() const
{
	return this->button[3].getGlobalBounds();
}

const sf::FloatRect Mainmenu::dragon() const
{
	return this->hitbox.getGlobalBounds();
}

const sf::FloatRect Mainmenu::nextgetbounds() const
{
	return this->nextbuttonsprite.getGlobalBounds();
}

const sf::FloatRect Mainmenu::beforegetbounds() const
{
	return this->beforebuttonsprite.getGlobalBounds();
}

void Mainmenu::update(float width, float height)
{
	if (playstate) {
		menu[0].setString("RESUME");
		menu[0].setPosition(sf::Vector2f((width / 2) - 30.f, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	}
	else {
		menu[0].setString("Play");
		menu[0].setPosition(sf::Vector2f((width / 2) - 15.f, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	}
}

void Mainmenu::howtoplay(sf::RenderWindow& window)
{
	window.draw(this->howtoplaysprites[this->pages]);
	if (this->pages < 4) {
		window.draw(this->nextbuttonsprite);
	}
	window.draw(this->beforebuttonsprite);
}

void Mainmenu::nextpages()
{
	if (this->pages < 4) {
		(this->pages)++;
	}
}

void Mainmenu::beforepages()
{
	if (this->pages > 0) {
		(this->pages)--;
	}
	else this->pages = 0;
}

const int Mainmenu::getpages() const
{
	return this->pages;
}
