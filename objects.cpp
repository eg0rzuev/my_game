#include "objects.h"

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

Smoke::Smoke(float x, float y):
	BackgrObj(x, y)
	{
		smokeIm_.loadFromFile		("images/smoke.png");
		smokeIm_.createMaskFromColor	(sf::Color::Black,0);
	}	

void Smoke::draw(sf::RenderWindow& window)
{
	time_t currTime = 0;
	time(&currTime);
	sf::Texture texture;
	texture.loadFromImage(smokeIm_);
	smoke_.setTexture(texture);
	smoke_.setPosition(x_, y_);
	switch(currTime % 4)
	{
		case 3:
			smoke_.setTextureRect(sf::IntRect(0, 100, 50, 100));
			window.draw(smoke_);			
			break;
		case 2:
			smoke_.setTextureRect(sf::IntRect(50, 100, 50, 100));
			window.draw(smoke_);			
			break;
		case 1:
			smoke_.setTextureRect(sf::IntRect(100, 100, 50, 100));
			window.draw(smoke_);			
			break;
		case 0:
			smoke_.setTextureRect(sf::IntRect(150, 100, 50, 100));
			window.draw(smoke_);			
			break;		
	}
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


void NatureObj::draw(sf::RenderWindow& window)
{
	sf::Texture texture;
	objImage_.createMaskFromColor	(IGNORED_COLOR,0);
	texture.loadFromImage		(objImage_);
	texture.setSmooth		(true);
	natureObj_.setScale		(sf::Vector2f(width_/(objImage_.getSize().x),heigth_/(objImage_.getSize().y)));
	natureObj_.setTexture		(texture);
	natureObj_.setPosition		(x_, y_);
	window.draw			(natureObj_);
}	

void Star::draw(sf::RenderWindow& window)//star is blinking
{
	time_t currTime = 0;
	time(&currTime);
	if(currTime % frequency_ == 0)
	{
		window.draw(star_);
	}			
}

