#ifndef MY_GAME_OBJECTS
#define MY_GAME_OBJECTS
#include <ctime>
#include "MAIN_HEADER.h"

const sf::Color STAR_COLOR = sf::Color::White;
const sf::Color IGNORED_COLOR = sf::Color(143,254,9);


enum STARS
{
	STAR_SIZE  = 5
};	       	


class BackgrObj
{
	public:
		BackgrObj	 	(float x, float y);
		~BackgrObj		() = default;
		virtual void draw	(sf::RenderWindow&) = 0;
	protected:
		int 	x_;
		int 	y_;
};

class NatureObj: public BackgrObj//i.e. planets or mountains
{
	public: 
		NatureObj(float x, float y, const std::string& imageName);
		NatureObj(float x, float y, float width, float height, const std::string& imageName);
		void draw(sf::RenderWindow&) override;
	private:
		sf::Image	objImage_;	
		sf::Sprite 	natureObj_;
		float 		width_;
		float 		heigth_;		
};

class Star: public BackgrObj//stars that will blink in the sky
{
	public:
		Star(float x, float y, int freq);
		void draw(sf::RenderWindow&) override;//star is not always on the screen, it blinks
	private:
		int 			frequency_;
		sf::RectangleShape 	star_;
};

class Smoke: public BackgrObj//smoke from the spaceship
{
	public:
		Smoke(float x, float y);
		void draw(sf::RenderWindow&) override;
	private:
		sf::Image	smokeIm_;
		sf::Sprite	smoke_;	
};		

#endif //MY_GAME_OBJECTS
