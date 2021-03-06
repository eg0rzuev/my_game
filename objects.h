#ifndef MY_GAME_OBJECTS
#define MY_GAME_OBJECTS
#include <ctime>
#include "MAIN_HEADER.h"

/*
 * header file with definitions of classes
 *
 * which describe objects drawn in some window
 *
 */

//obvious definitions
const sf::Color STAR_COLOR = sf::Color::White;
const sf::Color IGNORED_COLOR = sf::Color(143,254,9); //pictures usually have bright green color in the background

/* parent virtual class 
 *
 * for objects that will be on background
 *
 * constructor sets x_, y_ coordinates 
 *
 */

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

/* objects of nature
 *
 * they are static and have their image
 *
 * NatureObj can be displayed on the screen -- method draw(...)
 *
 * constructor with 3 params -- set coords and name of image to upload
 *
 * cnstrctr with 5 prms -- same as with 3 but !!! size of NatureObj is regulated
 *
 */

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

/* star which blinks in the sky
 *
 * actually they are small squares which are displayed from time to time
 *
 * frequency_ is for frequency of blinking
 *
 * star_ is small square
 */
class Star: public BackgrObj//stars that will blink in the sky
{
	public:
		enum STARS
		{
			STAR_SIZE  = 5
		};	       	
		Star(float x, float y, int freq);
		void draw(sf::RenderWindow&) override;//star is not always on the screen, it blinks
	private:
		int 			frequency_;
		sf::RectangleShape 	star_;
};

/*
 * smoke coz spaceship is on fire!
 *
 * animation!!!!
 *
 */

class Smoke: public BackgrObj//smoke from the todo spaceship
{
	public:
		Smoke(float x, float y);
		void draw(sf::RenderWindow&) override;
	private:
		sf::Image	smokeIm_;
		sf::Sprite	smoke_;	
};	

/*class Bullet
{
	public:
		Bullet(Vector
}*/

#endif //MY_GAME_OBJECTS
