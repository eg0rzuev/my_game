#include "objects.h"

//constructor descriptions 
BackgrObj::BackgrObj(float x, float y):
	x_(x),
	y_(y)
	{}

Star::Star(float x, float y, int freq): 
	BackgrObj(x, y),
	frequency_(freq),
	star_(sf::Vector2f(STAR_SIZE, STAR_SIZE))
	{
		star_.setFillColor(STAR_COLOR);
		star_.setPosition(x_, y_);
	}

Smoke::Smoke(float x, float y /*float width, float heigth*/):
	BackgrObj(x, y)
	//width_(width),
	//heigth_(heigth)
	{
		smokeIm_.loadFromFile		( "images/smoke.png");
		smokeIm_.createMaskFromColor	(sf::Color::Black, 0);
	}

NatureObj::NatureObj(float x, float y, const std::string& imageName):
	BackgrObj(x, y)
	{
		objImage_.loadFromFile("images/" + imageName);
		width_ 	= objImage_.getSize().x;
		heigth_ = objImage_.getSize().y;
	}

NatureObj::NatureObj(float x, float y, float width, float heigth, const std::string& imageName):
	BackgrObj(x, y),
	width_(width),
	heigth_(heigth)
	{
		objImage_.loadFromFile("images/" + imageName);
	}

/* here draw(...) funcs are described
 *
 * every class has it's way to be drawn
 *
 */

void Smoke::draw(sf::RenderWindow& window)
{
	time_t currTime = 0;
	time(&currTime);		/* now currTime == (number of seconds since 01.01.1970) 
					 * when program is launched draw(window) works all the time 
					 * because of "while" cycle in main
					 */
	sf::Texture texture;		//some important things to create sf::Sprite
	texture.loadFromImage(smokeIm_);
	smoke_.setTexture(texture);
	smoke_.setPosition(x_, y_);
	switch(currTime % 4)		// so depending on what time is it window.draw(smoke_) 
					// will display different things (check images/smoke.png out)
	{
		case 3:
			smoke_.setTextureRect(sf::IntRect(0, 0, 20, 40)); 
			window.draw(smoke_);			
			break;
		case 2:
			smoke_.setTextureRect(sf::IntRect(20, 0, 20, 40));
			window.draw(smoke_);			
			break;
		case 1:
			smoke_.setTextureRect(sf::IntRect(40, 0, 20, 40));
			window.draw(smoke_);			
			break;
		case 0:
			smoke_.setTextureRect(sf::IntRect(60, 0, 20, 40));
			window.draw(smoke_);			
			break;		
	}
}


/*
 *
 *
 */

void NatureObj::draw(sf::RenderWindow& window)
{
	sf::Texture texture;
	objImage_.createMaskFromColor	(IGNORED_COLOR,0); // IGNORED_COLOR pixels are ignored
	texture.loadFromImage		(objImage_);
	texture.setSmooth		(true);
	natureObj_.setScale		(width_/(objImage_.getSize().x),heigth_/(objImage_.getSize().y));//size of Spriteis set 
	natureObj_.setTexture		(texture);
	natureObj_.setPosition		(x_, y_);
	window.draw			(natureObj_);
}	

/* the same mechanics with time as in Smoke.draw(...)
 */

void Star::draw(sf::RenderWindow& window)
{
	time_t currTime = 0;
	time(&currTime);
	if(currTime % frequency_ == 0)
	{
		window.draw(star_);
	}			
}

